/**
* File for demo of join and remove list functions
* Author: Dharsan Ravindran 
* Instructor: Dr. Burton Ma
* Course: CISC 220
* Date: November 24, 2021
*/
#include<stdio.h>
#include<stdlib.h>
#include "list_utils.c"

//assigns a random list of size n
void list_non_e(list *z, int n){
    for(int x=0; x<(n+1);x++){
        list_add(z, rand()%100);
    }
}

//assigns a list of the same 5 specified elements 
void *list_same_five(list *e,int n){
    for(int x= 0; x<6;x++){
        list_add(e,n);
    }
} 

/**
 * @brief fucntion for testing the join function
 * 
 */
void list_join_test(){
    list *a = list_init_empty();
    list_non_e(a,7);
    list *b = list_init_empty();
    list_same_five(b,7);
    printf("a = %s\n", list_to_string(a));
    printf("b = %s\n", list_to_string(b));
    list *c = NULL;
    list *d = NULL;
    printf("c = NULL\n");
    printf("d = NULL\n");
    //joins two non-empty lists, and prints the resulting list
    printf("a + b = %s\n", list_to_string(list_join(a,b)));
    //joins NULL and a non-empty list, and print the resulting list
    printf("c + a = %s\n", list_to_string(list_join(c,a)));
    //joins a non-empty list and NULL, and prints the resulting list
    printf("b + d = %s\n", list_to_string(list_join(b,d)));
    //joins NULL and NULL, and prints the resulting list
    printf("c + d = %s\n", list_to_string(list_join(c,d)));
}

/**
 * @brief function for testing the removal function
 * 
 */
void list_remove_test(){
    list *f = list_init_empty();
    list_same_five(f,5);
    int x[]={1,2,3,3,4,7};
    list *j=list_init_arr(6,x);
    printf("j =");
    list_print(j);
    //removes an element that occurs zero times in a list of size five or greater, and print the list
    list_remove_all(j,6);
    printf("j after 6 remove: %s\n",  list_to_string(j));
    list *k=list_init_arr(6,x);
    printf("k =");
    list_print(k);
    //removes an element that occurs one time in a list of size five or greater, and print the list
    list_remove_all(k,4);
    printf("k after 4 remove: %s\n",  list_to_string(k));
    list *l=list_init_arr(6,x);
    printf("l =");
    list_print(l);
    //removes an element that occurs two times in a list of size five or greater, and print the list
    list_remove_all(l,3);
    printf("l after 3 remove: %s\n",  list_to_string(l));
    printf("f = %s\n", list_to_string(f));
    //remove an element that occurs five times in a list of size five, and print the list
    list_remove_all(f,5);
    printf("f after 5 remove: %s\n",  list_to_string(f));
    
}

int main(void){
    printf("\nJoin Test:\n");
    //executes the join test
    list_join_test();
    printf("\nRemoval Test:\n");
    //conducts all removal tests
    list_remove_test();
}