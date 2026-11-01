#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <concepts>
#include <stack>

#define itn int
typedef long long int64;
typedef long long i64;
typedef unsigned long long ui64;
typedef unsigned int uint;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

#define debug(...) fprintf(stderr, __VA_ARGS__)

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

template <typename Data>
concept Mergeable = requires(Data a, Data b)
  { { merge(a, b) } -> std::convertible_to<Data>;};
template <typename Data, typename Delta>
concept Addable = requires(Data a, Delta d) { a += d; };
template <typename Data, typename Action>
concept RangeChangeable =
  requires(Data& a, Action b) { a.act(b, 1ll, 1ll); };
template <typename Action>
concept Composable =
  requires(Action a, Action b) { a.compose(b); };
template <typename Data, typename Action>
concept SegtreeRC_concept = Mergeable<Data> &&
  RangeChangeable<Data, Action> && Composable<Action>;
template <typename Data, typename coord = int>
  requires Mergeable<Data>
struct Segtree {
struct Node{Data data;int son[2];Node():data(),son{0,0}{}};
inline static std::vector<Node> pl{Node()};
static void clear() {pl.assign(1, Node());}
static int newNode()
  {pl.emplace_back();return (int)pl.size() - 1;}
int root; coord L, R;
Segtree(coord l, coord r) {root = 0;L = l;R = r;}
void pushup(int p) { pl[p].data =
    merge(pl[pl[p].son[0]].data, pl[pl[p].son[1]].data);
}
int chg(int p, coord l, coord r, coord pos, Data val) {
  coord mid = l + r >> 1; if (!p) p = newNode();
  if(l == r) {pl[p].data = val;return p;}
  if(pos<=mid)pl[p].son[0]=chg(pl[p].son[0],l,mid,pos,val);
  else pl[p].son[1]=chg(pl[p].son[1], mid+1, r, pos, val);
  pushup(p);return p;
}
void chg(coord pos, Data val){root=chg(root,L,R,pos,val);}
// When data is "Addable", the following 2 func exist.
template <typename Delta> requires Addable<Data, Delta>
int add(int p, coord l, coord r, coord pos, Delta dd) {
  coord mid = l + r >> 1; if (!p) p = newNode();
  if(l == r) {pl[p].data += dd;return p;}
  if(pos<=mid)pl[p].son[0]=add(pl[p].son[0],l,mid,pos,dd);
  else pl[p].son[1]=add(pl[p].son[1], mid+1, r, pos, dd);
  pushup(p);return p;
}
template <typename Delta> requires Addable<Data, Delta>
void add(coord pos, Delta dd){root=add(root,L,R,pos,dd);}
Data query(int p, coord l, coord r, coord ql, coord qr) {
  coord mid = l + r >> 1; if (!p) return pl[0].data;
  if(ql <= l && r <= qr) return pl[p].data;
  if(qr <= mid)return query(pl[p].son[0], l, mid, ql,qr);
  if(ql > mid)return query(pl[p].son[1], mid+1, r, ql,qr);
  return merge(query(pl[p].son[0], l, mid, ql, qr),
                query(pl[p].son[1], mid + 1, r, ql, qr));
}
Data query(coord l, coord r) {return query(root,L,R,l,r);}
};

constexpr ui64 MOD = 998244353;

ui64 qpow(ui64 a, ui64 b) {
    ui64 ans = 1;
    for(;b;b>>=1) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

ui64 inv(ui64 a) {
    return qpow(a, MOD - 2);
}

struct Monoid {
    ui64 b, c, d, e;
    Monoid():b(), c(), d(), e(){}
    Monoid(ui64 p):b((p + p) % MOD), c(p), d(p), e(p){}
};

Monoid merge(const Monoid& s, const Monoid& t) {
    Monoid ans;
    ans.b = (s.b + s.c * t.b) % MOD;
    ans.c = s.c * t.c % MOD;
    ans.d = (s.d + s.e * t.b + t.d) % MOD;
    ans.e = (s.e * t.c + t.e) % MOD;
    return ans;
}

struct Operation {
    int time, pos;
    ui64 pp;
};

bool operator < (const Operation& a, const Operation& b) {
    return a.time < b.time;
}

void solve() {
    itn n;readInt(n);
    veci64 ll(n + 2), rr(n + 2);
    for (int i = 1; i <= n; ++i)
        readInt(ll[i], rr[i]);
    veci64 pp(n + 2);
    for (int i = 1; i <= n; ++i)
        pp[i] = inv(rr[i] - ll[i] + 1);
    
    // auto P = [&ll, &rr, &pp](int i, int col)->i64 {
    //     if(i == 0)return 0;
    //     if(ll[i] <= col && col <= rr[i])
    //         return pp[i];
    //     return 0;
    // };

    std::vector<Operation> ops;
    for (int i = 1; i <= n; ++i) {
        ops.emplace_back(ll[i], i, pp[i]);
        ops.emplace_back(rr[i] + 1, i, 0);
    }
    std::sort(ops.begin(), ops.end());

    Segtree<Monoid> tree(1, n);
    i64 ans = 0;

    auto it = ops.begin();
    for (;it != ops.end();) {
        int cur = it->time;
        while(it!=ops.end() && it->time == cur) {
            tree.chg(it->pos, Monoid(it->pp));
            ++it;
        }
        if(it == ops.end())
            break;
        int nxt = it->time;
        ui64 dura = nxt - cur;
        ans = (ans + dura * (tree.query(1, n).d)) % MOD;
    }

    printf("%lld\n", ans);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}