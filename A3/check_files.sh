#!/bin/bash
#
#Dharsan R
#check_files.sh: checks if files specified in a specified 
#file are in the executed directory 

#sets the file to first argument 
specfile=$1

#if no arguments are inputed then error is printed and exit staus of 1
if (( $# != 1 )); then
    echo "Usage: check_files.sh specfile" >&2
    exit 1
fi

#if the specified file does not exist or is not readable then error is printed and exit staus of 2
if ! [[ -f $specfile || -r $specfile ]]; then 
    echo "${specfile} is missing or could not be read" >&2
    exit 2
fi

#variable for counting number of missing files
missing=0

while read line; do
    if ! [[ $line =~ ^'#' ]]; then          #only moves forward if a line is not a comment
        if ! [[ $line =~ ^""$ ]]; then      #only moves forward if a line is not a blank line 
            #if the file does not exist or is not normal than error is 
            #printed and missing file is incremented
            if ! [[ -f $line ]]; then       
                missing=$(( missing + 1 ))
                echo "${line} is missing." >&2
            fi
        fi
    fi
done < "$specfile"

#if there is more than one missing file exit status of 3
if (( $missing >= 1 )); then
    exit 3
fi