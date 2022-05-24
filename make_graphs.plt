#!/usr/bin/env gnuplot

#---------------------------
#  Identificación del alumno
#
#  Nombre Completo: Isser Kaleb Antonio Vasquez
#----------------------------

set encoding iso_8859_1
set term png size 800,600

set datafile separator ":"

FILE_5x9="experimentos/experimento_5x9_100.txt"
FILE_6x5="experimentos/experimento_6x5_100.txt"
FILE_6x6="experimentos/experimento_6x6_100.txt"
FILE_10x5="experimentos/experimento_10x5_100.txt"
FILE_600x600="experimentos/experimento_600x600_100.txt"
FILE_graphs="experimentos/graphs.txt"
  

#-------------
#	Tiempos de ejecucion, media y desviacion estandar
#------------- 
	 
#------------- 5x9 -------------#       
set title "Execution time, mean and Standard deviation Graph (5x9 Matrix)"
set ylabel "Time (ns)"
set xlabel "Num de Experimento"
set output "Graph_1.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
#set ytics format "10^{%L}"
#set yrange [400:]
#set logscale y 20

set xrange [0:100]

#Obtener la media y la desviacion estandar
stats FILE_5x9 using 2 name "ijk5x9"
stats FILE_5x9 using 3 name "kij5x9"
#Obtener la media y la desviacion estandar
stats FILE_6x5 using 2 name "ijk6x5"
stats FILE_6x5 using 3 name "kij6x5"
#Obtener la media y la desviacion estandar
stats FILE_6x6 using 2 name "ijk6x6"
stats FILE_6x6 using 3 name "kij6x6"
#Obtener la media y la desviacion estandar
stats FILE_10x5 using 2 name "ijk10x5"
stats FILE_10x5 using 3 name "kij10x5"
#Obtener la media y la desviacion estandar
stats FILE_600x600 using 2 name "ijk600x600"
stats FILE_600x600 using 3 name "kij600x600"

plot FILE_graphs using 1:2:4 title "5x9 ijk" lt 7 lc 22 with yerrorbars


#Se grafican utilizando los archivos de datos generados por los experimentos.
#plot FILE_5x9 using 0:($2) title "5x9 ijk experiments"  with lines lt 30 lw 1 dt 1,\
        ijk5x9_mean t "5x9 ijk mean" with lines lt 30 lw 2 dt 3,\
        ijk5x9_stddev t "5x9 ijk standard dev" with lines lt 3 lw 2 dt 3,\
        FILE_5x9 using 0:($3) title "5x9 kij experiments"  with lines lt 31 lw 1 dt 1,\
        kij5x9_stddev t "5x9 kij standard dev" with lines lt 20 lw 2 dt 3,\
        kij5x9_mean t "5x9 kij mean" with lines lt 31 lw 2 dt 3

