#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

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

struct Seg {
    int l, r;
    int id;
};

bool operator == (Seg a, Seg b) {
    return a.id == b.id;
}

class CmpL {
public:
    bool operator () (Seg a, Seg b) {
        if(a.l == b.l)
            return (a.r > b.r);
        return (a.l > b.l);
    }
};

class CmpR {
public:
    bool operator () (Seg a, Seg b) {
        if(a.r == b.r)
            return (a.l < b.l);
        return (a.r < b.r);
    }
};


int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::priority_queue<Seg, std::vector<Seg>, CmpL> setL;
        std::priority_queue<Seg, std::vector<Seg>, CmpR> setR;
        std::vector<Seg> seg(n);
        int64 ans = 0;
        for(int i=0;i<n;++i) {
            readInt(seg[i].l, seg[i].r);
            seg[i].id = i;
            setL.push(seg[i]);
            setR.push(seg[i]);
            ans += seg[i].r - seg[i].l;
        }
        int cnt = n;
        for(;cnt>1;cnt-=2) {
            if(setL.top() == setR.top()) {
                int id = setL.top().id;
                setL.pop();setR.pop();
                if(seg[id].r - setL.top().l > setR.top().r - seg[id].l) {
                    ans += seg[id].r - setL.top().l;
                    setL.pop();
                } else {
                    ans += setR.top().r - seg[id].l;
                    setR.pop();
                }
            } else {
                int idL = setL.top().id;
                int idR = setR.top().id;
                ans += seg[idR].r - seg[idL].l;
                setL.pop();
                setR.pop();
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}