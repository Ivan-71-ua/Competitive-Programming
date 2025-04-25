#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 100100;
    long long n;
    cin>>n;
    vector<long long> c(N+1,0);
    for(long long p = 0; p < n; p++){
        long long x;
        cin>>x;
        ++c[x];
    }
    for(long long p = 1; p <= N; p++){
            c[p] += c[p - 1];
    }
    long long q;
    cin>>q;
    while(q--){
        long long a;
        cin>>a;
         if(a <= N)
            cout <<c[a]<<endl;
         else
            cout <<c[N]<<endl;
    }
    return 0;
}