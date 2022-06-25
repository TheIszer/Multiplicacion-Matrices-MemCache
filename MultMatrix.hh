#pragma once

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
//  Nombre Completo: Isser Kaleb Antonio Vasquez
/////////////////////////////////////////////////////////////////////////////////

#include <global.hh>
#include <Matrix.hpp>
// Intrinsics to use
#include <emmintrin.h> 
#include <immintrin.h> 
#include <xmmintrin.h>

class MultMatrix
{
private:		//Atributos
	//Todas las variables privadas deben comenzar con _

public:			//Metodos
	MultMatrix(){}
	~MultMatrix(){}
	
	void DOijk(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C);
	void DOkij(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C);
	//SIMD
	void DOijkSIMD(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C);
	void DOkijSIMD(const Matrix<float>& A, const Matrix<float>& B, Matrix<float>& C);
};



