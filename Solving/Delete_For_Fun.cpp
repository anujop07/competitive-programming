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
void solve1(){
    int n;
    cin >> n;
   
    ll k;
    cin>>k;
    // k--;
    string s;
    cin>>s;

    if(s[k-1]=='0')
    {
        cout<<-1<<endl;
        return;
    }
    vector<ll>ans;

    ll curr=1;

     s=s+s+s;

     int op=n+k-1;

     int i=op-1;
     int j=op+1;

     debug(op);

     // here 

     ll cn=1;

     
     ans.push_back(k-1);
   
     while(cn<n)
     {
       if(cn%2==1)
       {
         // even
         if(s[i]=='0')
         {
            ans.push_back(i%n);
            i--;
         } 
         else
         {
            if(s[j]=='1')
            {
                curr--;
            }
             ans.push_back(j%n);
             j++;
         }
         cn++;
       }   
       else
       {
           if(s[i]=='1')
         {
            ans.push_back(i%n);
            i--;
            curr++;
         } 
         else
         {
            if(s[j]=='1')
            {
                curr++;
            }
             ans.push_back(j%n);
             j++;
         }
         cn++;

       }
       if(curr<=0)
       {
          cout<<-1<<endl;
          return;
       }
     }

    //  cout<<"YES"<<endl;
     for(int it:ans)
     {
        cout<<it+1<<" ";
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