#!/bin/bash

fall=false

while IFS= read -r -d '' file; do
    if [[ $file =~ \.git ]]; then
        continue
    fi

    if [[ "${file##*.}" == "pdf" ]] || [[ "${file##*.}" == "jpg" ]]; then
        continue
    fi

    if [[ $(tail -c 1 "$file" | wc -l) != $'1' ]]; then
        echo "'$file' does not end with a newline."
        fall=true
    fi
done < <(find . -type f -print0)

if $fall; then
    exit 1
fi
