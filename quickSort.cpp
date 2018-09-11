#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
using namespace std;
int partition (int arr[], int l, int h){
    int x = arr[h];
    int i = (l - 1);
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }
    swap (arr[i + 1],arr[h]);
    return (i + 1);
}
void quickSort(int arr[], int l, int h){
    int stack[ h - l + 1 ];
    int top = -1;
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    while ( top >= 0 ){
        h = stack[ top-- ];
        l = stack[ top-- ];

        int p = partition( arr, l, h );

        if ( p-1 > l ){
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        if ( p+1 < h ){
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}
int main(){
	int n;
	cout<<"Enter the size of array\n";
	cin>>n;
    int arr[n];
    cout<<"Enter the size of the array\n";
    rep(i,n) cin>>arr[i];
    quickSort( arr, 0, n - 1 );
    cout<<"The sorted array is\n";
    rep(i,n) cout<<arr[i]<<" ";
}
