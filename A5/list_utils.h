/**
* Header file for list_utils.c file
* Author: Dharsan Ravindran 
* Instructor: Dr. Burton Ma
* Course: CISC 220
* Date: November 24, 2021
*/

#ifndef LIST_UTIL_H
#define LIST_UTIL_H
#include "list.h"

/**
 * @brief Joins two lists into a new list given the pointers
 * for two differnt lists and returns the new list.
 * 
 * @param arr1, a list
 * @param arr2, a list
 * @return list* , new joined list
 */
list *list_join(list *arr1, list *arr2);

/**
 * @brief Removes all specified elements from a specified list
 * 
 * @param arr , list to remove from
 * @param elem , element to remove
 */
void list_remove_all(list *arr, int elem);
#endif