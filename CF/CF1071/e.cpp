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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;int64 x, y;readInt(n, x, y);
        std::vector<char> str(n+2);
        scanf("%s", str.begin() + 1);
        std::vector<int64> p(n+1);
        for(int i=1;i<=n;++i)
            readInt(p[i]);
        int cnt[2] = {0, 0};
        for(int i=1;i<=n;++i)
            ++cnt[str[i]-'0'];
        std::vector<int64> a(n+1), b(n+1);
        for(int i=1;i<=n;++i) {
            if(str[i] == '0') {
                a[i] = (p[i] / 2) + 1;
                x -= (p[i] / 2) + 1;
            } else {
                b[i] = (p[i] / 2) + 1;
                y -= (p[i] / 2) + 1;
            }
        }
        if(x < 0 || y < 0){
            printf("NO\n");
            continue;
        }
        for(int i=1;i<=n;++i) {
            if(str[i] == '0') {
                b[i] = std::min(y, p[i] - a[i]);
                y -= std::min(y, p[i] - a[i]);
            } else {
                a[i] = std::min(x, p[i] - b[i]);
                x -= std::min(x, p[i] - b[i]);
            }
        }
        for(int i=1;i<=n;++i) {
            if(a[i] + b[i] < p[i]) {
                int64 d = p[i] - a[i] - b[i];
                if(str[i] == '0') {
                    a[i] += std::min(d, x);
                    x -= std::min(d, x);
                } else {
                    b[i] += std::min(d, y);
                    y -= std::min(d, y);
                }
            }
        }
        bool ans = true;
        for(int i=1;i<=n;++i) {
            if(a[i] + b[i] < p[i]) {
                ans = false;
                break;
            }
        }
        if(!ans) {
            printf("NO\n");
            continue;
        }
        if(cnt[0] && cnt[1]) {
            printf("YES\n");
            continue;
        }
        if(cnt[0] == 0) {
            for(int i=1;i<=n;++i) {
                if(a[i] + 1 < b[i] && x) {
                    ++a[i];
                    --x;
                }
            }
            if(x<=y)printf("YES\n");
            else printf("NO\n");
        }
        if(cnt[1] == 0) {
            for(int i=1;i<=n;++i) {
                if(b[i] + 1 < a[i] && y) {
                    ++b[i];
                    --y;
                }
            }
            if(y<=x)printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}