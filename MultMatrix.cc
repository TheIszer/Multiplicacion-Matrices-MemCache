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
	__m128 matrix_b; //registro de float de 128 bits

	__m128 step01;
	__m128 step02;
	__m128 step03;
	__m128 step04;
	__m128 step05;
	__m128 step06;
	__m128 step07;

	matrix_a = _mm_setzero_ps();
	matrix_b = _mm_setzero_ps();

	float* dataMemoryIn  = new float[4];
	float* dataMemoryOut = new float[4];
	
	dataMemoryIn[0] = 0.5;
	dataMemoryIn[1] = 1.5;
	dataMemoryIn[2] = 2.5;
	dataMemoryIn[3] = 3.5;
	
	// __m128 _mm_load_ps(float const* mem_addr)
	// dst[127:0] := MEM[mem_addr+127:mem_addr]
	matrix_a = _mm_load_ps(dataMemoryIn);
	matrix_b = _mm_load_ps(dataMemoryIn);
	
	showRegister("matrix_a", matrix_a);
	
	//step01 = matrixA;
	step01 = _mm_shuffle_ps(matrix_a, matrix_a, _MM_SHUFFLE(1,1,3,3) );
	step02 = _mm_shuffle_ps(matrix_b, matrix_b, _MM_SHUFFLE(2,3,2,3) );
	step03 = _mm_shuffle_ps(matrix_a, matrix_a, _MM_SHUFFLE(0,0,2,2) );
	step04 = _mm_shuffle_ps(matrix_b, matrix_b, _MM_SHUFFLE(0,1,0,1) );

	step05 = _mm_mul_ps(step01, step02);
	step06 = _mm_mul_ps(step03, step04);

	step07 = _mm_add_ps(step05, step06);

	
	showRegister("step01", step01);
	showRegister("step02", step02);
	showRegister("step03", step03);
	showRegister("step04", step04);
	showRegister("step05", step05);
	showRegister("step06", step06);
	showRegister("step07", step07);
}

void MultMatrix::DOkijSIMD(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C){

}