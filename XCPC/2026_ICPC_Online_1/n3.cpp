//gpt improved version
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int NEG = -INF;

struct DS {
    vector<int> st, rk, bit;
};

void build(const vector<int>& a, const vector<int>& b, DS& d) {
    int n = a.size() - 1;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);

    sort(ord.begin(), ord.end(), [&](int i, int j) {
        if (a[i] != a[j])
            return a[i] < a[j];
        if (b[i] != b[j])
            return b[i] < b[j];
        return i < j;
    });

    d.rk.resize(n + 1);
    d.st.assign(2 * n + 2, 0);

    int pa = INF, pb = INF, r = 0;
    for (int id : ord) {
        int c = a[id] + n;

        if (a[id] != pa) {
            pa = a[id];
            pb = INF;
            r = 0;
        }

        if (b[id] != pb) {
            pb = b[id];
            ++r;
            ++d.st[c + 1];
        }

        d.rk[id] = r;
    }

    for (int i = 1; i < d.st.size(); ++i)
        d.st[i] += d.st[i - 1];

    d.bit.assign(d.st.back(), NEG);
}

int query(const DS& d, int c, int k) {
    int o = d.st[c];
    int res = NEG;

    for (; k; k -= k & -k)
        res = max(res, d.bit[o + k - 1]);

    return res;
}

void update(DS& d, int c, int k, int v) {
    int o = d.st[c];
    int m = d.st[c + 1] - o;

    for (; k <= m; k += k & -k)
        d.bit[o + k - 1] = max(d.bit[o + k - 1], v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n + 1), y(n + 1);

    for (int i = 1; i <= n; ++i) {
        int r, g, b;
        cin >> r >> g >> b;

        x[i] = x[i - 1] + r - g;
        y[i] = y[i - 1] + r - b;
    }

    // X: 固定 x，对 y 做前缀 max
    // Y: 固定 y，对 x 做前缀 max
    DS X, Y;
    build(x, y, X);
    build(y, x, Y);

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        int f = ans - i;

        // [1, i] 整段合法
        if (x[i] >= 0 && y[i] >= 0)
            f = 0;

        int cx = x[i] + n;
        int cy = y[i] + n;

        // x_j = x_i, y_j <= y_i
        f = max(f, query(X, cx, X.rk[i]));

        // y_j = y_i, x_j <= x_i
        f = max(f, query(Y, cy, Y.rk[i]));

        ans = max(ans, f + i);

        // 一定要 query 完再插入，保证 j < i
        update(X, cx, X.rk[i], f);
        update(Y, cy, Y.rk[i], f);
    }

    cout << ans << '\n';

    return 0;
}