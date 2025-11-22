// Author: anuj
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<"\n";
#else
#define debug(x)
#endif

template<typename T> void _print(T t){cerr<<t;}
template<> void _print<string>(string t){cerr<<'"'<<t<<'"';}
template<typename T,typename V> void _print(pair<T,V> p){cerr<<"{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
template<typename T> void _print(vector<T> v){cerr<<"[ "; for(T i:v){_print(i); cerr<<" ";} cerr<<"]";}
template<typename T> void _print(set<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(multiset<T> s){cerr<<"{ "; for(T i:s){_print(i); cerr<<" ";} cerr<<"}";}
template<typename K, typename V> void _print(map<K,V> m){cerr<<"{ "; for(auto i:m){_print(i); cerr<<" ";} cerr<<"}";}
template<typename T> void _print(vector<vector<T>> v)
{
    cerr<<"[\n";
    for(auto &row:v)
    {
        cerr<<"  [ ";
        for(auto &x:row)
        {
            _print(x);
            cerr<<" ";
        }
        cerr<<"]\n";
    }
    cerr<<"]";
}

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
vector<vector<int>> cycles;

int findInPath(int v)
{
    for(int i = path.size() - 1; i >= 0; i--)
    {
        if(path[i] == v) return i;
    }
    return -1;
}

void dfs(int u, int parent)
{
    visited[u] = true;
    path.push_back(u);

    for(int v : adj[u])
    {
        if(v == parent) continue;

        if(!visited[v])
        {
            dfs(v, u);
        }
        else
        {
            int idx = findInPath(v);
            if(idx != -1)
            {
                vector<int> cycle;
                for(int i = idx; i < path.size(); i++)
                {
                    cycle.push_back(path[i]);
                }
                cycles.push_back(cycle);
            }
        }
    }

    path.pop_back();
}

vector<int> bfs(int src, int n)
{
    const int INF = 1e9;
    vector<int> dist(n+1, INF);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

ll solve1()
{
    int n;
    cin >> n;

    ll a, b;
    cin >> a >> b;

    adj.assign(n+1, {});
    visited.assign(n+1, false);
    cycles.clear();
    path.clear();

    for(int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u >= 1 && u <= n) adj[u].push_back(v);
        if(v >= 1 && v <= n) adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i, -1);
        }
    }

    set<int> st;

    for(auto &cy : cycles)
    {
        if(cy.size() >= 3)
        {
            for(int node : cy)
            {
                st.insert(node);
            }
        }
    }

    vector<int> distA = bfs((int)a, n);
    vector<int> distB = bfs((int)b, n);

    for(int node : st)
    {
        if(distB[node] < distA[node])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        if(solve1()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
