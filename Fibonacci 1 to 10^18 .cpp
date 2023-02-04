
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define long long long int
const long M = 1000000007; // modulo
map<long, long> F;

long  f(long n) {
    if (F.count(n)) return F[n];
    long k=n/2;
    if (n%2==0) { // n=2*k
        return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
    } else { // n=2*k+1
        return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
    }
}

int main(){
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif 
    long n;
    F[0]=F[1]=1;
    while (cin >> n)
    cout << (n==0 ? 0 : f(n-1)) << endl;
}
