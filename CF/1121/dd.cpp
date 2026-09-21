#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

i64 cal(int n, const veci& vec) {
    veci a = vec;
    for (int i = 1; i <= n; i += 2)
        a[i] = -a[i];
    i64 cnt = 0;
    for (int l = 1; l <= n; ++l) {
        int sum = 0;
        for (int r = l; r <= n; ++r) {
            sum += a[r];
            if(sum % 3 == 0)
                ++cnt;
        }
    }
    return cnt;
}

void solve(int n) {
    veci vec(n + 2);
    i64 mn = LLONG_MAX;
    for (int a = 1; a <= n; ++a)
    for (int b = a; b <= n; ++b)
    for (int c = b; c <= n; ++c) {
        vec[a] = 1;
        vec[b] = 1;
        vec[c] = 1;

        mn = std::min(mn, cal(n, vec));

        vec[a] = 0;
        vec[b] = 0;
        vec[c] = 0;
    }
    // printf("n = %4d| ", n);

    bool flag = 0;

    for (int a = 1; a <= n; ++a)
    for (int b = a; b <= n; ++b) 
    for (int c = b; c <= n; ++c) {
        if(flag) break;
        vec[a] = 1;
        vec[b] = 1;
        vec[c] = 1;

        if(mn == cal(n, vec)) {
            int t = (n + 2) / 3;
            // printf("%2d ,%2d| ", t, t&1);
            // printf("%2d %2d %2d |", a, b, c);
            for (int i = 1; i <= n; ++i)
                printf("%d", vec[i]);
            flag = 1;
            break;
        }

        vec[a] = 0;
        vec[b] = 0;
        vec[c] = 0;
    }

    printf("\n");
}

int main() {
    // printf("44\n");
    for (int n = 7; n <= 50; ++n)
        solve(n);
        // printf("%d\n", n);

    return 0;
}