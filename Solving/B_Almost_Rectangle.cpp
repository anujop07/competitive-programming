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
void show(vector<string>&arr)
{
    for(auto it:arr)
    {
        cout<<it<<endl;
    }
}

void solve(vector<vector<int>>&vis,int x,int y)
{
     int x1=x;
     int y1=y;
     int n=vis.size();
     while(x1<n)
     {
        vis[x1][y1]++;
        x1++;
     }
     x1=x;

     while(x1>=0)
     {
        vis[x1][y1]++;
        x1--;
     }

     x1=x;
     while(y1<n)
     {
        vis[x1][y1]++;
        y1++;
     }
     y1=y;

     while(y1>=0)
     {
        vis[x1][y1]++;
        y1--;
     }


}
void solve1(){
    int n;
    cin >> n;
    vector<string> arr(n);
    in(arr);
   
    int x1,y1,x2,y2;

    x1=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]=='*')
            { 
                if(x1==-1)
                {
                    x1=i;
                    y1=j;
                }  
                else
                {
                    x2=i;
                    y2=j;
                }
            }
        }
    }
    // same 
    if(x1==x2)
    {
        if(x1-1>=0)
        {
            arr[x1-1][y1]='*';
            arr[x1-1][y2]='*';
        }
        else
        {
             arr[x1+1][y1]='*';
            arr[x1+1][y2]='*';
        }
        show(arr);
        return;
    }
     if(y1==y2)
    {
        if(y1-1>=0)
        {
            arr[x1][y1-1]='*';
            arr[x2][y1-1]='*';
        }
        else
        {
             arr[x1][y1+1]='*';
            arr[x2][y2+1]='*';
        }
        show(arr);
        return ;
    }

    vector<vector<int>>vis(n,vector<int>(n,0));

    solve(vis,x1,y1);
    solve(vis,x2,y2);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j]==2)
            {
                cout<<"*";
            }
            else
            {
                cout<<arr[i][j];
            }
        }
        cout<<endl;
    }
    // 
    return ;
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