#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5];
bool bk[N + 5];
int gb(int x, int k) {
    return (x >> k - 1) & 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0, cnt = 0;
    for (int i = 30; i >= 1; i--) {
        bool fl = true;
        int p10 = 0;
        vector<int> p01;
        for (int j = 2; j <= n; j++) {
            if (!gb(a[j - 1], i) && gb(a[j], i))
                p01.push_back(j - 1);
            if (gb(a[j - 1], i) && !gb(a[j], i)) {
                if (p10) fl = false;
                else p10 = j - 1;
            }
        }
        if (!fl) cnt += 1, ans += (1 << i - 1);
        else {
            if (p10) {
                if (!bk[p10]) {
                    if (cnt) {
                        cnt -= 1, bk[p10] = true;
                        for (auto p : p01) bk[p] = true;
                    }
                    else cnt += 1, ans += (1 << i - 1);
                }
                else for (auto p : p01) bk[p] = true;
            }
            else for (auto p : p01) bk[p] = true;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) bk[i] = false;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}