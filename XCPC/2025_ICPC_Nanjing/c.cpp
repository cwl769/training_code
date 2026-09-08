#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        i64 n;scanf("%lld", &n);
        if(n & 1)
            printf("No\n");
        else
            printf("Yes\n%lld %lld\n", n >> 1, n >> 1);
    }


    return 0;
}