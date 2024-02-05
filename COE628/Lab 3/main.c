
/* 
 * File:   main.c
 * Author: tghori
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h> 

int main(int argc, char** argv) {
    char* input;

    do {
        char* args[100];
        input = (char*)malloc(100 * sizeof(char)); 
        printf("Your command>");
        int Index = 0, argsindex = 0, ch, flag;

      
        while ((ch = getchar()) != '\n') {  //input characters into char array
            if (Index == 0) {
                args[argsindex] = input + Index; 
                *(input + Index) = ch; 
                Index++;
                argsindex++;
            } else if (isspace(ch)) {
                
                *(input + Index) = '\0';
                Index++;
                
                if (ch != '\n') {
                    args[argsindex] = input + Index;
                    argsindex++;
                }
            } else {
                *(input + Index) = ch;
                Index++;
            }
        }

        *(input + Index) = '\0';    //final character Null terminator
        args[argsindex] = NULL; 

        if (Index == 0) {
            free(input);
            continue;
        }

        if (*(input + Index - 1) == '&') {
            *(input + Index - 1) = '\0';
            flag = 1;
            
        } else flag = 0;       

        if (strncmp(input, "exit", 4) == 0) { //exit command
            free(input);
            return EXIT_SUCCESS;
        }
        pid_t pid = fork(); //attempts child process creation
        if (pid < 0) { //Child Process Creation Error
            
            fprintf(stderr, "Error");
            free(input);
            return EXIT_FAILURE;
            
        }

        if (pid > 0) { //Returned to parent and pid = child process id
            
            if (!flag) wait(NULL); 
        
        } else { // pid == 0, child process created
            int val = execvp(args[0], args); 
            if (val == -1) {
                perror("Error");
            }
            free(input); 
            exit(val); 
        }
        free(input); 

    } while (1); 

    return EXIT_SUCCESS;
}
