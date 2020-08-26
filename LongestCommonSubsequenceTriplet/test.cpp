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
int lcs(string a, string b, string c)
{
    int l = a.length(), m = b.length(), n = c.length();
    int ***dp = new int**[l+1];
    for(int i = 0; i <= l ; i++)
    {
        dp[i] = new int*[m+1];
        for(int j = 0; j <= m ; j++)
        {
            dp[i][j] = new int[n+1]();
        }
    }
    for(int i = 1; i <= l ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
                {
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[l][m][n];
}
int32_t main(){
    int t;
    cin>>t;
    while(t--)
    {
        int l,m,n;
        cin>>l>>m>>n;
        string a, b, c;
        cin>>a>>b>>c;
        cout<<lcs(a,b,c)<<endl;
    }
    return 0;
}