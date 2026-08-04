#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long i64;

int *getsa(char *str) {
    int n = strlen(str);
    int *cursa = (int *)calloc(n, sizeof(int));
    int *currk = (int *)calloc(n * 2, sizeof(int));
    int *sa = (int *)calloc(n, sizeof(int));
    int *rk = (int *)calloc(n * 2, sizeof(int));
    size_t cnt_size = std::max(n + 1, 128);
    int *cnt = (int *)calloc(cnt_size, sizeof(int));
    for (int i = 0; i < n; ++i)
        ++cnt[(int)str[i]];
    for (int i = 1; i < 128; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i)
        cursa[--cnt[str[i]]] = i;
    for (int i = 0, p = 1; i < n; ++i) {
        if (i && str[cursa[i]] != str[cursa[i - 1]])
            ++p;
        currk[cursa[i]] = p;
    }
    for (int w = 1; w < n; w <<= 1) {
        std::swap(currk, rk);
        std::swap(cursa, sa);
        for (int i = n - w; i < n; ++i)
            cursa[i - (n - w)] = i;
        for (int i = 0, p = w - 1; i < n; ++i)
            if (sa[i] >= w)
                cursa[++p] = sa[i] - w;
        memset(cnt, 0, cnt_size * sizeof(int));
        std::swap(cursa, sa);
        for (int i = 0; i < n; ++i)
            ++cnt[rk[sa[i]]];
        for (int i = 1; i <= n; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i)
            cursa[--cnt[rk[sa[i]]]] = sa[i];
        int p = 1;
        for (int i = 0, cur, last = -1; i < n; ++i) {
            cur = cursa[i];
            if (i && (rk[cur] != rk[last] || rk[cur + w] != rk[last + w]))
                ++p;
            currk[cur] = p;
            last = cur;
        }
        if (p == n)
            break;
    }

    free(currk);
    currk = nullptr;
    free(rk);
    rk = nullptr;
    free(sa);
    sa = nullptr;
    free(cnt);
    cnt = nullptr;
    return cursa;
}

struct Fenwick {
    int *c, N;
    Fenwick(int n) {
        N = n + 10;
        c = (int*)calloc(N, sizeof(int));
    }
    Fenwick() {
        free(c);
    }
    void add(int x, int v) {
        ++x;
        for(;x<N;x += (x&(-x)))
            c[x] += v;
    }
    int get(int x) {
        int ans = 0;
        for(;x;x -= (x&(-x)))
            ans += c[x];
        return ans;
    }
    int sum(int l, int r) {
        ++l;++r;
        return get(r) - get(l - 1);
    }
};

char str[50010];

int main() {
    freopen("suffix.in", "r", stdin);
    freopen("suffix.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", str);
    int *sa = getsa(str);
    int *rk = (int*)calloc(n + 10, sizeof(int));
    for (int i = 0; i < n; ++i) {
        rk[sa[i]] = i;
    }
    
    int *h = (int*)calloc(n + 10, sizeof(int));
    h[0] = 0;
    for (int i = 0, cur = 0; i < n; ++i) {
        if(rk[i] == 0)
            continue;
        if(cur)
            --cur;
        while(str[sa[rk[i]] + cur] == str[sa[rk[i] - 1] + cur])
            ++cur;
        h[rk[i]] = cur;
    }
    
    Fenwick tree(n);
    i64 ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += tree.sum(sa[i], n);
        tree.add(sa[i], 1);
    }
    
    for(int i = 1, cnt = 1; i < n; ++i) {
        if(h[i] >= m) {
            ans -= cnt;
            ++cnt;
        } else {
            cnt = 1;
        }
    }

    printf("%lld\n", ans);


    fclose(stdin);
    fclose(stdout);
    return 0;
}