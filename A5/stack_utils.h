/**
* Header file for stack_utils.c file
* Author: Dharsan Ravindran 
* Instructor: Dr. Burton Ma
* Course: CISC 220
* Date: November 24, 2021
*/
#ifndef STACK_UTIL_H
#define STACK_UTIL_H
#include "stack.h"
#include <stdbool.h>

/**
 * @brief reverses a stack given the pointer for said stack
 * 
 * @param sta, stack to reverse
 */
void stack_reverse(stack *sta);

/**
 * @brief Pointer to function that compares two elements and returns true if equal
 * 
 */
typedef bool (*compare_elem)(const void *s, const void *t);

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
bool stack_equals(const stack *sta1, const stack *sta2, compare_elem ele);


#endif