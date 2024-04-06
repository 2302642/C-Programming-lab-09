/*!
@file       the name of source file is q.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Lab 9
@date       file created on 03/11/2023
@brief      provide a brief explanation about what this source file does:
            
            This file is contains 5 function declaraction be to called by main in qdriver.
            Functions:
            - char* str_to_upper(char* string);                                                           // recieve a string and change all characters to upper case
            - WordCount words_starting_with(const char* dictionary, char letter);                         // count the number of strings that start with a certain characters either of it being upper case or lower case  
            - ErrorCode spell_check(const char* dictionary, const char* word);                            // check if the string recieve is spelled correctly
            - ErrorCode word_lengths(const char* dictionary, WordCount lengths[],WordLength count);       // find the size of each string and store into the structure array called lengths[]
            - ErrorCode info(const char* dictionary, DictionaryInfo* info);                               // find the total number of words in the file and identiy the string lengt of the largest and smallest words
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

#include "q.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* str_to_upper(char* string) {                                                          // recieve a string and change all characters to upper case
    /*for (size_t i = 0; i < strlen(string); i++) {
        if (string[i] >= 'a' && string[i] <= 'z') { string[i] = string[i] - 32; }           // Convert lowercase to uppercase
    }*/
    for(size_t i=0;i< strlen(string);i++){
        string[i] = (char)toupper(string[i]);                                               // Convert lowercase to uppercase
    }
    return string;
}

WordCount words_starting_with(const char* dictionary, char letter){                         // count the number of strings that start with a certain characters either of it being upper case or lower case  
    FILE *input_file = fopen(dictionary, "r");                                              // opening file file_name for read
    if (input_file == NULL){ return FILE_ERR_OPEN; }                                        // checking if file exist if print error statement and exit the programe

    int word_count = 0;
    char word[LONGEST_WORD]; 
    char* upper_letter = str_to_upper(&letter);

    while(fgets(word, LONGEST_WORD, input_file) !=NULL){
        str_to_upper(word);
        if (word[0] == *upper_letter){ word_count++; }                                      // comparing the first char of the string taken in with letter to check if string starts with letter
    }
    fclose(input_file);
    return word_count;
}

ErrorCode spell_check(const char* dictionary, const char* word){                            // check if the string recieve is spelled correctly
    FILE *input_file = fopen(dictionary, "r");                                              // opening file file_name for read
    if (input_file == NULL){ return FILE_ERR_OPEN; }                                        // checking if file exist if print error statement and exit the programe

    char dictionary_word [LONGEST_WORD];
    char letter_checker [LONGEST_WORD];

    strcpy(letter_checker, word); str_to_upper(letter_checker);                             // setting the strings to the same form
    while(fscanf(input_file,"%s",dictionary_word)!= EOF){
        str_to_upper(dictionary_word);                                                      // setting the strings to the same form
        if(strcmp(dictionary_word, letter_checker) == 0) {                                  // comparing the strings to check if they are the same
            fclose(input_file);
            return WORD_OK;
        }
    }
    fclose(input_file);
    return WORD_BAD; 
}

ErrorCode word_lengths(const char* dictionary, WordCount lengths[],WordLength count){       // find the size of each string and store into the structure array called lengths[]
    FILE *input_file = fopen(dictionary, "r");                                              // opening file file_name for read
    if (input_file == NULL){ return FILE_ERR_OPEN; }                                        // checking if file exist if print error statement and exit the programe

    int i = 0;
    char letter;

    while ( (letter = (char)fgetc(input_file)) != EOF ) {
        if (letter == '\n') {

            if (i <= count) {                                                               // identifing the size of the string
                lengths[i] += 1;
                i = 0;
            } else i = 0;
        } else i++;
    }

    fclose(input_file);
    return FILE_OK;
}

ErrorCode info(const char* dictionary, DictionaryInfo* info){                               // find the total number of words in the file and identiy the string lengt of the largest and smallest words// find the total number of words in the file and identiy the string lengt of the largest and smallest words
    FILE *input_file = fopen(dictionary, "r");                                              // opening file file_name for read
    if (input_file == NULL){ return FILE_ERR_OPEN; }                                        // checking if file exist if print error statement and exit the programe

    int word_count = 0;
    char word[LONGEST_WORD]; 
    WordLength L_WORD, S_WORD;
    size_t large = 0, small = LONGEST_WORD, word_size = 0;

    while( fgets(word, LONGEST_WORD, input_file) != NULL ){    
        word_size = strlen(word)-1;                                                         // identifying the number of words in the file 
        if(word_size < small){ S_WORD = (unsigned char) word_size; small = word_size;}      // identifying the size of smallest string in the file
        if(word_size > large){ L_WORD = (unsigned char) word_size; large = word_size;}      // identifying the size of largest string in the file
        word_count++;
    }
    //storing into the structure DictionaryInfo
    info -> count = word_count;                                                             
    info -> shortest = S_WORD;
    info -> longest = L_WORD;
    fclose(input_file);
    return FILE_OK;
}



