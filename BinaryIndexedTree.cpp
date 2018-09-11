#include<bits/stdc++.h>
using namespace std;
//Point updates and Range Queries
//1-based indexing everywhere
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
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    return BITree;
}
int main()
{
    int n,Q,l,r,pos,x;
    char  ss[10];
    scanf("%d%d",&n,&Q);

    int *BITree = constructBITree(n);
    while(Q--)
    {
        scanf("%s",ss);
        if(strcmp(ss,"find")==0){
            scanf("%d%d",&l,&r);

                printf("%lld\n",getSum(BITree,n,r)-getSum(BITree,n,l-1));

        }
        else{
            scanf("%d%d",&pos,&x);

            updateBIT(BITree,n,pos,x);
        }
    }
    return 0;
}
