#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// adds all libraries

//Dharsan R 20219218

void main(int argc, char *argv[]) {
    // creates a charcter array for normal alphabet 
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    // error if incorect number of arguments
    if(argc!=3){
        fprintf( stderr, "Usage: encrypt shift str\n" );
        exit(1);
    }
    char *msg = argv[2];
    int msg_len = strlen(msg);
    char enc[msg_len + 1];
    enc[msg_len] = '\0';
    int rota = atoi(argv[1]); // creates an integer for value of rotation
    //adjusts the shift number for a full cycle fo the alphabet
    if(rota>=26 || rota <=-26){
        rota=rota%26;
    }
    // if rotation/shift number is negative it is adjusted to be positiv 
    if(rota<0){
        rota=sizeof(alpha)+rota;
    }
    //cycles through the message and conducts the shift
    for(int i=0; i<msg_len; i++){
        char letter = toupper(argv[2][i]);//changes each charcter to an upper case charachter
        enc[i]=letter;//puts the un-encrypted character inthe encrpted string
        for (int x=0; x<sizeof(alpha); x++){
            // if the un-encrypted character is a letter then the appropriate shift occurs
            if(letter==alpha[x]){
                enc[i]=alpha[(x+rota)%26];
            }
        }
    }
    printf("%s\n",enc); //outputs the encrypted string ending with a new line charachter
}