#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct list {
                int numList[200];
                int endList;
		int maxList;
        } callList;

void AddItem(int item, struct list *callList);

bool checkItem(int item, struct list *callList);

void printList(struct list *callList);

void initializeList(int maxSize, struct list *callList);

int bingoArray(struct list *callList, int index);

int sizeOf(struct list *callList);
