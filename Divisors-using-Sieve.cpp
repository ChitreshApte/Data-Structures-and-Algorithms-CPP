#include<bits/stdc++.h>
#define int      long long 
using namespace std;

const int N = 1e6;
//the smallest prime divisor of the number
int di[N+1];

//this sieve will help us to find the divisors of a number fast
void Sieve()
{
	for(int i=1;i<=N;i+=2) di[i] = -1;
	for(int i=2;i<=N;i+=2) di[i] = 2;
	for(int i=2;i*i<=N;i++)
	{
		if(di[i] == -1) //i is a prime number
		{
			for(int j=i; j<=N; j+=i)
				if(di[j] == -1)
					di[j] = i;
		}
	}
	//still some prime numbers are left
	for(int i=3;i<=N;i++)
		if(di[i]==-1)
			di[i]=i;
}

void myDivisors(vector<int> &d, int num)
{
	unordered_map<int,int> mp;
	while(num!=1)
	{
		mp[di[num]]++;
		num /= di[num];
	}
	d.clear();
	d.push_back(1);
	for(pair<int,int> p:mp)
	{
		int num = p.first;
		int cnt = p.second;
		int sz = d.size(); //the number of divisors I have
		for(int i=0; i<sz*cnt; i++)
			d.push_back(d[i]*num);
	}
    //use this if we want the numbers in sorted order
	sort(d.begin(), d.end());
}

int32_t main()
{
	Sieve();
    
	int n;
    cin>>n;
    
    vector<int> divisors;
    myDivisors(divisors, n);
    
    for(int num : divisors)
        cout<<num<<" ";
}	