#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//remote.cs.binghamton.edu

void print_sorted_array(int input_arr[],int i_arr_size)
{
  printf("Sorted Array: ");
  for(int j =0;j<i_arr_size;j++)
  {
    printf("%d\t",input_arr[j]);
  }
  printf("\n");
}

void printArray(int* input_arr[],int i_arr_size)
{
  for(int j =0;j<i_arr_size;j++)
  {
    printf("%d\t",input_arr[j]);
  }
  printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int coolSort(int* hop_arr[],int* input_arr[],int i_arr_size,int h_arr_size)
{
  int x = 0;
  while(x<h_arr_size)
  {
    int h_select = 0;
    h_select = hop_arr[x];
    //printf("h_select:%d\n",h_select);
    int to_be_sorted_elements[50];
    int location[50];
    int y = 0,k=0;
    while(y<i_arr_size)
    {
      //printf("y:%d\n",y);
      //printf("k:%d\n",y);
      //printf("input_arr[y]:%d\n",input_arr[y]);
      to_be_sorted_elements[k] = input_arr[y];
      location[k] = y;
      k++;
      y += h_select;
    //  printf("y:%d\n",y);
    }

    insertionSort(to_be_sorted_elements,k);
    int z = 0;
    for(int i =0;i<k;i++)
    {
      //printf("location[z]%d\n",location[z]);
      input_arr[location[z]] = to_be_sorted_elements[i];
      z++;
    }

    if(k == i_arr_size)
    {
      print_sorted_array(to_be_sorted_elements,k);
    }

    x++;
  }
  //insertionSort(input_arr,i_arr_size);
}

int main(int argc, char *argv[]){
  int i_arr_size,h_arr_size;
  int* input_arr[10] = {2,5,6,55,10,9,8,1,10,5};
  int* hop_arr[3] = {5,3,1};
  i_arr_size = 10;
  h_arr_size = 3;
  printf("\n--------------- Test Case 1 ---------------\n");
  printf("Input Array: ");
  printArray(input_arr,i_arr_size);
  printf("Hop Array: ");
  printArray(hop_arr,h_arr_size);

  coolSort(hop_arr,input_arr,i_arr_size,h_arr_size);

  printf("\n--------------- Test Case 2 ---------------\n");
  int* input_arr2[10] = {2,5,9,4,10,7,8,110,11,5};
  int* hop_arr2[3] = {5,2,1};
  printf("Input Array: ");
  printArray(input_arr2,i_arr_size);
  printf("Hop Array: ");
  printArray(hop_arr2,h_arr_size);

  coolSort(hop_arr2,input_arr2,i_arr_size,h_arr_size);
  //print_sorted_array(input_arr,i_arr_size);
}
