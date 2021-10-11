#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define sz(c)               (ll)c.size()
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll x, ll y,ll p)
{
    ll res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=((res%p)*(x%p))%p;
        y=y>>1;
        x=((x%p)*(x%p))%p;
    }
    return res;
}
bool isprime(ll n)
{
    if(n<2) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    else
    {
        ll z=sqrt(n);
        rep(i,z-1) if(n%(i+2)==0) return false;
        return true;
    }
}
void dfs1(vii &g,vi &vis,stack<ll> &s,ll c)
{
    vis[c]=1;
    for(auto i:g[c])
    {
        if(!vis[i])
        {
            dfs1(g,vis,s,i);
        }
    }
    s.push(c);
}
void dfs2(vii &g,vi &vis,ll c,ll t)
{
    vis[c]=t;
    for(auto i:g[c])
    {
        if(vis[i]==1)
        {
            dfs2(g,vis,i,t);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vii g(n),ag(n);
    rep(i,m)
    {
        ll u,v;
        cin>>u>>v;
        g[--u].pb(--v);
        ag[v].pb(u);
    }
    stack<ll> s;
    vi vis(n,0);
    rep(i,n)
    {
        if(!vis[i])
        {
            dfs1(g,vis,s,i);
        }
    }
    ll t=1;
    while(!s.empty())
    {
        ll z=s.top();
        s.pop();
        if(vis[z]==1)
        {
            t++;
            dfs2(ag,vis,z,t);
        }
    }
    return 0;
}
