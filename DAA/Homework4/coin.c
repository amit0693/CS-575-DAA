#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void powerChange(int n_cents,int power_denomination_array[],int s)
{
	int num_units;
	printf("The coins required to make change are:\n");
	for(int i=s-1;i>=0 && n_cents;i--)
	{
		if(power_denomination_array[i]<=n_cents)	
		{
			num_units = n_cents/power_denomination_array[i];		
			for(int a=0;a<num_units;a++)
            {
				printf("%d\n",power_denomination_array[i]);
            }
			n_cents=n_cents-num_units*power_denomination_array[i];
		}
	}
}
void Change(int n_cents)
{
	int quarters=25,dime=10,nickel=5,penny=1;
	int denomination_array[4]={penny,nickel,dime,quarters};
	int denomination_size = (int)(sizeof(denomination_array) / sizeof(denomination_array[0]));
	powerChange(n_cents, denomination_array,4);
}
void main()
{
	int n_cents,total;
	printf("-----------------   Part-a  -----------------\n");
	printf("\nMAKE CHANGE CONSISTING OF QUARTERS,DIMES,NICKELS AND PENNIES\n");
	printf("\nEnter the number of cents to make change: ");
	scanf("%d",&n_cents);
	Change(n_cents);
	printf("-----------------   Part-b  ----------------\n");
	printf("\nDENOMINATIONS ARE POWERS of c\n");
	int c,k,q,r;
	printf("\nEnter the value for c\n");
	scanf("%d",&c);
	printf("Enter the value for k\n");
	scanf("%d",&k);
	int denominations[k+1];
	for(q=0;q<k+1;q++)
	{
		denominations[q]= pow(c,q);
	}
	powerChange(n_cents,denominations,k+1);
	printf("###############   Part-d  ###############\n");
	printf("\nk DIFFERENT DENOMINATIONS\n");
	printf("\nEnter the total num of denominations\n");
	scanf("%d",&total);
	int k_denominations[total];
	printf("Enter the k different denominations\n");
	for(int p=0;p<total;p++)
    {
		scanf("%d",&k_denominations[p]);
    }
	powerChange(n_cents,k_denominations,total);
}



