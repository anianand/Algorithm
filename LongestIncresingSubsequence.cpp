#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int search(vector<int>&arr,vector<int>&temp,int l,int r,int n){
	if(r==l) return r;
	if(r-l==1){
		if(arr[temp[l]]>n) return l;
		return r;
	}
	else if(r>l){
		int mid=(r+l)/2;
		if(arr[temp[mid]]>=n) return search(arr,temp,l,mid,n);
		else return search(arr,temp,mid,r,n);
	}
}
int main(){
    int n,le=1;
    cin>>n;
    vector<int>arr(n),temp(n,0),res(n,-1);
    rep(i,n) cin>>arr[i];
    for(int i=1;i<n;i++){
    	if(arr[i]<arr[temp[0]]) temp[0]=i;
    	else if(arr[i]>arr[temp[le-1]]){
    		res[i]=temp[le-1];
    		temp[le++]=i;
		}
		else{
			int p=search(arr,temp,-1,le-1,arr[i]);
			temp[p]=i;
			res[i]=temp[p-1];
		}
	}
	cout<<le;
}
