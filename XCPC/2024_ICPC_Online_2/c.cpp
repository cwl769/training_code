#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

i64 a[300010], b[300010];
int str[300010];
int nxt[300010];
int ned[300010];
int anc[300010];//
// i64 ss[300010];//

int main() {
    int n;scanf("%d", &n);
    i64 lastans = 0;
    i64 sum = 0;
    for (int i = 1; i <= n; ++i) {
        int cc;
        scanf("%d%lld%lld", &cc, a + i, b + i);
        str[i] = (cc + lastans) % n;
        // str[i] = cc;
        ned[i - 1] = str[i];
        if(i == 1) {
            nxt[i] = 0;
        } else {
            int j = nxt[i - 1];
            while(j && str[j + 1] != str[i]) {
                j = nxt[j];
            }
            if(str[j + 1] == str[i])
                nxt[i] = j + 1;
            else
                nxt[i] = 0;
        }

        // for(int x = nxt[i - 1];;x = anc[x]) {
        //     if(ned[x] != str[i]) {
        //         sum -= ss[x];
        //     }
        //     if(x == 0)
        //         break;
        // }
        
        for (int x = nxt[i - 1];x;) {
            if(ned[x] != str[i]) {
                sum -= b[i - x];
                x = nxt[x];
            } else {
                x = anc[x];
            }
        }

        if(i != 1 && str[i] == str[1]) {
            sum += b[i];
        }
        lastans += a[i] * (sum + b[1]);
        // printf("[%d] %lld\n", i, sum);
        printf("%lld\n", lastans);
        if(i > 1) {
            if(ned[nxt[i - 1]] == ned[i - 1]) {
                anc[i - 1] = anc[nxt[i - 1]];
                // ss[i - 1] = ss[nxt[i - 1]] + b[i - 1];
            } else {
                anc[i - 1] = nxt[i - 1];
                // ss[i - 1] = b[i - 1];
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     printf("%2d ", str[i]);
    // printf("\n");
    // for (int i = 1; i <= n; ++i)
    //     printf("%2lld ", a[i]);
    // printf("\n");
    // for (int i = 1; i <= n; ++i)
    //     printf("%2lld ", b[i]);
    // printf("\n");
    // for (int i = 1; i <= n; ++i)
    //     printf("%2d ", nxt[i]);
    // printf("\n");
    // for (int i = 1; i < n; ++i)
    //     printf("%2c ", ned[i] + 'a');
    // printf("\n");
    // for (int i = 1; i < n; ++i)
    //     printf("%2d ", anc[i]);
    // printf("\n");

    return 0;
}