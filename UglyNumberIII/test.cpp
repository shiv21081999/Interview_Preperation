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
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}   
int nthUglyNumber(int n, int a, int b, int c) {
    int start = 1, end = INT_MAX;
    while(start <= end)
    {
        int mid = (start +end)/2;
        int o = ((mid / a) + (mid/b) + (mid/c) - (mid/lcm(a,b)) - (mid/lcm(b,c)) - (mid/lcm(c,a)) + (mid/lcm(a,lcm(b,c))));
        if(o < n)
            start = mid+1;
        else
            end = mid - 1;
    }
    return start;
}
int32_t main()
{
    int num;
    int a, b, c;
    cin>>num;
    cin>>a>>b>>c;

    cout<<nthUglyNumber(num, a, b, c)<<endl;
    return 0;
}