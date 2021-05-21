#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <semaphore.h>
#include "ArrayGenerator.h"

int n = 1000000;
int t = 10;
int array1[];
int seg_size;
sem_t wait;


int Seq_Search(int array[], int n, int target, int start)
    {
     int i = start;
     int R = start + seg_size;
     while(i <= R)
     {
        if (array[i] == target)
        {
            sem_wait(&wait);
            printf("%d", target);
            printf(" Was found at location ");
            printf("%d", i);
            sem_post(&wait);

            //tried to use semaphore to fix the output format
            //But the program still works.
            break;

        }
        else{i++;}
     }
     printf("%d", target);
     puts(" Was not found in the array");
    }


int main()
{
    int array1 = arrayGenerator(n);
    seg_size = (n/t);
    sem_init(&wait, 0, 1);
    #pragma omp parallel num_threads(t)

        //for(int i = 0; i < n; i++)
        {
         int T_id = omp_get_thread_num();
        Seq_Search(array1, n , 10000, ((n/t)* T_id));
        }


    return 0;
}

main();
