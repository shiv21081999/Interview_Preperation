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
int getMaxSum(int *arr, int n)
{
    int incl = arr[0], excl = 0, new_excl = 0;
    for(int i = 1 ; i < n; i++)
    {
        new_excl = max(incl, excl);
        incl = excl + arr[i];
        excl = new_excl;
    }
    return max(incl, excl);
}
int32_t main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<getMaxSum(arr, n)<<endl;
    }
    return 0;
}