//Selection process:
//If below 4.0 GPA, student fails
//Students are sorted by GPA, highest to lowest (for society and management, students are counted in stream AND s/m)
//Keeps going down the list until cap for stream is hit
//Once cap is hit, if there are other students with the same GPA and choice below them, then ALL students with the same GPA are cut

#include <stdio.h>
#include <stdlib.h>

struct student{
    int studentnum;
    float gpa;
    int choices[10];
};

int main(){
    FILE *stulist = fopen("students.csv", "r");
}