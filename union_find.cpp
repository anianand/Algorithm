#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define io	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
struct edge{
	int src,dest,weight;
};
bool cmp(edge a,edge b){
	if(a.weight==b.weight) return(a.src+a.dest+a.weight<b.src+b.dest+b.weight);
	return a.weight<b.weight;
}
int find(int parent[], int i){
    return ((parent[i] == i)?i: parent[i]=find(parent, parent[i]));
}
void Union(int parent[], int x, int y){
    parent[find(parent, x)] = find(parent, y);
}
int main(){
	io
	int n,m,ans=0,c=0;
	cin>>n>>m;
	vector<edge>arr(m);
	int parent[n];
	rep(i,n) parent[i]=i;
	rep(i,m){
		cin>>arr[i].src>>arr[i].dest>>arr[i].weight;
		arr[i].src--;
		arr[i].dest--;
	}
	sort(arr.begin(),arr.end(),cmp);
	rep(i,m){
		if(c==n-1) break;
		int x=find(parent,arr[i].src);
		int y=find(parent,arr[i].dest);
		if(x==y) continue;
		Union(parent,x,y);
		ans+=arr[i].weight;
		c++;
	}
	cout<<ans;
}
