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

int p[200000], pcnt=0;
int mnp[200010];
// int miu[200010];
void Euler(int N) {
    // miu[1] = 1;
    for(int x=2;x<=N;++x) {
        if(!mnp[x]) {
            p[pcnt] = x;
            ++pcnt;
            mnp[x] = x;
            // miu[x] = -1;
        }
        for(int j=0;;++j) {
            int64 t = 1ll * x * p[j];
            if(t>N)break;
            mnp[t] = p[j];
            if(p[j]==mnp[x]) {
                // miu[t] = 0;
                break;
            } else {
                // miu[t] = -miu[x];
            }
        }
    }
}

int cnt[200010];
int cnti[200010];

int main() {
    Euler(200009);
    // printf("%d\n", pcnt);
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n+1);
        std::vector<int> b(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        for(int i=1;i<=n;++i)
            readInt(b[i]);
        bool flag = true;
        
        for(int pos=1;pos<=n;++pos) {
            for(int x=a[pos];x!=1;) {
                int tp = mnp[x];
                ++cnt[tp];
                cnti[tp] = pos;
                if(cnt[tp]>1)
                    flag = false;
                while(x%tp == 0)x/=tp;
            }
        }
        
        if(!flag) {
            printf("0\n");
            for(int pos=1;pos<=n;++pos) {
                for(int x=a[pos];x!=1;) {
                    int tp = mnp[x];
                    --cnt[tp];
                    cnti[tp] = 0;
                    while(x%tp == 0)x/=tp;
                }
            }
            continue;
        }

        int64 ans = 0;
        b[0] = INT_MAX;
        int mni = 0;
        int smni = 0;
        for(int i=1;i<=n;++i) {
            if(b[i] < b[mni]) {
                smni = mni;
                mni = i;
            } else if(b[i] < b[smni]) {
                smni = i;
            }
        }
        ans = b[mni] + b[smni];
        
        for(int i=1;i<=n;++i) {
            int x = a[i] + 1;
            for(;x!=1;) {
                int tp = mnp[x];
                if(cnti[tp]&&cnti[tp]!=i)
                    ans = std::min(ans, (int64)b[i]);
                while(x%tp==0)x/=tp;
            }
        }

        std::vector<int> appear;

        for(int pos=1;pos<=n;++pos) {
            for(int x=a[pos];x!=1;) {
                int tp = mnp[x];
                --cnt[tp];
                cnti[tp] = 0;
                appear.push_back(tp);
                while(x%tp == 0)x/=tp;
            }
        }
        
        for(auto tp:appear) {
            int r = a[mni] % tp;
            if(r) {
                ans = std::min(ans, 1ll * (tp - r) * b[mni]);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}