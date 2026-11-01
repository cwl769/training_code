#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
typedef long long i64;

const int wid = 20;

int id(int x, int nxt) {
    return (x + 10) * wid + nxt;
}

void cal(i64 n, std::vector<i64> &dis) {
    int lim = id(n, wid) + 100;
    dis.resize(0);
    dis.resize(lim, LLONG_MAX);
    dis[id(0, 0)] = 0;
    std::queue<int> q;
    q.emplace(id(0, 0));
    while(q.size()) {
        int tmp = q.front(); q.pop();
        int x = tmp / wid - 10;
        int k = tmp % wid;
        int y;
        //op 1
        if(k + 1 < wid && x + (1 << k) <= n) {
            y = id(x + (1 << k), k + 1);
            // printf("op1| y = %d (%d, %d)\n", y, x + (1 << k), k + 1);
            if(dis[tmp] + 1 < dis[y]) {
                dis[y] = dis[tmp] + 1;
                q.emplace(y);
            }
        }
        //op 2
        if(x - 1 >= -10) {
            y = id(x - 1, 0);
            // printf("op2| y = %d (%d, %d)\n", y, x - 1, 0);
            if(dis[tmp] + 1 < dis[y]) {
                dis[y] = dis[tmp] + 1;
                q.emplace(y);
            }
        }
    }
}

int lowbit(int x) {
    return x & (-x);
}

void printBit(i64 x, i64 w) {
    for (int i = w - 1; i >= 0; --i)
        printf("%d", (x >> i) & 1);
}

int f[1000010];

int main() {
    int n = 128;
    std::vector<i64> dis;
    cal(n, dis);
    int base = 0;
    for (int x = 0; x <= n; ++x) {
        if(x >= 8 && lowbit(x) == x) {
            base = x;
        }
        // printBit(x, 10);
        // printf("[%4d, %4d]", x, base);
        i64 ans = LLONG_MAX;
        int mnk = wid;
        for (int k = 0; k < wid; ++k){
            // ans = std::min(ans, dis[id(x, k)]);
            if(dis[id(x, k)] < ans) {
                ans = dis[id(x, k)];
                mnk = k;
            }
        }
        f[x] = ans;

        // printf("%d ", f[x] - f[x - base]);

        // printf("%2lld    |%2d    ", ans, mnk);
        // if(mnk)
        //     printf("|%3d ", x - (1 << mnk) + 1 - base);
        // if(lowbit(x + 1) == x + 1)
        //     printf("\n");

        // printf("\n");
    }

    for (int i = 0; i <= n; ++i) {
        printf("[%3d] %2d\n", i - 1, f[i] + 1);
    }

    i64 tmp = 0;
    for (int i = 0; i <= 1000; ++i)
        tmp += f[i];
    printf("sum: %lld\n", tmp);


    return 0;
}