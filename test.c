#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592654

int main(){
    int studentcount = 500;
    float normal[studentcount];
    for(int i = 0; i < studentcount; i++){      //generates normal distribution of grades centered at 7 with a standard deviation of 2 using Box-Muller transform
        float z;
        do{
            z = 7 + 2*(sqrt(-2*log((double)rand()/(double)RAND_MAX))*cos(2*PI*((double)rand()/(double)RAND_MAX)));
            if(z > 12){
                z = 12;
            }
        } while(z < 0 || z > 12);
        z = trunc(z*10)/10;
        normal[i] = z;
    }
}