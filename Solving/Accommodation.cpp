// Author: anuj
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve1()
{
    ll B, G, X, Y, N;
    cin >> B >> G >> X >> Y >> N;

    // Each room needs at least X+Y people
    if (X + Y > N)
        return -1;

    // Minimum rooms by capacity
    ll LB = (B + G + N - 1) / N;   // ceil((B+G)/N)

    // Maximum rooms by minimum requirement
    ll UB = min(B / X, G / Y);

    if (LB <= UB)
        return LB;
    else
        return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cout << solve1() << "\n";
    }

    return 0;
}

