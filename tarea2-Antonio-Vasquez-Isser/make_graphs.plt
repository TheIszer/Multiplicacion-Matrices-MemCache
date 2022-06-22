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
FILE_1280x1280="experimentos/exp1280x1280.txt"

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
stats FILE_1280x1280 using 2 name "ijk1280x1280"
stats FILE_1280x1280 using 3 name "kij1280x1280"

#Obtenemos la media y desviacion estandar guardandola en un archivo de texto
set print "dataExperiments.txt"
print "#rows:metodo:mean:stddev:metodo:mean:stddev"
print "5:ijk:", ijk5x5_mean, ":", ijk5x5_stddev, ":kij:", kij5x5_mean, ":", kij5x5_stddev
print "10:ijk:", ijk10x10_mean, ":", ijk10x10_stddev, ":kij:", kij10x10_mean, ":", kij10x10_stddev
print "20:ijk:", ijk20x20_mean, ":", ijk20x20_stddev, ":kij:", kij20x20_mean, ":", kij20x20_stddev
print "40:ijk:", ijk40x40_mean, ":", ijk40x40_stddev, ":kij:", kij40x40_mean, ":", kij40x40_stddev
print "80:ijk:", ijk80x80_mean, ":", ijk80x80_stddev, ":kij:", kij80x80_mean, ":", kij80x80_stddev
print "160:ijk:", ijk160x160_mean, ":", ijk160x160_stddev, ":kij:", kij160x160_mean, ":", kij160x160_stddev
print "320:ijk:", ijk320x320_mean, ":", ijk320x320_stddev, ":kij:", kij320x320_mean, ":", kij320x320_stddev
print "640:ijk:", ijk640x640_mean, ":", ijk640x640_stddev, ":kij:", kij640x640_mean, ":", kij640x640_stddev
print "1280:ijk:", ijk1280x1280_mean, ":", ijk1280x1280_stddev, ":kij:", kij1280x1280_mean, ":", kij1280x1280_stddev

#Archivo de datos de los experimentos:
FILE_DATA="dataExperiments.txt"

#-------------
#	GRAFICAS
#------------- 
	 
#------------- Execution time Graph -------------#       
set title "Execution time Graph (mean and Standard deviation for 50 experiments)"
set ylabel "Time (ns)"
set xlabel "Size of Square Matrix"
set output "Graph_ExecutionTime.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y y X.
set ytics format "10^{%L}"
set xtics format "10^{%L}"
#set yrange [0:1000000000000]
set yrange[0:]
set logscale y 10
set logscale x 10

plot FILE_DATA using 1:3:4 title "ijk" lt 7 lc 22 lw 1 with yerrorbars,\
        FILE_DATA using 1:6:7 title "kij" lt 7 lc 15 lw 1 with yerrorbars,\



#------------- SPEED UP -------------#       
set title "SpeedUp Graph (KIJ method)"
set ylabel "SpeedUp(S)"
set xlabel "Size of Square Matrix"
set output "Graph_SpeedUp.png"

#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala normal base 2, rango y formato para el eje Y y X.
set ytics format "%.2f"

#Se grafican utilizando los 2 archivos de datos
#Se sigue la formula: SpeedUp = (t_ejec_seq) / (t_ejec_improved), 
#                               donde: (t_ejec_ijk) / (t_ejec_kij)
#Se utilizan el 3er y 6to rubro de los datos: S = $3 / $6
plot FILE_DATA using 1:(($3)/($6)) title "kij" with linespoints lt 7 lc 22 pointtype 7 pointsize 1.3
