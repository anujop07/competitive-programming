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
ll solve(vector<ll>&arr,vector<ll>&brr)
{
    int n=arr.size();
 
    vector<ll>leftarr(n);
    leftarr[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        leftarr[i]=max(arr[i],leftarr[i-1]+arr[i]);
    }
 
    vector<ll>rightarr(n);

    // left brr
    vector<ll>temp(n);
    // vector<ll>leftarr(n);
    temp[0]=brr[0];
    for(int i=1;i<n;i++)
    {
        temp[i]=max(brr[i],temp[i-1]+brr[i]);
    }

    rightarr[n-1]=brr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightarr[i]=max(brr[i],rightarr[i+1]+brr[i]);
    }
 

    ll ans=LONG_LONG_MIN;

    ll sum=0;
    ll maxi=rightarr[0];
    debug(leftarr);
    debug(rightarr);

    for(int i=0;i<n;i++)
    { 
        ans=max(ans,leftarr[i]+rightarr[i]);
       
        ll currans=leftarr[i]+(rightarr[i]+(temp[i])-brr[i]);
        ans=max(ans,currans);
    }

    return ans;

    
}
ll solve1(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);
    
    vector<ll>brr(n);

    in(brr);

    ll ans1=solve(arr,brr);
    ans1=max(ans1,solve(brr,arr));

    return ans1;
   

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