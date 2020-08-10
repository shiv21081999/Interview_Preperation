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
int power[33];
void getCount(int *arr, int a)
{
    if (a==0)
        return;
    int count = 0, d=0, n=0;
    for (int i = 1; i <= 32; i++)
    {
        d = power[i];
        n = power[i-1];
        count = (a/d)*n;
        count += max(0ll, a%d-n+1);
        arr[i-1] = count;
    }
}
int getSumOfAllPairXors(int a, int b, int c, int d)
{
    int *counta = new int[32];
    int *countb = new int[32];
    int *countc = new int[32];
    int *countd = new int[32];
    memset(counta, 0, sizeof(int)*32);
    memset(countb, 0, sizeof(int)*32);
    memset(countc, 0, sizeof(int)*32);
    memset(countd, 0, sizeof(int)*32);
    getCount(countb, b);
    if (a!=0)
        getCount(counta, a-1);
    getCount(countd, d);
    if(c!=0)
        getCount(countc, c-1);
    for(int i = 0;i < 32 ;i++)
    {
        countb[i] -= counta[i];
        countd[i] -= countc[i];
        // cout<<countb[i]<<" "<<countd[i]<<endl;
    }
    int n = b-a+1;
    int m = d-c+1;
    int ans = 0; 
    for(int i = 0; i < 32; i++)
    {
        int count1 = countb[i];
        int count2 = countd[i];
        int add = (((count1*(m-count2))%mod)+(((n-count1)*count2)%mod))%mod;
        add *= power[i];
        add%=mod;
        ans += add;
        ans%=mod;
    }
    return ans;
}
int32_t main() {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    power[0] = 1;
    for (int i = 1; i < 33; i++)
    {
        power[i] = power[i-1]*2;
    }
    cout<<getSumOfAllPairXors(a, b, c, d);
    return 0;
}