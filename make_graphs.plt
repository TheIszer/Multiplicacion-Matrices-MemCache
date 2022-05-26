#!/usr/bin/env gnuplot

#---------------------------
#  Identificación del alumno
#
#  Nombre Completo: Isser Kaleb Antonio Vasquez
#----------------------------

set encoding iso_8859_1
set term png size 800,600

set datafile separator ":"

#Archivos de datos generados por run_experiments_sh
FILE_5x5="experimentos/exp5x5.txt"
FILE_10x10="experimentos/exp10x10.txt"
FILE_20x20="experimentos/exp20x20.txt"
FILE_40x40="experimentos/exp40x40.txt"
FILE_80x80="experimentos/exp80x80.txt"
FILE_160x160="experimentos/exp160x160.txt"
FILE_320x320="experimentos/exp320x320.txt"
FILE_640x640="experimentos/exp640x640.txt"

#Obtener la media y la desviacion estandar de cada archivo a traves de stats
#Se guarda esta informacion en una variable
stats FILE_5x5 using 2 name "ijk5x5"
stats FILE_5x5 using 3 name "kij5x5"

stats FILE_10x10 using 2 name "ijk10x10"
stats FILE_10x10 using 3 name "kij10x10"

stats FILE_20x20 using 2 name "ijk20x20"
stats FILE_20x20 using 3 name "kij20x20"

stats FILE_40x40 using 2 name "ijk40x40"
stats FILE_40x40 using 3 name "kij40x40"

stats FILE_80x80 using 2 name "ijk80x80"
stats FILE_80x80 using 3 name "kij80x80"

stats FILE_160x160 using 2 name "ijk160x160"
stats FILE_160x160 using 3 name "kij160x160"

stats FILE_320x320 using 2 name "ijk320x320"
stats FILE_320x320 using 3 name "kij320x320"

stats FILE_640x640 using 2 name "ijk640x640"
stats FILE_640x640 using 3 name "kij640x640"

#Obtenemos la media y desviacion estandar guardandola en un archivo de texto
#Para el metodo IJK
set print "dataExperimentsIJK.txt"
print "#metodo:rows:mean:stddev"
print "ijk:5:", ijk5x5_mean, ":", ijk5x5_stddev
print "ijk:10:", ijk10x10_mean, ":", ijk10x10_stddev
print "ijk:20:", ijk20x20_mean, ":", ijk20x20_stddev
print "ijk:40:", ijk40x40_mean, ":", ijk40x40_stddev
print "ijk:80:", ijk80x80_mean, ":", ijk80x80_stddev
print "ijk:160:", ijk160x160_mean, ":", ijk160x160_stddev
print "ijk:320:", ijk320x320_mean, ":", ijk320x320_stddev
print "ijk:640:", ijk640x640_mean, ":", ijk640x640_stddev

#Para el metodo KIJ
set print "dataExperimentsKIJ.txt"
print "#metodo:rows:mean:stddev"
print "kij:5:", kij5x5_mean, ":", kij5x5_stddev
print "kij:10:", kij20x20_mean, ":", kij20x20_stddev
print "kij:20:", kij20x20_mean, ":", kij20x20_stddev
print "kij:40:", kij40x40_mean, ":", kij40x40_stddev
print "kij:80:", kij80x80_mean, ":", kij80x80_stddev
print "kij:160:", kij160x160_mean, ":", kij160x160_stddev
print "kij:320:", kij320x320_mean, ":", kij320x320_stddev
print "kij:640:", kij640x640_mean, ":", kij640x640_stddev

#Archivos de datos de los experimentos:
FILE_IJK="dataExperimentsIJK.txt"
FILE_KIJ="dataExperimentsKIJ.txt"
  

#-------------
#	Tiempos de ejecucion, media y desviacion estandar
#------------- 
	 
#------------- 5x9 -------------#       
set title "Execution time Graph (mean and Standard deviation for 50 experiments)"
set ylabel "Time (ns)"
set xlabel "Size of Square Matrix"
set output "Graph_1.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
set ytics format "10^{%L}"
#set yrange [0:1000000000000]
set yrange[0:]
set logscale y 10

plot FILE_IJK using 2:3:4 title "ijk" lt 7 lc 22 lw 1 with yerrorbars,\
        FILE_KIJ using 2:3:4 title "kij" lt 7 lc 15 lw 1 with yerrorbars,\

#Se grafican utilizando los archivos de datos generados por los experimentos.
#plot FILE_5x9 using 0:($2) title "5x9 ijk experiments"  with lines lt 30 lw 1 dt 1,\
        ijk5x9_mean t "5x9 ijk mean" with lines lt 30 lw 2 dt 3,\
        ijk5x9_stddev t "5x9 ijk standard dev" with lines lt 3 lw 2 dt 3,\
        FILE_5x9 using 0:($3) title "5x9 kij experiments"  with lines lt 31 lw 1 dt 1,\
        kij5x9_stddev t "5x9 kij standard dev" with lines lt 20 lw 2 dt 3,\
        kij5x9_mean t "5x9 kij mean" with lines lt 31 lw 2 dt 3

