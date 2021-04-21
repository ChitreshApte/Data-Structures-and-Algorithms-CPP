
//In this the value of the mod needs to be greater than n or else we have to use the lucas theorem.

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;
int add(int a,int b){return (a%mod + b%mod)%mod;}
int mult(int a,int b){return (a%mod * b%mod)%mod;}
int sub(int a,int b){return (a%mod - b%mod+mod)%mod;}

const int MAXN = 1e6;
int F[MAXN+1];

int power(int a, int n)
{
    if(n == 0) return 1;
    int res = power(a, n/2);
    res = mult(res, res);
    if(n&1) res = mult(res, a);
    return res;
}

int C(int n, int k)
{
    if(k > n) return 0;
    int res = F[n];
    res = mult(res, power(F[k], mod-2));
    res = mult(res, power(F[n-k], mod-2));
    return res;
}

int32_t main()
{
    F[0] = F[1] = 1;
    for(int i=2; i<=MAXN; i++)
        F[i] = mult(F[i-1], i);
        
    int q, n, k;
    cin>>q;
    while(q--)
    {
        cin>>n>>k;
        cout<<C(n,k)<<"\n";
    }
}