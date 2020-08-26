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
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int x = primes.size();
    int *index = new int[x];
    memset(index, 0, sizeof(int)*x);
    int *next_val = new int[x];
    for(int i = 0; i < x; i++)
    {
        next_val[i] = primes[i];
    }
    int  *ugly = new int[n];
    ugly[0] = 1;
    for(int i = 1; i < n;i++)
    {
        int next = INT_MAX;
        for(int j = 0; j < x; j++)
        {
            next = min(next, next_val[j]);
        }
        ugly[i] = next;
        for(int j = 0; j < x; j++)
        {
            if(next == next_val[j])
            {
                index[j]++;
                next_val[j]=ugly[index[j]]*primes[j];
            }
        }
    }       
    int ans = ugly[n-1];
    delete [] next_val;
    delete [] index;
    delete [] ugly;
    return ans;
}
int32_t main()
{
    int num;
    cin>>num;
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        arr[i] = a;
    }

    cout<<nthSuperUglyNumber(num, arr)<<endl;
    return 0;
}