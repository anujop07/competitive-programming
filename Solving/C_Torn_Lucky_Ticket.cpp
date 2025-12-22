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
    vector<string> arr(n);
    in(arr);
  
    // map<ll,ll>mp;

    ll ans=0;

    map<ll,ll>odd,even;


    for(auto it:arr)
    {
        int sum=0;
        for(char ch:it)
        {
            int ele=ch-'0';
            sum+=ele;
        }
        
        if(it.size()%2==1)
        {
           odd[sum]++;
        }
        else 
        {
            even[sum]++;
        }
    }
    
    // we have mapped the even and off

    // what could be sum 
    // 9 9 9 9 9
    // 90 max

    debug(odd);
    debug(even);
    for(int sum=2;sum<=90;sum++)
    {
        for(int ele1=1;ele1<sum;ele1++)
        {
            int ele2=sum-ele1;
            ans+=odd[ele1]*odd[ele2];
            ans+=even[ele1]*even[ele2];

        }
    }

    return ans;
   

    return 0;
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