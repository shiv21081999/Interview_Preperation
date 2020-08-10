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
class Trie{
    public:
        bool isWord = false;
        Trie *children[26];
};
void insert(Trie *head, string val)
{
    Trie *curr = head;
    int n = val.size();
    for(int i = 0;i < n;i++){
        int index = val[i]-'a';
        if(!curr->children[index]){
            Trie *newnode = new Trie();
            curr->children[index] = newnode;
        }
        curr = curr->children[index];
    }
    curr->isWord = true;
}
bool isPresent(Trie *head, string val)
{
    Trie* curr = head;
    int n = val.size();
    for(int i = 0 ;i < n ;i++)
    {
        int index = val[i] - 'a';
        if(curr->children[index]){
            if(curr->children[index]->isWord)
                return true;
            curr = curr->children[index];
        }
        else
        {
            break;
        }
        
    }
    return false;
}
void printPossible(string arr[], int n)
{
    Trie *head = new Trie();
    bool flag = true;
    for(int i = 0;i < n;i++){
        if(isPresent(head, arr[i]))
        {
            cout<<"FAIL"<<endl;
            cout<<arr[i]<<endl;
            return;
        }
        insert(head, arr[i]);
    }
    cout<<"PASS"<<endl;

}
int32_t main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i =0 ;i < n;i++)
    {
        cin>>arr[i];
    }
    printPossible(arr, n);
    return 0;
}