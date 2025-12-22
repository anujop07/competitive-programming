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
    int n;
    cin >> n;

    ll c;
    cin>>c;

    // not able to prove that lets see how it gpe
    vector<ll> arr(n+1);
    
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    //
    ll curj=-1;
    vector<ll>pre(n+1,0);
    pre[1]=arr[1];
    for(ll i=2;i<=n;i++)
    {
        pre[i]=arr[i]+pre[i-1];
         if(arr[1]+arr[i]>=i*c)
         {
            curj=i;   
         }
    }
    if(curj==-1)
    {
        return false;
    }

    // take some upto the here 

    ll cursum=pre[curj];

    // greedy go next here like
    ll prevj=curj;
    curj++;
    while(curj<=n)
    {
        if(cursum+arr[curj]>=curj*c)
        {
           cursum=pre[curj];
           prevj=curj;
        }
        curj++;
    }

    return prevj==n;


    return true;
    // TODO: implement solution here

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
       if(solve1())
       {
        cout<<"YES"<<endl;
       }
       else
       {
        cout<<"NO"<<endl;
       }
    }
    return 0;
}