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
./run_experiments.sh --matrix ./data/5x5-F.txt --repeticiones 50 >> ./experimentos/exp5x5.txt
sleep 10
./run_experiments.sh --matrix ./data/10x10-F.txt --repeticiones 50 >> ./experimentos/exp10x10.txt
sleep 20
./run_experiments.sh --matrix ./data/20x20-F.txt --repeticiones 50 >> ./experimentos/exp20x20.txt
sleep 30
./run_experiments.sh --matrix ./data/40x40-F.txt --repeticiones 50 >> ./experimentos/exp40x40.txt
sleep 60
./run_experiments.sh --matrix ./data/80x80-F.txt --repeticiones 50 >> ./experimentos/exp80x80.txt
sleep 120
./run_experiments.sh --matrix ./data/160x160-F.txt --repeticiones 50 >> ./experimentos/exp160x160.txt
sleep 240
./run_experiments.sh --matrix ./data/320x320-F.txt --repeticiones 50 >> ./experimentos/exp320x320.txt
sleep 480
./run_experiments.sh --matrix ./data/640x640-F.txt --repeticiones 50 >> ./experimentos/exp640x640.txt
sleep 960

./run_experiments.sh --matrix ./data/5x5-F.txt --repeticiones 50 >> ./experimentos/2exp5x5.txt
sleep 10
./run_experiments.sh --matrix ./data/10x10-F.txt --repeticiones 50 >> ./experimentos/2exp10x10.txt
sleep 20
./run_experiments.sh --matrix ./data/20x20-F.txt --repeticiones 50 >> ./experimentos/2exp20x20.txt
sleep 30
./run_experiments.sh --matrix ./data/40x40-F.txt --repeticiones 50 >> ./experimentos/2exp40x40.txt
sleep 60
./run_experiments.sh --matrix ./data/80x80-F.txt --repeticiones 50 >> ./experimentos/2exp80x80.txt
sleep 120
./run_experiments.sh --matrix ./data/160x160-F.txt --repeticiones 50 >> ./experimentos/2exp160x160.txt
sleep 240
./run_experiments.sh --matrix ./data/320x320-F.txt --repeticiones 50 >> ./experimentos/2exp320x320.txt
sleep 480
./run_experiments.sh --matrix ./data/640x640-F.txt --repeticiones 50 >> ./experimentos/2exp640x640.txt