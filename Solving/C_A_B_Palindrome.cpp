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
string solve1(){
    ll a,b;
    cin>>a>>b;
    int n;
    n=a+b;
 
    ll a1=a;
    ll b1=b;
    string s;
    cin>>s;
    
    int i=0;
    int j=n-1;

    ll cn1=0;
    ll cn2=0;

     ll any=0;
    while(i<=j)
    {
       if(s[i]!=s[j]&& s[i]!='?' && s[j]!='?') return "-1";
       if(s[i]==s[j] && s[i]!='?')
       {
          i++;
          j--;
          continue;
       }    
       if(s[i]==s[j] && s[i]=='?')
       {
           any+=2;
           if(i==j)
           {
             any--;
           }
           i++;
           j--;
           continue;
       }

       // 
       if(s[i]=='?')
       {
        s[i]=s[j];
       }
       else
       {
         s[i]=s[j];
       }
       i++;
       j--;
    }

    for(char ch:s)
    {
        a-=(ch=='0');
        b-=(ch=='1');
    }

    if(a<0 || b<0 ) return "-1";

    i=0;
    j=n-1;
    while(i<=j)
    {
          if(s[i]==s[j] && s[i]=='?')
          {
              if(i==j)
              {
                 if(a%2==1 && a>=0)
                 {
                    s[i]='0';
                    a--;
                 }
                 else if(b%2==1 && b>=0)
                 {
                     s[i]='1';
                     b--;
                 }
                 else
                 {
                    return "-1";
                 }
                 
              } 
              else
              {

                if(a>=b)
                {
                   s[i]='0';
                   s[j]='0';
                   a=-2;
                }
                else
                {
                    s[j]='1';
                    s[i]='1';
                     b-=2;
                }

              }
          }
          i++;
                 j--;
    }

    for(char ch:s)
    {
        a1-=(ch=='0');
        b1-=(ch=='1');
    }
    if(a1==0 && b1==0) return s;
    return "-1";
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