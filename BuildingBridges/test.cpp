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
struct node
{
    int s, n;
};
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n == 0 || n==1)
        {
            cout<<n<<endl;
            continue;
        }
        node *arr = new node[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].n;
        }
        for(int i = 0;i < n; i++)
        {
            cin>>arr[i].s;
        }
        sort(arr, arr + n, [&](node a, node b) {
            if (a.s == b.s)
                return a.n < b.n;
            return a.s < b.s;
        });
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<arr[i].n<<" "<<arr[i].s<<endl;
        // }
        vector<int> lis;
        lis.pb(arr[0].n);
        for (int i = 1; i < n; i++)
        {
            if (arr[i].n >= lis[lis.size() - 1])
            {
                lis.pb(arr[i].n);
            }
            else
            {
                int index = lower_bound(lis.begin(), lis.end(), arr[i].n) - lis.begin();
                lis[index] = arr[i].n;
            }
        }
        cout << lis.size() << endl;
        delete [] arr;
    }

    return 0;
}