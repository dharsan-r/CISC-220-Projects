
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// adds all libraries

//Dharsan R 20219218

// normpdf function calcualtes the normal probability density function using a variable
void normpdf(double x, double *pdf){
    *pdf = (1.0/sqrt(2*M_PI))*exp(-((x*x)/2));
}

// adds two double values and returns output
void add(double x, double y, double *result){
    *result=x+y;
}

void main(int argc, char *argv[]) {
    double p; // double value for result storage
    // error if incorect number of arguments
    if(argc!=2 && argc!=3){
        fprintf( stderr, "Usage: math_demo num1 [num2]\n" );
        exit(1);
    }else if(argc==2){ // if only one command line is given normal proabability density fucntion is executed
    normpdf(atof(argv[1]), &p);
    printf("phi(x) = %.8f\n", p); //formats and prints pdf function 
    }else{// if only two command line args are given both doubles are added
    add(atof(argv[1]),atof(argv[2]),&p);
    printf("%6.2f + %6.2f = %6.2f\n",atof(argv[1]), atof(argv[2]), p); //formats and prints sum and result accordingly
    }
}


