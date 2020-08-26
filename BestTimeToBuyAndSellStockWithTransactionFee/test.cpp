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
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    if(n <= 1)
        return 0;
    if(n == 2)
        return max(0ll, (prices[1] - prices[0])-fee);
    int a = 0, b = -prices[0]; 
    int c = max(a, b+prices[1]-fee);
    int d = max(b, a-prices[1]);
    a = c;
    b = d;
    for(int i = 2; i < n ; i++)
    {
        c = max(a, b+prices[i]-fee);
        d = max(b, a-prices[i]);
        a = c;
        b = d;
    }
    return max(c,d);
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
    cin >> k;
    cout << maxProfit(arr, k) << endl;

    return 0;
}