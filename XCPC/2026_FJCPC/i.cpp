#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::pair<int, int> PII;

char str[200010];
char tmp1[10], tmp2[10];

void solve() {
    int n, m, k;scanf("%d%d%d", &n, &m, &k);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
        str[i] -= 'a';
    }
    std::vector<veci> ban(26);
    for (int i = 1; i <= m; ++i) {
        scanf("%s%s", tmp1, tmp2);
        char x = tmp1[0];
        char y = tmp2[0];
        x -= 'a'; y -= 'a';
        ban[x].emplace_back(y);
    }
    std::vector<veci> trans(n + 2);
    veci cur(26, n + 1);
    for (int i = n; i >= 1; --i) {
        trans[i] = cur;
        cur[str[i]] = i;
    }
    trans[0] = cur;

    for (int i = 1; i <= n; ++i) {
        for(auto y : ban[str[i]]) {
            trans[i][y] = n + 1;
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     printf("i = [%2d]\n", i);
    //     for(int c = 0; c < 26; ++c)
    //         printf("--%c--> %2d\n", 'a' + (char)c, trans[i][c]);
    // }

    veci len(n + 2);
    len[n + 1] = 0;
    for (int i = n; i >= 0; --i) {
        for(int c = 0; c < 26; ++c)
        len[i] = std::max(len[i], len[trans[i][c]]);
        ++len[i];
    }
    // printf("---\n");
    if(len[0] <= k) {
        printf("-1\n");
        return;
    }
    int x = 0;
    std::vector<char> ans;
    for(int t = k; t >= 1; --t) {
        // printf("x:%d t:%d\n", x, t);
        for(int c = 0; c < 26; ++c) {
            if(len[trans[x][c]] >= t) {
                ans.emplace_back(c + 'a');
                x = trans[x][c];
                break;
            }
        }
    }
    for (auto c : ans)
        putchar(c);
    printf("\n");
}

int main() {
    int T;scanf("%d", &T);
    while(T--)solve();

    return 0;
}