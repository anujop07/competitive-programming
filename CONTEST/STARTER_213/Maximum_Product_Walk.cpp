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
ll getp(ll cn)
{
    ll mod=998244353;
    ll ans=1;
    while(cn--)
    {
        ans=((ans%mod)*(2LL)%mod)%mod;
    }
    return ans;
}

ll solvecn(int node,int par ,vector<vector<ll>>&adj,vector<ll>&cn,vector<ll>&arr)
{
     ll curans=0;

     if(arr[node]<0) curans++;

     for(auto it:adj[node])
     {
        if(it==par) continue;
        curans+=solvecn(it,node,adj,cn,arr);
     }

     cn[node]=curans;
     return curans;
     
}
ll solvesize(int node,int par ,vector<vector<ll>>&adj,vector<ll>&all,vector<ll>&arr)
{
     ll curans=abs(arr[node]);

     for(auto it:adj[node])
     {
        if(it==par) continue;
        curans+=abs(solvesize(it,node,adj,all,arr));
     }

     all[node]=curans;
    
     return curans;
     
}

void solve(int node,int par,vector<vector<ll>>&adj,vector<ll>&all,vector<ll>&negcnt,ll &ans,ll &allcn,ll &allsum)
{
      // take node
      // 
      // p1 ->node in an lower side
      // ok

      ll negcn=negcnt[node];
      ll sum=all[node];

      if(negcn%2==0)
      {
         ans=max(ans,sum);
      }


      ll upsidesum=allsum-sum;
      ll negcn2=allcn-negcn;

      if(negcn2%2==0)
      {
        ans=max(ans,upsidesum);
      }

      for(auto it:adj[node])
      {
         if(it==par)
         {
            continue;
         }

         solve(it,node,adj,all,negcnt,ans,allcn,allsum);
      }

      
}
long long modpow(long long a, long long b, long long mod = 998244353) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) 
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// To compute 2^powcn % 998244353
long long getPower(long long powcn) {
    return modpow(2, powcn);
}
ll solve1(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    vector<vector<ll>>adj(n);

    for(int i=0;i<n-1;i++)
    {
        ll u;ll v;
        cin>>u>>v;
 
        u--;
        v--;
        
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<ll>negcnt(n,0);
    vector<ll>all(n,0);
    ll cn=0;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=abs(arr[i]);
        if(arr[i]<0) cn++;
    }
    if(cn%2==0)
    {
      
       // return 
       return getPower(sum);
    }

   
     solvecn(0,-1,adj,negcnt,arr);
     solvesize(0,-1,adj,all,arr); 
      
     ll ans=0;
     debug(negcnt);
     debug(all);

      solve(0,-1,adj,all,negcnt,ans,cn,sum);

      return getPower(ans);
     
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