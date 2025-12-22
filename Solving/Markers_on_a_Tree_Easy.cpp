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
bool getpath(int node,int par,vector<ll>&ans,vector<vector<ll>>&adj)
{
      ll curans=0;
      if(node==adj.size()-1)
      {
        ans.push_back(node);
        return true;
      }
      for(auto it:adj[node])
      {
        if(it!=par)
        {
            if(getpath(it,node,ans,adj))
            {
               ans.push_back(node);
               return true;
            }
        }
      }
      return false;
      
}

// how many, is that found
ll solve2(ll node,ll par,string &s,ll &u,ll &v,vector<vector<ll>>&adj)
{
    // 
    ll curans=0;

    for(auto it:adj[node])
    {
        if(it==par) continue;
        if(it==u && node==v) continue;
        if(it==v && node==u) continue;

        curans+=solve2(it,node,s,u,v,adj);
    }
    
    if((curans || s[node-1]=='1') && node!=1 && node!=adj.size()-1)
    {
        curans++;
    }

    return curans;
}
ll solve(ll u,ll v,vector<vector<ll>>&adj,string &s)
{

    ll n=adj.size()-1;
    debug(n);
    ll from1= 2*solve2(1,-1,s,u,v,adj);
    ll fromn=2*solve2(n,-1,s,u,v,adj);
    debug(u);
    debug(v);
    debug(from1);
    debug(fromn);
    return from1+fromn;
     
}
ll solve1(){
    int n;
    cin >> n;
 
    vector<vector<ll>>adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        ll ele;
        cin>>ele;
        adj[i+2].push_back(ele);
        adj[ele].push_back(i+2);
    }
    string s;
    cin>>s;

    // for(int i=0;i<n;i++)
    // {
    //     cout<<min(arr[i],0LL)<<endl;
    // }
    // //1 to n 
    vector<ll>ans1;
    getpath(1,-1,ans1,adj);
    debug(ans1);

    reverse(ans1.begin(),ans1.end());

    ll ans=LONG_MAX;
    for(int i=0;i<ans1.size()-1;i++)
    {
      ans=min(ans,solve(ans1[i],ans1[i+1],adj,s));
    }

   
    return ans;


    return 0;
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