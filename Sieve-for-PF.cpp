#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int di[MAXN+1];     // di[i] refers to the lowest prime divisor of i

void Sieve()    // purpose: for finding the prime factorization of a number
{
    for(int i=1;i<=MAXN;i+=2)// for all odds set it as -1, will change later
        di[i]=-1;
    for(int i=2;i<=MAXN;i+=2)// for all even set it to 2
        di[i]=2;
    for(int i=2;i*i<=MAXN;i++)
        if(di[i]==-1)
        {
            for(int j=i;j<=MAXN;j+=i)
                if(di[j]==-1)
                    di[j]=i;
        }
    for(int i=3;i<=MAXN;i+=2)
        if(di[i]==-1)
            di[i]=i;
}
vector<int> prime_factors(int n)//returns nothing for n=1
{
    vector<int> answer;
    while(n!=1)
    {
        answer.push_back(di[n]);
        n/=di[n];
    }
    return answer;
}
int main()
{
    Sieve();
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<int> ans=prime_factors(n);
    for(auto x: ans)
    cout<<x<<" ";
}





