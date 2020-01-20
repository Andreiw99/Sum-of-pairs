#include <stdio.h>
#include <stdlib.h>
#include "functiip2.h"
#include <time.h>

int main()
{
    FILE *file=fopen("numere_random_p2.txt", "r");
    FILE *out_file=fopen("dataout.txt", "w");
    int vector[519000],counter=0,iterator,maxim=-1,number;
    clock_t start,finish;
    double duration;
    start=clock();
    generare();
    while(fscanf (file, "%d", &number)==1)
    {
        vector[counter]=number;                                      // Cat timp exista numere in fisier, se adauga intr-un vector
        counter++;
    }
    quick_sort(vector,0,counter-1);                                 // Se ordoneaza crescator vectorul
    for(iterator=0;iterator<counter/2;iterator++)
    {
        fprintf(out_file,"(%d, %d) ", vector[iterator],vector[counter-1-iterator]);
        if(maxim<vector[iterator]+vector[counter-1-iterator])                           // Se obtine suma si partitile dorite
            maxim=vector[iterator]+vector[counter-1-iterator];
    }
    fprintf(out_file,"\nSuma: %d ", maxim);
    finish=clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;           // Se calculeaza timpul de executie
    fprintf(out_file, "duration: %.3fs \n", duration);
    fclose(file);
    fclose(out_file);
    return 0;
}
