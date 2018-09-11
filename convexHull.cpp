#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

void make_sub_hull(vector< pair<int,int> > v,pair<int,int> mi,pair<int,int> ma,pair<int,int> p);

set<pair<int,int> > hull;

int ccw(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    int m=((b.fi-a.fi)*(c.se-a.se))-((b.se-a.se)*(c.fi-a.fi));
    return m;
}


void solve(vector< pair<int,int> > v, pair<int,int> mi,pair<int,int> ma){
    if(!v.size())
        return;
    int m;
    int n=v.size(),ans=0,p=-999,i;
    for(i=0;i<n;i++){
        m=abs(ccw(mi,ma,v[i]));
        if(m>ans){
            ans=m;
            p=i;
        }
    }

    if(p!=-999){

        make_sub_hull(v,mi,ma,v[p]);
    }
}


void make_sub_hull(vector< pair<int,int> > v,pair<int,int> mi,pair<int,int> ma,pair<int,int> p){
    if(!v.size())
        return;
    int n=v.size(),i;
    vector< pair<int,int> > u,l;
    int x=ccw(mi,ma,p);

    for(i=0;i<n;i++){
        if(v[i]!=mi&&v[i]!=ma){
            int m=ccw(mi,v[i],p);
            if(m*x<0)
                u.pb(v[i]);
        }
    }
    x=ccw(mi,ma,p);
    for(i=0;i<n;i++){
        if(v[i]!=mi&&v[i]!=ma){
            int m=ccw(ma,p,v[i]);
            if(m*x<0)
                l.pb(v[i]);
        }
    }

    hull.insert(mi);
    hull.insert(ma);
    hull.insert(p);
    solve(u,mi,p);
    solve(l,ma,p);
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n,i,x,y;
	//cout<<"Enter the no of points\n";
    cin >> n;
    vector< pair<int,int> > v;
    //cout<<"Enter the points as x and y\n";
    for(i=0;i<n;i++){
        cin >> x >> y;
        v.pb(make_pair(x,y));
    }
    sort(v.begin(),v.end());


    vector< pair<int,int> > u,l;
    pair<int,int> mi=v[0],ma=v[n-1];
    for(i=0;i<n;i++){
        if(v[i]!=mi&&v[i]!=ma){
            int m=ccw(mi,ma,v[i]);
            if(m>0)
                u.pb(v[i]);
            else if(m<0)
                l.pb(v[i]);
        }
    }

    solve(u,mi,ma);
    solve(l,mi,ma);
    //cout << endl << "The points are:" << endl<<"-------------------"<<endl;
    for(set<pair<int,int> >::iterator it=hull.begin();it!=hull.end();it++)
        cout <<it->fi << " "<< it->se << endl;
    return 0;
}
