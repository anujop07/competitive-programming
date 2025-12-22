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
ll solve(vector<ll>&arr,vector<ll>&brr,ll x)
{
     ll ans=x;

    for(int i=0;i<arr.size();i++)
    {
        ans=max(ans+brr[i],arr[i]);
    }
    // debug(ans);
    return ans;
}
ll solve1(){
    ll n;
    cin >> n;
    ll k;
    cin>>k;
    vector<ll> arr(n);
    in(arr);

    vector<ll>brr(n);
    in(brr);

    ll opt1=0;
     ll ans=solve(arr,brr,1);
     // 360 comes extra !!
     // return 
     ll s=1;
     ll e=k+1;

     ll largest=e;
     while(s<=e)
     {
        ll mid=(s+e)/2;
        if(solve(arr,brr,mid)>ans)
        {
            largest=mid;
            e=mid-1;     
        }
        else
        {
            s=mid+1;
        }
     }
     
     // we have larger one here 

     ll left=k-largest+1;

     debug(largest);
     return (ans*k)+(left*(left+1))/2;



     debug("timepa");

     for(int i=1;i<=k;i++)
     {
        debug(i);
        ll curr=solve(arr,brr,i);
        opt1+=curr;
        debug(curr);
     }
     debug(opt1);
    // at which it will ineacrese
    // if a
    if(brr[0]>arr[0]) return ((k*(k+1))/(2LL))+(ans*k);

     ll same=min(arr[0]-brr[0],k);
     debug(same);
    k-=same;

    debug(k);
    debug(ans);

    // how should i return????
        return (ans*same)+(ans*k)+(k*(k+1))/2LL;






    // TODO: implement solution here

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