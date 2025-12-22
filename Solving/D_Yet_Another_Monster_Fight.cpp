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
ll solve(ll node,ll curr,vector<ll>&arr)
{
    //  pair<ll,ll>
     priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

     pq.push({arr[node],node});

     vector<int>vis(arr.size(),0);
     vis[node]=1;

     while(!pq.empty())
     {
        ll curnode=pq.top().second;
        ll req=pq.top().first;

        pq.pop();

        if(req>curr) return false;
        curr--;

        // push adjcent ele here
        if(curnode+1<arr.size()&& vis[curnode+1]==0)
        {
            vis[curnode+1]=1;
            pq.push({arr[curnode+1],curnode+1});
        }

        if(curnode-1>=0&& vis[curnode-1]==0)
        {
            vis[curnode-1]=1;
            pq.push({arr[curnode-1],curnode-1});
        }
     }

     return true;
}
ll solve1(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    ll ans=2e9;


    vector<ll>pre(n);
    vector<ll>suf(n);


    for(int i=0;i<n;i++)
    {
        pre[i]=arr[i]+(n-1-i);
        suf[i]=arr[i]+i;
    }

    for(int i=1;i<n;i++)
    {
        pre[i]=max(pre[i],pre[i-1]);
    }

    for(int i=n-2;i>=0;i--)
    {
        suf[i]=max(suf[i],suf[i+1]);
    }


    for(int i=0;i<n;i++)
    {
        ll currans=arr[i];
        if(i>0)
        {
            currans=max(currans,pre[i-1]);
        }
        if(i+1<n)
        {
            currans=max(currans,suf[i+1]);
        }
        ans=min(ans,currans);
    }

    return ans;
    // ll maxi=*max_element(arr.begin(),arr.end());
    // // ll mini=
    // ll s=maxi;
    // ll e=1e18;
    // debug(maxi);

    
    // ll startidx=0;
    // debug(111);
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[startidx]<arr[i]) 
    //     {
    //         startidx=i;
    //     }
    // }
    // // debug(startidx);
  

    // debug(startidx);
    // ll ans=e;
    // while(s<=e)
    // {
    //     ll mid=(s+e)/2;
    //     // debug(mid);
    //     bool f=0;
    //     // for(int i=0;i<n;i++)
    //     // {
    //     //     if(solve(i,mid,arr))
    //     //     {
    //     //         f=1;
    //     //         break;
    //     //     }
    //     // }
        
    //     if(f)
    //     {
    //          ans=mid;
    //          e=mid-1;
    //     }
    //     else
    //     {
    //          s=mid+1;
    //     }
    // }
    // return ans;

    // return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    while(t--){
        cout << solve1() << "\n";
    }
    return 0;
}