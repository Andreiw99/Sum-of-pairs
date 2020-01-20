#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int vector[], int begin,int end)
{
    int pivot,iterator1,iterator2,auxiliar;
    pivot=vector[begin];
    iterator1=begin-1;
    iterator2=end+1;
    while(1)
    {
        do
        {
        iterator2--;
        }
        while(vector[iterator2]>pivot);
        do
        {
        iterator1++;
        }
        while(vector[iterator1]<pivot);
        if(iterator1<iterator2)
        {
            auxiliar=vector[iterator1];
            vector[iterator1]=vector[iterator2];
            vector[iterator2]=auxiliar;
        }
        else
            return iterator2;
    }
}

void quick_sort(int vector[],int begin,int end)
{
    int pivot;
    if(begin<end)
    {
        pivot=partition(vector,begin,end);
        quick_sort(vector,begin,pivot);
        quick_sort(vector,pivot+1,end);
    }
}

void generare()
{
 FILE *file=fopen("numere_random_p2.txt", "w");
    int iterator,random_number;
    srand(time(0));
    for(iterator=0;iterator<100000;iterator++)
    {
        random_number= rand() %100000;
        fprintf(file,"%d ", random_number);
    }
    fprintf(file, "\n");
    fclose(file);
}
