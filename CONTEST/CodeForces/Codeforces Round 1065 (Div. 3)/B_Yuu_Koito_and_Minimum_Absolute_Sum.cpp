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
ll cal(vector<ll>&arr)
{
     ll ans=0;
    ll prevPick=-1;
    for(int i=0;i<arr.size();i++)
    {
        if(prevPick==-1 && arr[i]!=-1)
        {
            prevPick=arr[i];
            continue;
        }
        if(arr[i]==-1)
        {
            continue;
        }

        ans+=(arr[i]-prevPick);
        prevPick=arr[i];
    }
    return ans;
}
void solve1(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    in(arr);


    for(int i=1;i<n-1;i++)
    {
        if(arr[i]==-1) arr[i]=0;
    }
    // procees ans 

    debug(arr);
    ll ans=cal(arr);
    debug(ans);
    if(arr[n-1]!=-1 && arr[0]!=-1)
    {
        cout<<abs(ans)<<endl;
        for(int it:arr)
        {
          cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    // last has arr[n-1]==-1

    if(arr[n-1]==-1)
    {
        if(arr[0]==-1) arr[0]=0;
        ans=cal(arr);

        debug(ans);
        arr[n-1]=arr[n-2]-ans;
        cout<<0<<endl;
        for(int it:arr)
        {
            cout<<it<<" ";

        }
        cout<<endl;
        return ;
    }

    ans=cal(arr);
    arr[0]=ans+arr[1];
    cout<<0<<endl;
    
        for(int it:arr)
        {
            cout<<it<<" ";

        }
        cout<<endl;


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