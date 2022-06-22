#include <MultMatrix.hh>

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
//  Nombre Completo: Isser Kaleb Antonio Vasquez
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//   Description:
//   		Definicion de los metodos del objeto MultMatrix, contiene los metodos
//			de multiplicacion de matrices "ijk" y "kij"
//
/////////////////////////////////////////////////////////////////////////////////


//Método ijk de multiplicacion de matrices
void MultMatrix::DOijk(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Variables i k j, siendo las matrices de tamaño ik & kj
	//int i = A.rows();
	//int k = A.cols(); //Tambien puede utilizarse B.rows()
	//int j = B.cols();	

	for(size_t i=0; i < A.rows(); i++){
		for(size_t j=0; j < B.cols(); j++){
			for(size_t k=0; k < A.cols(); k++){
				//c[i][j] += a[i][k] * b[k][j];
				C.value(i, j,  C.value(i, j)+A.value(i,k)*B.value(k,j)  );
			}			
		}
	}

}

//Método kij de multiplicacion de matrices
void MultMatrix::DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
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
}