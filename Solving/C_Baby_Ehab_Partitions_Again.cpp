// Author: anuj
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

// ---------- PBDS ----------
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// ---------- Debug ----------
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<"\n";
#else
#define debug(x)
#endif

// Primitive types
template<typename T> void _print(T t){cerr<<t;}
template<> void _print<string>(string t){cerr<<'"'<<t<<'"';}
template<typename T,typename V> void _print(pair<T,V> p){cerr<<"{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
template<typename T> void _print(vector<T> v){cerr<<"[ "; for(T i:v){_print(i); cerr<<" ";} cerr<<"]";}
template<typename T> void _print(set<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(multiset<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename K, typename V> void _print(map<K,V> m){cerr<<"{ "; for(auto i:m){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(vector<vector<T>> v){
    cerr<<"[\n";
    for(auto &row:v){ cerr<<"  [ "; for(auto &x:row){ _print(x); cerr<<" "; } cerr<<"]\n"; }
    cerr<<"]";
}

// ---------- Utility Functions ----------
template<typename T> void sort(vector<T>& a){sort(a.begin(),a.end());}
template<typename T> void rsort(vector<T>& a){sort(a.rbegin(),a.rend());}
template<> void sort<string>(vector<string>& a){sort(a.begin(),a.end());}
template<typename T> T summ(const vector<T>& a){return accumulate(a.begin(),a.end(),T(0));}
template<typename T> void in(vector<T>& a){for(auto &i:a){cin>>i;}}

// ===================================================
// =================== SOLVE FUNCTION =================
// ===================================================
bool solve(ll i,ll cursum,vector<ll>&arr,ll sum,vector<vector<int>>&dp)
{
    if(i>=arr.size()) return cursum==sum/2;

    if(cursum>sum/2) return false;

    if(dp[i][cursum]!=-1) return dp[i][cursum];

    bool ans=false;

    ans=ans | solve(i+1,cursum+arr[i],arr,sum,dp);
    ans=ans | solve(i+1,cursum,arr,sum,dp);
    return dp[i][cursum]=ans;
}
void solve1(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    ll sum=summ(arr);
    if(sum%2==1)
    {
        cout<<0<<endl;
        return ;
    }

    int miniidx=0;
    int od=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[miniidx]>arr[i])
        {
            miniidx=i;
        }
        if(arr[i]%2==1)
        {
            od=i;
        }
    }
    // sort(arr);
    // for(int it:arr) mp[it]++;

    
    vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
    if(solve(0,0,arr,sum,dp))
    {
        cout<<1<<endl;
       
        if(od!=-1)
        {
            cout<<od+1<<endl;
        }
        else
        {
            // all are even then 
            // which one is to s;ec here 
            // divising by 2 will not cause here 
            // so we can have like that here

            while(true)
            {
                for(int i=0;i<n;i++)
                {
                    arr[i]=arr[i]/2;
                    if(arr[i]%2==1) 
                    {
                        cout<<i+1<<endl;
                        return ;
                    }
                }
            }
        }
       
    }
    else
    {
        cout<<0<<endl;
    }
    // TODO: implement solution here

    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t=1;
    while(t--){
       solve1();
    }
    return 0;
}