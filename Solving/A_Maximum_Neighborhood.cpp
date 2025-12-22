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

template<typename T> void _print(T t){cerr<<t;}
template<> void _print<string>(string t){cerr<<'"'<<t<<'"';}

// ===================================================
// =================== SOLVE FUNCTION =================
// ===================================================
ll solve1()
{
    int n;
    cin >> n;

    vector<vector<ll>> arr(n, vector<ll>(n));

    ll cn = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cn;
            cn++;
        }
    }

    ll ans = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ll cost = arr[i][j];

            for(int k = 0; k < 4; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni >= 0 && ni < n && nj >= 0 && nj < n)
                {
                    cost += arr[ni][nj];
                }
            }

            ans = max(ans, cost);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cout << solve1() << endl;
    }

    return 0;
}
