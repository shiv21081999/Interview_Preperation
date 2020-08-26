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
int getCount(int n, int k)
{
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[k+1]();
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k ; j++)
        {
            if(j == 1 || j == n)
                dp[i][j] = 1;
            else
                dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
        }
    }
    return dp[n][k];
}
int32_t main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ans = getCount(n, k);
        cout<<ans<<endl;
    }
    return 0;
}