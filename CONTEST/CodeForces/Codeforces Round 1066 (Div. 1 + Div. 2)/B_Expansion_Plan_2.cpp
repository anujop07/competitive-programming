// Author: anuj
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll solve1(){
    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    string s;
    cin >> s;

    ll curx = 0, cury = 0;
    int i = 0;


    ll cn=0;
    ll both=0;
    for(char ch:s)
    {
        if(ch=='4')
        {
            cn++;
        }
        else
        {
            both++;
        }
    }

    x=abs(x);
    y=abs(y);

    x-=min(x,both);
    y-=min(y,both);

    if(x<=0 && y<=0) return true;


    ll minus=min(x,cn);
    x-=minus;
    cn-=minus;

    minus=min(y,cn);
    y-=minus;
    cn-=minus;

   if(x<=0 && y<=0) return true;
    return false;



    // while(i < s.size())
    // {
    //     if(curx==x && cury==y) return true;
        
    //     if(s[i] == '4')
    //     {
    //         if(curx < x) curx++;
    //         else if(curx > x) curx--;
    //         else if(cury < y) cury++;
    //         else if(cury > y) cury--;
    //     }
    //     else
    //     {
    //         if(curx<x) curx++;
    //         if(curx>x) curx--;
    //         if(cury<y) cury++;
    //         if(cury>y) cury--;
    //     }
    //     i++;
    // }

    if(curx==x && cury==y) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        if(solve1()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
