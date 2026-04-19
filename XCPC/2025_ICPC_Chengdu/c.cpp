#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

typedef long long int64;

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

typedef std::vector<std::pair<int64, int> >::iterator Itr;

bool check(int64 t, int64 k, std::vector<std::pair<int64, int> >& a, std::vector<std::pair<int64, int> >& b) {
    Itr it[2];
    Itr end[2];
    it[0] = a.begin();
    it[1] = b.begin();
    end[0] = a.end();
    end[1] = b.end();
    for(int trn=1;it[0] != end[0] || it[1] != end[1];trn^=1,t-=k) {
        if(it[trn]==end[trn])continue;
        if(t < it[trn]->first)return false;
        ++it[trn];
    }
    return true;
}

void printAns(int64 t, int64 k, Itr ita, Itr itb, const Itr& enda, const Itr& endb, int trn) {
    if(ita==enda && itb==endb)return;
    // printf("printAns %lld %d %lld\n", t, trn, itb->first);
    if(itb!=endb)
        printAns(t-k, k, itb+1, ita, endb, enda, trn^1);
    else
        printAns(t-k, k, itb, ita, endb, enda, trn^1);
    if(itb!=endb)
        printf("%lld %d %d\n", t, trn, itb->second);
}

int main() {
    int64 n, m, k;readInt(n, m, k);
    std::vector<std::pair<int64, int> > a(n);
    std::vector<std::pair<int64, int> > b(m);
    for(int i=0;i<n;++i)
        readInt(a[i].first), a[i].second=i+1;
    for(int i=0;i<m;++i)
        readInt(b[i].first), b[i].second=i+1;

    std::sort(a.begin(), a.end(), std::greater<std::pair<int64, int> >());
    std::sort(b.begin(), b.end(), std::greater<std::pair<int64, int> >());
    
    int64 l = 0, r = 1e15;
    for(;l<r;) {
        int64 mid = ((l+r)>>1ll);
        if(check(mid, k, a, b) || check(mid, k, b, a)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int64 ans = l;
    printf("%lld\n", ans + k);
    if(check(ans, k, a, b)) {
        printAns(ans, k, a.begin(), b.begin(), a.end(), b.end(), 1);
    } else {
        printAns(ans, k, b.begin(), a.begin(), b.end(), a.end(), 0);
    }

    return 0;
}