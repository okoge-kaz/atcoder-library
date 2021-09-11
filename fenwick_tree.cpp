#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template <class T> class fenwick_tree {
    // BIT Binary Indexed Treeとして使える オーバーフローの恐れがあるので、AtCoderでは正規のac-libraryを使うこと
    public:
        fenwick_tree() : _n(0) {}
        explicit fenwick_tree(int n) : _n(n), data(n) {}

        void add(int p, T x){
            // p: 0-index
            assert(0 <= p && p < _n) // アクセスが不正な場合と範囲外アクセス
            p++;
            while(p <= _n){
                data[p-1] += x;
                p += p & -p;
            }
        }

        T sum(int l, int r){
            // [l,r): 0-index
            assert(0 <= l && l <= r && r <= n);
            return sum(r) - sum(l);
        }
    private:
        int _n;
        vector<T> data;

        T sum(int r){
            T s = 0;
            while(r > 0){
                s += data[r-1];
                r -= r & -r;
            }
            return s;
        }
};