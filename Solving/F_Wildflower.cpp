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

ll solve(ll node,ll par,vector<vector<ll>>&adj,ll &len1,ll &len2)
{
        ll curans=1;
        // debug(node);
        vector<ll>curr;
        for(auto it:adj[node])
        {
            if(it!=par)
            {
                ll childans=solve(it,node,adj,len1,len2);;
                curans+=childans;
                curr.push_back(childans);
                
            }

        }
        if(curr.size()==2)
        {
            len1=curr[0];
            len2=curr[1];
        }
    
        return curans;
    
}

ll power(ll n){
    ll ans = 1;
    ll base = 2;
    ll mod = 1e9+7;

    while(n > 0){
        if(n & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        n >>= 1;
    }
    return ans;
}
ll solve1(){
    int n;
    cin >> n;
    
    vector<vector<ll>>adj(n+1);

    for(int i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll cn=0;

    for(int i=2;i<=n;i++)
    {
        if(adj[i].size()==1) cn++;
    }

    if(cn>2) return 0;
    ll mod=1e9+7;
    if(cn==1)
    {
       return power(n);
    }

    ll len1=0;
    ll len2=0;

    solve(1,-1,adj,len1,len2);

    debug(len1);
    debug(len2);


    ll maxi=max(len1,len2);
    ll mini=min(len1,len2);


    ll p1=n-2*mini;
    ll p2=p1-1;

    if(len1==len2)
    {
        p2=p1;
    }
    debug(p1);
    debug(p2);

    return (power(p1)%mod+power(p2)%mod)%mod;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cout << solve1() << "\n";
    }
    return 0;
}