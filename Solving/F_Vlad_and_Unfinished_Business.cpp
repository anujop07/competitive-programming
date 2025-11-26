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
// dounf , dist
pair<ll,ll>solve(ll node,ll par,vector<vector<ll>>&adj,set<ll>&st)
{
    // here 
    pair<ll,ll>curans={0,1};

    if(st.count(node)) curans.first=1;

    for(auto it:adj[node])
    {
         if(it==par) continue;
         pair<ll,ll>childans=solve(it,node,adj,st);
         if(childans.first)
         {
            curans.first=1;
            curans.second+=childans.second;
         }
    }

    // debug(node);
    // debug(curans.second);
    return curans;

}
void dfs(ll node,ll par, ll &y,vector<vector<ll>>&adj,ll cur,ll &ans)
{
     if(node==y) ans=cur;

     for(auto it:adj[node])
     {
        if(it!=par)
        {
            dfs(it,node,y,adj,cur+1,ans);
        }
     }
}
ll solve1(){
    
    ll n,k;
    cin>>n>>k;

    vector<vector<ll>>adj(n+1);

    ll x,y;
    cin>>x>>y;

    set<ll>st;
    
    for(int i=0;i<k;i++)
    {
        ll node;
        cin>>node;
        st.insert(node);
    }
    for(int i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    st.insert(y);
    // here
    ll ans=2LL*(solve(x,-1,adj,st).second-1LL);

    //ans and then distbewebn them here 
    //
    ll dist=1;
    dfs(x,-1,y,adj,0,dist);
    debug(ans);
    debug(dist);
    return ans-dist;

    return 0;
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