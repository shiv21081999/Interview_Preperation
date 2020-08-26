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
int32_t main(){
    int t;
    cin>>t;
    int *arr = new int[101];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= 100; i++)
    {
        arr[i] = (arr[i-1] + (i-1)*(arr[i-2]))%mod;
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<arr[n]<<endl;
    }
    return 0;
}