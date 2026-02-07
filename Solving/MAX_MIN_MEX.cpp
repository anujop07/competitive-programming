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
vector<ll>fact;
ll mod=1e9+7;
void preCompu()
{
    fact.resize(1e6);
    fact[0]=1;

    for(int i=1;i<fact.size();i++)
    {
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
    // here precOmpute done 
}
// void de()
// {
//     ll n = 7;

//     for (int cur = 1; cur <= n; cur++)
//     {
//         vector<ll> a;
//         for (int i = 1; i <= cur; i++)
//             a.push_back(i);

//         ll cnt = 0;

//         cout << "cur = " << cur << "\n";

//         do
//         {
//             ll mn = a[0];
//             ll mx = a[0];

//             bool ok = true;

//             for (int i = 0; i < cur; i++)
//             {
//                 mn = min(mn, a[i]);
//                 mx = max(mx, a[i]);

//                 // check: prefix must be continuous
//                 if (mx - mn != i)
//                 {
//                     ok = false;
//                     break;
//                 }
//             }

//             if (ok)
//             {
//                 cnt++;

//                 // print valid permutation
//                 for (ll x : a)
//                     cout << x << " ";
//                 cout << "\n";
//             }

//         } while (next_permutation(a.begin(), a.end()));

//         cout << "Total valid = " << cnt << "\n\n";
//     }
// }

ll solve1(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);

    sort(arr);

    ll cn=1;
    ll ans=1;
    map<ll,ll>mp;

    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[i-1]==1)
        {
            cn++;
        }
        else
        {
            ans=max(ans,cn);
            mp[cn]++;
            cn=1;
        }
    }
    // here is the logic for the like ?? why we got and 
    ans=max(ans,cn);
    if(ans==1) return fact[n];
    mp[cn]++;

    ll contri=2;
    if(ans==3)
    {
        contri=4;
    }

    ll can=mp[ans];

    return ((can%mod)*(contri%mod)*(fact[n-ans]%mod))%mod;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    de();
    preCompu();
    int t;
    cin >> t;
    while(t--){
        cout << solve1() << "\n";
    }
    return 0;
}