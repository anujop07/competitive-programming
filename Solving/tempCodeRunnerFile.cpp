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

ll ask(vector<int>&arr,int curi)
{
    cout<<"? ";
    for(int it:arr)
    {
        cout<<it<<" ";
    }
    cout<<curi<<" ";
    cout<<endl;

    ll mad;
    cin>>mad;
    return mad;

}
void solve1()
{
   ll n;
   cin>>n;
   
   vector<int>arr={1};

   vector<int>ans(2*n+1,0);

   vector<int>got;
   set<int>st;

   for(int i=2;i<=2*n;i++)
   {
       ll x=ask(arr,i);

       if(x==0)
       {
         arr.push_back(i);
       }
       else
       {
         ans[i]=x;
         got.push_back(i);
         st.insert(i);
       }
   }

   for(int i=2*n;i>=1;i--)
   {
      // c
      if(st.count(i)) continue;
      // here is the main part for
      ll x=ask(got,i);

      ans[i]=x;
   }

   // >
   cout<<"! ";
   for(int i=1;i<=2*n;i++)
   {
    cout<<ans[i]<<" ";
   }
   cout<<endl;
   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    while(t--){
        solve1();
    }
    return 0;
}