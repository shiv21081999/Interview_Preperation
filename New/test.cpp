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
int32_t main(){
    int n;
    cin>>n;
    string arr[n];
    unordered_map<string, int>m;
    bool flag = 0;
    string ans;
    for(int i =0 ;i < n;i++)
    {
        cin>>arr[i];
        if(m.find(arr[i])!=m.end() && !flag)
        {
            flag = 1;
            ans = arr[i];
        }
        else if(!flag)
        {
            string pref = "";
            for(int j=0; j<arr[i].length(); ++j)
            {
                pref = pref+arr[i][j];
                if(m.find(pref)!=m.end())
                {
                    flag = 1;
                    ans = arr[i];
                    break;
                }
            }
        }
        m[arr[i]]++;
    }
 //   printPossible(arr, n);
if(flag)
{
    cout<<ans;
}
else 
{
    cout<<"no";
}
    return 0;
}