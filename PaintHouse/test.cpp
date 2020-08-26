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
int getCost(vector<vector<int>> &arr, int **dp, int index, int col, int n)
{
    if(index == n)
        return 0;
    if(dp[index][col] != -1)
        return dp[index][col];
    int ans = INT_MAX;
    for(int i = 1; i <= 2; i++)
    {
        ans = dp[index][col] = min(ans, getCost(arr, dp, index+1, (col+i)%3, n)+arr[index][col]);
    }
    return ans;
}
int getMinCost(vector<vector<int> > &arr) {
    int n = arr.size();
    int **dp = new int*[n];
    for(int i =0 ;i  < n ; i++)
    {
        dp[i] = new int[3];
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    int ans1 = getCost(arr, dp, 0, 0, n);
    for(int i =0 ;i  < n ; i++)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    int ans2 = getCost(arr, dp, 0, 1, n);
    for(int i =0 ;i  < n ; i++)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    int ans3 = getCost(arr, dp, 0, 2, n);
    return min(ans1, min(ans2, ans3));
}
int32_t main(){
    int n; 
    cin>>n;
    int **arr = new int*[n];
    for(int i = 0;i  < n; i++)
    {
        arr[i] = new int[3];
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int cost = getMinCost(arr, n);
    cout<<cost<<endl;
    return 0;
}