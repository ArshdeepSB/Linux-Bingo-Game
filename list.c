#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include <stdbool.h>


void AddItem(int item, struct list *callList){
	
	if( callList->endList <= callList->maxList ){
		callList->numList[callList->endList] = item;
		callList->endList = callList->endList + 1;	
	}
	else{
		printf("ERROR exceeded max expectation number");
	}
}

bool checkItem(int item, struct list *callList){
	 for( int i = 0; i < callList->endList; i++){
                if(item == callList->numList[i]){
		return true;
		}
        }
	return false;
}

void printList(struct list *callList){
	printf("CallList: ");
	
	for( int i = 0; i < callList->endList; i++){
	    if(callList->numList[i]>0 && callList->numList[i] <= 15) 
            {
		if( callList->numList[i]< 10){
			printf("L0");	
		}
		else{ 
            		printf("L");
		}
            }
            else if(callList->numList[i] >= 16 && callList->numList[i] <= 30)
            {
            printf("I");
            }
            else if(callList->numList[i] >= 31 && callList->numList[i] <= 45)
            {
            printf("N");
            }
            else if(callList->numList[i] >= 46 && callList->numList[i] <= 60)
            {
             printf("U");
            }
            else if(callList->numList[i] >= 61 && callList->numList[i] <= 75)
            {
            printf("X");
            }
            else
            {
                printf("%s","File error");
            }	
		printf("%d ", callList->numList[i]);
	}
	printf("\n");
}

void initializeList(int maxSize, struct list *callList){
	callList->maxList = 100;
	callList->endList = 0;
}

int bingoArray(struct list *callList, int index){
	return callList->numList[index];
}

int getSize(struct list *callList){
	return sizeof(callList->numList) / sizeof(int);
	}


