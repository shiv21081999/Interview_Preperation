#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
int getAns(int *arr, int n)
{
    int *dec = new int[n];
    int *inc = new int[n];
    memset(dec, 0, sizeof(int)*n);
    memset(inc, 0, sizeof(int)*n);
    dec[0] = inc[0] = arr[0];
    bool flag = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j]>arr[i])
            {
                dec[i] = max(dec[i], inc[j]+arr[i]);
                flag = true;
            }
            else if(arr[j] < arr[i] && flag)
            {
                inc[i] = max(inc[i], dec[j]+arr[i]);
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < n ; i++)
    {
        ans = max(inc[i], ans);
        ans = max(dec[i], ans);
    }
    return ans;
}
int32_t main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n ;i++)
    {
        cin>>arr[i];
    }
    int ans = getAns(arr, n);
    cout<<ans<<endl;
    return 0;
}