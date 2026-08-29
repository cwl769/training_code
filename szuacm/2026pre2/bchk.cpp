#include <cstdio>
#include <cstring>
#include <algorithm>

char name[110][110];
char ab[256];
int num[256];

int main() {
    FILE *input = fopen("b.in", "r");
    FILE *ansfl = fopen("b.out", "r");
    int n;
    fscanf(input, "%d", &n);
    for (int i = 1; i <= n; ++i) {
        fscanf(input, "%s", name[i]);
    }
    fscanf(ansfl, "%s", ab);
    int len = strlen(ab);
    if (len != 26)
        return 1;
    for (int i = 0; i < 26; ++i)
        num[ab[i]] = i + 1;
    for (int i = 2; i <= n; ++i) {
        int len = std::max(strlen(name[i - 1]), strlen(name[i]));
        for (int j = 0; j < len; ++j) {
            if (name[i - 1][j] != name[i][j]) {
                if (num[name[i - 1][j]] > num[name[i][j]])
                    return 2;
                break;
            }
        }
    }

    return 0;
}
