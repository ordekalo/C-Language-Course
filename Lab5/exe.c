//
// Created by ordekalo on 09/04/2020.
//

#include <stdio.h>
#include <string.h>
#include "functions.h"


void Q1() {
    char str1[MAX];
    printf("please enter a string:\n");
    scanf("%s", str1);
    printf("%s\n", str1);

    printf("please enter another string:\n");
    char str2[MAX];
    if (fgets(str2, MAX, stdin) != NULL) {
        //putting 0 in the end of string instead of "\n"
        str2[strlen(str2) - 1] = 0;
        puts(str2);
    }

    printf("the longer string is: ");
    if (strlen(str1) > strlen(str2)) {
        puts(str1);
    } else {
        puts(str2);
    }

    int val = strcmp(str1, str2);
    if (val < 0) {
        printf("alphabetic smaller is: ");
        puts(str1);
    } else if (val == 0) {
        printf("both strings are equal alphabetically\n");
    } else {
        printf("alphabetic smaller is: ");
        puts(str2);
    }
}

void Q2() {
    printf("please enter a sentence:\n");
    char str[MAX];
    if (fgets(str, MAX, stdin) != NULL) {
        //putting 0 in the end of string instead of "\n"
        str[strlen(str) - 1] = 0;
        puts(str);
    }
    char word[MAX];
    int mostCapitalize = mostCapitalCountWord(str, word);
    printf("the most capitalized word is %s , it has %d capitals\n", word, mostCapitalize);
}

void Q3() {
    printf("please enter a sentence:\n");
    char str[MAX];
    if (fgets(str, MAX, stdin) != NULL) {
        //putting 0 in the end of string instead of "\n"
        str[strlen(str) - 1] = 0;
        puts(str);
    }
    removeRedundantSpaces(str);
    puts(str);
}

void Q4() {
}
