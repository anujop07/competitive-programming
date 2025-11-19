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
ll solve1(){
    int n;
    cin >> n;
     
    vector<int>deg(n+1,0);

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;

        deg[u]++;
        deg[v]++;

    }

    string s;
    cin>>s;
    // 
    // label no
    int cn=0;

    // 
    int one=0;
    int zero=0;

    int extra=0;
    for(int i=2;i<=n;i++)
    {
        if(deg[i]==1)
        {
            if(s[i-1]=='?') cn++;
            if(s[i-1]=='0') zero++;
            if(s[i-1]=='1') one++;
        }
        else 
        {
            extra+=(s[i-1]=='?');
        }
    }

    debug(extra);
    debug(one);
    debug(zero);
    debug(cn);
    if(s[0]!='?')
    {
        // direc
        ll ans=zero;
        if(s[0]=='0') ans=one;
        return ans+(cn+1)/2;
    }   
    
    if(one==0 && zero==0)
    {
         if(extra%2==1)
         {
            return (cn+1)/2;
         }
         return (cn)/2;
    }
    if(one==zero)
    {
         if(extra%2==1) 
         {
           return one+(cn+1)/2;
         }
         
    }
    return max(one,zero)+(cn)/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    while(t--){
        cout << solve1() << "\n";
    }
    return 0;
}