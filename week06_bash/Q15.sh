#! /bin/bash

file_wordcnt(){
    echo "$FILE 파일의 단어는 $(wc -w < $FILE) 개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt $FILE