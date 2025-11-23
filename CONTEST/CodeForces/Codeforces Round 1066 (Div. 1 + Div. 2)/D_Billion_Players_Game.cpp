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
ll solve(vector<ll>&nums,ll ele)
{
    ll ans=0;
    for(ll it:nums) ans+=(abs(it-ele));
    return ans;
}
ll solve1(){
    int n;
    cin >> n;
    ll left,right;
    cin>>left>>right;

    vector<ll>arr(n);
    in(arr);
    sort(arr);
  
    ll mid=(arr[n/2]);

    if(left>mid) mid=left;
    if(mid>right) mid=right;

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(arr[i]-mid);
    }

    return ans;

//    vector<ll>nums(n);
//    in(nums);
// //    ll ans=0;
//    ll cn=0;
//    ll sum=0;

//    debug(nums);

//    vector<ll>arr;
//    ll g=0;
//    for(ll it:nums)
//    {
//     if(it<=l || it>=r)
//     {
//         cn++;
//         sum+=it;
//     }
//     else
//     {
//         arr.push_back(it);
//     }
//    }

  
//       ll ans=solve(nums,l);
//       ans=min(ans,solve(nums,r));
      
//       if(arr.size()==0) return ans;
   
//    // here is the main here 

//    // here 
// //    debug(arr);
//    sort(arr.begin(),arr.end());

//    // some here are the
    
//    n=arr.size();
//    vector<ll>pre(n);
//    ll curr=0;
//    for(int i=0;i<arr.size();i++)
//    {
//        curr+=arr[i];
//        pre[i]=curr;
//    }

// //    debug(pre);
//    debug(arr);
//    debug(nums);

//     // n=arr.size();

//     // ans=0;

 
//     // ll ok=pre[n-1];

//     // ll L=abs(sum-cn*l);
//     // debug(sum);
//     // debug(cn);
//     // L+=abs(ok-n*l);
//     // ll R=abs(sum-cn*r);
    
//     // R-=abs(ok-n*r);
//     // debug(L);
//     // debug(R);
//     // ans=max(ans,min(L,R));

// //    for(int i=0;i<arr.size();i++)
// //    {
    
// //     //    ll rsum=pre[n-1]-pre[i];
// //     //    ll rcn=n-(i+1);

// //     //    ll lcn=i+1;
// //     //    ll lsum=pre[i];

// //     //    ll leftans=abs(sum-(cn*l));

// //     //    leftans-=abs((lsum)-(i+1)*l);
// //     //    leftans+=abs(rsum-rcn*l);
      
// //     //    ll rightans=abs(sum-(cn*r)); 
// //     //    rightans+=abs(lcn*r-(lsum));
// //     //    rightans-=abs(rcn*r-rsum);
// //     //    ans=max(ans,min(leftans,rightans));

// //     // try for the median i dont know the poroff for it overe here



// //    }
//    debug(arr);
   
//    return max(0LL,ans);
   
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