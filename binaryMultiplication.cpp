#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
using namespace std;
int main(){
	cout<<"Enter the first binary number\n";
	string a,b;
	cin>>a;
	cout<<"Enter the second binary number\n";
	cin>>b;
	int x=a.length(),y=b.length();
	int n=x+y,ans[x+y];
	rep(i,n) ans[i]=0;
	rep(i,y){
		int carry=0;
		if(b[y-i-1]=='1'){
			rep(j,x){
				int p=a[x-j-1]=='1'?1:0;
				int q=ans[i+j];
				ans[i+j]=q^p^carry;
				carry=(p&q)|(carry&(p^q));
			}
			if(carry) ans[i+x]=1;
		//rep(i,n) cout<<ans[n-i-1];
		//cout<<endl;
		}
	}
	rep(i,n) cout<<ans[n-i-1];
}
