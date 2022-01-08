#!/bin/bash
#
#Dharsan R
#scramble.sh: scrambles and returns a specified string

#puts each character of the string into a differnt index in an array in order
function to_array {
    for (( x=0; x<${length}; x++ ));do
    arr[x]="${scrambled:x:1}"
    done
}

#converts an array of charcters and concates all the characters to a string
function to_string {
    #sets new string variable
    new_word=""
    for (( x=0; x<${length}; x++ ));do
        new_word="${new_word}${arr[x]}"
    done
    #returns the string that was extracted from the array
    echo ${new_word}
}

#returns a random integer between two arguments a(inclusive) and b(exclusive)
function rand {
    a=$1
    b=$2
    echo $(( ($a + $RANDOM) % $b ))
}

#shuufles the array based on the Fisher-Yates algorithm
function shuffle {
    for (( i=0; i<(( $length -1 )); i++ ));do
        c=${arr[i]}
        j=$(rand i $length) #calls the random function to get a random integer for the index of j
        #swaps arr[i] and arr[j]
        arr[i]=${arr[j]}
        arr[j]=$c
    done
}

#if there is no argument exit status is set to 0
if (( $# == 0 ));then 
    exit 0
fi

scrambled=$1            #sets teh string to be scrambled in scrambled
length=${#scrambled}    #sets the length of the string in a new variable
declare -a arr          #declares a new array arr
to_array                #executes the to_array function
shuffle                 #executes the shuffle function
to_string               #executes the to_string function

