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

bool check(int x, int y) {
    printf("? %d 2 %d %d\n", x, x, y);
    fflush(stdout);
    int t;readInt(t);
    return t == 2;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> lv(n+1);
        for(int i=1;i<=n;++i) {
            printf("? %d %d ", i, n);
            for(int j=1;j<=n;++j)
                printf("%d ", j);
            printf("\n");
            fflush(stdout);
            readInt(lv[i]);
        }
        std::vector<std::vector<int> > nd(n+1);
        for(int i=1;i<=n;++i) 
            nd[lv[i]].push_back(i);
        int mx = INT_MIN, mxnd = 0;
        for(int i=n;i>=1;--i)
            if(nd[i].size()) {
                mx = i;
                mxnd = nd[i][0];
                break;
            }
        std::vector<int> ans;
        ans.push_back(mxnd);
        for(int x=mxnd,curlv=mx;curlv>1;--curlv) {
            for(auto yit=nd[curlv-1].begin();yit!=nd[curlv-1].end();++yit) {
                int y = *yit;
                if(check(x, y)) {
                    x = y;
                    ans.push_back(y);
                    break;
                }
            }
        }
        printf("! %d ", mx);
        for(auto it=ans.begin();it!=ans.end();++it) 
            printf("%d ", *it);
        printf("\n");
        fflush(stdout);
    }

    return 0;
}