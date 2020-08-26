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
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if(n <= 1)
        return 0;
    if(n == 2)
        return max(0ll, prices[1]-prices[0]);
    int **dp = new int*[3];
    for(int i = 0; i < 3; i++)
    {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i < 3; i++)
    {
        int prevdiff = INT_MIN;
        for(int j = 1; j < n ; j++)
        {
            prevdiff = max(prevdiff, dp[i-1][j-1] - prices[j-1]);
            dp[i][j] = max(dp[i][j-1], prices[j] + prevdiff);
        }
    }
    int ans = dp[2][n-1];
    for(int i = 0; i < 3; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProfit(arr) << endl;
    return 0;
}