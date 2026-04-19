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

char tmp[500010];

int main() {
    int n;int64 m;readInt(n, m);
    std::vector<int64> sum(256);
    std::vector<char*> name(n);
    for(int i=0;i<n;++i) {
        scanf("%s", tmp);
        int len = strlen(tmp);
        char * str = (char*)malloc(sizeof(char) * (len+1));
        strcpy(str, tmp);
        name[i] = str;
        for(int j=0;j<len;++j)
            ++sum[str[j]];
    }
    // for(char c='A';c<='Z';++c)
    //     printf("%c %lld \n", c, sum[c]);
    for(int l=0;l<n;++l) {
        int64 k = m;
        int len = strlen(name[l]);
        std::vector<int64> cnt(256, 0);
        for(int i=0;i<len;++i)
            ++cnt[name[l][i]];
        
        for(char c='A';c<='Z';++c) {
            if(cnt[c] == 0) continue;
            if(cnt[c] == sum[c]) {
                k = -1;
                break;
            } else {
                // printf("%c %lld \n", c, ((sum[c]-cnt[c])*m-cnt[c]));
                // k = std::min(k, ((sum[c]-cnt[c])*m-cnt[c])/(sum[c]-cnt[c]));
                // floor(-cnt[c]/(sum[c]-cnt[c]))
                int64 tmp = m;
                if(cnt[c] % (sum[c]-cnt[c])) {
                    tmp -= cnt[c] / (sum[c]-cnt[c]) + 1ll;
                } else {
                    tmp -= cnt[c] / (sum[c]-cnt[c]);
                }
                if(tmp < 0) {
                    k = -1;
                    break;
                } else {
                    k = std::min(k, tmp);
                }
            }
        }
        printf("%lld ", k);
    }
    

    return 0;
}