#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
#include <set>
#include <stack>
#include <map>

const i64 inf = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    int n;
    scanf("%d", &n);
    veci sr(n + 2), sy(n + 2), sb(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        int r, y, b;
        scanf("%d%d%d", &r, &y, &b);
        sr[i] = sr[i - 1] + r;
        sy[i] = sy[i - 1] + y;
        sb[i] = sb[i - 1] + b;
    }
    veci py(n + 2), pb(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        py[i] = sr[i] - sy[i];
        pb[i] = sr[i] - sb[i];
    }
    std::vector<std::vector<std::pair<int, int>>> bx(n * 2 + 2), by(n * 2 + 2);
    for (int i = 1; i <= n; ++i)
    {
        int x = py[i];
        int y = pb[i];
        bx[x + n].emplace_back(y, i);
        by[y + n].emplace_back(x, i);
    }

    for (int x = -n; x <= n; ++x)
    {
        std::sort(bx[x + n].begin(), bx[x + n].end());
        std::sort(by[x + n].begin(), by[x + n].end());
    }

    veci64 f(n + 2);
    for (int i = 1; i <= n; ++i)
        f[i] = -inf;

    for (int i = 1; i <= n; ++i)
        if (py[i] >= 0 && pb[i] >= 0)
        {
            f[i] = 0;
        }

    i64 predp = 0;
    for (int j = 1; j <= n; ++j)
    {
        f[j] = std::max(f[j], predp - j);
        predp = std::max(predp, f[j] + j);
        int x = py[j];
        int y = pb[j];
        if (1)
        {
            auto it = std::lower_bound(bx[x + n].begin(), bx[x + n].end(), (std::pair<int, int>){y, 0});
            int len = it - bx[x + n].begin();
            for (; it != bx[x + n].end(); ++it)
            {
                int i = it->second;
                f[i] = std::max(f[i], f[j]);
            }
            while((int)bx[x + n].size() > len)
                bx[x + n].pop_back();
        }
        if (1)
        {
            auto it = std::lower_bound(by[y + n].begin(), by[y + n].end(), (std::pair<int, int>){x, 0});
            int len = it - by[y + n].begin();
            for (; it != by[y + n].end(); ++it)
            {
                int i = it->second;
                f[i] = std::max(f[i], f[j]);
            }
            while((int)by[y + n].size() > len)
                by[y + n].pop_back();
        }
    }
    printf("%lld\n", predp);

    return 0;
}