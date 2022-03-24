#include<stdio.h>
#include<stdlib.h>
void knapsack_table(int Knap_Capacity,int Wts[],int Val[], int numberOfItems)
{
	int num_of_items = numberOfItems;
	int i,j,knapsack[num_of_items+1][Knap_Capacity+1]; 
	for (int a = 0; a<num_of_items+1; a++) {
		for (int b = 0; b<Knap_Capacity+1; b++) {
				knapsack[a][b] = 0;
		}
		
	}
	for(i=0;i<num_of_items+1;i++)     	{
		for(j=0;j<Knap_Capacity+1;j++) 	{
			if(i==0 || j==0)           	
                knapsack[i][j]=0;
			else if(Wts[i-1]<=j){      knapsack[i][j]=Val[i-1]+knapsack[i-1][j-Wts[i-1]]>knapsack[i-1][j]?Val[i-1]+knapsack[i-1][j-Wts[i-1]]:knapsack[i-1][j];
			}
			else                      knapsack[i][j]=knapsack[i-1][j];
		}
	}
	printf("The Knap Sack Table is shown below\n");
		for (int a = 0; a<num_of_items+1; a++) {
		printf("\n------------------------------------------\n");
		for (int b = 0; b<Knap_Capacity+1; b++) {
			printf("%d\t", knapsack[a][b]);
		}
	}
	printf("\n------------------------------------------\n\n");
	int output = knapsack[num_of_items][Knap_Capacity];
	printf("Maximum value of knapsack is :%d and the items included are\n", output);
	j=Knap_Capacity;
	for(i=num_of_items;i>0 && output>0;i--)
	{
		if(output==knapsack[i-1][j])
		{	
			continue;
		}
		else
		{
			printf("Item:%d\tWeight:%d\tValue:%d\n", i,Wts[i-1],Val[i-1]);
			output=output-Val[i-1];
			j=j-Wts[i-1];
		}
	}
}
int main()
{
	int n;
	printf("Enter the number of items\n");
	scanf("%d",&n);
	int weights[n],value[n],capacity;

	printf("Enter the weights of each item\n");
	for(int a=0;a<n;a++)
	{
		scanf("%d",&weights[a]);
	}
	printf("Enter the values associated with weight\n");
	for(int b=0;b<n;b++)
	{
		scanf("%d",&value[b]);
	}

	printf("Enter the capacity of knapsack\n");
	scanf("%d",&capacity);

	printf("Weights are :\n");
	for(int a=0;a<n;a++)
	{
		printf("%d ",weights[a]);
	}
	printf("\n");

	printf("Values are :\n");
	for(int a=0;a<n;a++)
	{
		printf("%d ",value[a]);
	}
	printf("\n");
	printf("Capacity is %d\n", capacity);
	knapsack_table(capacity,weights,value, n);
}


