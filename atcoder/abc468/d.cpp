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

char str[10010];

void solve() {
    scanf("%s", str+1);
    int n = strlen(str+1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
	int dif = 0;
	for(int j = 0;;++j) {
            if (i - j < 1 || i + j > n)
		break;
            if (str[i + j] != str[i - j]) {
                ++dif;
	    }
            if (dif > 1)
                break;
            ++ans;
	}
    }
    for (int i = 1; i < n; ++i) {
        int dif = 0;
        for (int j = 0;; ++j) {
            if (i - j < 1 || i + j + 1 > n)
                break;
            if (str[i - j] != str[i + j + 1])
                ++dif;
            if (dif > 1)
                break;
            ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    //int T;readInt(T);
    //while(T--) {
        solve();
    //}

    return 0;
}
