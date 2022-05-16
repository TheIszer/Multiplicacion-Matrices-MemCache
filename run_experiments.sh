#!/bin/bash

#/////////////////////////////////////////////////////////////////////////////////
#  Identificación del alumno
#
#  Nombre Completo: Isser Kaleb Antonio Vasquez
#/////////////////////////////////////////////////////////////////////////////////

#/////////////////////////////////////////////////////////////////////////////////
#//   Usage:
#//           ./run_experiments --matrix <ruta_al_archivo_de_datos> --repeticiones <nro>
#//
#//   Description:
#//           -->Completar la descripción
#//
#/////////////////////////////////////////////////////////////////////////////////

#chmod +x run_experiments.sh
ruta_de_datos=$2
repeticiones=$4

echo "Archivo: $2 Repeticiones: $4"
echo "Variables $ruta_de_datos y $repeticiones"

./mult --A $ruta_de_datos

((n=repeticiones+1))
echo "repeticiones++ $n"

for i in ((repeticiones))
do 
    echo "a"
done

echo "FIN"