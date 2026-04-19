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

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::vector<std::vector<int> > pos(n+1);
        for(int i=1;i<=n;++i)
            pos[a[i]].push_back(i);
        std::vector<int> l(n+1, INT_MAX);
        std::vector<int> cnt;
        int ans = 0;
        for(int x=1;x<=n;++x) {
            if(pos[x].empty())continue;
            if(pos[x].back() < l[x-1] || (cnt[0] == 0 && cnt[1] == 0)) {
                //cal ans
                std::vector<int> f(cnt.size());
                if(0<cnt.size())
                    f[0] = 0;
                if(1<cnt.size())
                    f[1] = std::min(cnt[0], cnt[1]);
                for(int i=2;i<cnt.size();++i)
                    f[i] = std::min(f[i-1]+cnt[i], f[i-2]+cnt[i-1]);
                if(f.size())
                    ans += f.back();
                cnt.clear();
                //new link
                auto tmp = std::lower_bound(pos[x-1].begin(), pos[x-1].end(), pos[x].back());
                cnt.push_back(tmp - pos[x-1].begin());
                if(pos[x-1].size())
                    tmp = std::upper_bound(pos[x].begin(), pos[x].end(), pos[x-1].front());
                else
                    tmp = pos[x].end();
                cnt.push_back(pos[x].end() - tmp);
                l[x] = ( (tmp == pos[x].end()) ? n+1 : *tmp );
            } else {
                auto tmp = std::lower_bound(pos[x-1].begin(), pos[x-1].end(), pos[x].back());
                cnt.back() += std::min(tmp, std::lower_bound(pos[x-1].begin(), pos[x-1].end(), l[x-1])) - pos[x-1].begin();
                printf("test1 %d %d\n", tmp - pos[x-1].begin(), std::lower_bound(pos[x-1].begin(), pos[x-1].end(), l[x-1]) - pos[x-1].begin());
                tmp = std::upper_bound(pos[x].begin(), pos[x].end(), pos[x-1].front());
                cnt.push_back(pos[x].end() - tmp);
                l[x] = ( (tmp == pos[x].end()) ? n+1 : *tmp );
            }
            printf("[%d] l(%d) ans:%d\n", x, l[x], ans);
            for(auto x:cnt)
                printf("%d ", x);
            printf("\n");
            
        }
        std::vector<int> f(cnt.size());
        if(0<cnt.size())
            f[0] = 0;
        if(1<cnt.size())
            f[1] = std::min(cnt[0], cnt[1]);
        for(int i=2;i<cnt.size();++i)
            f[i] = std::min(f[i-1]+cnt[i], f[i-2]+cnt[i-1]);
        if(f.size())
            ans += f.back();
        cnt.clear();
        printf("%d\n", ans);
    }

    return 0;
}