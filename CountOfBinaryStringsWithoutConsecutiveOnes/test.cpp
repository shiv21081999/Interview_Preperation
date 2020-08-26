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
int getCount(int n){
    int *a = new int[n];
    int *b = new int[n];
    a[0] = 1;
    b[0] = 1;
    for(int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}
int32_t main(){
    int n;
    cin>>n;
    cout<<getCount(n)<<endl;
    return 0;
}