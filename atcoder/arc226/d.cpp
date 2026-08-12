#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
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

std::queue<int> q[6];
std::vector<std::pair<int, int>> mov;

void print_mov() {
    printf("%d\n", (int)mov.size());
    for (auto [x, y] : mov) {
        printf("%d %d\n", x, y);
    }
    mov.clear();
    fflush(stdout);
}

int movecnt = 0;

void move(int src, int dst) {
    ++movecnt;
    mov.emplace_back(src, dst);
    q[dst].emplace(q[src].front());
    q[src].pop();
}

void merge(int src, int dst) {
    int szs = q[src].size();
    int szt = q[dst].size();
    if (szs == 0)
        return;
    while (szs && szt) {
        if (q[src].front() <= q[dst].front()) {
            move(src, dst);
            --szs;
        } else {
            move(dst, dst);
            --szt;
        }
    }

    while (szs) {
        move(src, dst);
        --szs;
    }
    while (szt) {
        move(dst, dst);
        --szt;
    }
}

int m = 8;
int m2 = m * m;
int m3 = m2 * m;

void solve() {
    int Q;
    readInt(Q);
    Q <<= 1;
    int cnt = 0;
    while (Q--) {
        int tp;
        readInt(tp);
        if (tp == 1) {
            int x;
            readInt(x);
            q[1].emplace(x);
            merge(1, 2);
            ++cnt;
            if (cnt % m == 0)
                merge(2, 3);
            if (cnt % m2 == 0)
                merge(3, 4);
            if (cnt % m3 == 0)
                merge(4, 5);
            print_mov();
        } else {
            int ans = 2e9, ansi = 0;
            for (int i = 1; i <= 5; ++i) {
                if (q[i].size() && q[i].front() < ans) {
                    ans = q[i].front();
                    ansi = i;
                }
            }
            q[ansi].pop();
            printf("%d\n", ansi);
            fflush(stdout);
        }
    }
    // printf("movecnt: %d\n", movecnt);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
    //     solve();
    // }
    solve();

    return 0;
}
