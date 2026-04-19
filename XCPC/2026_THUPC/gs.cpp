#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int t, n, a[N + 5], b[N + 5];
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    queue<int> q;
    int pa = 0, pb = 0, cnt = 0, cnta = 0, cntb = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '1') {
            cnt += 1;
            if (pa <= pb)
                a[++pa] = 1, cnta += 1;
            else
                b[++pb] = 1, cntb += 1;
        }
        else q.push(cnt);
        while (!q.empty()) {
            int x = q.front();
            if (x <= cnta || x <= cntb) {
                if (pa >= pb) a[++pa] = 0;
                else b[++pb] = 0;
                q.pop();
            }
            else break;
        }
    }
    for(int i=1;i<=pa;++i)
        printf("%d", a[i]);
    printf("\n");
    for(int i=1;i<=pb;++i)
        printf("%d", b[i]);
    printf("\n");
    vector<int> ans;
    int tmp = 0;
    for (int i = 1; i <= max(pa, pb); i++) {
        if (a[i] + b[i] + tmp >= 2) {
            ans.push_back((a[i] + b[i] + tmp) % 2);
            tmp = 1;
        }
        else {
            ans.push_back(a[i] + b[i] + tmp);
            tmp = 0;
        }
        a[i] = b[i] = 0;
    }
    if (tmp) ans.push_back(1);
    else ans.push_back(0);
    reverse(ans.begin(), ans.end());
    int p = 0;
    while (p < ans.size() - 1 && ans[p] == 0) p += 1;
    for (; p < ans.size(); p++) cout << ans[p];
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}