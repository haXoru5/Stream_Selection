#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    int sorted[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 9; i > 0; i--)
    {
        int rnum = rand() % i;
        int rval = sorted[rnum];
        sorted[rnum] = sorted[i];
        sorted[i] = rval;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d, ",sorted[i]);
    }
        
}