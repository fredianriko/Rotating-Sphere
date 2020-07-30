#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE* pipe = popen("C:/gnuplot/bin/gnuplot.exe", "w");
    if(pipe != NULL ){
        fprintf(pipe, "set multiplot layout 2,2 title 'Multiplot by Fredi Anriko' font ',14'\n");
        fprintf(pipe, "set xlabel 'x'\n");
        fprintf(pipe, "set ylabel 'y'\n");
        fprintf(pipe, "set xrange[-6:6]\n");
        fprintf(pipe, "set yrange[-1:1]\n");
        fprintf(pipe, "set tmargin 4\n");
        fprintf(pipe, "set title 'Sin(x)'\n");
        fprintf(pipe, "plot sin(x)\n");
        fprintf(pipe, "set title 'Sin(2*x)'\n");
        fprintf(pipe, "plot sin(2*x)\n");
        fprintf(pipe, "set title 'Cos(x)'\n");
        fprintf(pipe, "plot cos(x)\n");
        fprintf(pipe, "set title 'Cos(2*x)'\n");
        fprintf(pipe, "plot cos(2*x)\n");

        fprintf(pipe, "set output \"Fredi Anriko.png\"\n" );
        fprintf(pipe, "unset multiplot \n");
        fprintf(pipe, "set term win\n");
        fflush(pipe);
        getchar();
    }else{
        puts("Couldn't open the file\n");
        pclose(pipe);
        return 0;
    }
}
