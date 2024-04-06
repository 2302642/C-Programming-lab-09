/*!
@file       the name of source file is q.h
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

typedef int WordCount;                                                                      // defining and setting the data type WordCount as datatype of int
typedef unsigned char WordLength;                                                           // defining and setting the data type WordLength as datatype of unsigned char
typedef int ErrorCode;                                                                      // defining and setting the data type ErrorCode as datatype of int

struct DictionaryInfo{                                                                      // defining the structure called DictionaryInfo containing the objects shortest, longest and count
    WordLength shortest;                                                                    // unsigned char shortest       store unsigned char data
    WordLength longest;                                                                     // unsigned char longest        store unsigned char data
    WordCount count;                                                                        // int count                    store int data
};
typedef struct DictionaryInfo DictionaryInfo;                                               // defining and setting the data type of DictionaryInfo as datatype of struct

enum ErrorCode{                                                                             // defining the enum called ErrorCode containing varibles that contain  certain values to take note and check if the functions a working as expected
    FILE_OK = -1,
    FILE_ERR_OPEN = -2,
    WORD_OK = -3,
    WORD_BAD = -4
};
enum{                                                                                       // defining the enum to define and set a variable to LONGEST_WORD to 50
    LONGEST_WORD = 50
};

char* str_to_upper(char* string);                                                           // recieve a string and change all characters to upper case
WordCount words_starting_with(const char* dictionary, char letter);                         // count the number of strings that start with a certain characters either of it being upper case or lower case  
ErrorCode spell_check(const char* dictionary, const char* word);                            // check if the string recieve is spelled correctly
ErrorCode word_lengths(const char* dictionary, WordCount lengths[],WordLength count);       // find the size of each string and store into the structure array called lengths[]
ErrorCode info(const char* dictionary, DictionaryInfo* info);                               // find the total number of words in the file and identiy the string lengt of the largest and smallest words


