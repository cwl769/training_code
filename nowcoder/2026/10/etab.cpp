#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[30][30][30][30][30], det[5];
int bct(int x) {
    int res = 0;
    while (x) {
        if (x & 1) res += 1;
        x >>= 1;
    }
    return res;
}
int dfs(int a, int b, int c, int d, int e) {
    if (dp[a][b][c][d][e] != INF) return dp[a][b][c][d][e];
    int pre;
    for (int msk = 0; msk < (1 << 5); msk++)
        if (bct(msk) == 3) {
            for (int i = 0; i <= 4; i++) {
                if ((msk >> i) & 1) det[i] = 1;
                else det[i] = 0;
            }
            if (a >= det[0] && b >= det[1] && c >= det[2] && d >= det[3] && e >= det[4]) {
                pre = dfs(a - det[0], b - det[1], c - det[2], d - det[3], e - det[4]);
                if (pre != -1) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], pre + 1);
            }
        }
    if (a >= 2) {
        pre = dfs(a - 2, b, c, d, e);
        if (pre != -1) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], pre + 1);
    }
    if (b >= 2) {
        pre = dfs(a, b - 2, c, d, e);
        if (pre != -1) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], pre + 1);
    }
    if (c >= 2) {
        pre = dfs(a, b, c - 2, d, e);
        if (pre != -1) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], pre + 1);
    }
    if (d >= 2) {
        pre = dfs(a, b, c, d - 2, e);
        if (pre != -1) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], pre + 1);
    }
    if (e >= 2) {
        pre = dfs(a, b, c, d, e - 2);
        if (pre != -1) dp[a][b][c][d][e] = min(dp[a][b][c][d][e], pre + 1);
    }
    if (dp[a][b][c][d][e] == INF) dp[a][b][c][d][e] = -1;
    return dp[a][b][c][d][e];
}

typedef long long i64;

i64 cal(i64 a, i64 b, i64 c, i64 d, i64 e) {
    if(a == 0 && b == 0) {
        i64 ans = 0;
        i64 mn = std::min({c, d, e});
        ans += mn;
        c -= mn;
        d -= mn;
        e -= mn;
        ans += c / 2;
        ans += d / 2;
        ans += e / 2;
        return ans;
    }
    if(a == 0) {
        i64 ans = 0;
        if(b == 1) {
            if((c&1) == (d&1)) {
                ans = 1 + cal(0, 0, c - 1, d - 1, e);
            } else if((c&1) == (e&1)) {
                ans = 1 + cal(0, 0, c - 1, d, e - 1);
            } else if((d&1) == (e&1)) {
                ans = 1 + cal(0, 0, c, d - 1, e - 1);
            }
        } else {
            
        }
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int a = 0; a <= 10; a++)
        for (int b = 0; b <= 10; b++)
            for (int c = 0; c <= 10; c++)
                for (int d = 0; d <= 10; d++)
                    for (int e = 0; e <= 10; e++)
                        dp[a][b][c][d][e] = INF;
    dp[0][0][0][0][0] = 0;
    for (int a = 0; a <= 10; a++)
        for (int b = 0; b <= 10; b++)
            for (int c = 0; c <= 10; c++)
                for (int d = 0; d <= 10; d++)
                    for (int e = 0; e <= 10; e++){
                        int ans = dfs(a, b, c, d, e);
                        if(a > b || b > c || c > d || d > e)
                            continue;
                        int tmp = cal(a, b, c, d, e);
                        if(ans != -1 && ans != tmp && a == 0 && b)
                            // cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << ans << ' ' << tmp << '\n';
                            printf("%2d %2d %2d %2d %2d %2d %2d\n", a, b, c, d, e, ans, tmp);
                    }
    return 0;
}