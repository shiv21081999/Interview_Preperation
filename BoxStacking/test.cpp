#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;struct node{
    int a,l,b,h;
};
int maxHeight(int height[],int width[],int length[],int n)
{
    node *temp = new node[3*n];
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        temp[index].a = height[i]*width[i];
        temp[index].l = height[i];
        temp[index].b = width[i];
        temp[index++].h = length[i];
        temp[index].a = length[i]*width[i];
        temp[index].l = length[i];
        temp[index].b = width[i];
        temp[index++].h = height[i];
        temp[index].a = height[i]*length[i];
        temp[index].l = length[i];
        temp[index].b = height[i];
        temp[index++].h = width[i];
    }
    sort(temp, temp + 3*n, [&](node a, node b){
        return a.a > b.a;
    });
    // for(int i = 0; i < n; i++)
    // {
    //     cout<<temp[i].h<<" "<<temp[i].a<<endl;
    // }
    int *lis = new int[n];
    for(int i = 0; i < n ;i++)
    {
        lis[i] =  temp[i].h;
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i ; j++)
        {
            if(temp[i].l < temp[j].l && temp[i].b < temp[j].b && lis[i] < lis[j] + temp[i].h)
            {
                lis[i] = lis[j] + temp[i].h;
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        ans = max(lis[i], ans);
    }
    return ans;
}

int32_t main(){
    
    return 0;
}