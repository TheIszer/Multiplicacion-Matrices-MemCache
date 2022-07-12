#!/bin/bash

#/////////////////////////////////////////////////////////////////////////////////
#  Identificación del alumno
#
#  Nombre Completo: Isser Kaleb Antonio Vasquez
#/////////////////////////////////////////////////////////////////////////////////

#/////////////////////////////////////////////////////////////////////////////////
#//     Usage:
#//         ./run_experiments --matrix <ruta_al_archivo_de_datos> --repeticiones <nro>
#//
#//     Si se llega a dar el siguiente error:
#//         -bash: ./run_experiments.sh: Permission denied
#//     Dar los permisos con el comando:
#//         chmod +x run_experiments.sh
#//
#//     Description:
#//         Script en Bash utilizado para la realizacion de los experimentos, se
#//         realizan <nro> de experimentos utilizando ./mult --A $ruta_de_datos
#//
#//     Output:
#//         #rowsxcols:time_ijk:time_kij    <-- Encabezado
#//         rowsxcols:time_ijk:time_kij     #<-- nros dependen de la ejecución
#//
#//     Para la obtencion de datos la salida se redirijio a un archivo txt, Ejemplo:
#//         ./run_experiments --matrix <archivo_de_datos> --repeticiones <nro> >> experimentoN.txt 
#/////////////////////////////////////////////////////////////////////////////////

#Variables
ruta_de_datos=$2
repeticiones=$4

#Header
echo "#rowsxcols:time_ijk:time_kij:time_ijkSIMD:time_kijSIMD"

#Loop
((count=repeticiones))
while [ $count -gt 0 ]
do
    ((count=count-1))
    ./mult --A $ruta_de_datos
done