#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
int siz[100005];
int parent[100005];
int find(int a){
    while(a!=parent[a])a=parent[a];
    return a;
}
void join(int a,int b){
    a=find(a);
    b=find(b);
    if(siz[a]<siz[b]) swap(a,b);
    siz[a]+=siz[b];
    parent[b]=a;
}
int main(){
    io
    int n,m,x,y,l;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        siz[i]=1;
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        join(x,y);
    }
    cin>>l;
    int arr[l+1];
    for(int i=0;i<l;i++){
        cin>>arr[i];
        arr[i] = find(arr[i]);
    }
    //displays parent of input nodes
    for(int i=0;i<;i++) cout<<arr[i];
}
