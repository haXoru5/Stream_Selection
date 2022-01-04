#include <stdio.h>
#include <stdlib.h>

int main(){
    int number = 100;
    int* arr = (int*) malloc(number*sizeof(int));
    printf("%p, size = %d",arr, sizeof(arr));
    for (int i = 0; i < number; i++)
    {
        arr[i] = 2*i;
    }

    for (int i = 0; i < number; i++)
    {
        printf("\ni[%d] = %d", i, arr[i]);
    }
    
    free(arr);
    return 0;
}