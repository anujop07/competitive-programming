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

ll solve(vector<ll>&arr, ll k)
{
    ll mini=k+1;
    ll maxi=arr.size()-k;
    // here is the main part over here 
    vector<int>nums;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=maxi && arr[i]>=mini)  nums.push_back(arr[i]);
    }

    debug(k);
    debug(nums);
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<nums[i-1]) return false;
    }
    
    return true;
}
ll solve1(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);
    ll ans=0;
  
    int i=1;
    int j=n;

   int cn=0;

    while(i<j)
    {
        if(arr[i-1]==i && arr[j-1]==j)
        {
            i++;
            j--;
        }
        else
        {
            cn++;
            i++;
            j--;
        }
    }
   
    if(cn==0) return 0;

    // here we can remove how mnay jere



    ll s=1;
    ll e=n/2;

    
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(solve(arr,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }

    return ans;
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