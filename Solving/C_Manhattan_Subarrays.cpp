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


ll solve(vector<ll>&arr)
{
    ll ans=0;
    int n=arr.size();
    for(int i=0;i<n-3;i++)
    {
        int a1=arr[i];
        int a2=arr[i+1];
        int a3=arr[i+2];
        int a4=arr[i+3];

        if(a1<=a2 && a2<=max(a3,a4)) continue;
        if(a2<=a3 && a3<=a4) continue;
        if(min(a1,a2)<=a3 && a3<=a4) continue;
        if(a1<=a2 && a2<=a3) continue;
        // here deac
         if(a1>=a2 && a2>=min(a3,a4)) continue;
        if(a2>=a3 && a3>=a4) continue;
        if(max(a1,a2)>=a3 && a3>=a4) continue;
        if(a1>=a2 && a2>=a3) continue;
        ans++;

    }
    return ans;
}
ll solve1()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    ll ans=n+(max(n-1,0LL));

    //  debug(ans);
    // len 3 
    
    for(int i=1;i<n-1;i++)
    {
        ans+=!((arr[i-1]>=arr[i] && arr[i]>=arr[i+1])||(arr[i-1]<=arr[i] && arr[i]<=arr[i+1]));

    }
    // debug(ans);
    return ans+solve(arr);
    return 0;
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
    while(t--)
    {
        cout << solve1() << "\n";
    }
    return 0;
}