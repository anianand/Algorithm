#include<bits/stdc++.h>
using namespace std;
/**
Range updates and Point Queries
1-based indexing everywhere
**/
long long  getSum(int BITree[], int n, int index)
{
    long long  sum = 0;

    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(int *BITree, int n, int index, int val)
{

    while (index <= n)
    {
       BITree[index] += val;
       index += index & (-index);
    }
}
int *constructBITree(int n)
{
    int *BITree = new int[n+10];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    return BITree;
}
int main()
{
    int n,Q,l,r,pos,x,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&n,&Q);

    int *BITree = constructBITree(n);
    while(Q--)
    {

            scanf("%d%d%d",&l,&r,&x);
            l++; r++;
            updateBIT(BITree,n,l,x);
            updateBIT(BITree,n,r+1,-x);

    }
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&pos);
        pos++;
        printf("%lld\n",getSum(BITree,n,pos));
    }
    }
    return 0;

}
