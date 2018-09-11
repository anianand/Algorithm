#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    rep1(i,n/2) heapify(arr, n, i);
    rep1(i,n){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){
	int size;
	cout<<"Enter the size of heap\n";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of the array\n";
	rep(i,size) cin>>arr[i];
	heapSort(arr,size);
	cout<<"----------------------\n";
	cout<<"Array after heap sort\n";
	rep(i,size) cout<<arr[i]<<" ";
	cout<<"\n----------------------\n";
	cout<<"level 3\n";
	int last;
	if(size<6) last=size;
	else last=6;
	range(i,3,last) cout<<arr[i]<<" ";
}
