#! /bin/bash

file_wordcnt(){
    files=$(ls *.txt)
    for file in $files; do
        echo "$file 파일의 단어는 $(wc -w < $file) 개 입니다."
    done
}

file_wordcnt