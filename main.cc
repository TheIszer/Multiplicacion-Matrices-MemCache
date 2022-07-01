#include <global.hh>

#include <Timer.hpp>
#include <Matrix.hpp>
 
#include <MultMatrix.hh>

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
// Nombre Completo: Isser Kaleb Antonio Vasquez
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./mult --A matrix_file
//
//   Description:
//   		Codigo fuente que mide el tiempo de ejecución en nanoSegundos de  
//			dos métodos de multiplicación de matrices (Métdodo ijk vs kij)
//
//		Input:
//			matrix_file.txt en donde:
//				Los datos deberan estar separados por un espacio " " y
// 				La primera linea debe ser el tamaño de la matriz Ej:6 6
//
//		Output:
//			rowsxcols:time_ijk:time_kij		(en nanosegundos)
//				Ejemplo de salida: 6x6:5009:3747
//
/////////////////////////////////////////////////////////////////////////////////

void uso(std::string pname)
{
	std::cerr << "Uso: " << pname << " --A MATRIX_FILE" << std::endl;
}

int main(int argc, char** argv)
{
	//Timers en nanosegundos
	Timer<std::chrono::nanoseconds> timer1;	//para la carga de la matriz
	Timer<std::chrono::nanoseconds> timer2;	//para el metodo ijk
	Timer<std::chrono::nanoseconds> timer3;	//para el metodo kij
	std::string fileMatrixA;
	
	///////////////////////////////////////
	//  Read command-line parameters
	///////////////////////////////////////
	if(argc != 3){
		uso(argv[0]);
		exit(EXIT_FAILURE);
	}
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "--A") {
			fileMatrixA = argv[i+1];
		}
	}
	
	if(fileMatrixA == ""){
		uso(argv[0]);
		exit(EXIT_FAILURE);
	}
	Matrix<float> m1(fileMatrixA, " ");
	
	timer1.start();
	try{
		m1.load();
	} catch(std::exception& e){
		std::cerr << e.what() <<std::endl;
		exit(EXIT_FAILURE);
	}
	timer1.stop();
	
	//std::cout << "Time to load matrix in memory: " << timer1.elapsed() << " ns\n";
	
	// Imprimir la matriz m1
	/*std::cout << "MATRIZ m1\n";
	for(size_t i=0; i< m1.rows(); i++){
		for(size_t j=0; j< m1.cols(); j++){
			std::cout << m1(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/
	

	///////////////////////////////////////
	//  Multiplicacion de matrices
	///////////////////////////////////////

	//Creación de matrix vacía
	MultMatrix mm;
	Matrix<float> C(m1.rows(), m1.cols());
	Matrix<float> C2(m1.rows(), m1.cols());
	Matrix<float> C3(m1.rows(), m1.cols());
	
	//Llamada al método del algoritmo ijk
	timer2.start();
	mm.DOijk(m1, m1, C);
	timer2.stop();
	
	//Imprimir la matriz C
	/*std::cout << "MATRIZ C\n";
	for(size_t i=0; i< C.rows(); i++){
		for(size_t j=0; j< C.cols(); j++){
			std::cout << C(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/

	//Llamada al método del algoritmo kij
	timer3.start();
	mm.DOkij(m1, m1, C2);
	timer3.stop();

	//Imprimir la matriz C
	/*std::cout << "MATRIZ C2\n";
	for(size_t i=0; i< C2.rows(); i++){
		for(size_t j=0; j< C2.cols(); j++){
			std::cout << C2(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/


	//Llamada al método del algoritmo SIMD ijk
	timer1.start();
	mm.DOijkSIMD(m1, m1, C3);
	timer1.stop(); 
	//Imprimir la matriz C
	std::cout << "MATRIZ C3\n";
	for(size_t i=0; i< C3.rows(); i++){
		for(size_t j=0; j< C3.cols(); j++){
			std::cout << C3(i,j) << "\t";
		}
		std::cout << std::endl;
	}


	//rowsxcols:time_ijk:time_kij:time_ijkSIMD:time_kijSIMD #<-- nros dependen de la ejecución
	std::cout << "rowsxcols:time_ijk:time_kij:time_ijkSIMD:time_kijSIMD\n";
	std::cout << m1.rows() << "x" << m1.cols() << ":" << timer2.elapsed() << ":" << timer3.elapsed() << ":" << timer1.elapsed() << ":" << "time_kijSIMD" << "\n";

	return(EXIT_SUCCESS);
}


