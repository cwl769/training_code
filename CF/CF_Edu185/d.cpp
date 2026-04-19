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

char str[300010];

int main() {
    int T;readInt(T);
    int id = 0;
    for(;T;--T) {
        int n, q;readInt(n, q);
        scanf("%s", str+1);
        int cnt = 0;
        int sum = 0;
        int cntsgli = 0;
        int cntsglv = 0;
        int cntsgliv = 0;
        int cnt2 = 0;
        for(int i=1;i<=n;++i) {
            if(str[i]!='?'){
                if(str[i]=='I') {
                    if(str[i+1]=='X' || str[i+1]=='V') {
                        sum += -1;
                    } else {
                        sum += 1;
                    }
                } else if(str[i] == 'V') {
                    sum += 5;
                } else if(str[i] == 'X') {
                    sum += 10;
                }
                continue;
            }
            int l = i, r = i + 1;
            while(str[r]=='?')++r;
            int len = r - l;
            cnt += len;

            if(str[l-1]=='I')++cntsglv;
            if(str[r]=='X'||str[r]=='V')++cntsgli;
            if((str[r]=='X'||str[r]=='V') && str[l-1]=='I' && len==1)++cntsgliv;
            int tmp = len;
            if(str[l-1]=='I')--tmp;
            if(str[r]=='X'||str[r]=='V')--tmp;
            if(tmp>=0)
                cnt2 += tmp/2;

            i=r-1;
        }
        cntsgli -= cntsgliv;
        cntsglv -= cntsgliv;
        // printf("cnt:%d\n", cnt);
        // printf("sum:%d\n", sum);
        // printf("cntsgli:%d\n", cntsgli);
        // printf("cntsglv:%d\n", cntsglv);
        for(;q;--q) {
            ++id;
            int cx, cv, ci;readInt(cx, cv, ci);
            int ans = sum;

            int sv = 0, si = 0;

            if(ci>=cnt) {
                ans += cnt;
                si = cnt;
                sv = 0;
            } else {
                ans += ci;
                si = ci;
                sv = cnt-ci;
                if(cv>=cnt-ci) {
                    ans += 5*(cnt-ci);
                } else {
                    ans += 5*cv + 10*(cnt-ci-cv);
                }
            }

            if(si < cntsgli || sv < cntsglv) {
                ans -= 2*(std::min(si, cntsgli+cntsgliv) + std::min(sv, cntsglv+cntsgliv));
            } else {
                ans -= 2*(cntsgli+cntsglv+cntsgliv);
                si -= cntsgli;
                sv -= cntsglv;
                ans -= 2*std::min(std::min(si, sv), std::min((si+sv-cntsgliv)/2, cnt2));
            }
            
            printf("%d\n", ans);
        }
    }

    return 0;
}