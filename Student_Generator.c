//Generates txt file of random number of students
//Column 1 has student number
//Column 2 has GPA
//Column 3 has array of top 10 choices

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592654


struct student{
    int studentnum;
    float gpa;
    int choices[10];
};


int main(){
    int studentcount;
    time_t t;   //initializes rand
    srand((unsigned)time(&t));

    studentcount = 500 + rand() % 101;      //generates random student count between 500 and 600

    float normal[studentcount];     //normal technically isnt supposed to work, change into malloc/pointers
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

    struct student students[studentcount];      //inputs the student data into the structs
    for(int k = 0; k < studentcount; k++){
        students[k].studentnum = 400277000 + k;         //student number doesn't really matter so it is just incremental
        students[k].gpa = normal[k];
        for(int j = 0; j < 10; j++){        //appends top 10 choices (randomly uniformly generated) into array
            students[k].choices[j] = rand() % 31;       //does NOT check for uniqueness
        }
    }

    FILE *stulist = fopen("students.txt", "w+");
    fprintf(stulist,"Student #\tGPA\tChoice Ranking\n");
    for(int i = 0; i < studentcount; i++){
        fprintf(stulist,"%d\t%0.1f\t[",students[i].studentnum, students[i].gpa);
        for(int j = 0; j < 10; j++){
            fprintf(stulist, "%d",students[i].choices[j]);
            if(j != 9){
                fprintf(stulist,", ");
            }
        }
        fprintf(stulist,"]\n");
    }
    fclose(stulist);

    return 0;
}

/* Engineering Streams:
0 = Chemical
1 = Chemical and Bioengineering
2 = Civil
3 = Computer
4 = Electrical
5 = Engineering Physics
6 = Materials
7 = Mechanical
8 = Mechatronics
9 = Software
+10 for Management
+20 for Society
*/
