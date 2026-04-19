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

char buf[256];

int main() {
    int n, m;readInt(n, m);
    std::vector<char> s(n+2), t(m+2);
    scanf("%s%s", s.begin(), t.begin());
    std::vector<bool> sb(256), tb(256);
    for(int i=0;i<n;++i)
        sb[s[i]] = 1;
    for(int i=0;i<m;++i)
        tb[t[i]] = 1;
    int q;readInt(q);
    for(;q;--q) {
        bool Takahashi = 1, Aoki = 1;
        scanf("%s", buf);
        int len = strlen(buf);
        for(int i=0;i<len;++i) {
            if(!sb[buf[i]])
                Takahashi = 0;
            if(!tb[buf[i]])
                Aoki = 0;
        }
        if(Takahashi && Aoki)
            printf("Unknown\n");
        else if(Takahashi)
            printf("Takahashi\n");
        else 
            printf("Aoki\n");
    }

    return 0;
}