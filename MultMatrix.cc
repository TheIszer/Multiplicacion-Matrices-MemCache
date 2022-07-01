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
void MultMatrix::DOijk(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C)
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
void MultMatrix::DOkij(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C)
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

void showRegister(std::string name, __m128 reg){
	float* tmpOut = new float[4];
	
	_mm_store_ps(tmpOut, reg);
	
	std::cout << name << " = ";
	for(size_t ii=0; ii < 4; ii++){
		std::cout << tmpOut[ii];
		std::cout << " ";
	}
	std::cout << std::endl;
	
	delete[] tmpOut;
}

//Método ijk de multiplicacion de matrices
void MultMatrix::DOijkSIMD(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C)
{
	//Variables i k j, siendo las matrices de tamaño ik & kj
	//ESTE METODO SOLO SIRVE PARA MATRICES CUADRADRAS 
	//		CON TAMAÑO DIVISIBLE EN 4
	int size = A.rows();

	for(size_t i=0; i < size; i++){
		float* arrTmp01  = new float[4];
		float* arrTmp02  = new float[4];
		float* result  = new float[4];
		__m128 vecTmp01;
		__m128 vecTmp02;
		__m128 vecResult;

		vecTmp01 = _mm_setzero_ps();
		vecTmp02 = _mm_setzero_ps();
		vecResult = _mm_setzero_ps();

		for(size_t j=0; j < size; j++){
			//Se van multiplicando de a 4 floats por medio de los vectores
			for(size_t k=0; k < size; k+=4){
				//Llenamos el arreglo 1 con A
				arrTmp01[0] = A.value(i,k);
				arrTmp01[1] = A.value(i,k+1);
				arrTmp01[2] = A.value(i,k+2);
				arrTmp01[3] = A.value(i,k+3);

				//Llenamos el arreglo 2 con B
				arrTmp02[0] = B.value(k, j);
				arrTmp02[1] = B.value(k+1, j);
				arrTmp02[2] = B.value(k+2, j);
				arrTmp02[3] = B.value(k+3, j);

				//Cargamos los vectores con los arreglos
				//	__m128 _mm_load_ps(float const* mem_addr)
				//	dst[127:0] := MEM[mem_addr+127:mem_addr]
				vecTmp01 = _mm_load_ps(arrTmp01);
				vecTmp02 = _mm_load_ps(arrTmp02);

				//Multiplicamos los vectores
				//	__m128 _mm_mul_ps (__m128 a, __m128 b)
				//	st[127:i] := a[127:i] * b[127:i]
				vecResult = _mm_mul_ps(vecTmp01, vecTmp02);
				//Los guardamos en un arreglo
				//	void _mm_store_ps (float* mem_addr, __m128 a)
				//	MEM[mem_addr+127:mem_addr] := a[127:0]
				_mm_store_ps(result, vecResult);

				//Almacenamos el resultado en la matriz C
				//	c[i][j] += result[0]+result[1]+result[2]+result[3];
				C.value(i, j,  C.value(i, j)+result[0]+result[1]+result[2]+result[3]  );
			}			
		}
	}

}

//Método kij de multiplicacion de matrices
void MultMatrix::DOkijSIMD(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C)
{
	//__m128 test;
	//float* r = new float[1];
	//r[0] = 2.93212f;
	//test = _mm_load_ps1(r);
	//showRegister("test", test);

	float* arrTmp = new float[4];
	float* result  = new float[4];
	__m128 vecTmp;
	__m128 vecResult;

	vecTmp = _mm_setzero_ps();
	vecResult = _mm_setzero_ps();

	for(size_t k=0; k < A.cols(); k++){
		for(size_t i=0; i < A.rows(); i++){
			//float r = a[i][k]
			//float r = A.value(i,k);
			float* r = new float[1];
			r[0] = A.value(i,k);
			__m128 rVec = _mm_load_ps1(r);
				for(size_t j=0; j < B.cols(); j+=4){
					//c[i][j] += r * b[k][j];
					//Llenamos el arreglo temporal con B
					arrTmp[0] = B.value(k, j);
					arrTmp[1] = B.value(k, j+1);
					arrTmp[2] = B.value(k, j+2);
					arrTmp[3] = B.value(k, j+3);
					//Cargamos los vectores con los arreglos
					vecTmp = _mm_load_ps(arrTmp);

					//Multiplicamos los vectores
					vecResult = _mm_mul_ps(rVec, vecTmp);
					//Los guardamos en un arreglo
					_mm_store_ps(result, vecResult);

					C.value(i,j, C.value(i, j)+result[0] );
					C.value(i,j+1, C.value(i, j)+result[1] );
					C.value(i,j+2, C.value(i, j)+result[2] );
					C.value(i,j+3, C.value(i, j)+result[3] );
				}			
		}
	}
}