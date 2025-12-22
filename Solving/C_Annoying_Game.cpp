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
ll maxSubarray(vector<ll> &a) 
{
    ll best = LLONG_MIN;
    ll curr = 0;

    for(ll x : a)
    {
        curr = max(x, curr + x);
        best = max(best, curr);
    }
    return best;
}
// ===================================================
// =================== SOLVE FUNCTION =================
// ===================================================
ll solve(vector<ll>&arr,vector<ll>&brr)
{
    // long long best=LLONG_MIN;
    // long long curr=0;
    // ll maxi=0;
    // for(int i=0;i<a.size();i++)
    // {
    //     if(curr+a[i]+maxi<a[i])
    //     {
    //         maxi=brr[i];
    //         curr=a[i];
    //     }
    //     else
    //     {
    //         maxi=max(maxi,brr[i]);
    //         curr+=a[i];
    //     }
    //     if(curr+maxi>best)
    //     {
    //         best=curr+maxi;
    //     }
    // }
    // return best;

    int n=arr.size();

    vector<ll>leftarr(n);
    leftarr[0]=arr[0];
    
    for(int i=1;i<n;i++)
    {
        leftarr[i]=max(arr[i],leftarr[i-1]+arr[i]);
    }

    vector<ll>rightarr(n);
    rightarr[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightarr[i]=max(arr[i],rightarr[i+1]+arr[i]);
    }

    debug(leftarr);
    debug(rightarr);

    ll normal=leftarr[0];
    for(int i=1;i<n;i++)
    {
        normal=max(normal,leftarr[i]);
    }

    ll best=normal;

    for(int i=0;i<n;i++)
    {
        ll newval=arr[i]+brr[i];

        ll left=0;
        if(i>0) left=leftarr[i-1];

        ll right=0;
        if(i<n-1) right=rightarr[i+1];
    
        ll currans=max(0LL,left)+newval+max(0LL,right);

        if(currans>best) best=currans;
    }

    debug(best);
    return best;
}


ll solve1(){
    int n;
    cin >> n;
    ll k;
    cin>>k;
    vector<ll> arr(n);
    in(arr);

    vector<ll>brr(n);
    in(brr);

    if(k%2==0)
    {
        // here she can decrase by ?
        // 
        return maxSubarray(arr);
    }
  
    // i can replace any ele 
    // we can maitian range over here 
    // is that??
    // yess 
    // ll ans=maxSubarray(arr);

    // for(int i=0;i<n;i++)
    // {
    //     ans=max(ans,arr[i]+brr[i]);
    // }

    // here 

    // if left ,(maxi left1 ,rig) right
    // may be -> 
    // only k -> odd 

//    ans=max(ans,solve(arr,brr));

   return solve(arr,brr);
    // return ans;
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