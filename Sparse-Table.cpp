//  http://adilet.org/blog/sparse-table/
//  https://cp-algorithms.com/data_structures/sparse-table.html
 
//This is the implementation of sparse table data struture

//It works with idempotent functions like minimum, maximum, GCD, and LCM.
 
#include<bits/stdc++.h>
using namespace std;
 
const int k=25;            //this is the log2(MAXN)+1
const int MAXN=10000001;   //10^7+1
int st[MAXN][k + 1];       //MAXN is the size of the largest array possible
 
//st[i][j] will store the value of f() for range [i, i+pow(2,j)-1]
 
/*for range sum query make this as f
int rsq(int l, int r)
{
    int sum=0;
    for(int j=k;j>=0;j--)
    {
        if( l+(1<<j)-1 <=r )
        {
            sum+=st[l][j];
            l+=(1<<j);
        }
    }
    return sum;
}*/
 
//currently, we are working on range minimum query
int query(int l, int r)
{
    int m=st[l][0];
    for(int j=k;j>=0;j--)
    {
        if( l+(1<<j)-1 <=r )
        {
            m=min(m, st[l][j]);
            l+=(1<<j);
        }
    }
    return m;
}
 
int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>st[i][0];//for a range of size 1, the answer is the number itself
        
    for(int j=1;j<=k;j++)
        for(int i=0; i+(1<<j)-1 < n; i++)
            st[i][j] = min( st[i][j-1], st[i+(1<<(j-1))][j-1] );
        
    int q;
    cin>>q;
    while(q--)
    {
        int i, j;
        cin>>i>>j;
        cout<<query(i, j)<<"\n";
    }
} 