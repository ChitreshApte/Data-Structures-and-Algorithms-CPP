#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin>>n;
    vector<int> a(n);
    int sum = 0;
    for(int &x : a)
    {
        cin>>x;
        sum += x;
    }

    bool t[n+1][sum+1];
    for(int i=0;i<=sum;i++) //with zero elements, no sum possible(first column)
        t[0][i]=false;
    for(int i=0;i<=n;i++) //zero sum, possible with any elements(first row)
        t[i][0]=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1] > j)
                t[i][j] = t[i-1][j];
            else
                t[i][j] = (t[i-1][j-a[i-1]] || t[i-1][j]);
        }
        
    //if sum is possible t[n][sum] is true
}