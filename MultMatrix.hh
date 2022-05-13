#pragma once

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
//  Nombre Completo: Isser Kaleb Antonio Vasquez
/////////////////////////////////////////////////////////////////////////////////

#include <global.hh>
#include <Matrix.hpp>

class MultMatrix
{
private:		//Atributos
	//Todas las variables privadas deben comenzar con _
	//Matrix<float> matrizA; 
	//Matrix<float> matrizB; 
	//Matrix<float> matrizC; 

public:			//Metodos
	MultMatrix(){ //Constructor
	}
	~MultMatrix(){}
	
	void DOijk(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C);
	void DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C);
	//Sin const
	//void DOijk(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C);
	//void DOkij(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C);

};



