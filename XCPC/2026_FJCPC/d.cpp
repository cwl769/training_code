#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

char str[100010];

int main() {
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    int cnt[2] = {0, 0};
    for (int i = 1; i <= n; ++i)
        ++cnt[str[i] - '0'];
    if(!(cnt[1] & 1)) {
        if(cnt[0]) {
            for (int i = 1; i <= n; ++i) {
                if(str[i] == '0') {
                    str[i] = '1';
                    break;
                }
            }
        } else {
            str[1] = '0';
        }
    }
    int id0 = 1, id1 = 1;
    for (int i = 1; i <= n; ++i) {
        if(str[i] == '1') {
            printf("%lld ", (1ll << 50) | id1);
            ++id1;
        } else {
            printf("%lld ", id0);
            ++id0;
        }
    }
    printf("\n");


    return 0;
}