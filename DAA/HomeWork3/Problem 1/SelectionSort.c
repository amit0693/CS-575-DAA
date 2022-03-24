#include <stdio.h> 
#include <stdlib.h>

void SelectionSorta(int Arr[], int size){		
        int min,j;
        for(int i=0;i<size -1;i++){
                min=i;
                for(j=i+1;j<size;j++){
                        if(Arr[j]<Arr[min])
                                min = j;
                }
                int temp=Arr[min];
                Arr[min]=Arr[i];
                Arr[i]=temp;
        }
        int loop;
        for(loop = 0; loop < 10; loop++)
        {
         printf("%4d", Arr[loop]);
        }
        printf("\n");
}

void SelectionSortb(int Arr[],int size,int k){		
        int i,j,min;
        for(i=0;i<k;i++){
                min=i;
                for(j=i+1;j<size;j++){
                        if(Arr[j]<Arr[min])
                                min=j;
                }
                int temp=Arr[min];
                Arr[min]=Arr[i];
                Arr[i]=temp;
        }
        int loop;
        for(loop = 0; loop < k; loop++)
        {
         printf("%4d", Arr[loop]);
                }
                printf("\n");
}

int SelectionSortc(int Arr[],int Size,int k){		 
	int i,j,min; double median;
	for(i=0;i<k;i++){
		min=i;
		for(j=i+1;j<Size;j++){
			if(Arr[j]<Arr[min])
				min=j;
		}
		int temp=Arr[min];
		Arr[min]=Arr[i];
		Arr[i]=temp;
	}
	if(k%2==0){
		int m=k/2;
		median=(( Arr[m]+Arr[m-1])/2);
	}
	else{
		int m=k/2;
		median= Arr[m];
	}
	return median;

}
int main(){
    int Arr[10]={4,6,8,15,20,22,10,3,9,2};
    int size=10;
    SelectionSorta(Arr,size);
    int Arr1[10]={4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
    int size1=10;
    int k=4;
    SelectionSortb(Arr1,size1,k);
    int Arr2[10]={4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
    int size2=10;
    int k1=6;
    SelectionSortb(Arr2,size2,k1);
    int Arr3[10]={4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
    int size3=10;
    int k2=4;
    int median = SelectionSortc(Arr3,size3,k2);
	printf("Median value is =%d\n",median);
    int Arr4[10]={4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
    int size4=10;
    int k3=6;
    int median1 = SelectionSortc(Arr4,size4,k3);
    printf("Median value is =%d\n",median1);
	return 0;
}