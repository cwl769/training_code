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

int dis1(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int dis2(int x1, int y1, int x2, int y2) {
    return std::max(std::abs(x1 - x2), std::abs(y1 - y2));
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, x1, y1, x2, y2;
        readInt(n, x1, y1, x2, y2);
        int ans = 0;
        int dx = std::abs(x1 - x2);
        int dy = std::abs(y1 - y2);
        if(dx >= dy) {
            std::swap(x1, y1);
            std::swap(x2, y2);
            std::swap(dx, dy);
        }
        // dx <= dy
        if(y1 > y2) {
            y1 = n - y1;
            y2 = n - y2;
        }
        if(x1 > x2) {
            x1 = n - x1;
            x2 = n - x2;
        }
        ans += y1;
        dx = std::max(0, dx - y1);
        if(dx == 0) {
            ans += std::max(dy, std::max());
        } else {
            ans += std::max(dy, x2);
        }
        printf("%d\n", ans);
    }

    return 0;
}