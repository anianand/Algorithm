#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    string a,b;
    cin>>a>>b;
    ll n1=a.size(),n2=b.size();
    ll dp1[n2+1];
    ll dp2[n2+1];
    memset(dp1,0LL,sizeof(dp1));
    memset(dp2,0LL,sizeof(dp2));
    // @ making memo table
    for(ll i=1;i<=n1;i++){
        for(ll j=1;j<=n2;j++){
            if(a[i-1] == b[j-1])
                dp2[j] = dp1[j-1] + 1;
            else
                dp2[j] = max(dp2[j-1],dp1[j]);  
        }
        // copy dp[2] to dp[1]
        for(ll k=0;k<=n2;k++){
            dp1[k] = dp2[k];
            dp2[k] = 0LL;
        }
    }
    //.. @ printing memo table
    /*for(ll i=0;i<=n2;i++){
        cout<<dp1[i]<<" ";
    }*/
    cout<<dp1[n2]<<endl;  
}

