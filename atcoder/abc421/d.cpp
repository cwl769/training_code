#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
typedef long long int64;

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

bool towards(int64 x[2], int d, int64 y[2]) {
    int px = ((int)(y[1] - x[1] < 0) << 1);
    px |= ((int)(y[0] - x[0] < 0) ^ (px>>1));
    return d == px || d == (px + 1) % 4;
}

int64 f(int64 p[2][2], int d[2], int cnt) {
    if(d[0] == d[1]) {
        if(p[0][0] == p[1][0] && p[0][1] == p[1][1])
            return cnt;
        else
            return 0;
    }
    if(p[0][0] == p[1][0] && p[0][1] == p[1][1])
        return 0;
    if((d[0]^0b10) == d[1]) {
        int t = (d[0] & 1);
        if(p[0][t^1] != p[1][t^1])return 0;
        if(std::abs(p[0][t] - p[1][t]) & 1)return 0;
        if((p[0][t] < p[1][t]) ^ (d[1]>>1))return 0;
        if(cnt * 2 < std::abs(p[0][t] - p[1][t]))return 0;
        return 1;
    }
    if(std::abs(p[0][0] - p[1][0]) != std::abs(p[0][1] - p[1][1]))return 0;
    if(!towards(p[0], d[0], p[1]) || !towards(p[1], d[1], p[0]))return 0;
    if(cnt < std::abs(p[0][0] - p[1][0]))return 0;
    return 1;
}

int g(char c) {
    switch (c)
    {
    case 'D':
        return 0;
        break;
    case 'R':
        return 1;
        break;
    case 'U':
        return 2;
        break;
    case 'L':
        return 3;
        break;
    
    default:
        break;
    }
}

char str[10];
int d[2][100010];
int c[2][100010];

int main() {
    int64 ans = 0;
    int64 x1, y1, x2, y2;
    readInt(x1, y1, x2, y2);
    int64 n;int m, l;
    readInt(n, m, l);
    for(int i=1;i<=m;++i) {
        scanf("%s%d", str, &c[0][i]);
        d[0][i] = g(str[0]);
    }
    for(int i=1;i<=l;++i) {
        scanf("%s%d", str, &c[1][i]);
        d[1][i] = g(str[0]);
    }
    int64 curN = 0;
    int64 p[2][2] = {{x1, y1}, {x2, y2}};
    int ind[2];
    for(int i=1,j=1;curN < n;) {
        // printf("curN:%lld i:%d[%d] j:%d[%d]\n", curN, i, c[0][i], j, c[1][j]);
        ind[0] = d[0][i];
        ind[1] = d[1][j];
        int cnt;
        if(c[0][i] == c[1][j]) {
            // printf("==\n");
            ans += f(p, ind, c[0][i]);
            curN += c[0][i];
            cnt = c[0][i];
            p[0][d[0][i]&1] += ((d[0][i]>>1)?-1:1) * cnt;
            p[1][d[1][j]&1] += ((d[1][j]>>1)?-1:1) * cnt;
            ++i,++j;
        } else if(c[0][i] < c[1][j]) {
            // printf("<\n");
            ans += f(p, ind, c[0][i]);
            curN += c[0][i];
            cnt = c[0][i];
            p[0][d[0][i]&1] += ((d[0][i]>>1)?-1:1) * cnt;
            p[1][d[1][j]&1] += ((d[1][j]>>1)?-1:1) * cnt;
            c[1][j] -= c[0][i];++i;
        } else {
            // printf(">\n");
            ans += f(p, ind, c[1][j]);
            curN += c[1][j];
            cnt = c[1][j];
            p[0][d[0][i]&1] += ((d[0][i]>>1)?-1:1) * cnt;
            p[1][d[1][j]&1] += ((d[1][j]>>1)?-1:1) * cnt;
            c[0][i] -= c[1][j];++j;
        }
    }
    printf("%lld\n", ans);

    return 0;
}