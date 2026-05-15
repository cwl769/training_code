#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
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

struct Ticket {
    i64 price, val;
};

struct cmp1 {
    bool operator () (Ticket a, Ticket b) const {
        if(a.price == b.price)return a.val < b.val;
        return a.price < b.price;
    }
};

struct cmp2 {
    bool operator () (Ticket a, Ticket b) const {
        // if(a.val - a.price == b.val - b.price) {
        //     if(a.price == b.price)return a.val < b.val;
        //     return a.price > b.price;
        // }
        // return a.val - a.price > b.val - b.price;
        if(a.price == b.price)return a.val > b.val;
        return a.price > b.price;
    }
};

struct cmp3 {
    bool operator () (Ticket a, Ticket b) const {
        if(a.val == b.val) return a.price < b.price;
        return a.val < b.val;
    }
};

void solve() {
    int n, m;readInt(n, m);
    veci a(n+1), b(m+1), c(m+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=m;++i)
        readInt(b[i]);
    for(int i=1;i<=m;++i)
        readInt(c[i]);
    std::priority_queue<i64> heap;
    i64 sum = 0;
    for(int i=1;i<=n;++i)
        sum += a[i];
    for(int i=1;i<=n;++i)
        heap.push(a[i]);
    std::multiset<Ticket, cmp1> set1;
    std::multiset<Ticket, cmp2> set2;
    std::multiset<Ticket, cmp3> set3;
    for(int i=1;i<=m;++i) {
        if(b[i] >= c[i])
            continue;
        set2.insert((Ticket){
            .price = b[i],
            .val = c[i]
        });
        set3.insert((Ticket){
            .price = b[i],
            .val = c[i]
        });
    }
    while(heap.size()) {
        i64 cur = heap.top();
        heap.pop();
        printf("-------cur:%lld-------\n", cur);
        while(set3.size() && set3.rbegin()->val >= cur) {
            Ticket tck = *set3.rbegin();
            set3.erase(set3.find(tck));
            set2.erase(set2.find(tck));
            set1.insert(tck);
        }
        for(auto tck:set1) {
            printf("{%lld, %lld}", tck.price, tck.val);
        }
        printf("\n");
        for(auto tck:set2) {
            printf("{%lld, %lld}", tck.price, tck.val);
        }
        printf("\n");
        for(auto tck:set3) {
            printf("{%lld, %lld}", tck.price, tck.val);
        }
        printf("\n");
        if(set1.size() ) {
            Ticket tck = *set1.begin();
            printf("use1 {%lld, %lld}\n", tck.price, tck.val);
            if(tck.price < cur) {
                sum -= cur - tck.price;
            }
            set1.erase(set1.find(tck));
            heap.push(tck.price);
        } else if(set2.size()) {
            Ticket tck = *set2.begin();
            printf("use2 {%lld, %lld}\n", tck.price, tck.val);
            sum -= tck.val - tck.price;
            set2.erase(set2.find(tck));
            set3.erase(set3.find(tck));
            heap.push(tck.price);
        }

        printf("---\n");
        for(auto tck:set1) {
            printf("{%lld, %lld}", tck.price, tck.val);
        }
        printf("\n");
        for(auto tck:set2) {
            printf("{%lld, %lld}", tck.price, tck.val);
        }
        printf("\n");
        for(auto tck:set3) {
            printf("{%lld, %lld}", tck.price, tck.val);
        }
        printf("\n");
    }
    printf("%lld\n", sum);
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}