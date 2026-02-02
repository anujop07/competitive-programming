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
 ll n,m;
 cin>>n>>m;

 string s,t;
 cin>>s>>t;

 int i=0
 int j=0;
 while(i<n && j<m)
 {
     if(s[i]==t[j]) j++;
     i++;
 }
 if(j<m) return -1;

 vector<vector<ll>> dp_next(m+1, vector<ll>(2, INT_MAX));
 vector<vector<ll>> dp_cur(m+1, vector<ll>(2, INT_MAX));

 // base case: i == n
 for(int j=0;j<=m;j++)
 {
     for(int isC=0;isC<=1;isC++)
     {
         if(j<m) dp_next[j][isC]=INT_MAX;
         else dp_next[j][isC]=0;
     }
 }

 for(int i=n-1;i>=0;i--)
 {
     for(int j=m;j>=0;j--)
     {
         for(int isC=0;isC<=1;isC++)
         {
             ll opt1=INT_MAX;

             if(j>=m)
             {
                 dp_cur[j][isC]=1;
                 continue;
             }

             if(isC)
             {
                 opt1=dp_next[j][1];
                 if(s[i]==t[j])
                 {
                     opt1=min(opt1,dp_next[j+1][0]);
                 }
             }
             else
             {
                 opt1=1+dp_next[j][1];
                 if(s[i]==t[j])
                 {
                     opt1=min(opt1,dp_next[j+1][0]);
                 }
             }
             dp_cur[j][isC]=opt1;
         }
     }
     dp_next=dp_cur;
 }

 return dp_next[0][0];
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