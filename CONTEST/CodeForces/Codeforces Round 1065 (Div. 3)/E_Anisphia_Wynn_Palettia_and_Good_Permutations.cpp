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
  
    map<ll,vector<ll>>mp;
    
    set<int>st;

    for(ll ele=2;ele<=n;ele++)
    {
        
        if(!st.count(ele))
        {
            ll curr=ele;
            ll cn=1;
            ll val=curr;

            while(val<=n)
            {
                if(!st.count(val))
               {
                   mp[curr].push_back(val);
               }
               st.insert(val);
               
             
               cn++;
               val=curr*cn;
            }

    
        }
    }

    vector<ll>single;
    single.push_back(1);
    
    vector<vector<ll>>arr;
    for(auto it:mp)
    {
        if(it.second.size()==1)
        {
            single.push_back(it.first);
        }
        else
        {
           arr.push_back(it.second);
        }
    }

   for(auto it:arr)
   {
    debug(it);
   }
    vector<int>ans(n,1);

 
    map<int,int>idx;

    int i=0;
    int j=0;
    int ansidx=0;
    int id=0;

    debug(single);
    
    
   for(int i=0;i<arr.size();i++) idx[i]=0;
    while(ansidx < n)                  
    { 
        if(i<single.size())             
        { 
            ans[ansidx]=single[i];
            ansidx++;                    
            i++;
        }
        
       
        if(j>=arr.size()) continue;

        int ineridx=idx[j];
        int left=arr[j].size()-ineridx;

        if(left<=3)
        {
            while(ineridx<arr[j].size() && ansidx < n)
            {
                ans[ansidx]=arr[j][ineridx];
                ineridx++;
                ansidx++;               
            }
            j++;
        
        }
        else
        {
           
               ans[ansidx]=arr[j][ineridx];
               ineridx++;
               ansidx++;                
          
               ans[ansidx]=arr[j][ineridx];
               ineridx++;
               ansidx++;                
        
               idx[j]=ineridx;
        }
        debug(ans);

    }
    
    debug(ans);
 
    for(int it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
         cout<<ans[i]-1<<endl;
    }

    if(true)
    {
        debug("THIS IS TH ");
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

    int t;
    cin >> t;
    while(t--){
        solve1();
    }
    return 0;
}