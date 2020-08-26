#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;
int countWays(int n, int k)
{
    int *dp = new int[n + 1];
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[1] = k;
    dp[2] = k * k;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]) % mod;
    }
    int ans = dp[n];
    delete[] dp;
    return ans;
}
int32_t main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int ans = countWays(n, k);
    cout << ans << endl;
    return 0;
}