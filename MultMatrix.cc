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

//SIMD
void MultMatrix::DOijkSIMD(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C){
	__m128 matrix_a; //registro de float de 128 bits	
	__m128 step01;
	matrix_a = _mm_setzero_ps();

	float* dataMemoryIn  = new float[4];
	float* dataMemoryOut = new float[4];
	
	dataMemoryIn[0] = 0.5;
	dataMemoryIn[1] = 1.5;
	dataMemoryIn[2] = 2.5;
	dataMemoryIn[3] = 3.5;
	
	// __m128 _mm_load_ps(float const* mem_addr)
	// dst[127:0] := MEM[mem_addr+127:mem_addr]
	matrix_a = _mm_load_ps(dataMemoryIn);
	
	showRegister("matrix_a", matrix_a);
	
	//step01 = matrixA;
	step01 = _mm_shuffle_ps(matrix_a, matrix_a, _MM_SHUFFLE(3,3,0,0) );
	
	showRegister("step01", step01);
}

void MultMatrix::DOkijSIMD(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C){

}