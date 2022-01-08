#!/bin/bash
#
#Dharsan R
#init_compile.sh:creates directotry for java packages

class=$1

#if no arguments are inputted then error is printed and exit status of 1
if (( $# != 1 ));then
    echo "Usage: init_compile.sh fully-qualified-classname" >&2
    exit 1
fi

#replaces all the dots in the package armunet with /for use in direcotries
class="${class//"."/"/"}"
#adds .java to end of package to complete path
class="${class}.java"


#if the file is in a package then the path for the storage of file is set
if [[ $class =~ "/" ]]; then
    direc="${class%/*}"
else
    direc=""
fi

#stores the name of the file in a variable
file="${class##*/}"

#if the specified file does not exist or is not readable then error is printed and exit staus of 2
if ! [[ -f $file ]];then
    echo "${file} missing in current directory" >&2
    exit 2
else
    mkdir -p "src/${direc}"
    cp "$file" "src/${direc}"
fi
