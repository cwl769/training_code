#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
struct vector {
    i64 x, y;
    vector() : x(), y() {}
    vector(i64 _x, i64 _y) : x(_x), y(_y) {}
    vector operator + (const vector& b) const {
        return {x + b.x, y + b.y};
    }
    vector operator - (const vector& b) const {
        return {x - b.x, y - b.y};
    }
    vector operator * (const i64 k) const {
        return {x * k, y * k};
    }
};
vector operator * (const i64 k, const vector& v) {
    return {k * v.x, k * v.y};
}
i64 dot(const vector& a, const vector& b) {
    return a.x * b.x + a.y * b.y;   
}
i64 cro(const vector& a, const vector& b) {
    return a.x * b.y - a.y * b.x;
}
/* add this part to enable sort */
int which(const vector& b) {
    if (b.x == 0 && b.y == 0)
        return -1;
    int ans = 0;
    if (b.x && b.y) {
        ans |= 1;
        if (b.y < 0) ans |= 6;
        if (b.x < 0) ans ^= 2;
    }
    else {
        if ((b.x + b.y) < 0) ans |= 4;
        if (b.x == 0) ans |= 2;
    }
    return ans;
}
bool operator < (const vector& a, const vector& b) {
    if(which(a) == which(b))
        return cro(a, b) > 0;
    return which(a) < which(b);
}
/* add this part to enable convex */
void convex(std::vector<vector> &pnt, std::vector<vector> &ans) {
    std::sort(pnt.begin(), pnt.end(), [](const vector& a, const vector& b)->bool {
        if(a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    });
    int n = pnt.size();
    std::vector<int> stack;
    std::vector<bool> vis(n);
    stack.emplace_back(0);
    for (int i = 1; i < n; ++i) {
        for(int sz = stack.size(); sz > 1; --sz) {
            const vector & a = pnt[stack[sz - 2]];
            const vector & b = pnt[stack[sz - 1]];
            if(cro(a - b, b - pnt[i]) > 0)
                break;
            stack.pop_back();
        }
        stack.emplace_back(i);
    }
    for (int i = 1; i < (int)stack.size(); ++i) {
        ans.emplace_back(pnt[stack[i]]);
        vis[stack[i]] = 1;
    }
    stack.clear();
    /* same as former one except the first element and the order */
    stack.emplace_back(n - 1);
    for (int i = n - 2; i >= 0; --i) {
        for(int sz = stack.size(); sz > 1; --sz) {
            const vector & a = pnt[stack[sz - 2]];
            const vector & b = pnt[stack[sz - 1]];
            if(cro(a - b, b - pnt[i]) > 0)
                break;
            stack.pop_back();
        }
        stack.emplace_back(i);
    }
    for (int i = 1; i < (int)stack.size(); ++i) {
        ans.emplace_back(pnt[stack[i]]);
        vis[stack[i]] = 1;
    }
}

const i64 MOD = 998244353;
const i64 half = 499122177;

i64 area(std::vector<vector> edg) {
    i64 ans = 0;
    vector prev;
    for(auto e : edg) {
        vector cur = prev + e;
        ans = (ans + cro(prev, cur) % MOD + MOD) % MOD;
        prev = cur;
    }
    return ans;
}

int main() {
    int n, m, Q;scanf("%d%d%d", &n, &m, &Q);
    std::vector<vector> a(n), b(m);
    for(int i = 0; i < n; ++i) 
        scanf("%lld%lld", &a[i].x, &a[i].y);
    for(int i = 0; i < m; ++i) 
        scanf("%lld%lld", &b[i].x, &b[i].y);
    std::vector<vector> p, q;
    convex(a, p);
    convex(b, q);
    n = p.size();
    m = q.size();
    for(int i = 0; i < m; ++i) {
        q[i].x = -q[i].x;
        q[i].y = -q[i].y;
    }

    i64 bq = 0, bp = 0;
    vector tmp;
    for(int i = 1; i < n; ++i) {
        tmp = p[i] - p[i-1];
        bp += std::__gcd(std::abs(tmp.x), std::abs(tmp.y));
        bp %= MOD;
    }
    tmp = p[0] - p[n-1];
    bp += std::__gcd(std::abs(tmp.x), std::abs(tmp.y));
    bp %= MOD;
    for(int i = 1; i < m; ++i) {
        tmp = q[i] - q[i-1];
        bq += std::__gcd(std::abs(tmp.x), std::abs(tmp.y));
        bq %= MOD;
    }
    tmp = q[0] - q[n-1];
    bq += std::__gcd(std::abs(tmp.x), std::abs(tmp.y));
    bq %= MOD;


    i64 s0, s1, s2;
    std::vector<vector> edg;

    edg.clear();
    for(int i = 1; i < m; ++i)
        edg.emplace_back(q[i] - q[i-1]);
    edg.emplace_back(q[0] - q[m-1]);
    std::sort(edg.begin(), edg.end());
    s0 = (area(edg) + 2 + bq) %MOD * half % MOD;

    edg.clear();
    for(int i = 1; i < n; ++i)
        edg.emplace_back(p[i] - p[i-1]);
    edg.emplace_back(p[0] - p[n-1]);
    for(int i = 1; i < m; ++i)
        edg.emplace_back(q[i] - q[i-1]);
    edg.emplace_back(q[0] - q[m-1]);
    std::sort(edg.begin(), edg.end());
    s1 = (area(edg) + 2 + bq + bp) %MOD * half % MOD;

    edg.clear();
    for(int i = 1; i < n; ++i)
        edg.emplace_back((p[i] - p[i-1]) * 2);
    edg.emplace_back((p[0] - p[n-1]) * 2);
    for(int i = 1; i < m; ++i)
        edg.emplace_back(q[i] - q[i-1]);
    edg.emplace_back(q[0] - q[m-1]);
    std::sort(edg.begin(), edg.end());
    s2 = (area(edg) + 2 + bq + bp + bp) %MOD * half % MOD;

    // printf("%lld %lld %lld\n", s0, s1, s2);

    i64 a0 = s0;
    i64 a2 = (s2 + a0 + MOD - s1 + MOD - s1) % MOD * half % MOD;
    i64 a1 = (s1 + MOD - s0 + MOD - a2) % MOD;

    // printf("%lld %lld %lld\n", a0, a1, a2);

    while(Q--) {
        i64 k;
        scanf("%lld", &k);
        k %= MOD;
        printf("%lld\n", (a0 + a1 * k % MOD + a2 * k % MOD * k % MOD) % MOD);
    }

    return 0;
}