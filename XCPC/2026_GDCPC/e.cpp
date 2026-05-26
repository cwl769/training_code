#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
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

std::vector<std::pair<veci, veci> > func(int tot) {
    std::vector<std::pair<veci, veci> > ans(tot-1);
    if(tot == 2) {
        ans[0].first.push_back(0);
        ans[0].second.push_back(1);
        return ans;
    }
    if(tot == 4) {
        ans[0].first = {0, 1};
        ans[0].second = {2, 3};
        ans[1].first = {0, 2};
        ans[1].second = {1, 3};
        ans[2].first = {0, 3};
        ans[2].second = {1, 2};
        return ans;
    }
    auto prev = func(tot / 2);
    int tot2 = tot/2;
    int tot4 = tot2/2;
    if(tot == 8) {
        for(int i=0,cur=0;i<tot2;++i,++cur) {
            ans[i].first.push_back(cur);
            ans[i].second.push_back(cur+tot2);
            for(int x=0;x<tot2;++x) {
                if(x == cur)
                    continue;
                ans[i].first.push_back(x+tot2);
                ans[i].second.push_back(x);
            }
        }
    } else {
        for(int i=0;i<tot4;++i)
            ans[i] = prev[i];
        int len = tot4;
        for(int i=0;i<tot4;++i) {
            for(int j=0;j<len;++j)
                ans[i].first.push_back(ans[i].second[j]+tot2);
            for(int j=0;j<len;++j)
                ans[i].second.push_back(ans[i].first[j]+tot2);
        }
        for(int i=0;i<tot4;++i) {
            // ans[i+tot4]
            for(auto x:prev[i].first) {
                if(x<tot4) {
                    ans[i+tot4].first.push_back(x);
                    ans[i+tot4].first.push_back(x+tot4);
                } else {
                    ans[i+tot4].first.push_back(x+tot4);
                    ans[i+tot4].first.push_back(x+tot4+tot4);
                }
            }
            for(auto x:prev[i].second) {
                if(x<tot4) {
                    ans[i+tot4].second.push_back(x);
                    ans[i+tot4].second.push_back(x+tot4);
                } else {
                    ans[i+tot4].second.push_back(x+tot4);
                    ans[i+tot4].second.push_back(x+tot4+tot4);
                }
            }
        }
    }

    for(int i=tot2;i<tot-1;++i) {
        for(auto x:prev[i-tot2].first) {
            ans[i].first.push_back(x);
        }
        for(auto x:prev[i-tot2].first) {
            ans[i].first.push_back(x+tot2);
        }
        for(auto x:prev[i-tot2].second) {
            ans[i].second.push_back(x);
        }
        for(auto x:prev[i-tot2].second) {
            ans[i].second.push_back(x+tot2);
        }
    }
    return ans;
}

char str[100010];

void solve() {
    i64 n;readInt(n);
    i64 tot = (1ll<<n);
    
    i64 sum = 0;
    auto query = func(tot);
    
    for(auto &[vec1, vec2]:query) {
        i64 tmp;
        for(auto x:vec1)
            str[x] = '0';
        for(auto x:vec2)
            str[x] = '1';
        printf("? %s\n", str);
        fflush(stdout);
        readInt(tmp);
        sum += tmp;
        for(auto x:vec1)
            str[x] = '1';
        for(auto x:vec2)
            str[x] = '0';
        printf("? %s\n", str);
        fflush(stdout);
        readInt(tmp);
        sum += tmp;
    }
    i64 tmp = tot + tot / 2 - 1;
    // fprintf(stderr, "%lld / %lld = %lld\n", sum, tmp, sum / tmp);
    // fflush(stderr);
    printf("! %lld\n", sum / tmp);
    fflush(stdout);
}

int main() {
    // int T;readInt(T);
    // while(T--) {
        solve();
    // }

    return 0;
}