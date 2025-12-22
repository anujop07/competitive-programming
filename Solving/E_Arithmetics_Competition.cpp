// // Author: anuj
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define ll long long

// // ---------- PBDS ----------
// template <typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// // ---------- Debug ----------
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr<<#x<<" "; _print(x); cerr<<"\n";
// #else
// #define debug(x)
// #endif

// // Primitive types
// template<typename T> void _print(T t){cerr<<t;}
// template<> void _print<string>(string t){cerr<<'"'<<t<<'"';}
// template<typename T,typename V> void _print(pair<T,V> p){cerr<<"{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
// template<typename T> void _print(vector<T> v){cerr<<"[ "; for(T i:v){_print(i); cerr<<" ";} cerr<<"]";}
// template<typename T> void _print(set<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
// template<typename T> void _print(multiset<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
// template<typename K, typename V> void _print(map<K,V> m){cerr<<"{ "; for(auto i:m){_print(i); cerr<<" ";} cerr<<"}";}
// template<typename T> void _print(vector<vector<T>> v){
//     cerr<<"[\n";
//     for(auto &row:v){ cerr<<"  [ "; for(auto &x:row){ _print(x); cerr<<" "; } cerr<<"]\n"; }
//     cerr<<"]";
// }

// // ---------- Utility Functions ----------
// template<typename T> void sort(vector<T>& a){sort(a.begin(),a.end());}
// template<typename T> void rsort(vector<T>& a){sort(a.rbegin(),a.rend());}
// template<> void sort<string>(vector<string>& a){sort(a.begin(),a.end());}
// template<typename T> T summ(const vector<T>& a){return accumulate(a.begin(),a.end(),T(0));}
// template<typename T> void in(vector<T>& a){for(auto &i:a){cin>>i;}}

// // ===================================================
// // =================== SOLVE FUNCTION =================
// // ===================================================
// vector<ll> getpre(vector<ll>arr)
// {
//     ll sum=0;
//     for(int i=0;i<arr.size();i++)
//     {
//         sum+=arr[i];
//         arr[i]=sum;

//     }
//     return arr;
// }

// ll solve(ll x,ll y,ll z,vector<ll>&arr1,vector<ll>&brr)
// {
//      // x frm 
//      ll mini=max(0LL,z-y);
//      ll maxi=min(x,z);

//      int endidx=max(0LL,min(y,z)-1);

//      ll s=max(1LL,mini);
//      ll e=maxi;

//      // how many ele should i take
//      ll ans=mini;


//      debug(mini);
//      debug(maxi);
//      while(s<=e)
//      {
//         ll mid=(s+e)/2;

//         debug(mid);
//         // mid from first one like
//         // 
//         ll firstsum=arr1[mid-1];
//         ll skipfrombrr=mid;
//         // debug(endidx);
//         ll secondsum=brr[endidx];
//         debug(secondsum);
//         int j=endidx-skipfrombrr;
//         // debug(j);
//         if(j>=0)
//         {
//             secondsum-=brr[j];
//         }

//         debug(firstsum);
//         debug(secondsum);
//         if(firstsum>secondsum)
//         {
//             ans=mid;
//             s=mid+1;
//         }
//         else
//         {
//             e=mid-1;
//         }


//      }

//      debug(ans);

//      // ans how many i have taken from the arr1
//      // then ans
//      ll res=0;
//      if(ans-1>=0)
//      {
//         res+=arr1[ans-1];
//      }

//      ll fromy=z-ans;

//      if(fromy-1>=0)
//      {
//         res+=brr[fromy-1];
//      }

//      return res;
// }
// void solve1(){
//     ll n;
//     cin >> n;
  
//     ll m;
//     cin>>m;

//     ll q;
//     cin>>q;

//     vector<ll> arr(n);
//     in(arr);

//     vector<ll>brr(m);
//     in(brr);

//     sort(arr);
//     sort(brr);

//     // for(int i=0;i<n;i++)
//     // {
//     //     arr[i]=arr[i]/100000000;
//     //     brr[i]=brr[i]/100000000;
//     // }
   

//     vector<ll>prearrS=getpre(arr);
//     vector<ll>prebrrS=getpre(brr);
//     rsort(arr);
//     rsort(brr);
//     vector<ll>prearr=getpre(arr);
//     vector<ll>prebrr=getpre(brr);
//   debug(arr);
//     debug(brr);
//     debug(prearr);
//     debug(prebrr);

    
//     while(q--)
//     {
//         ll x,y,z;
//         cin>>x>>y>>z;

//         ll currans=0;
//         if(x<=y)
//         {
//            currans=solve(x,y,z,prearr,prebrr);
//         }
//         else
//         {
//             currans=solve(y,x,z,prebrr,prearr);
//         }

//         cout<<currans<<endl;

//     }



   

//     // return 0;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     cin >> t;
//     while(t--){
//         solve1();
//     }
//     return 0;
// }

// when u realize this not biary seactr on anser 
// Author: anuj
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

template<typename T> void _print(T t){ cerr<<t; }
template<> void _print<string>(string t){ cerr<<'"'<<t<<'"'; }
template<typename T,typename V> void _print(pair<T,V> p)
{
    cerr<<"{"; _print(p.first); cerr<<","; _print(p.second); cerr<<"}";
}
template<typename T> void _print(vector<T> v)
{
    cerr<<"[ ";
    for(T i:v)
    {
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}
template<typename T> void _print(set<T> s)
{
    cerr<<"{ ";
    for(T i:s)
    {
        _print(i);
        cerr<<" ";
    }
    cerr<<"}";
}
template<typename T> void _print(multiset<T> s)
{
    cerr<<"{ ";
    for(T i:s)
    {
        _print(i);
        cerr<<" ";
    }
    cerr<<"}";
}
template<typename K,typename V> void _print(map<K,V> m)
{
    cerr<<"{ ";
    for(auto i:m)
    {
        _print(i);
        cerr<<" ";
    }
    cerr<<"}";
}
template<typename T> void _print(vector<vector<T>> v)
{
    cerr<<"["<<endl;
    for(auto &row:v)
    {
        cerr<<"  [ ";
        for(auto &x:row)
        {
            _print(x);
            cerr<<" ";
        }
        cerr<<"]"<<endl;
    }
    cerr<<"]";
}

template<typename T> void in(vector<T>& a)
{
    for(auto &i:a)
    {
        cin>>i;
    }
}

// ===================================================
// =================== SOLVE FUNCTION =================
// ===================================================

void solve1()
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<ll>a(n),b(m);
    in(a);
    in(b);

    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());

    vector<ll>pa(n+1),pb(m+1);
    for(int i=0;i<n;i++)
    {
        pa[i+1]=pa[i]+a[i];
    }
    for(int i=0;i<m;i++)
    {
        pb[i+1]=pb[i]+b[i];
    }

    vector<pair<int,int>> best(n+m+1);
    int l=0,r=0;

    for(int z=1;z<=n+m;z++)
    {
        if(l<n && r<m)
        {
            if(a[l]<b[r])
            {
                r++;
            }
            else
            {
                l++;
            }
        }
        else if(l==n)
        {
            r++;
        }
        else
        {
            l++;
        }
        best[z]={l,r};
    }

    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;

        int xz=best[z].first;
        int yz=best[z].second;

        if(xz>x)
        {
            cout<<pa[x]+pb[z-x]<<endl;
        }
        else if(yz>y)
        {
            cout<<pa[z-y]+pb[y]<<endl;
        }
        else
        {
            cout<<pa[xz]+pb[yz]<<endl;
        }`
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        solve1();
    }
    return 0;
}
