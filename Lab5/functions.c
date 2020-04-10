//
// Created by ordekalo on 10/04/2020.
//
#include <string.h>
#include <ctype.h>
#include "functions.h"


int mostCapitalCountWord(const char *str, char *theWord) {
    int maxUpper = 0;
    int counter;
    char copy[MAX];
    strcpy(copy, str);
    char *delimiters = " :,-";
    char *words;

    words = strtok(copy, delimiters);
    while (words != NULL) {
        counter = 0;
        for (int i = 0; i < strlen(words); i++) {
            if (isupper(words[i])) {
                counter++;
            }
        }
        if (counter > maxUpper) {
            maxUpper = counter;
            strcpy(theWord, words);
        }
        words = strtok(NULL, delimiters);
    }
    return maxUpper;
}

void removeRedundantSpaces(char *string) {
    int counter = 0;
    int whiteCounter = 0;
    for (int i = 0; string[i]; i++) {
        if (!isspace(string[i])) {
            string[counter++] = string[i];
            whiteCounter = 0;
        } else {
            whiteCounter++;
            if (whiteCounter == 1) {
                string[counter++] = string[i];
            }
        }
    }
    string[counter] = 0;
}

