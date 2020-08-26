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
    int profit = 0;
    for(int i = 1 ; i < n-1; i++)
    {
        if(prices[i] >prices[i-1])
            profit+=(prices[i]-prices[i-1]);
    }
    return profit;
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