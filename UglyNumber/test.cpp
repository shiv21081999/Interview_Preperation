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
bool isUgly(int num) {
    if(num <= 0)
        return false;
    while(num%2==0)
    {
        num/=2;
    }
    while(num%3==0)
    {
        num/=3;
    }
    while(num%5==0)
    {
        num/=5;
    }
    if(num>1)
        return false;
    return true;
}
int32_t main()
{
    int num;
    cin>>num;
    cout<<isUgly(num)<<endl;
    return 0;
}