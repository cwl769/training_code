#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

int next(int x, int n) {
    return x % n + 1;
}

int dis(int s, int t, int n) {
    int ans = 0;
    while(s != t) {
        s = next(s, n);
        ++ans;
    }
    return ans;
} 

int main() {
    int n, s, t;
    scanf("%d%d%d", &n, &s, &t);
    int d = dis(t, s, n);
    int cnt = (d + 1) / 2;
    while(cnt) {
        --cnt;
        t = next(t, n);
    }
    printf("%d\n", t);

    return 0;
}