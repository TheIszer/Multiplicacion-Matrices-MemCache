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
  

#-------------
#	Tiempos de ejecucion, media y desviacion estandar
#------------- 
	 
#------------- 5x9 -------------#       
set title "Execution time, mean and Standard deviation Graph"
set ylabel "Time (ns)"
set xlabel "Num de Experimento"
set output "Graph_5x9.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
set ytics format "10^{%L}"
set yrange [400:]
set logscale y 20

#Obtener la media y la desviacion estandar
stats FILE_5x9 using 2 name "ijk5x9"
stats FILE_5x9 using 3 name "kij5x9"
#Se grafican utilizando los archivos de datos generados por los experimentos.
plot FILE_5x9 using 0:($2) title "5x9 ijk experiments"  with lines lt 30 lw 1 dt 1,\
        ijk5x9_mean t "5x9 ijk mean" with lines lt 30 lw 2 dt 3,\
        ijk5x9_stddev t "5x9 ijk standard dev" with lines lt 3 lw 2 dt 3,\
        FILE_5x9 using 0:($3) title "5x9 kij experiments"  with lines lt 31 lw 1 dt 1,\
        kij5x9_stddev t "5x9 kij standard dev" with lines lt 20 lw 2 dt 3,\
        kij5x9_mean t "5x9 kij mean" with lines lt 31 lw 2 dt 3


#------------- 6x5 -------------#       
set title "Execution time, mean and Standard deviation Graph"
set ylabel "Time (ns)"
set xlabel "Num de Experimento"
set output "Graph_6x5.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
set ytics format "10^{%L}"
set yrange [400:]
set logscale y 20

#Obtener la media y la desviacion estandar
stats FILE_6x5 using 2 name "ijk6x5"
stats FILE_6x5 using 3 name "kij6x5"
#Se grafican utilizando los archivos de datos generados por los experimentos.
plot FILE_6x5 using 0:($2) title "6x5 ijk experiments"  with lines lt 30 lw 1 dt 1,\
        ijk6x5_mean t "6x5 ijk mean" with lines lt 30 lw 2 dt 3,\
        ijk6x5_stddev t "6x5 ijk standard dev" with lines lt 3 lw 2 dt 3,\
        FILE_6x5 using 0:($3) title "6x5 kij experiments"  with lines lt 31 lw 1 dt 1,\
        kij6x5_stddev t "6x5 kij standard dev" with lines lt 20 lw 2 dt 3,\
        kij6x5_mean t "6x5 kij mean" with lines lt 31 lw 2 dt 3


#------------- 6x6 -------------#       
set title "Execution time, mean and Standard deviation Graph"
set ylabel "Time (ns)"
set xlabel "Num de Experimento"
set output "Graph_6x6.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
set ytics format "10^{%L}"
set yrange [400:]
set logscale y 20

#Obtener la media y la desviacion estandar
stats FILE_6x6 using 2 name "ijk6x6"
stats FILE_6x6 using 3 name "kij6x6"
#Se grafican utilizando los archivos de datos generados por los experimentos.
plot FILE_6x6 using 0:($2) title "6x6 ijk experiments"  with lines lt 30 lw 1 dt 1,\
        ijk6x6_mean t "6x6 ijk mean" with lines lt 30 lw 2 dt 3,\
        ijk6x6_stddev t "6x6 ijk standard dev" with lines lt 3 lw 2 dt 3,\
        FILE_6x6 using 0:($3) title "6x6 kij experiments"  with lines lt 31 lw 1 dt 1,\
        kij6x6_stddev t "6x6 kij standard dev" with lines lt 20 lw 2 dt 3,\
        kij6x6_mean t "6x6 kij mean" with lines lt 31 lw 2 dt 3


#------------- 10x5 -------------#       
set title "Execution time, mean and Standard deviation Graph"
set ylabel "Time (ns)"
set xlabel "Num de Experimento"
set output "Graph_10x5.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
set ytics format "10^{%L}"
set yrange [400:]
set logscale y 20

#Obtener la media y la desviacion estandar
stats FILE_10x5 using 2 name "ijk10x5"
stats FILE_10x5 using 3 name "kij10x5"
#Se grafican utilizando los archivos de datos generados por los experimentos.
plot FILE_10x5 using 0:($2) title "10x5 ijk experiments"  with lines lt 30 lw 1 dt 1,\
        ijk10x5_mean t "10x5 ijk mean" with lines lt 30 lw 2 dt 3,\
        ijk10x5_stddev t "10x5 ijk standard dev" with lines lt 3 lw 2 dt 3,\
        FILE_10x5 using 0:($3) title "10x5 kij experiments"  with lines lt 31 lw 1 dt 1,\
        kij10x5_stddev t "10x5 kij standard dev" with lines lt 20 lw 2 dt 3,\
        kij10x5_mean t "10x5 kij mean" with lines lt 31 lw 2 dt 3


#------------- 600x600 -------------#       
set title "Execution time, mean and Standard deviation Graph"
set ylabel "Time (ns)"
set xlabel "Num de Experimento"
set output "Graph_600x600.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
set ytics format "10^{%L}"
set yrange [10000000:]
set logscale y 20

#Obtener la media y la desviacion estandar
stats FILE_600x600 using 2 name "ijk600x600"
stats FILE_600x600 using 3 name "kij600x600"
#Se grafican utilizando los archivos de datos generados por los experimentos.
plot FILE_600x600 using 0:($2) title "600x600 ijk experiments"  with lines lt 30 lw 1 dt 1,\
        ijk600x600_mean t "600x600 ijk mean" with lines lt 30 lw 2 dt 3,\
        ijk600x600_stddev t "600x600 ijk standard dev" with lines lt 3 lw 2 dt 3,\
        FILE_600x600 using 0:($3) title "600x600 kij experiments"  with lines lt 31 lw 1 dt 1,\
        kij600x600_stddev t "600x600 kij standard dev" with lines lt 20 lw 2 dt 3,\
        kij600x600_mean t "600x600 kij mean" with lines lt 31 lw 2 dt 3