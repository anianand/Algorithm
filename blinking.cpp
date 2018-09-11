#include<bits/stdc++.h>
#include "windows.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=n-1;i>=0;i--)
#define range(i,p,q) for(int i=p;i<=q;i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define ve vector
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void blink(string S,int tim=500)
{
    string D(S),E(S);
    for(auto &x:D)
        x=' ';
    for(auto &x:E)
        x='\b';
    for(int i=0;i<5;i++)
    {
        Sleep(tim);
        cout << S << E;
        Sleep(tim);
        cout << D << E;
    }
    cout << S;
}
string str(int i)
{
    if(i==0)
        return "0";
    string D;
    while(i)
    {
        D+='0'+(i%10);
        i/=10;
    }
    reverse(D.begin(),D.end());
    return D;
}
void bar(int s)
{
    // 178,219   181, 199
    int a=0,r=0;
    r=100/s;
    char ar[30];
    string D;
    D+=static_cast<char>(181);
    for(int i=0;i<s+1;i++)
        D+=' ';
    D+=static_cast<char>(199);
    for(int i=0;i<s+1;i++)
    {
        string R=str(a),E,F;
        R=" "+R+"%";
        E=R;
        D[i+1]=static_cast<char>(219);
        string G(D+R);
        E=G;
        for(auto &x:E)
            x='\b';
        for(auto &x:F)
            x=' ' ;
        Sleep(500);
        cout << G << E;
        Sleep(500);
        cout << F << E;

        a+=r;
    }
}
int main()
{
    cout <<"                           ";
    blink("Welcome");
    cout <<"\n";
    cout << "Enter your name : ";
    string s;
    cin >> s;
    bar(25);
    cout << endl;
    blink("Cheers !!!\a",650);
    cout << endl <<s << " you have successfully executed...";


    return 0;
}
