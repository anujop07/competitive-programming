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

ll solve(ll node,ll par,ll total,vector<vector<ll>>&adj,map<ll,ll>&mp)
{
    ll curans=1;
    ll all=1;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            ll fromchild=solve(it,node,total,adj,mp);
            all+=fromchild;
            mp[node]=max(mp[node],fromchild);
        }
    }
    // here 
    mp[node]=max(mp[node],total-all);

    return all;

}
void solve1(){
    ll n;
    cin>>n;

    vector<vector<ll>>adj(n+1);
    
    for(int i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<ll,ll>mp;
    // node->max compo

    solve(1,-1,n,adj,mp);


    ll mini=INT_MAX;

    for(auto it:mp)
    {
        mini=min(mini,it.second);
    }

    ll cn=0;
    vector<int>centroid;

    for(auto it:mp)
    {
        if(it.second==mini)
        {
            centroid.push_back(it.first);
        }
    }
    debug(centroid);
    debug(mp);

    if(centroid.size()==1)
    {
        // size 1 has
        ll u=1;
        ll v=adj[1][0];

        cout<<u<<" "<<v<<endl;
        cout<<u<<" "<<v<<endl;
        debug("here onecnteroid ");
    }
    else
    {
        // here 
        ll u=-1;
        ll v=-1;

        bool f=0;
        for(auto it:adj[centroid[0]])
        {
            if(it!=centroid[1])
            {
                f=1;
                u=centroid[0];
                v=it;
            }
        }
        // here 
        if(f==1)
        {
           cout<<u<<" "<<v<<endl;
           cout<<centroid[1]<<" "<<v<<endl;
            return ;
        }
         for(auto it:adj[centroid[1]])
        {
            if(it!=centroid[0])
            {
                u=centroid[1];
                v=it;
            }
        }

            cout<<u<<" "<<v<<endl;
           cout<<centroid[0]<<" "<<v<<endl;


    }
  

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve1();
    }
    return 0;
}