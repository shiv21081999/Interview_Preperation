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
bool isMatch(string s, string p) {
    int n = p.length();
    int m = s.length();
    bool **dp = new bool*[2];
    for(int i = 0; i < 2; i++)
    {
        dp[i] = new bool[n+1];
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for(int i = 1; i <= n; i++)
    {
        if(p[i-1] == '*')
            dp[0][i] = dp[0][i-2];
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(p[j-1] == '*')
            {
                dp[1][j] = dp[1][j-2];
                if(j-2<0 || s[i-1] == p[j-2] || p[j-2] == '.')
                    dp[1][j] = dp[1][j] | dp[0][j];
            }
            else if(p[j-1] == '.' || p[j-1] == s[i-1])
                dp[1][j] = dp[0][j-1];
            else
                dp[1][j] = false;
        }
        for(int j =0; j <= n; j++)
        {
            dp[0][j] = dp[1][j];
        }
    }
    bool ans = dp[0][n];
    delete [] dp[0];
    delete [] dp[1];
    delete [] dp;
    return ans;

}
int32_t main(){
    string s, p;
    cin>>s;
    cin>>p;
    cout<<isMatch(s, p)<<endl;
    return 0;
}