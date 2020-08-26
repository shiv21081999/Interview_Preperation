#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<intint>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
int numTilings(int n) {
    int mod = 1000000007;
    if(n <=2)
        return n;
    if(n == 3)
        return 5;
    int *a = new int[n+1];
    int *b = new int[n+1];
    a[0] = 0, a[1] = 1, a[2] = 2, a[3] = 5; 
    for(int i = 4; i <= n; i++)
    {
        a[i] = ((2*a[i-1]%mod) + (a[i-3]%mod))%mod;
    }       
    return a[n]%mod;
}
int32_t main(){
    int n;
    cin>>n;
    cout<<numTilings(n)<<endl;
    return 0;
}