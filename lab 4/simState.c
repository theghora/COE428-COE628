
#include <stdlib.h>
#include <stdio.h>

typedef struct linkedlist {  //makes a linked list
    char State;               //a variable repersenting state
    struct linkedlist * zero; // Points to a linkedlist when state is 0
    struct linkedlist * one; // Points to a linkedlist when state is 1
    struct linkedlist * curr; // Current linkedlist
}linkedlist;   //linkedlist variable name

int main(int argc, char * argv[]) 
{
printf("Starting State: E\n");
printf("Commands:\nf = Terminate Program\nc = change the state machine\np = print everything\ng = check if all states are present\nd = delete state\n");
char input[3];
int unreach[8] = {0,0,0,0,0,0,0,0};
int reach[8] = {0,0,0,0,0,0,0,0}; //if any index is greater than 0 then the linkedlist assosicated with that index is reachable and is not part of garbage
int garbage = 0;
int chngeNum = 0; 
int count;
int delete[8] = {0,0,0,0,0,0,0,0};

struct linkedlist * head = (struct linkedlist *)malloc(sizeof(struct linkedlist)); //linked list of top node
struct linkedlist * A = (struct linkedlist *)malloc(sizeof(struct linkedlist));  //linked list for A state
struct linkedlist * B = (struct linkedlist *)malloc(sizeof(struct linkedlist));  //linked list of B state
struct linkedlist * C = (struct linkedlist *)malloc(sizeof(struct linkedlist));  //linked list of C state
struct linkedlist * D = (struct linkedlist *)malloc(sizeof(struct linkedlist));  //linked list of D state
struct linkedlist * F = (struct linkedlist *)malloc(sizeof(struct linkedlist));  //linked list of F state
struct linkedlist * G = (struct linkedlist *)malloc(sizeof(struct linkedlist));  //linked list of G state
struct linkedlist * H = (struct linkedlist *)malloc(sizeof(struct linkedlist));  //linked list of H state
struct linkedlist * currState = (struct linkedlist *)malloc(sizeof(struct linkedlist)); // linked list of current state

//my state machine
head -> State = 'E';
head -> zero = F;
head -> one = G;

A -> State = 'A';
A -> zero = B;
A -> one = F;

B -> State = 'B';
B -> zero = D;
B -> one = H;

C -> State = 'C';
C -> zero = C;
C -> one = head;

D -> State = 'D';
D -> zero = C;
D -> one = B;

F -> State = 'F';
F -> zero = G;
F -> one = D;

G -> State = 'G';
G -> zero = H;
G -> one = A;

H -> State = 'H';
H -> zero = A;
H -> one = C;

int x = 1;
currState -> curr = head; //Sets initial State
while (x == 1)
{
    char temporary;
    int num = 0;
    for(int i = 0; i < 3; i++){
        input[i] = ' ';
    }

    scanf("%c", &temporary);
    while(temporary != '\n' ){

        if(temporary != ' '){
            input[num] = temporary;
            num++;
        }
        scanf("%c",&temporary);
    }
    
    if(input[0] == 'f'){  //to exit the program
        exit(0);
    }

    else if(input[0] == '0'){   //goes to the 0 state
        currState -> curr = currState -> curr -> zero;
        printf("%c\n", currState -> curr -> State);
    }
    else if(input[0] == '1'){  //goes to the 1 state 
        currState -> curr = currState -> curr -> one;
        printf("%c\n", currState -> curr -> State);
    }
    else if(input[0] == 'c'){   //change command which changes the state machine
        if(input[1] == '0'){    //if changing the 0 state
            if(input[2] == 'A' && delete[0] == 0)
                currState -> curr -> zero = A;
            else if(input[2] == 'B' && delete[1] == 0)
                currState -> curr -> zero = B;
            else if(input[2] == 'C' && delete[2] == 0)
                currState-> curr-> zero = C;
            else if(input[2] == 'D' && delete[3] == 0)
                currState -> curr -> zero = D;
            else if(input[2] == 'E' && delete[4] == 0)
                currState -> curr-> zero = head;
            else if(input[2] == 'F' && delete[5] == 0)
                currState -> curr -> zero = F;
            else if(input[2] == 'G' && delete[6] == 0)
                currState-> curr -> zero = G;
            else if(input[2] == 'H' && delete[7] == 0)
                currState -> curr -> zero = H;  
        }
        
        else if(input[1] = '1'){    //if changing the 1 state
            if(input[2] == 'A' && delete[0] == 0)
                currState -> curr -> one = A;
            else if(input[2] == 'B' && delete[1] == 0)
                currState -> curr -> one = B;
            else if(input[2] == 'C' && delete[2] == 0)
                currState-> curr-> one = C;
            else if(input[2] == 'D' && delete[3] == 0)
                currState -> curr -> one = D;
            else if(input[2] == 'E' && delete[4] == 0)
                currState -> curr-> one = head;
            else if(input[2] == 'F' && delete[5] == 0)
                currState -> curr -> one = F;
            else if(input[2] == 'G' && delete[6] == 0)
                currState-> curr -> one = G;
            else if(input[2] == 'H' && delete[7] == 0)
                currState -> curr -> one = H; 
        }
    }
    else if(input[0] == 'p'){  //prints the state machine in alphabetical order
	      printf("%c %c %c\n", A -> State, A -> zero -> State, A -> one -> State);
          printf("%c %c %c\n", B -> State, B -> zero -> State, B -> one -> State);              
          printf("%c %c %c\n", C -> State, C -> zero -> State, C -> one -> State);
          printf("%c %c %c\n", D -> State, D -> zero -> State, D -> one -> State);
          printf("%c %c %c\n", head -> State, head -> zero -> State, head -> one -> State);
          printf("%c %c %c\n", F -> State, F -> zero -> State, F -> one -> State);
          printf("%c %c %c\n", G -> State, G -> zero -> State, G -> one -> State);
          printf("%c %c %c\n", H -> State, H -> zero -> State, H -> one -> State);
    }
    else if(input[0] == 'g'){   //checks if a letter has been moved to garbage
	struct linkedlist * collectlinkedlist = (struct linkedlist *)malloc(sizeof(struct linkedlist));
	chngeNum = 0; 
	garbage = 0;
	collectlinkedlist -> curr = currState -> curr;
	for (count = 0; count < 300; count++){  //checks to see if all states are present, aka if a state has been moved to garbage
    
		if (collectlinkedlist -> curr -> State == 'A' || collectlinkedlist -> curr -> zero -> State == 'A' || collectlinkedlist -> curr -> one -> State == 'A')
			reach[0]++;
		if (collectlinkedlist -> curr -> State == 'B' || collectlinkedlist -> curr -> zero -> State == 'B' || collectlinkedlist -> curr -> one -> State == 'B')
			reach[1]++;
		if (collectlinkedlist -> curr -> State == 'C' || collectlinkedlist -> curr -> zero -> State == 'C' || collectlinkedlist -> curr -> one -> State == 'C')
			reach[2]++;
		if (collectlinkedlist -> curr -> State == 'D' || collectlinkedlist -> curr -> zero -> State == 'D' || collectlinkedlist -> curr -> one -> State == 'D')
			reach[3]++;
		if (collectlinkedlist -> curr -> State == 'E' || collectlinkedlist -> curr -> zero -> State == 'E' || collectlinkedlist -> curr -> one -> State == 'E')
			reach[4]++;
		if (collectlinkedlist -> curr -> State == 'F' || collectlinkedlist -> curr -> zero -> State == 'F' || collectlinkedlist -> curr -> one -> State == 'F')
			reach[5]++;
		if (collectlinkedlist -> curr -> State == 'G' || collectlinkedlist -> curr -> zero -> State == 'G' || collectlinkedlist -> curr -> one -> State == 'G')
			reach[6]++;
		if (collectlinkedlist -> curr -> State == 'H' || collectlinkedlist -> curr -> zero -> State == 'H' || collectlinkedlist -> curr -> one -> State == 'H')
			reach[7]++;
		if (chngeNum == 0)
			collectlinkedlist -> curr = collectlinkedlist -> curr -> zero;
		else if (chngeNum == 1)
			collectlinkedlist -> curr = collectlinkedlist -> curr -> one;
		if (count >= 100)
			chngeNum = 1;
    }         
    for(int i = 0; i < 8; i++){   
        if(reach[i] == 0){
            if(garbage == 0){
                printf("Garbage: < %c", 'A' + i);
                garbage = 1;                
            }
            else
            printf(", %c", 'A' + i);
            unreach[i] = 1;
        }
    }
    if (garbage > 0){printf(" >\n");}
    else{printf("No garbage \n");}
    }
    else if(input[0] == 'd'){  //deletes a state and its connecting ones
        int tinitial = 0;
        garbage = 0;
        if(input[1] == ' '){
            if(garbage == 0)
                printf("No States Delete.\n");
            else{
                printf("delete: < ");
                for(int i = 0; i < 8; i++){
                    if(unreach[i] == 1){
                        if(tinitial == 0){
                            printf("%c", 'A' + i);
                            tinitial++;
                        }
                        else
                            printf(", %c", 'A' + i); //deletes A if nothing else given
                        delete[i] = 1;
                        switch (i){  //sets state as blank
                            case 0:
                                A -> State = ' ';
                                break;
                            case 1:
                                B -> State = ' ';
                                break;
                            case 2:
                                C -> State = ' ';
                                break;
                            case 3:
                                D -> State = ' ';
                                break;
                            case 4:
                                head -> State = ' ';
                                break;
                            case 5:
                                F -> State = ' ';
                                break;
                            case 6:
                                G -> State = ' ';
                                break;
                            case 7:
                                H -> State = ' ';
                                break;
                        }
                        
                    }           
                }
                printf(" >\n");
            }
        }
        if(input[1] != ' '){  //if letter to delete is specified
            if(input[1] == 'A' && delete[0] == 0){ //actual deleting action
                A -> State = ' ';
                delete[0] = 1;
                printf("Delete.\n");
            }
            else if(input[1] == 'B' && delete[1] == 0){
                B -> State = ' ';
                delete[1] = 1;
                printf("Delete.\n");
            }
            else if(input[1] == 'C' && delete[2] == 0){
                C -> State = ' ';
                delete[2] = 1;
                printf("Delete.\n");
            }
            else if(input[1] == 'D' && delete[3] == 0){
                D -> State = ' ';
                delete[3] = 1;
                printf("Delete.\n");
            }
            else if(input[1] == 'E' && delete[4] == 0){
                head -> State = ' ';
                delete[4] = 1;
                printf("Delete.\n");
            }
            else if(input[1] == 'F' && delete[5] == 0){
                F -> State = ' ';
                delete[5] = 1;
                printf("Delete.\n");
            }
            else if(input[1] == 'G' && delete[6] == 0){
                G -> State = ' ';
                delete[6] = 1;
                printf("Delete.\n");
            }
            else if(input[1] == 'H' && delete[7] == 0){
                H -> State = ' ';
                delete[7] = 1;
                printf("Delete.\n");
            }
            else  //if letter to delete is not specified
                printf("Not Delete.\n");
        }
    }
}
exit(0);  //exits the program
}