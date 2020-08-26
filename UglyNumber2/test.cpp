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
int nthUglyNumber(int n) {
    int *ugly = new int[n];
    ugly[0] = 1;
    int i2,i3,i5;
    i2= i3= i5= 0;
    int next2 = 2, next3 = 3, next5 = 5;
    for(int i = 1;i < n;i++)
    {
        int next_ugly = min(next5, min(next3, next2));
        ugly[i] = next_ugly;
        if(next_ugly == next2)
        {
            i2++;
            next2 = 2*ugly[i2];
        }
        if(next_ugly == next3){
            i3++;
            next3 = 3*ugly[i3];
        }
        if(next_ugly == next5){
            i5++;
            next5 = 5*ugly[i5];
        }
    }
    int ans = ugly[n-1];
    delete [] ugly;
    return ans;
}
int32_t main()
{
    int num;
    cin>>num;
    cout<<nthUglyNumber(num)<<endl;
    return 0;
}