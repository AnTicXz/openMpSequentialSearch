#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "ArrayGenerator.h"

int Seq_Search(int array[], int n, int target)
    {
     int i = 0;
     int R = n - 1;
     while(i <= R)
     {
        if (array[i] == target)
        {
            printf("%d", target);
            printf(" Was found at location ");
            printf("%d", i);
            puts("");
        }
        else{i++;}
     }
     printf("%d", target);
     puts(" Was not found in the array");
    }


int main()
{
    int n = 1000;
    int array1 = arrayGenerator(n);

    Seq_Search(array1, n , 25);

    return 0;
}

main();
