#include <cstdio>
#include <cassert>

bool edg[2010][2010];

char op[10];
char str[100010];

int main() {
    fprintf(stderr, "Data preparing ...\n");
    fflush(stderr);
    FILE * input = fopen("e.in", "r");
    int n, m;fscanf(input, "%d%d", &n, &m);
    int tot = (1<<n);
    for(int i=0;i<m;++i) {
        int x, y;fscanf(input, "%d%d", &x, &y);
        edg[x][y] = edg[y][x] = 1;
    }
    int ans = 0;
    for(int i=0;i<tot;++i)
    for(int j=i+1;j<tot;++j)
        if(edg[i][j])
            ++ans;
    
    fprintf(stderr, "Data prepared, starting test ...\n");
    fprintf(stderr, "answer is %d\n", ans);
    fflush(stderr);
    
    printf("%d\n", n);
    fflush(stdout);

    while(1) {
        scanf("%s%s", op, str);
        fprintf(stderr, "[Receive]|%s| |%s|\n", op, str);
        fflush(stderr);
        if(op[0] == '?') {
            int cnt = 0;
            for(int i=0;i<tot;++i) {
                if(str[i]=='1') {
                    ++cnt;
                }
            }
            assert(cnt == tot / 2);
            int ret = 0;
            for(int i=0;i<tot;++i)
            for(int j=i+1;j<tot;++j)
                if(edg[i][j] && (str[i]=='1' || str[j]=='1'))
                    ++ret;
            printf("%d\n", ret);
            fflush(stdout);
            fprintf(stderr, "[Send]%d\n", ret);
            fflush(stderr);
        } else {
            int x;sscanf(str, "%d", &x);
            if(ans == x)
                fprintf(stderr, "Accepted!\n");
            else
                fprintf(stderr, "Wrong Answer");
            fflush(stderr);
            return ans != x;
        }
    }

    return 0;
}