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
#	Tiempos de ejecucion
#------------- 
	 
set title "Execution time Graph"
set ylabel "Time (s)"
set xlabel "Num de Experimento"
set output "01-texec.png"	


#Se coloca la leyenda del gráfico.
set key inside bottom left box lt -1
#Estilo del grafico.
set style fill pattern 0 border -1
set grid 

#Se coloca escala logaritmica base 2, rango y formato para el eje Y.
set yrange [0:]
set logscale y 20

plot FILE_5x9 using 0:($2) title "5x9 ijk"  with lines lt -1 lw 2 pointtype 11 pointsize 1.3 dt 1,\
        FILE_5x9 using 0:($3) title "5x9 kij"  with lines lt 30 lw 2 pointtype 13 pointsize 1.3 dt 1


#Obtener media y distribucion estandar (mean & std_dev)
#Se obtuvo a traves de la consola de GNUPLOT con las siguientes instrucciones

#5x9
#stats FILE_5x9 using 2 name "5x9ijk"
#stats FILE_5x9 using 3 name "5x9kij"
#print 5x9ijk_mean
#print 
#print 5x9kij_mean


#print 5x9ijk_mean
#print 5x9kij_mean

#Se grafican utilizando los 3 archivos de datos, descartando los datos de 1 Thread ya que su SpeedUp es 1.
#Se sigue la formula: SpeedUp = (t_ejec_1th) / (t_ejec_Tth), 
#                               donde T es el número de Threads
#Se utilizan el 3er y 4to rubro de los datos: S = $3 / $4
#plot FILE_5x9 using $1 title "ijk"  with linespoints lt -1 pointtype 11 pointsize 1.3 dt 1,\
        FILE_5x9 using $2 title "kij"  with linespoints lt -1 pointtype 13 pointsize 1.3 dt 1    