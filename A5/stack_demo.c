/**
* File for demo of stack reverse and equal list functions
* Author: Dharsan Ravindran 
* Instructor: Dr. Burton Ma
* Course: CISC 220
* Date: November 24, 2021
*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "stack_utils.c"

// returns a string true or faslse based on the boolean value
char *bool_string(bool ans){
    if(ans){
        return "True";
    }
    return "False";
}

/**
 * @brief function to test for the reversal of a stack
 * 
 */
void stack_reverse_test(){
    //reverses an empty stack, and prints the resulting stack
    stack *a = stack_init();
    printf("a: is_empty = %s\n", bool_string(stack_is_empty(a)));
    stack_reverse(a);
    printf("a reversed: ");
    stack_print(a,&print_double);

    //reverses a stack of size 1, and prints the resulting stack
    stack *b=stack_init();
    int j = 2;
    stack_push(b, &j);
    printf("b: ");
    stack_print(b,&print_int);
    stack_reverse(b);
    printf("b reversed: ");
    stack_print(b,&print_int);

    //reverses a stack of size 3, and print sthe resulting stack
    stack *c=stack_init();
    int k = 1;
    int l = 2;
    int m = 3;
    stack_push(c, &k);
    stack_push(c, &l);
    stack_push(c, &m);
    printf("c: ");
    stack_print(c,&print_int);
    stack_reverse(c);
    printf("c reversed: ");
    stack_print(c,&print_int);
    free(a);
    free(b);
    free(c);
}

/**
 * @brief function to test for the equality of two stacks
 * 
 */
void stack_equal_test(){
    // compares two empty stacks, and prints the result
    stack *c = stack_init();
    stack *d = stack_init();
    printf("c: is_empty = %s\n", bool_string(stack_is_empty(c)));
    printf("d: is_empty = %s\n", bool_string(stack_is_empty(d)));
    printf("c=d: %s\n", bool_string(stack_equals(c,d,&compare_double)));

    // compares two equal stacks of size 1, and prints the result
    double e1 = 7;
    double e2 = 7;
    stack_push(c, &e1);
    stack_push(d, &e2);
    printf("c: ");
    stack_print(c,&print_double);
    printf("d: ");
    stack_print(d,&print_double);
    printf("c=d: %s\n", bool_string(stack_equals(c,d,&compare_double)));
    // alters the sceond stack 
    stack_pop(d);
    double e3 =6;
    stack_push(d, &e3);
    printf("c: ");
    stack_print(c,&print_double);
    printf("d: ");
    stack_print(d,&print_double);
    //compares two unequal stacks of size 1, and print the result
    printf("c=d: %s\n", bool_string(stack_equals(c,d,&compare_double)));
    stack_pop(d); // alters the seocnd stack
    // ensures that both stacks equal
    double e4=6;
    double e5=5.22;
    double e6=5.22;
    stack_push(d, &e2);
    stack_push(d, &e3);
    stack_push(c, &e4);
    stack_push(d, &e5);
    stack_push(c, &e6);
    printf("c: ");
    stack_print(c,&print_double);
    printf("d: ");
    stack_print(d,&print_double);
    // compares two equal stacks of size 3, and prints the result
    printf("c=d: %s\n", bool_string(stack_equals(c,d,&compare_double)));
    double e7 = 3;
    stack_pop(d); // alters the second stcak to make sure they aren't equal
    stack_push(d,&e7);
    printf("c: ");
    stack_print(c,&print_double);
    printf("d: ");
    stack_print(d,&print_double);
    // compares two unequal stacks of size 3, and prints the result
    printf("c=d: %s\n", bool_string(stack_equals(c,d,&compare_double)));
    free(c);
    free(d);
}

int main(void){
    printf("\nStack Reverse Test:\n");
    // conducts all reversal stack tests
    stack_reverse_test();
    printf("\nStack Equals Test:\n");
    // conducts all equal stack tests
    stack_equal_test();
}