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
//           -->Completar la descripción
//
/////////////////////////////////////////////////////////////////////////////////

void uso(std::string pname)
{
	std::cerr << "Uso: " << pname << " --A MATRIX_FILE" << std::endl;
}

int main(int argc, char** argv)
{
	Timer<std::chrono::nanoseconds> timer1;
	Timer<std::chrono::nanoseconds> timer2;
	Timer<std::chrono::nanoseconds> timer3;
	std::string fileMatrixA;
	
	///////////////////////////////////////
	//  Read command-line parameters
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
	
	std::cout << "Time to load matrix in memory: " << timer1.elapsed() << " ns\n";
	
	//Imprimir la matriz m1
	/*std::cout << "MATRIZ m1\n";
	for(size_t i=0; i< m1.rows(); i++){
		for(size_t j=0; j< m1.cols(); j++){
			std::cout << m1(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/
	
	// Ejemplo de creación de matrix vacía
	MultMatrix mm;
	Matrix<float> C(m1.rows(), m1.cols());
	Matrix<float> C2(m1.rows(), m1.cols());
	
	//Ejemplo de llamada al método del algoritmo ijk

	timer2.start();
	mm.DOijk(m1, m1, C);
	timer2.stop();
	//std::cout << "rowsxcols:time_ijk=" << timer2.elapsed() << " ns"  << ":time_kij #1\n";
	
	//Imprimir la matriz C
	/*std::cout << "MATRIZ C\n";
	for(size_t i=0; i< C.rows(); i++){
		for(size_t j=0; j< C.cols(); j++){
			std::cout << C(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/

	timer3.start();
	mm.DOkij(m1, m1, C2);
	timer3.stop();
	//std::cout << "rowsxcols:time_ijk:time_kij=" << timer3.elapsed() << " ns"  << " #1\n\n";

	//Imprimir la matriz C
	/*std::cout << "MATRIZ C2\n";
	for(size_t i=0; i< C2.rows(); i++){
		for(size_t j=0; j< C2.cols(); j++){
			std::cout << C2(i,j) << "\t";
		}
		std::cout << std::endl;
	}*/

	//rowsxcols:time_ijk:time_kij #<-- nros dependen de la ejecución
	std::cout << m1.rows() << "x" << m1.cols() << ":" << timer2.elapsed() << ":" << timer3.elapsed() << " #\n";

	return(EXIT_SUCCESS);
}


