#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <time.h>
void primMST(int n, int adj_matrix[][n])
{
  int spanning_matrix[n][n];
  for(int i = 0; i<n; i++)                             
  {
    for(int j=0;j<n;j++)
    {
      spanning_matrix[i][j] = 0;
    }
  }
  int pq[n];
	int cost[n],parent_v[n];
	for(int i=0;i<n;i++)		
  {
		parent_v[i]=-1;
    cost[i]=999;
    pq[i]=i;
  }
  cost[0]=0;
	int queue_count=n;	while(queue_count>0)																	//
	{
		int min_vertex,i,min_cost=999;
		for(int i=0;i<n;i++)
			if(cost[i]<min_cost && pq[i]!=-1)													//
			{
				min_vertex=i;
				min_cost=cost[i];
			}
		int v= min_vertex;
		queue_count--;
		pq[v]=-1;
		for(int z=0;z<n;z++)
			if(adj_matrix[v][z]>0 && adj_matrix[v][z]<999)
			{
				if(pq[z]!=-1 && cost[z]>adj_matrix[v][z])
				{
					parent_v[z]=v;
					cost[z]=adj_matrix[v][z];
				}
			}
	}
	for(int i=1;i<n && cost[i]!=999;i++)
  {
    spanning_matrix[parent_v[i]][i] = cost[i];
    spanning_matrix[i][parent_v[i]] = cost[i];
  }
  printf("\n\t----- Prim's Matrix -----\t\n\n");
  for(int i = 0; i<n; i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d\t",spanning_matrix[i][j]);		
    }
    printf("\n");
  }
  char letters[7] = {'t','u','v','w','x','y','z'};
  printf("\n");
	int total_cost = 0;
  printf("{ ");
  for(int i=1;i<n && cost[i]!=999;i++)
  {
    printf("(%c %c)\t",letters[parent_v[i]], letters[i]);		
	}
  printf("}\n");
  for(int i=1;i<n && cost[i]!=999;i++)
  {
    printf("%c-%c:%d\n",letters[parent_v[i]], letters[i],cost[i]);		
		total_cost += cost[i];
	}
	printf("Total cost of MST is: %d\n",total_cost);
}
int main()
{
   srand( time(0) );	
   int n = 7;
   int adj_matrix[n][n];
   adj_matrix[0][0] = 0;
   adj_matrix[0][1] = 2;
   adj_matrix[0][2] = 4;
   adj_matrix[0][3] = 0;
   adj_matrix[0][4] = 0;
   adj_matrix[0][5] = 7;
   adj_matrix[0][6] = 0;
   adj_matrix[1][0] = 2;
   adj_matrix[1][1] = 0;
   adj_matrix[1][2] = 3;
   adj_matrix[1][3] = 0;
   adj_matrix[1][4] = 0;
   adj_matrix[1][5] = 0;
   adj_matrix[1][6] = 0;
   adj_matrix[2][0] = 4;
   adj_matrix[2][1] = 3;
   adj_matrix[2][2] = 0;
   adj_matrix[2][3] = 4;
   adj_matrix[2][4] = 3;
   adj_matrix[2][5] = 8;
   adj_matrix[2][6] = 0;
   adj_matrix[3][0] = 0;
   adj_matrix[3][1] = 0;
   adj_matrix[3][2] = 4;
   adj_matrix[3][3] = 0;
   adj_matrix[3][4] = 6;
   adj_matrix[3][5] = 0;
   adj_matrix[3][6] = 0;
   adj_matrix[4][0] = 0;
   adj_matrix[4][1] = 0;
   adj_matrix[4][2] = 3;
   adj_matrix[4][3] = 6;
   adj_matrix[4][4] = 0;
   adj_matrix[4][5] = 6;
   adj_matrix[4][6] = 8;
   adj_matrix[5][0] = 7;
   adj_matrix[5][1] = 0;
   adj_matrix[5][2] = 8;
   adj_matrix[5][3] = 0;
   adj_matrix[5][4] = 6;
   adj_matrix[5][5] = 0;
   adj_matrix[5][6] = 12;
   adj_matrix[6][0] = 0;
   adj_matrix[6][1] = 0;
   adj_matrix[6][2] = 0;
   adj_matrix[6][3] = 0;
   adj_matrix[6][4] = 8;
   adj_matrix[6][5] = 12;
   adj_matrix[6][6] = 0;
   printf("\n***********Initial Adjacency Matrix***********n");
   for(int i = 0; i<n; i++)
   {
     for(int j=0;j<n;j++)
     {
       printf("%d\t",adj_matrix[i][j]);
     }
     printf("\n");
   }
       primMST(n,adj_matrix);
			 return 0;
}
