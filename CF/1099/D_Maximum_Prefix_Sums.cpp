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

char str[200010];
i64 a[200010];
i64 c[200010];

bool op[200010];//0 <=, 1 ==
i64 val[200010];

bool conflict(int pos, bool cop, i64 cval) {
    if(cop) {
        if(op[pos])
            return cval != val[pos];
        else
            return val[pos] < cval;
    } else {
        if(op[pos]&&cval < val[pos])
            return true;
        return false;
    }
}

void update(int pos, bool cop, i64 cval) {
    if(cop) {
        op[pos] = cop;
        val[pos] = cval;
    } else {
        if(!op[pos]) {
            val[pos] = std::min(val[pos], cval);
        }
    }
}

bool solve() {
    int n;readInt(n);
    scanf("%s", str+1);
    for(int i=1;i<=n;++i)
        readInt(a[i]);
    for(int i=1;i<=n;++i)
        readInt(c[i]);
    a[n+1] = LLONG_MAX;
    c[0] = LLONG_MIN;
    for(int i=0;i<=n;++i) {
        op[i] = 0;
        val[i] = LLONG_MAX;
    }

    for(int i=2;i<=n;++i)
        if(c[i-1] > c[i])
            return false;

    int lst = 0;
    i64 sum = 0;
    int i=1;
    for(;i<=n;++i) {
        if(str[i] == '0')
            break;
        sum += a[i];
        if(c[i] != c[i-1]) {
            if(sum != c[i])
                return false;
        } else {
            if(sum > c[i])
                return false;
        }
    }
    for(;i<=n;++i) {
        if(str[i] == '1') {
            sum += a[i];
        } else {
            lst = i;
        }
        
        bool cop;
        i64 cval;
        if(c[i] != c[i-1]) {
            cop = 1;
            cval = c[i] - sum;
        } else {
            cop = 0;
            cval = c[i] - sum;
        }
        // printf("[%d]%d %lld\n", lst, cop, cval);
        if(conflict(lst, cop, cval))
            return false;
        update(lst, cop, cval);
    }
    i64 anssum = 0;
    for(int i=1;i<=n;++i) {
        if(str[i] == '0') {
            a[i] = val[i] - anssum;
            anssum += a[i];
        }
    }

    return true;
}

int main() {
    int T;readInt(T);
    while(T--) {
        if(solve()) {
            printf("Yes\n");
            for(int i=1;;++i) {
                if(a[i] == LLONG_MAX)
                    break;
                printf("%lld ", a[i]);
            }
            printf("\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}