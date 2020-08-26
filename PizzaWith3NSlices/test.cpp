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
int getSum(vector<int> &slices, int n)
{
    int m = slices.size();
    int **dp = new int*[m+1];
    for(int i = 0; i <= m; i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= m ; i++)
    {
        for(int j = 1; j <= n && j <= i ; j++)
        {
            if(i == 1)
                dp[i][j] = slices[i-1];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-2][j-1] + slices[i-1]);
            }
        }
    }
    return dp[m][n];
}
int maxSizeSlices(vector<int>& slices) {
    int n = slices.size();
    vector<int> a(n-1);
    vector<int> b(n-1);
    for(int i = 0; i < n-1; i++)
        a[i] = slices[i];
    for(int i = 1; i < n; i++)
        b[i-1] = slices[i];
    return max(getSum(a, n/3), getSum(b, n/3));
}
int32_t main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<maxSizeSlices(arr);
    return 0;
}