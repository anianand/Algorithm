#include<bits/stdc++.h>
using namespace std;
//2D BIT
//1-based indexing everywhere
long long tree[1050][1050];

long long  getSum(int x,int y)
{
    long long  sum = 0;

   while (x)
    {
        int yy=y;
        while(yy){
       sum += tree[x][yy];
       yy-= yy & (-yy);
        }
        x-= (x&(-x));
    }
    return sum;
}
void update(int x,int y,int val,int MAX)
{
    while (x<=MAX)
    {
        int yy=y;
        while(yy<=MAX){
       tree[x][yy] += val;
       yy+= yy & (-yy);
        }
        x+= (x&(-x));
    }
}
int *constructBITree(int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    return BITree;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
            int n;
    scanf("%d",&n);
    memset(tree,0,sizeof tree);

    while(1)
    {
        char s[10];
        scanf("%s",s);
        if(s[1]=='E'){
                int x,y,val;

            scanf("%d%d%d",&x,&y,&val);
            long long p_val  = getSum(x+1,y+1) + getSum(x,y) - getSum(x+1,y) - getSum(x,y+1);
            update(x+1,y+1,val-p_val,n+9);
        }
        else if(s[1]=='U'){
                long long sumx=0;
             int x1,y1,x,y;

            scanf("%d%d%d%d",&x,&y,&x1,&y1);
           sumx = getSum(x1+1,y1+1) + getSum(x,y) - getSum(x1+1,y) - getSum(x,y1+1);
            printf("%lld\n",sumx);
        }
        else
            break;
    }
    printf("\n");
    }
    return 0;
}
