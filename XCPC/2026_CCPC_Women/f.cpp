#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

i64 gcd(i64 a, i64 b) {
    if (b == 0)
        return std::abs(a);
    return gcd(b, a % b);
}

struct Frac {
    i64 son, mom;
    Frac():son(0), mom(1){}
    Frac(i64 a) : son(a), mom(1) {}
    Frac(i64 a, i64 b) {
        if(b < 0) {
            a = -a;
            b = -b;
        }
        i64 g = gcd(std::abs(a), std::abs(b));
        a /= g;
        b /= g;
        son = a; mom = b;
    }
    Frac operator + (const Frac& b) const {
        return Frac(son * b.mom + b.son * mom, mom * b.mom);
    }
    Frac operator - (const Frac& b) const {
        return Frac(son * b.mom - b.son * mom, mom * b.mom);
    }
    Frac operator * (const Frac& b) const {
        return Frac(son * b.son, mom * b.mom);
    }
    Frac operator / (const Frac& b) const {
        return Frac(son * b.mom, mom * b.son);
    }
};

int main() {
    i64 x, y, l, r, v;
    scanf("%lld%lld%lld%lld%lld", &x, &y, &l, &r, &v);
    i64 s = std::min(y, r) - std::max(x, l);
    // printf("%lld %lld %lld %lld %lld %lld\n", x, y, l, r, v, s);
    Frac u(s * v, r - l);
    // printf("%lld/%lld\n", u.son, u.mom);
    Frac t = Frac(y - x) / u;
    printf("%lld/%lld\n", t.son, t.mom);

    return 0;
}