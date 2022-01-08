#include <stdio.h>

//Dharsan R 20219218

void main(int argc, char *argv[]) {
    //increments through all the arguments
    for (int i = 1; i < argc; i++) {
        // if last element is reached no space is put to ensure no trailing spaces
        if (i==(argc-1)){
            printf("%s",argv[i]);
        }else{
            printf("%s ",argv[i]); //adds spaces between arguments otherwise
        }
    }
    printf("\n");// adds new line after the output regardless
}