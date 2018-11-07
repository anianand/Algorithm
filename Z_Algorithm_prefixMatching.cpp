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
string s;
ll n,l,r,ans;
ll z[100005];
void solve(){
    n=s.length();
    rep(i,n) z[i]=0;
    z[0]=n;
    l=0;
    r=0;
    ans=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=i;
            r=i;
            while(r<n && s[r-l]==s[r]) r++;
            z[i]=r-l;
            r--;
        }
        else{
            int k=i-l;
            if(z[k]<r-i+1) z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r-l]==s[r]) r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    rep(i,n) ans+=z[i];
    cout<<ans<<endl;
}
int main(){
    io
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        solve();
    }
}

