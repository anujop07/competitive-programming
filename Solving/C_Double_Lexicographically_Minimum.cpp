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
   
    string s;
    cin>>s;

    ll n=s.size();

    string ans="";
    for(int i=0;i<n;i++) ans.push_back('-');

    int i=0;
    int j=n-1;
    char prev='-';
    map<char,int>mp;

    for(char ch:s) mp[ch]++;
    
    char curr='a';
    // debug(mp);
    while(i<j)
    {
        if(mp[curr]==0)
        {
            curr++;
            continue;
        }
        // here 
        if(mp[curr]%2==0)
        {
            while(mp[curr]>0)
            {
                ans[i]=curr;
                ans[j]=curr;
                i++;
                j--;
                mp[curr]-=2;
            }
            // curr++;
        }
        else
        {
            if(prev=='-')
            {
                 prev=curr;
                 bool f=0;
                 while(mp[curr]>1)
                 {
                    if(f)
                    {
                        ans[i]=curr;
                        i++;
                    }
                    else
                    {
                        ans[j]=curr;
                        j--;
                    }
                    f=!f;
                    mp[curr]--;
                   
                 }
                //  curr++;
            }
            else
            {
                // place first 
                bool f=0;
                 while(mp[curr]>1)
                 {
                    if(f)
                    {
                        ans[i]=curr;
                        i++;
                    }
                    else
                    {
                        ans[j]=curr;
                        j--;
                    }
                    f=!f;
                    mp[curr]--;
                   
                 }

                 // place 
                 ans[i]=prev;
                 ans[j]=curr;
                 mp[curr]=0;
                 mp[prev]=0;    
                 i++;
                 j--;
                 prev='-';

            }

        }
        debug(ans);
        debug(i);
        debug(j);
        curr++;
         
    }

    // plcase remaing one
    char rem='-';
    for(auto it:mp)
    {
        if(it.second)
        {
            rem=it.first;
        }
    }
    // debug(rem);
    for(char &ch:ans)
    {
        if(ch=='-')
        {
            ch=rem;
        }
    }
    debug(ans);
    cout<<ans<<endl;
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        // cout<<"CALLED"<<endl;
       solve1();
    }
    return 0;
}