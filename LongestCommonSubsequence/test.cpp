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
int lcs(string a, string b)
{
    int n = a.length();
    int m = b.length();
    if(n > m)
        return lcs(b,a);
    int **dp = new int*[2];
    for(int i = 0; i < 2; i++)
    {
        dp[i] = new int[n+1]();
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[j-1] == b[i-1])
                dp[1][j] = 1+dp[0][j-1];
            else
                dp[1][j] = max(dp[0][j], dp[1][j-1]);
        }
        for(int j = 0 ; j <= n ; j++)
            dp[0][j] = dp[1][j];
    }
    int ans = dp[0][n];
    delete [] dp[0];
    delete [] dp[1];
    delete [] dp;
    return ans;
}
int32_t main(){
    string a, b;
    cin>>a>>b;
    cout<<lcs(a,b)<<endl;
    return 0;
}