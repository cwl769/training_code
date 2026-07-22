#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

constexpr int N = 1000010;
bool vis[N];
std::vector<int> prime;
void Euler() {
    vis[0] = vis[1] = 1;
    for (int x = 2; x < N; ++x) {
        if (!vis[x]) {
            prime.emplace_back(x);
        }
        for (auto p : prime) {
            int tmp = p * x;
            if (tmp >= N)
                break;
            vis[tmp] = 1;
            if (x % p == 0)
                break;
        }
    }
}

int main() {
    Euler();
    int n;
    scanf("%d", &n);
    std::vector<int> d;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0)
            d.push_back(i);
    }
    int siz = d.size();
    for (int i = 0; i < siz; ++i) {
        for (int j = i + 1; j < siz; ++j) {
            if (d[j] % d[i] == 0 && !vis[d[j] / d[i]]) {
                printf("%d %d %d\n", d[i], d[j], d[j] / d[i]);
            }
        }
    }


    return 0;
}
