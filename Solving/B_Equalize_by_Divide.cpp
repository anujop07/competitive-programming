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
    vector<ll> arr(n);
    in(arr);

    vector<pair<ll,ll>>nums;
    for(int i=0;i<n;i++)
   {
     nums.push_back({arr[i],i});
   }
   sort(arr);
   if(arr[0]==arr[n-1])
   {
     cout<<0<<endl;
     return ;
   }
   
   if(arr[0]==1)
   {
     cout<<-1<<endl;
     return;
   }

   sort(nums);

   // if all one and one non
   

   // can we create at east ome tqo hre
   // last wale ko 2
   int i=0;
   while(nums[i].first==1) i++;

   ll ele=nums[i].first;

   int idx=nums[i].second+1;
   vector<pair<ll,ll>>ans;
   debug(ele);
  
   while(true)
   {
        for(int i=0;i<n;i++)
    {
        while(nums[i].first>ele)
        {
            ans.push_back({nums[i].second+1,idx});
            nums[i].first=(nums[i].first+ele-1)/ele;
            // arr[nums[i].first]=nums[i].first;
        }
    }
    debug(nums);
    set<int>st;
      for(int i=0;i<n;i++)
      {
         if(ele>nums[i].first)
         {
            ele=nums[i].first;
            idx=nums[i].second+1;
         }
          st.insert(nums[i].first);
      }
      if(st.size()==1) break;
   }

   cout<<ans.size()<<endl;

   for(int i=0;i<ans.size();i++)
   {
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
   }
   // if all wual then om

   debug(nums);
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