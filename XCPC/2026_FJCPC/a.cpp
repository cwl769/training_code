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
    int ans = 0;
    for (int i = 1; i + 4 <= n; ++i) {
        if(
            str[i] == 'f' && 
            str[i+1] == 'j' && 
            str[i+2] == 'c' && 
            str[i+3] == 'p' && 
            str[i+4] == 'c'
        ) ++ans;
    }
    printf("%d\n", ans);

    return 0;
}