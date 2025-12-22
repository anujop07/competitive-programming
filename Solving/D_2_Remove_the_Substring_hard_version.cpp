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
  
    string s;
    cin>>s;

    string t;
    cin>>t;


    vector<int>pre;
    vector<int>suf;

    int i=0;
    int j=0;

    while(i<s.size() && j<t.size())
    {
        if(s[i]==t[j])
        {
            pre.push_back(i);
            j++;
        }
        i++;
        
    }


    i=s.size()-1;
    j=t.size()-1;

    while(i>=0 && j>=0)
    {
        if(s[i]==t[j])
        {
            suf.push_back(i);
            j--;
            
        }
        i--;
    }


    //
    ll ans=0;
    i=0;
    j=0;
    while(i<s.size() && j<t.size())
    {
        if(s[i]==t[j])
        {
            int rem=t.size()-(j+1);
            if(rem==0)
            {
                ans=max(ans,(ll)s.size()-i-1);
            }
            else
            {
                ans=max(ans,(ll)i-suf[rem-1]);
            }
            j++;
        }
        i++;
        
    }

    i=s.size()-1;
    j=t.size()-1;

    while(i>=0 && j>=0)
    {
        if(s[i]==t[j])
        {
            int rem=j;
            if(rem==0)
            {
                ans=max(ans,(ll)i);
            }
            else 
            {
                ans=max(ans,i-(ll)pre[rem-1]-1);
            }
            j--;
            
        }
        i--;
    }

    return ans;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

   cout<<solve1()<<endl;
    return 0;
}