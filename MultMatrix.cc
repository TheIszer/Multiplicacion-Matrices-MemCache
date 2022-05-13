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
	


	for(size_t i=0; i < filas(a); i++){
		for(size_t j=0; j < columnas(b); j++){
			for(size_t k=0; k < columnas(a); k++){
			c[i][j] += a[i][k] * b[k][j];
			}			
		}
		}
}


void MultMatrix::DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C)
{
	//Completar
}

