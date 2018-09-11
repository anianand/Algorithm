#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
using namespace std;
float a[500],b[500];
void mergesort (int num){
    int rght,rend;
    int i,j,m,t;

    for (int k=1; k < num; k *= 2 ) {       
        for (int left=0; left+k < num; left += k*2 ) {
            rght = left + k;        
            rend = rght + k;
            if (rend > num) rend = num; 
            m = left;
			i = left;
			j = rght; 
            while (i < rght && j < rend) { 
                if (a[i] <= a[j]) {         
                    b[m] = a[i]; i++;
                } else {
                    b[m] = a[j]; j++;
                }
                m++;
            }
            while (i < rght) { 
                b[m]=a[i]; 
                i++;
				m++;
            }
            while (j < rend) { 
                b[m]=a[j]; 
                j++;
				m++;
            }
            for (m=left; m < rend; m++)  a[m] = b[m]; 
        }
    }
}
int main(){
	int n;
	cout<<"Enter the size of array\n";
	cin>>n;
	cout<<"Enter the elements of array\n";
	rep(i,n) cin>>a[i];
	mergesort(n);
	cout<<"Sorted array is\n";
	rep(i,n) cout<<a[i]<<" ";
}
