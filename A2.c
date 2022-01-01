// asbadhan, Badhan, Arshdeep, 501024284, 04
// jfaldu, Faldu, Jash, 501060429, 04
// k228pate, Patel, Krish, 501018374, 04
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include <ctype.h>

void printNumMatrix(int matrix[5][5]);
void printStrMatrix(char matrix[100][100]);
void makeNumMatrix(int matrix[5][5], FILE *fp);
void makeStringMatrix(char strMatrix[100][100], int numMatrix[5][5], int callSize);
void checkBingo(char strMatrix[100][100]);


// goes into list.h

int main(int argc, char *argv[])
        {
	int numMatrix[5][5];
	char strMatrix[100][100];
	bool stop = false;
	bool first = true; 
	char ch[100];
	int loopTime; 
	int randInt;
	int storeNum = -2;
	int sizeCounter  = 0;
	char str2[20];
	int loopCounter = 0;	
	bool qFound = false;
		
    FILE *fp;
//Error checking
  	 if ( (fp = fopen( argv[2],"r")) == NULL ) {
      		fprintf(stderr,"%s is nonexistent or unreadable \n", argv[2]);
      		exit(3);
   		}

	if( argv[1]  < 0 ){
	fprintf(stderr,"Usage: A2 seed cardFile2 \n");
                exit(1);
	}
	int randomNum = atoi(argv[1]);
	srand(randomNum);
	if( strcmp(argv[0], "./A2")!= 0 ){
	fprintf(stderr,"Usage: A2 seed cardFile3 %s\n", argv[0]);
                exit(1);
	}
	if( isdigit(argv[1][0])  != 2048 ){
	fprintf(stderr,"Expected integer seed, but got %s \n", argv[1] );
                exit(2);
	}
	        char str1[20] = "";
                for(int i = 0; i<5 ; i++){
                        for(int j = 0; j <5; j++){
                                while ((fscanf(fp, "%s", str1)) != EOF){
                                        int num = atoi(str1);
                                        numMatrix[i][j] = num;
					loopCounter++;
                                        break;
                                } 
                }
		}
		if(loopCounter < 25){
			fprintf(stderr,"%s has bad format \n", argv[2] );                                        
			 exit(4);

		}

//	checks for extra numbers
	while ((fscanf(fp, "%s", str2)) != EOF){
                                        fprintf(stderr,"%s has bad format \n", argv[2] );
                                        exit(4);
                                }
//	checks range of numbers
    for (int i = 0; i < 5; i++){
            if(numMatrix[i][0] < 0 && numMatrix[i][0] > 15) 
            {
	    printf("num matrix: %d", numMatrix[i][0]);
            fprintf(stderr,"%s has bad format \n", argv[2] );
                exit(4);
            }
            else if(numMatrix[i][1] < 16 && numMatrix[i][1] > 30)
            {
            fprintf(stderr,"%s has bad format \n", argv[2] );
                exit(4);
            }
            else if(numMatrix[i][2] < 31 && numMatrix[i][2] > 45 || numMatrix[2][2]!= 0)
            {
            fprintf(stderr,"%s has bad format \n", argv[2] );
                exit(4);
            }
            else if(numMatrix[i][3]<46 && numMatrix[i][3]>60)
            {
             fprintf(stderr,"%s has bad format \n", argv[2] );
                exit(4);
            }
            else if(numMatrix[i][4] < 61 && numMatrix[i][4]>75)
            {
            fprintf(stderr,"%s has bad format \n", argv[2] );
                exit(4);
            }
		else{}
            
    }	
	bool count = false;
	for(int i = 0; i <5; i++)
        {
            for (int j = 0; j < 5 ; j++)
            {
                for(int k =0 ; k<5 ;k++)
                {
                    if( numMatrix[i][j] == numMatrix[k][j] && i!=k){
                        
                        count = true;
                    }
                }
        } 
    }

    if(count==true)
    {
      fprintf(stderr,"%s has bad format \n", argv[2] );
                exit(4);
    }

	
	

	// keep 2 arrays, string array to put ms and int array for finding location
	fclose(fp);
	initializeList(100, &callList);
	//PROGRAM STARTS
	while (true){
		
		system("clear");	
		randInt = rand() % 75;
		for(int i = 0; i < loopTime; i++){
		while (true){
			if (checkItem(randInt, &callList) == false){ 
			AddItem(randInt, &callList);
			break;
			}
			randInt = rand() % 75;
			}
		}
		printList(&callList);

		printf("L   I   N   U   X \n");
		
		sizeCounter = sizeCounter + 1;
                makeStringMatrix(strMatrix, numMatrix, sizeCounter);
		printStrMatrix(strMatrix);
		checkBingo(strMatrix);
        	printf("Enter any non-enter key for Call (q to quit):");
	

		fgets(ch, 100, stdin);
			
		if ((strchr(ch, 'q')) != NULL || (strchr(ch, 'Q')) != NULL ){
			break; 
		}
		else {
			loopTime = strlen(ch) - 1;
			printf("\n");			
		}
	}	
	return 0;
       } 


void checkBingo(char strMatrix[100][100]){
	for (int i = 0; i < 5; i++){
		if(strMatrix[i][2] == 'm' && strMatrix[i][6] == 'm' && strMatrix[i][10] == 'm' && strMatrix[i][14] == 'm'  && strMatrix[i][18] == 'm' ){ 
		printf("Winner\n");
		exit(0);
	 }

	for (int i = 2; i <= 18; i=i+4){
		if(strMatrix[0][i] == 'm' && strMatrix[1][i] == 'm' && strMatrix[2][i] == 'm' && strMatrix[3][i] == 'm'  && strMatrix[4][i] == 'm' ){
                printf("Winner\n");
		exit(0);
         }
	}

	 if(strMatrix[0][2] == 'm' && strMatrix[1][6] == 'm' && strMatrix[2][10] == 'm' && strMatrix[3][14] == 'm'  && strMatrix[4][18] == 'm' ){
                printf("Winner\n");
		exit(0);
         }

	 if(strMatrix[0][18] == 'm' && strMatrix[1][14] == 'm' && strMatrix[2][10] == 'm' && strMatrix[3][6] == 'm'  && strMatrix[4][2] == 'm' ){
                printf("Winner\n");
		exit(0);
         }
	
	if(strMatrix[0][2] == 'm' && strMatrix[0][18] == 'm' && strMatrix[4][2] == 'm' && strMatrix[4][18] == 'm'){
                printf("Winner\n");
		exit(0);
         }


}
}

void printNumMatrix(int matrix[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printStrMatrix(char matrix[100][100]){
    for (int i = 0; i < 5; i++)
    {
        printf("%s  \n", matrix[i]);
    }

}

	

void makeStringMatrix(char strMatrix[100][100], int numMatrix[5][5], int callSize) {
	int tempNum;
	char temp[20];
	char strRow1[20] = "";
	char strRow2[20] = "";
	char strRow3[20] = "";
	char strRow4[20] = "";
	char strRow5[20] = "";

	for(int i = 0; i<5 ; i++){
        for(int j = 0; j <5; j++){
		tempNum = numMatrix[i][j];
		for(int k = 0; k < callSize; k++){
			if(callList.numList[k] == tempNum || tempNum == 0){
				sprintf(temp, "%dm", tempNum);
				break;
			}
			else{
				sprintf(temp, "%d ", tempNum);
			}
		}
			if( i == 0){
                                if(tempNum < 10){
                                        strcat(strRow1, "0");
                                }
				strcat(strRow1, temp);
				strcat(strRow1, " ");
			}
			
			if( i == 1){
                                if(tempNum < 10){
                                        strcat(strRow2, "0");
                                }
				strcat(strRow2, temp);
				strcat(strRow2, " ");
			}
		
			if (i == 2){
                                if(tempNum < 10){
                                        strcat(strRow3, "0");
                                }
				strcat(strRow3, temp);
				strcat(strRow3, " ");	
			}
		
			if (i == 3){
                                if(tempNum < 10){
                                        strcat(strRow4, "0");
                                }
				strcat(strRow4, temp);
				strcat(strRow4, " ");
			}
			
			if (i == 4){
                                if(tempNum < 10){
                                        strcat(strRow5, "0");
                                }
				strcat(strRow5, temp);
				strcat(strRow5, " ");
			}
        }
    }

	
	
	strcpy(strMatrix[0], strRow1);
	strcpy(strMatrix[1], strRow2);
        strcpy(strMatrix[2], strRow3);
        strcpy(strMatrix[3], strRow4);
        strcpy(strMatrix[4], strRow5);

}

