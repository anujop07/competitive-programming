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
ll isok(ll sum, ll ele,ll rem)
{
    // ele--;
    ll leftsum=sum-ele;
    rem--;
    if(leftsum>=(rem*(rem+1))/2) return true;
    
    return false;
}
void solve1(){
   ll n,l,r,s;
   cin>>n>>l>>r>>s;
   set<ll>st;
   ll rem=r-l+1;

   vector<ll>ans;
   ll cn=n;
   while(rem>0 && cn>0)
   {
       while(cn>0 &&!isok(s,cn,rem))
       {
           cn--;
       }
       debug(cn);
       if(cn>0)
       {
        ans.push_back(cn);
        rem--;
        st.insert(cn);
        s-=cn;
        cn--;
       }
       debug(s);
   }

   ll sum=summ(ans);
   vector<int>arr2;
   for(int i=1;i<=n;i++)
   {
       if(!st.count(i))
       {
         arr2.push_back(i);
       }
   }
   int i1=0;
   int i2=0;
   if(s==0 && ans.size()==r-l+1)
   {
      for(int i=1;i<=n;i++)
      {
        if(i>=l && i<=r)
        {
            cout<<ans[i-l]<<" ";
        }
        else
        {
            cout<<arr2[i1]<<" ";    
            i1++;
        }
      }
      cout<<endl;
      return ;
   }
   cout<<-1<<endl;
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