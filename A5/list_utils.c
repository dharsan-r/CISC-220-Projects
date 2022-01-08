/**
* File for join and remove list functions
* Author: Dharsan Ravindran 
* Instructor: Dr. Burton Ma
* Course: CISC 220
* Date: November 24, 2021
*/
#include<stdio.h>
#include<stdlib.h>
#include "list_utils.h" // inlcudes the header file
#include "list.c" // includes all the functions for a list

/**
 * @brief Joins two lists into a new list given the pointers
 * for two differnt lists and returns the new list.
 * 
 * @param arr1, a list
 * @param arr2, a list
 * @return list* , new joined list
 */
list *list_join(list *arr1, list *arr2){
    list *n = list_init_empty(); // creates the new list

    //null if new list could not be allocated
    if(n==NULL){
        return NULL;
    }
    //empty list if both lists are null
    if(arr1==NULL && arr2==NULL){
        return n;
    }
    //if ony list1 is null outputs list 2
    else if(arr1==NULL){
        for(int y = 0; y<list_size(arr2); y++){
            list_add(n, list_get(arr2, y));
        }
    }
     //if ony list 2 is null outputs list 1
    else if(arr2==NULL){
        for(int z = 0; z<list_size(arr1); z++){
            list_add(n, list_get(arr1, z));
        }
    }
    //joins both lists into new list
    else{
        for(int x = 0; x<list_size(arr1); x++){
            list_add(n, list_get(arr1, x));
        }
        for(int y = 0; y<list_size(arr2); y++){
            list_add(n, list_get(arr2, y));
        }
    }
    //returns new list
    return n;
}

/**
 * @brief Removes all specified elementrs from a specified list with worst case O(n) complexity 
 * 
 * @param arr , list to remove from
 * @param elem , element to remove
 */
void list_remove_all(list* arr, int elem){
    //assigns size of list
    int len=list_size(arr);
    //creates a duplicate list
    list *dup = list_init(list_size(arr));
    //only uses one iteration so O(n) complexity to crete a removed list
    for(int x = 0; x<len;x++){
        if(list_get(arr,x)!=elem){
            list_add(dup,list_get(arr,x));
        }
    }
    //assigns editited list to old list and shortens old list for removal
    arr->arr=dup->arr;
    arr->size=list_size(dup);
}