#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>


	void SetColor(int ForgC);// function to hcange color
	
	int main(void){
		int rows_count=0;      // used it for counting the number rows
		int array[30][30]={0}; // two dimensional array to prind alphabates in rows and column order
		int i, j, k;          // counter variables
		int n;      		// to store the number of letters of word (input by user) 
		int a=65;         // variable use to assign english alphabate to array
		int c=0;         // variable use to temporarily store column number of word
		int r=0;		// variable use to temporarily store row number of word
		int col[20];    // array to store the number of columns letters fall in (input by user)
		int row[20];	// array to store the number of rows letters fall in (input by user)
		SetColor(43);   // fuction change color
		
		//prompt user to enter the length of the word
		printf("\n  Enter the length of the word:\n\n"); 
		SetColor(46); // change color of the text
		scanf("%d",&n); 
		
		system("cls"); // funtion clears the screen
		printf("\n\n\n");
		
		// Display alphabates in rows and column
		for(i=0;1;i++){
			rows_count++; // counts number of rows we will need later
			
			// prints number of rows against every row
			if(i==0)
			printf("\t\t   "); // skips first row because of numbering of column
			else
			printf("\t\t%2d  ",i); 
			
			
			for(j=1;j<=n;j++){
				
				if(i==0){
					printf("%5d",j); // gives numbering to column
					continue;
				}
				
				//prints alphabates
				array[i][j]=a;
				a++;
				printf("%4c ",array[i][j]);
				if(a==91)
				break;
			}
			printf("\n\n");
			if(a==91)      //  a==91 means if a gets more than 'Z'   
				break;
		}
		printf("\n");
		
		SetColor(43);
		
		// to prompt user to enter the column number letters fall in
		for(i=0;i<n;i++){
			printf("Enter the number of column letter %d falls in :",i+1);
			scanf("%d",&col[i]);
		}
		
		system("cls");
		printf("\n\n");
		
		//this portion transponse the alphabtes (rows into column)
	for(i=0;i<n;i++){
		c=col[i];
			if(i==0){
				printf("\t\t");
				for(j=0;j<rows_count-1;j++)
				printf(" %4d",j+1);
				printf("\n\n");
				}
			printf("\t\t");
	for(j=0;j<rows_count;j++){
	
		if(array[j][c]!=NULL)
		printf(" %4c",array[j][c]);
	}
	printf("\n\n\n");
}

		// to prompt user to enter the number of columns(rows) letter falls in 
		for(i=0;i<n;i++){
			printf("Enter the number of column the %d letter is fall in :",i+1);
			scanf("%d",&row[i]);
		}
		
system("cls");

	//prints the word user has picked
	for(k=0;k<3;k++){   // for decoration
		if(k==0)
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t");
		for(j=0;j<n+(n+(n-1));j++){
			if(k==1){
				printf("*");
				
				// prints the picked word
				for(i=0;i<n;i++){
					c=col[i];
					r=row[i];
					printf(" %c",array[r][c]);
}
				printf(" *");
				break;
			}
			
			
			
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n\n\n");
	getch();
		return 0;
		
	}
	
	
	
	
//fnction to change color of text	
	void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
