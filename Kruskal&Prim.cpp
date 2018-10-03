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
#define sz(c)               c.size()
ll root(vi &dsu,ll x)
{
    while(dsu[x]!=x)
    {
        dsu[x]=dsu[dsu[x]];
        x=dsu[x];
    }
    return x;
}
void union1(vi &dsu,ll x,ll y)
{
    ll x1=root(dsu,x);
    ll y1=root(dsu,y);
    dsu[x1]=dsu[y1];
    return;
}
vector< vector< pii > > prim(vector< vector< pii > > &g,ll n,ll x)
{
    vector< vector< pii > > ans(n);
    vi vis(n,0);
    priority_queue< pair<ll,pair<ll,ll> >,vector< pair<ll,pair<ll,ll> > >,greater< pair<ll,pair<ll,ll> > > > q;
    q.push(mp(0,mp(0,0)));
    while(!q.empty())
    {
        pair<ll,pair<ll,ll> > z=q.top();
        q.pop();
        if(vis[z.se.se]==0)
        {
            vis[z.se.se]=1;
            ans[z.se.fi].pb(mp(z.fi,z.se.se));
            ans[z.se.se].pb(mp(z.fi,z.se.fi));
            rep(i,sz(g[z.se.se]))
            {
                if(vis[g[z.se.se][i].se]==0)
                {
                    q.push(mp(g[z.se.se][i].fi,mp(z.se.se,g[z.se.se][i].se)));
                }
            }
        }
    }
    return ans;
}
vector< vector< pii > > kruskal(vector< vector< pii > > &g,ll n,ll m)
{
    vector< pair<ll,pair<ll,ll> > > edges(2*m);
    ll in=0;
    rep(i,n)
    {
        rep(j,sz(g[i]))
        {
            edges[in]=mp(g[i][j].fi,mp(i,g[i][j].se));
            in++;
        }
    }
    sort(all(edges));
    vi dsu(n);
    rep(i,n) dsu[i]=i;
    vector< vector< pii > > ans(n);
    rep(i,2*m)
    {
        pair<ll,pair<ll,ll> > z=edges[i];
        if(root(dsu,z.se.fi)!=root(dsu,z.se.se))
        {
            union1(dsu,z.se.fi,z.se.se);
            ans[z.se.fi].pb(mp(z.fi,z.se.se));
            ans[z.se.se].pb(mp(z.fi,z.se.fi));
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector< vector< pii > > g(n),ans;
    rep(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        g[x].pb(mp(w,y));
        g[y].pb(mp(w,x));
    }
    ll flag;
    cin>>flag;
    if(flag) ans=prim(g,n,0);
    else ans=kruskal(g,n,m);
    return 0;
}
