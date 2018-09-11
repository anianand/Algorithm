#include <stdio.h>
 
int partition (int arr[], int first, int h);

void quicksort (int arr[], int first, int last)
{

    int memory[ last - first + 1 ];
 
    int index = -1;
 	index++;
    memory[ index ] = first;
    index++; 
    memory[ index ] = last;

    while ( index >= 0 )
    {
        last = memory[ index];
        index--;
        first = memory[ index];
        index--;
 
        int part_index = partition( arr, first, last );
 

        if ( part_index-1 > first )
        {
        	index++;
            memory[ index ] = first;
            index++;
            memory[ index ] = part_index - 1;
        }
 
        if ( part_index+1 < last )
        {
        	index++;
            memory[ index ] = part_index + 1;
            index++;
            memory[ index ] = last;
        }
    }
}
int partition (int arr[], int first, int h)
{
    int x = arr[h];
    int i = (first - 1);
	 for (int j = first; j <= h- 1; j++){
        if (arr[j] <= x){
            i++;
            int* s1 = &arr[i];
            int* s2 = &arr[j];
            int t = *s1;
    		*s1 = *s2;
    		*s2 = t;} }
			int* s1 = &arr[i+1];
            int* s2 = &arr[h];
            int t = *s1;
    		*s1 = *s2;
    		*s2 = t;
			return (i + 1);
}

int main()
{
    	int i,n,arr[1000];
    printf("Enter size of array: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
    	scanf("%d", &arr[i]);
	}
    quicksort( arr, 0, n - 1 );
     for ( i = 0; i < n; i++ )
        printf( "%d ", arr[i] );
    return 0;
}
