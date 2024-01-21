#!/bin/bash

res=true
find . -type f | while read -r file; do
    if [[ $(tail -c 1 "$file" | wc -l) != $'1' ]]; then
        echo "'$file' does not end with a newline."
        res=false
    fi
    
    if [[ res == false ]]; then
        exit 1
    fi
done
