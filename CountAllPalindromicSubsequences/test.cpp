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
int getCount(string s, int i, int j, int **dp)
{
    if(i == j)
        return 1;
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == s[j])
        return getCount(s, i+1,j, dp) + getCount(s, i, j-1, dp) + 1;
    else
        return getCount(s, i+1, j, dp) + getCount(s, i, j-1, dp) - getCount(s, i+1, j-1, dp);
}
int countPalindromicSubsequence(string s)
{
    int **dp = new int*[s.length()+1];
    for(int i = 0; i <= s.length(); i++)
    {
        dp[i] = new int[s.length() + 1];
        for(int j =0 ; j < s.length() ; j++)
        {
            dp[i][j] = -1;
        }
    }
    return getCount(s, 0, s.length()-1,dp);
}
int32_t main(){
    string s;
    cin>>s;
    cout<<countPalindromicSubsequence(s)<<endl;
    return 0;
}