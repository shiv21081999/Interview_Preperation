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
int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();
    if(n <= 1)
        return 0;
    if(n == 2)
        return max(0ll, prices[1] - prices[0]);
    if(k>= n/2)
    {
        int profit = 0;
        for(int i = 1; i < n; i++)
        {
            if(prices[i] > prices[i-1])
                profit+=(prices[i] - prices[i-1]);
        }
        return profit;
    }
    int **dp = new int*[k+1];
    for(int i = 0; i <= k; i++)
    {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i < k+1; i++)
    {
        int prevdiff = INT_MIN;
        for(int j = 1; j < n ; j++)
        {
            prevdiff = max(prevdiff, dp[i-1][j-1] - prices[j-1]);
            dp[i][j] = max(dp[i][j-1], prices[j] + prevdiff);
        }
    }
    int ans = dp[k][n-1];
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
    int k;
    cin>>k;
    cout << maxProfit(arr,k) << endl;
    return 0;
}