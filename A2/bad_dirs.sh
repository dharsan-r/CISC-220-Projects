#!/bin/bash
#
# bad_dirs.sh: List incorrectly named directories

# list directories with spaces
spaces=$(find . -maxdepth 1 -type d -regex '.* .*' -print | sort)
if [[ -n $spaces ]]; then
  echo "Filenames with spaces:"
  echo "$spaces"
fi

# complete the script starting from here`
