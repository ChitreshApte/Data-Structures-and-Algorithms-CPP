#include <iostream>

using namespace std;

const int N = 1e6;
int phi[N+1]; //phi[i] = count of numbers in [1,i] which are co-prime with i

void precompute() {
    for(int i=1; i<=N; i++) phi[i] = i;
    
    for(int i=2; i<=N; i++)
        if(phi[i] == i) //i is a prime
            for(int j=i; j<=N; j+=i) {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
}

int main() {
    precompute();
}