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
ll solve(string &s ,string &t,ll &k)
{
    vector<ll>freq(k,0);

   int i=0;
   int j=0;
   
   int n=s.size();
   int m=t.size();

   while(i<n && j<m)
   {
      if(s[i]==t[j]) j++;
      i++;
   }
   if(i==n && i==m) return 1;

   if(j<m) return 0;
   // here what we can do 
   // like
   // for(int )
   ll cn=0;
   ll ans=0;
   j=i;
   
   while(j<n)
   {
       if(freq[s[j]-'a']==0)
       {
           cn++;
           freq[s[j]-'a']++;
       }

       if(cn==k)
       {
         // here all charcter had
         // add one charcter and skip that j also here 
         // erase here all freq
         for(ll &it:freq)
         {
             it=0;
         }
         ans++;
         cn=0;

       }
       debug(freq);
       debug(j);
       j++;
   }

   bool g=0;
   for(int it:freq)
   {
      if(it) 
      {
        ans++;
        break;
      }
   }


   return max(1LL,ans);

}
void  solve1()
{
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    ll q;
    cin>>q;

    string temp=s;
    sort(temp.begin(),temp.end());

    while(q--)
    {
        string t;
        cin>>t;

         debug(t);
         ll curr=solve(s,t,k);
        
         cout<<curr<<endl;
        // cout<<<<endl;
    }

    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t=1;
    while(t--){
       solve1();
    }
    return 0;
}