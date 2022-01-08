/**
* File for reverse and equal list functions
* Author: Dharsan Ravindran 
* Instructor: Dr. Burton Ma
* Course: CISC 220
* Date: November 24, 2021
*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "stack_utils.h"
#include "stack.c"

//compares if two doubles are equal
bool compare_double(const void *s, const void *t){
    double j = *(double *)(s);
    double k = *(double *)(t);
    return j==k;
}

//compares if two ints are equal
bool compare_int(const void *s, const void *t){
    int j = *(int *)(s);
    int k = *(int *)(t);
    return j==k;
}

//compares if two chars are equal
bool compare_char(const void *s, const void *t){
    char j = *(char *)(s);
    char k = *(char *)(t);
    return j==k;
}

// prints a character 
void print_char(const void *s){
    char k = *(char *)(s);
    printf("%c",k);
}

// prints a double
void print_double(const void *s) {
    double k = *(double *)(s);
    printf("%lf", k);
}

// prints an integer
void print_int(const void *s) {
    int k = *(int *)(s);
    printf("%d", k);
}

/**
 * @brief reverses a stack given the pointer for said stack
 * 
 * @param sta, stack to reverse
 */
void stack_reverse(stack *sta){
    node *m = NULL;
    node *n  = sta->top;
    node *next = NULL;
    while (n != NULL) {
        next = n->next;
        n->next = m;
        m = n;
        n = next;
    }
    sta->top = m;
}

/**
 * @brief Checks if two stacks are qual base don teh aprameters "Two stacks are equal if they contain identical sequences of equal elements, 
 * and two empty stacks are considered to be equal"
 * 
 * @param sta1 : Stack 1 to compare
 * @param sta2 : Stack 2 to compare
 * @param ele : the function to compare an element in the stack
 * @return true : returns if two stack are equal
 * @return false : returns if two stack are not equal
 */
bool stack_equals(const stack *sta1, const stack *sta2, compare_elem comp){
    size_t len=stack_size(sta1);
    //checks if both stacks ar equal length
    if(len==stack_size(sta2)){
        node *n1=sta1->top;
        node *n2=sta2->top;
        // iterates over all nodes in each stack in order ensuring their order matches
        while(n1 && n2){
            // compares the two elements in each node and checks if the match returns false if not
            if(!comp(n1->elem,n2->elem)){
                return false;
            }
            n1=n1->next;
            n2=n2->next;
        }
    }
    //if both stacks of unequal length returns false
    else if (len!=stack_size(sta2)){
        return false;
    }
    return true;
}  
