#include <vector>
class segmentree
{
    vector<int> tree;
    int n;
    int get_size(int k)
    {
        r=2;
        --k;
        while(k)
        k>>=1,r<<=1;
        return r;
    }
public:
    void construct(int sz)
    {
        n=sz-1;
        tree.resize(get_size(sz));
    }
    void construct(vector<int> &v)
    {
        n=v.size()-1;
        tree.resize(get_size(v.size());
        make(v,1,0,n);
    }
    void make(vector<int> &v,int node,int L,int R)
    {
      if(L==R)
      {
        tree[node]=v[L];
        return;
      }
      int mid=(L+R)>>1;
      make(v,node<<1,L,mid);
      make(v,(node<<1)+1,mid+1,R);
      tree[node]=max(tree[node<<1],tree[(node<<1)+1]);
    }
    int find(int L,int R,int x,int y,int c)
    {
        if(x>R || y<L)
          return 0;
        if(L>=x && R<=y)
          return tree[c];
        return max(find(L,(L+R)>>1,x,y,c<<1),find((L+R)>>1)+1,R,x,y,(c<<1)+1));
    }
    void update(int pos,int val, int c,int L,int R)
    {
      if(pos<L || pos> R)
      return ;
      if(L==R)
      {
        tree[c]=val;
        return;
      }
      update(pos,val,c*2,L,(L+R)>>1);
      update(pos,val,c*2+1,((L+R)>>1)+1,R);
      tree[c]=max(tree[2*c],tree[2*c+1]);
        
    }
};
