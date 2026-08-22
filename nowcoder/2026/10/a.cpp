#include <cmath>
#include <cstdio>
typedef long long i64;

struct Vector {
    i64 x, y;
};

struct Vectord {
    double x, y;
};

i64 outp(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

double getlen(Vector s, Vector a) {
    double sl = sqrt(s.x * s.x + s.y * s.y);
    double al = sqrt(a.x * a.x + a.y * a.y);
    double sina = s.y / sl;
    double cosa = s.x / sl;
    double sinb = a.y / al;
    double cosb = a.x / al;
    double ans = al;
    ans /= sina;
    ans *= fabs(sina * cosb - sinb * cosa);
    return ans;
}
double getlend(Vector s, Vectord a) {
    double sl = sqrt(s.x * s.x + s.y * s.y);
    double al = sqrt(a.x * a.x + a.y * a.y);
    double sina = s.y / sl;
    double cosa = s.x / sl;
    double sinb = a.y / al;
    double cosb = a.x / al;
    double ans = al;
    ans /= sina;
    ans *= fabs(sina * cosb - sinb * cosa);
    return ans;
}

void solve() {
    Vector s, a, b;
    scanf("%lld%lld", &s.x, &s.y);
    scanf("%lld%lld", &a.x, &a.y);
    scanf("%lld%lld", &b.x, &b.y);
    Vector ss;
    if(s.x < 0) {
        ss = {.x = s.y, .y = -s.x};
    } else {
        ss = {.x = -s.y, .y = s.x};
    }
    // printf("(%lld, %lld)\n", s.x, s.y);
    // printf("(%lld, %lld)\n", a.x, a.y);
    // printf("(%lld, %lld)\n", b.x, b.y);
    // printf("(%lld, %lld)\n", ss.x, ss.y);
    double anssa = getlen(s, a);
    double anssb = getlen(s, b);
    Vectord ssd;
    ssd.x = ss.x;
    ssd.y = ss.y;
    // printf("(%.15lf, %.15lf)\n", ssd.x, ssd.y);
    double slen = sqrt(s.x * s.x + s.y * s.y);
    double alen = sqrt(a.x * a.x + a.y * a.y);
    ssd.x = ssd.x / slen * alen;
    ssd.y = ssd.y / slen * alen;
    // printf("%.15lf %.15lf (%.15lf %.15lf)\n", slen, alen, ssd.x, ssd.y);
    double anssss = getlend(s, ssd);
    // printf("%.15lf %.15lf %.15lf\n", anssa, anssb, anssss);
    i64 opas = outp(a, s);
    i64 opbs = outp(b, s);
    // printf("%lld %lld\n", opas, opbs);
    if((opas <= 0 && opbs <= 0) || (opas >= 0 && opbs >= 0)) {
        printf("%.15lf ", std::min(anssa, anssb));
    } else {
        printf("%.15lf ", 0.0);
    }

    i64 opass = outp(a, ss);
    i64 opbss = outp(b, ss);
    if((opass <= 0 && opbss <= 0) || (opass >= 0 && opbss >= 0)) {
        printf("%.15lf\n", std::max(anssa, anssb));
    } else {
        printf("%.15lf\n", anssss);
    }
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
    

    return 0;
}