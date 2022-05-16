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

echo "#rowsxcols:time_ijk:time_kij"

#./mult --A $ruta_de_datos

((count=repeticiones))
while [ $count -gt 0 ]
do
    ((count=count-1))
    ./mult --A $ruta_de_datos
done