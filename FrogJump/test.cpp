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
bool canCross(int *arr, int n, int index, int last, bool** dp, bool **visited)
{
    if(index < 0)
        return false;
    if(index == n-1)
        return true;
    if(visited[index][last])
        return dp[index][last];
    bool ans = false;
    visited[index][last] = true;
    for(int i = index + 1; i < n; i++)
    {
        if(last+arr[index] == arr[i] && last > 0)
            ans = ans | canCross(arr, n, i, last, dp, visited);
        else if(last+arr[index]-1 == arr[i] && last-1 > 0)
            ans = ans | canCross(arr, n, i, last - 1, dp, visited);
        else if(last + arr[index] + 1 == arr[i])
            ans = ans | canCross(arr, n, i, last + 1, dp, visited);
    }
    dp[index][last] = ans;
    return ans;
}
bool canCross(vector<int>& stones) {
    int n = stones.size();
    int *arr = new int[n];
    bool **dp = new bool*[n+1];
    bool **visited = new bool*[n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new bool[n+1]();
        visited[i] = new bool[n+1]();
        memset(dp[i], false, sizeof(bool)*(n+1));
        memset(visited[i], false, sizeof(bool)*(n+1));
    }
    for(int i = 0; i < n; i++)
        arr[i] = stones[i];
    bool ans = canCross(arr, n, 0, 0, dp, visited);
    for(int i = 0; i <= n; i++)
    {
        delete [] dp[i];
        delete [] visited[i];
    }
    delete [] visited;
    delete [] dp;
    delete [] arr;
    return ans;
}
int32_t main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<canCross(arr)<<endl;
    return 0;
}