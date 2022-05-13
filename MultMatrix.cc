#include <MultMatrix.hh>

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
//  Nombre Completo:
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//   Description:
//           -->Completar la descripción
//
/////////////////////////////////////////////////////////////////////////////////



/*void MultMatrix::DOijk(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Completar
	int i = C.rows();
	int j = C.cols();

	std::cout << "test\n";
	std::cout << "rows: "<< C.rows() << std::endl;
	std::cout << "cols: "<< C.cols() << std::endl;
	std::cout << "const A: "<< A.value() << std::endl;
	
	
	//std::cout << "columms: "<< A.cols() << std::endl;
	

	for(size_t i=0; i < filas(a); i++){
		for(size_t j=0; j < columnas(b); j++){
			for(size_t k=0; k < columnas(a); k++){
			c[i][j] += a[i][k] * b[k][j];
			}			
		}
		}
}*/


void MultMatrix::DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Completar
}

//Sin const
void MultMatrix::DOijk(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C)
{
	//Completar
	//DO ijk
	//int i = A.rows();
	//int k = A.cols(); //Tambien B.rows()
	//int j = B.cols();	

	std::cout << "const A(0,0): "<< A.value(0,0) << std::endl;
	std::cout << "const B(1,1): "<< B.value(1,1) << std::endl;

	for(size_t i=0; i < A.rows(); i++){
		for(size_t j=0; j < B.cols(); j++){
			for(size_t k=0; k < A.cols(); k++){
				//c[i][j] += a[i][k] * b[k][j];
				C.value(i, j,  C.value(i, j)+A.value(i,k)*B.value(k,j)  );
			}			
		}
	}
}