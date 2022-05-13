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



void MultMatrix::DOijk(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Completar

	//DO ijk
	//int i = A.rows();
	//int k = A.cols(); //Tambien B.rows()
	//int j = B.cols();	

	std::cout << "test\n";
	std::cout << "rows: "<< C.rows() << std::endl;
	std::cout << "cols: "<< C.cols() << std::endl;
	std::cout << "const A value(0,0): "<< A.value(0,0) << std::endl;

	//Matrix<float> Atemp(C.rows(), C.cols());
	//Atemp << A;
	
	

	//std::cout << "columms: "<< A.cols(0,0) << std::endl;
	

	/* for(size_t i=0; i < filas(a); i++){
		for(size_t j=0; j < columnas(b); j++){
			for(size_t k=0; k < columnas(a); k++){
			c[i][j] += a[i][k] * b[k][j];
			}			
		}
	} */
}


void MultMatrix::DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Completar
}

//Sin const
/*void MultMatrix::DOijk(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C)
{
	//Completar
	//DO ijk
	//int i = A.rows();
	//int k = A.cols(); //Tambien B.rows()
	//int j = B.cols();	

	for(size_t i=0; i < A.rows(); i++){
		for(size_t j=0; j < B.cols(); j++){
			for(size_t k=0; k < A.cols(); k++){
				//c[i][j] += a[i][k] * b[k][j];
				C.value(i, j,  C.value(i, j)+A.value(i,k)*B.value(k,j)  );
			}			
		}
	}
}*/

//Sin const
/*void MultMatrix::DOkij(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C)
{
	//Completar

	for(size_t k=0; k < A.cols(); k++){
		for(size_t i=0; i < A.rows(); i++){
			//float r = a[i][k]
			float r = A.value(i,k);
				for(size_t j=0; j < B.cols(); j++){
					//c[i][j] += r * b[k][j];
					C.value(i,j, C.value(i, j)+r*B.value(k,j)  );
				}			
		}
	}
}*/