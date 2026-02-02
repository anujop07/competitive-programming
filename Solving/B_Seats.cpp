// Author: anuj (improved)
// Problem: largest k such that array can be sorted by swapping pairs with |ai-aj| >= k
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b;
        for (int i = 0; i < n; ++i) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());
        if (a == b) {
            cout << -1 << '\n';
            continue;
        }
        ll mn = *min_element(a.begin(), a.end());
        ll mx = *max_element(a.begin(), a.end());
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ll cand = max(a[i] - mn, mx - a[i]);
                ans = min(ans, cand);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
