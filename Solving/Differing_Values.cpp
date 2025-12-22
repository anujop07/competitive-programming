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
    
    ll k;
    cin>>k;

    ll one=0;

    string s;
    cin>>s;

    for(char ch:s)
    {
        if(ch=='1')
        {
            one++;
        }
    }

    ll zero=n-one;
    
    ll odd=0;
    ll even=0;
    vector<int>vis(n,0);

    // if(zero>one) swap(one,zero);
    for(int i=0;i<n-k;i++)
    {
        if(vis[i]==1) continue;
        int j=i;
        ll cn=0;
        while(j<n)
        {
            vis[j]=1;
            cn++;
            j+=k;
        }


        debug(cn);
        if(cn%2==0)
        {
            if(cn/2>min(zero,one)) return false;

            zero-=cn/2;
            one-=cn/2;
        }
        else
        {
            // take max one from
            ll req1=(cn+1)/2;
            ll req2=cn/2;
            if(one>=zero)
            {
                one-=req1;
            zero-=req2;
            }
            else
            {
                
                zero-=req1;
               one-=req2;
            }
            

            if(one<0 || zero<0) return false;

        }
    }

    
    return true;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
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