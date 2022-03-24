#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void longestCommonSubSequence(char *X,char *Y,int len1,int len2)
{
	int table[len1+1][len2+1];
	//making tht first row and column zero's
	for(int i=0;i<=len1;i++)
		table[i][0]=0;
	for(int i=0;i<=len2;i++)
		table[0][i]=0;
	for(int i=1;i<=len1;i++)
	{
		//printf("Entering first for loop\n");
		for(int j=1;j<=len2;j++)
		{
			//printf("Entering second for loop\n");
			if(X[i-1]==Y[j-1])
			{
				//printf("Else if condition\n");
				table[i][j]=table[i-1][j-1]+1;
			}
			else
			{
				table[i][j]=table[i - 1][j]>=table[i][j - 1]?table[i - 1][j]:table[i][j - 1];
			}
		}
	}

	printf("\n=====================================================================================================================\n");
	printf("\n\t\t\t\t\t\tLCS TABLE\t\t\n");
	printf("\n=====================================================================================================================\n");

	for(int k=0;k<=len1;k++)
	{
		printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		for(int l=0;l<=len2;l++)
		{
			printf("%d\t",table[k][l]);
		}

	}
	printf("\n---------------------------------------------------------------------------------------------------------------------\n");

	//To Print the Longest Common SubSequence
	int index = table[len1][len2];
	char result[index+1];
	result[index]='\0';
	int i = len1, j = len1;
	while (i > 0 && j > 0) 
    { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (X[i-1] == Y[j-1]) 
      { 
          result[index-1] = X[i-1]; // Put current character in result 
          i--;
          j--; 
          index--;
          //printf("LCS inside while%c\n", result[index]);     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (table[i-1][j] > table[i][j-1]) 
      {
         i--;
      }
      else
         j--;
   }
   printf("\nLongest Common SubSequence is : %s\n", result);
   int len = strlen(result);
   printf("\nLength of Longest Common SubSequence is: %d\n\n",len);
} 

int main() 
{ 
  char X[] = "10010101"; 
  char Y[] = "010110110"; 
  int m = strlen(X); 
  int n = strlen(Y); 
  printf("\nString X: %s\n", X);
  printf("\nString Y: %s\n", Y);
  longestCommonSubSequence(X, Y, m, n); 
  return 0; 
}
