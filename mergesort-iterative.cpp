#include<stdlib.h>
#include<stdio.h>
 
void merge(int arr[], int first, int mid, int last) {
    int i, j, k;
    int m = mid - first + 1;
    int n =  last - mid;
 
    int arr1[m], arr2[n];
    
    for (i = 0; i < m; i++)
        arr1[i] = arr[first + i];
    for (j = 0; j < n; j++)
        arr2[j] = arr[mid + 1+ j];
 
    
    i = 0,j = 0,k = first;
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
	    }
        else {
            arr[k] = arr2[j];
            j++;
        }
	    k++;
    }
    while (i < m){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
 
void mergesort(int arr[], int n) { 
   int merging_size; 
   int index_left;
   int index_right_end;
   
   for (merging_size=1; merging_size<=n-1; merging_size = 2*merging_size) {
       
       for (index_left=0; index_left<n-1; index_left += 2*merging_size) {

           int mid = index_left + merging_size - 1;		
           if(index_left + 2*merging_size - 1>=n-1)
               index_right_end = n-1;
	   else
	       index_right_end = index_left + 2*merging_size - 1;
           
           merge(arr, index_left, mid, index_right_end);
       }
   }
}
 


int main() {
    int i,n,arr[1000];
    printf("Enter size of array: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
    	scanf("%d", &arr[i]);
    }
 
    printf("Given array is \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
 
    mergesort(arr, n);
 
    printf("\nSorted array is \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
  
    return 0;
}
