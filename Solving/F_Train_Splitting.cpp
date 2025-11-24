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
void solve1(){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>>adj(n+1);

    vector<pair<ll,ll>>input;
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        input.push_back({u,v});

    }


    map<pair<ll,ll>,ll>mp;
    int color=1;
    if((n*(n-1))/2==m) 
    {
        // it was wrong logic for the ...->
        // 1 to 2 -> color 2 
        // 
        for(auto it:adj[1])
        {
           mp[{it,1}]=color;
           mp[{1,it}]=color;
        }
        mp[{1,2}]=2;
        mp[{2,1}]=2;

        color=3;
    }
    else
    {
        // here givw 1
        // 
        int node=-1;
        int size=-1;
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()!=n-1)
            {
                if(node==-1)
                {
                    node=i;
                    size=adj[i].size();
                }
                else
                {
                    if(size>adj[i].size())
                    {
                        node=i;
                        size=adj[i].size();
                    }
                }
            }
        }
        // we g
        debug(node);
        debug(adj[node]);
         for(auto it:adj[node])
        {
           mp[{it,node}]=color;
           mp[{node,it}]=color;
           
        }

        color++;

        // now done
        
    }


    cout<<color<<endl;
    for(auto it:input)
    {
        if(mp.count(it))
        {
            cout<<mp[it]<<" ";
        }
        else
        {
            cout<<color<<" ";
        }
    }
    cout<<endl;

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
      solve1();
    }
    return 0;
}