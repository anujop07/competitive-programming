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
   ll n,m,k;
   cin>>n>>m>>k;

   vector<ll>arr(n);
   vector<ll>spike(m);
   in(arr);
   in(spike);


   string s;
   cin>>s;
 
  
   ll cur=0;

   vector<ll>leftmax(s.size(),0);
   vector<ll>rightmax(s.size(),0);

   for(int i=0;i<k;i++)
   {
       char ch=s[i];
       if(ch=='L')
       {
          cur--;
       }
       else
       {
          cur++;
       }
       leftmax[i]=max(0LL,-cur);
       rightmax[i]=max(0LL,cur);
       
       if(i>0)
       {
           leftmax[i]=max(leftmax[i],leftmax[i-1]);
           rightmax[i]=max(rightmax[i],rightmax[i-1]);
       }
   }
   // from each robot closese here like spike

   vector<ll>diff(k+4,0);

   sort(spike);
   for(int i=0;i<n;i++)
   {
        int ri=upper_bound(spike.begin(),spike.end(),arr[i])-spike.begin();
        ll rclose=LONG_MAX;
        ll lclose=LONG_LONG_MAX;

        int li=ri-1;

        if(ri<spike.size())
        {
            rclose=spike[ri]-arr[i];
        }
        if(li>=0)
        {
            lclose=arr[i]-spike[li];
        }

        // to reach it 
        ll s1=1;
        ll e=k;
        ll ans=-1;
        while(s1<=e)
        {
            ll mid=(s1+e)/2;
            if(lclose<=leftmax[mid-1] || rclose<=rightmax[mid-1] )
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s1=mid+1;
            }
        }
        debug(i);
        debug(ans);
        debug(lclose);
        debug(rclose);
        // debug

        if(ans==-1)
        {
            diff[1]++;
            diff[k+1]--;
        }
        else
        {
            // he die at mid
            diff[1]++;
            diff[ans]--;
        }
   }
   debug(leftmax);
   debug(rightmax);

   ll sum=0;
   for(int i=1;i<=k;i++)
   {
       sum+=diff[i];
       cout<<sum<<" ";
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