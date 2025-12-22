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
    ll k;
    cin>>k;
    vector<ll> arr(n);
    in(arr);

    vector<ll>diff(2*k+3);

    ll total=n/2;

    int i=0;
    int j=n-1;

    map<ll,ll>mp;
    
    while(i<j)
    {
        ll sum=arr[i]+arr[j];
        ll mini=min(arr[i],arr[j]);
        ll maxi=max(arr[i],arr[j]);
        
        mp[sum]++;
        
        ll l=sum-maxi+1;
        ll r=sum+(k-mini);

        diff[l]++;
        diff[r+1]--;

        i++;
        j--;
        
    }

    ll sum=0;
    for(int i=0;i<diff.size();i++)
    {
        sum+=diff[i];
        diff[i]=sum;
    }

    // here 
    ll ans=n;
    for(ll i=2;i<=2*k;i++)
    { 
        ll reqsum=i;
    
        ll curans=diff[reqsum]-mp[reqsum];
        curans+=2*(total-diff[reqsum]);
        
        ans=min(ans,curans);
    }
    return ans;

    
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