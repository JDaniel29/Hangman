#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** loadStates(){
    char gallowDelimiter[10];
    char tempVal[10];
    char currentGallow[66];

    strcpy(gallowDelimiter, "=========");

    FILE* gallowsFile = NULL;
    gallowsFile = fopen("gallows.txt", "r");
    if(gallowsFile == NULL){
        printf("ERROR: Cannot read gallows.txt. Please make sure the file is in the same directory.");
        return NULL;
    }

    char** returnArray = (char**)calloc(7, sizeof(char*) * 66);
    if(returnArray == NULL){
        printf("ERROR: Cannot allocate space for the gallows art. Make sure there is memory avaliable on this device");
    }
    
    for(int i = 0; i < 7; i++){
        strcpy(currentGallow, "");
        while(true){
            fgets(tempVal, 10, gallowsFile);
            strcat(currentGallow, tempVal);
            if(strcmp(tempVal, gallowDelimiter) == 0){
                break;
            }
        }
        returnArray[i] = (char*)calloc(66, sizeof(char*));
        strcpy(returnArray[i], currentGallow);
    }


    return returnArray;
}