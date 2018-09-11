#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
int answer(int arr[], int n){
    int dp[n][n];
    rep(i,n){
    	rep(j,n) dp[i][j]=0;
	}
    int i, j, k, L, q;
    for (L=2; L<n; L++){
        for (i=1; i<n-L+1; i++){
            j = i+L-1;
            dp[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++){
                q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                dp[i][j]=min(q,dp[i][j]);
            }
        }
    }
    cout<<"\nDp matrix\n";
    rep(i,n){
    	rep(j,n){
    		if(i==0||j==0) continue;
    		cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    return dp[1][n-1];
}
int main(){
    int size;
    cout<<"Enter the number of matrices\n";
    cin>>size;
    int arr[size];
    cout<<"Enter the dimensions of matrices respectively\n";
    rep(i,size) cin>>arr[i];
    cout<<"Minimum number of multiplications is "<<answer(arr, size)<<endl;
    return 0;
}
