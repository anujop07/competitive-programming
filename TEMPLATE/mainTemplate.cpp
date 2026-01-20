// --------- Lazy Segment Tree (Range Add, Range Sum Query) ---------
struct LazySegTree {
    int n;
    vector<ll> seg, lazy;

    LazySegTree(int n){
        this->n = n;
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void build(vector<ll>& a, int idx, int l, int r){
        if(l == r){ seg[idx] = a[l]; return; }
        int mid = (l + r) / 2;
        build(a, idx*2+1, l, mid);
        build(a, idx*2+2, mid+1, r);
        seg[idx] = seg[idx*2+1] + seg[idx*2+2];
    }

    void push(int idx, int l, int r){
        if(lazy[idx] != 0){
            seg[idx] += (r - l + 1) * lazy[idx];
            if(l != r){
                lazy[idx*2+1] += lazy[idx];
                lazy[idx*2+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, ll val){
        push(idx, l, r);
        if(r < ql || l > qr) return;
        if(ql <= l && r <= qr){
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(idx*2+1, l, mid, ql, qr, val);
        update(idx*2+2, mid+1, r, ql, qr, val);
        seg[idx] = seg[idx*2+1] + seg[idx*2+2];
    }

    ll query(int idx, int l, int r, int ql, int qr){
        push(idx, l, r);
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        return query(idx*2+1, l, mid, ql, qr) +
               query(idx*2+2, mid+1, r, ql, qr);
    }
};
// Usage:
// LazySegTree seg(n);
// seg.build(arr, 0, 0, n-1);
// seg.update(0,0,n-1,l,r,val);
// ll ans = seg.query(0,0,n-1,l,r);