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

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

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

struct Pos {
    i64 x, y;
};

bool operator < (Pos a, Pos b) {
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool operator == (Pos a, Pos b) {
    return a.x == b.x && a.y == b.y;
}

const double sqr3 = 1.732050808;

i64 r, t;

i64 dis2(Pos a, Pos b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool test(Pos pos, Pos tar, i64& ax, i64& ay) {
    if(dis2(pos, tar) <= r * r) {
        ax *= tar.x;
        ay *= tar.y;
        return true;
    }
    return false;
}

Pos cal(i64 x, i64 y) {
    i64 negx = 1;
    i64 negy = 1;
    if(x < 0) {
        negx = -1;
        x = -x;
    }
    if(y < 0) {
        negy = -1;
        y = -y;
    }
    i64 ax = negx, ay = negy;
    i64 kx = x / t;
    if(kx&1) {
        i64 ky = y / (r * 2ll);
        if(test({x, y}, {kx*t+t, ky*2ll*r}, ax, ay))
            return {ax, ay};
        if(test({x, y}, {kx*t+t, ky*2ll*r+r+r}, ax, ay))
            return {ax, ay};
        if(test({x, y}, {kx*t, ky*2ll*r+r}, ax, ay))
            return {ax, ay};
    } else {
        i64 ky = y / (r * 2ll);
        if(test({x, y}, {kx*t, ky*2ll*r}, ax, ay))
            return {ax, ay};
        if(test({x, y}, {kx*t, ky*2ll*r+r+r}, ax, ay))
            return {ax, ay};
        if(test({x, y}, {kx*t+t, ky*2ll*r+r}, ax, ay))
            return {ax, ay};
    }
    return {LLONG_MAX, LLONG_MAX};
}

void solve() {
    i64 n;readInt(n, r);
    t = (i64)(sqr3 * r) + 1;
    std::vector<Pos> pos(n);
    for(int i=0;i<n;++i)
        readInt(pos[i].x, pos[i].y);
    
    // i64 mxx = 0, mxy = 0;
    // for(auto p:pos) {
    //     i64 x = std::abs(p.x);
    //     i64 y = std::abs(p.y);
    //     mxx = std::max(mxx, x);
    //     mxy = std::max(mxy, y);
    // }
    
    std::vector<Pos> vec;
    for(auto p:pos) {
        vec.push_back(cal(p.x, p.y));
    }
    std::sort(vec.begin(), vec.end());
    vec.resize(std::unique(vec.begin(), vec.end()) - vec.begin());
    if(vec.back().x == LLONG_MAX)
        vec.pop_back();
    printf("%d\n", (int)vec.size());
    for(auto p:vec) {
        printf("%lld %lld\n", p.x, p.y);
    }
}

int main() {
    solve();

    return 0;
}