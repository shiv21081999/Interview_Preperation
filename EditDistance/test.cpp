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
int minDistance(string a, string b) {
    int n = a.length(), m = b.length();
    if(n < m)
        return minDistance(b, a);
    int **dp = new int*[2];
    for(int i = 0;i <= 1; i++)
    {
        dp[i] = new int[m+1]();
    }
    for(int i = 0;i <= m; i++)
    {
        dp[0][i] = i;
    }
    dp[0][0] = 0;
    dp[1][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[1][0] = i;
        for(int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
                dp[1][j] = dp[0][j-1];
            else{
                dp[1][j] = min(dp[0][j], min(dp[1][j-1],dp[0][j-1]))+1;
            }
        }
        for(int j = 0; j <= m; j++)
            dp[0][j] = dp[1][j];
    }
    int ans = dp[0][m];
    for(int i = 0; i <= 1; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
int32_t main(){
    string a,b;
    cin>>a>>b;
    cout<<minDistance(a,b)<<endl;
    return 0;
}