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

public:			//Metodos
	MultMatrix(){}
	~MultMatrix(){}
	
	void DOijk(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C);
	void DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C);
};



