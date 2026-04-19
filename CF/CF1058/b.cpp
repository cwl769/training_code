#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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

struct bcj{
    int *fa;
    bcj(int n) {
        fa = (int*)malloc(n*sizeof(int));
        for(int i=0;i<n;++i)
            fa[i] = i;
    }
    ~bcj() {
        free(fa);
    }
    int get(int x) {
        if(fa[x] == x)
            return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        fa[x] = y;
    }
};

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> b(n+1);
        for(int i=1;i<=n;++i)
            readInt(b[i]);
        std::vector<int> d(n+1);
        for(int i=1;i<=n;++i)
            d[i] = b[i] - b[i-1];
        bcj bcj(n+1);
        for(int i=1;i<=n;++i)
            if(i-d[i] > 0)
                bcj.merge(i, i-d[i]);
        std::vector<int> v(n+1);
        int cnt = 0;
        for(int i=1;i<=n;++i) {
            int rt = bcj.get(i);
            if(v[rt])
                printf("%d ", v[rt]);
            else {
                v[rt] = (++cnt);
                printf("%d ", v[rt]);
            }
        }
        printf("\n");
    }

    return 0;
}