n=input()
ans,c=1,0
li=[0]*n
def primes1(n):
    """ Returns  a list of primes < n """
    sieve = [True] * (n/2)
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i/2]:
            sieve[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
    return [2] + [2*i+1 for i in xrange(1,n/2) if sieve[i]]
l=primes1(n+2)
for i in l:
    li[i-2]=1
for i in xrange(n):
    if li[i]==0:
        li[i]=2
        ans=2
print ans
for i in li:
    print i,
