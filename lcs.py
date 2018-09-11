def lcs(i,j):
    if (i,j) not in me:
        if (i==0 or j==0) and a[i]==b[j]:
            me[(i,j)]=1
            return 1
        elif (i==0 or j==0):
            me[(i,j)]=0
            return 0
        elif a[i]==b[j]:
            p=lcs(i-1,j-1)+1
            me[(i,j)]=p
            return p
        else:
            p=lcs(i,j-1)
            q=lcs(i-1,j)
            me[(i,j-1)]=p
            me[(i-1,j)]=q
            return max(p,q)
    return me[(i,j)]
n,m=map(int,raw_input().split())
a,b=raw_input(),raw_input()
me={}
print lcs(n-1,m-1)