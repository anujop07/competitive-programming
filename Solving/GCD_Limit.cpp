#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int MOD = 998244353;

int64 modpow(int64 a, int64 e=MOD-2){
    int64 r=1;
    while(e){
        if(e&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    vector<int> Ms(T);
    int maxM = 0;
    for(int i=0;i<T;i++){
        cin>>Ms[i];
        maxM = max(maxM, Ms[i]);
    }

    int N = maxM;
    // Precompute divisors for all n <= N
    vector<vector<int>> divisors(N+1);
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i) divisors[j].push_back(i);
    }

    // Compute Möbius mu up to N using linear sieve
    vector<int> primes;
    vector<int> mind(N+1,0);
    vector<int> mu(N+1,0);
    mu[1]=1;
    for(int i=2;i<=N;i++){
        if(!mind[i]){
            mind[i]=i;
            primes.push_back(i);
        }
        for(int p:primes){
            int64 v = 1LL*p*i;
            if(v> N) break;
            mind[v]=p;
            if(i%p==0) break;
        }
    }
    // Compute mu via prime factorization (fast enough for N<=2e5)
    for(int i=1;i<=N;i++){
        int x=i;
        int cnt=0;
        bool square_free=true;
        for(int p:primes){
            if(1LL*p*p > x) break;
            if(x%p==0){
                cnt++;
                x/=p;
                if(x%p==0){ square_free=false; break; }
            }
        }
        if(!square_free){ mu[i]=0; continue; }
        if(x>1) cnt++;
        mu[i] = (square_free ? ( (cnt%2)? -1 : 1 ) : 0);
    }
    mu[1]=1;

    // Precompute divisors list for all possible H is already divisors[H]
    
    // Process each test case separately
    for(int tc=0; tc<T; ++tc){
        int M = Ms[tc];
        int64 invM = modpow(M);

        // pvals[h] aligns with divisors[h]: p_h(t) = pvals[h][idx]
        vector<vector<int>> pvals(M+1);
        pvals[0] = {};
        for(int h=1; h<=M; ++h){
            pvals[h].reserve(divisors[h].size());
            for(int t: divisors[h]){
                int H = h / t;
                int K = M / t;
                // count numbers <= K coprime to H = sum_{d | H} mu[d] * floor(K/d)
                int64 cnt = 0;
                for(int d: divisors[H]){
                    if(mu[d]==0) continue;
                    cnt += (int64)mu[d] * (K / d);
                }
                cnt %= MOD;
                if(cnt<0) cnt += MOD;
                int64 pmod = (cnt * invM) % MOD;
                pvals[h].push_back((int)pmod);
            }
        }

        // Now compute r(h,d) for each d and accumulate result
        int64 total = 0; // will be in mod
        // We'll use local arrays for r per d
        for(int d=1; d<=M; ++d){
            int maxk = M / d;
            if(maxk <= 1) continue; // no g> d
            // rvals indexed by k (1..maxk) where h = k*d
            vector<int64> rvals(maxk+1, 0);
            rvals[1] = 1; // r(d,d) = 1
            // For k = 2..maxk compute r(k*d, d)
            for(int k=2; k<=maxk; ++k){
                int h = k * d;
                // Find p_h(h) and denom = 1 - p_h(h)
                // pvals[h] aligned with divisors[h] (which are sorted ascending)
                // divisors[h].back() == h
                int64 p_h_h = pvals[h].back(); // last divisor is h
                int64 denom = (1 - p_h_h) % MOD;
                if(denom < 0) denom += MOD;
                int64 denom_inv = modpow(denom);

                // sum over t | h, with t >= d and t < h, and t % d == 0
                int64 sum = 0;
                auto &divs = divisors[h];
                auto &ps = pvals[h];
                int sz = (int)divs.size();
                for(int idx=0; idx<sz; ++idx){
                    int t = divs[idx];
                    if(t < d) continue;
                    if(t == h) continue;
                    if(t % d != 0) continue;
                    int kt = t / d;
                    sum += (int64)ps[idx] * rvals[kt];
                    if(sum >= (1LL<<62)) sum %= MOD;
                }
                sum %= MOD;
                rvals[k] = (sum * denom_inv) % MOD;
            }
            // accumulate contributions for k=2..maxk
            for(int k=2; k<=maxk; ++k){
                total += rvals[k];
                if(total >= MOD) total -= MOD;
            }
        }

        // final expected value = (1/M) * total
        int64 ans = (total % MOD) * invM % MOD;
        cout << ans << '\n';
    }

    return 0;
}
