#ifndef ARRAYGENERATOR_H_INCLUDED
#define ARRAYGENERATOR_H_INCLUDED
int* arrayGenerator(int n){
    srand(time(0));
    int init = rand()%10000;
    int*array = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        array[i] = init+i;
    }

    return array;

}


#endif // ARRAYGENERATOR_H_INCLUDED
