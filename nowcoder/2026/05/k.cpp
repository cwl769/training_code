#include <cstdio>

int lim = 80;

int n, k;
int a[1000010], b[1000010];
int ans[2][1000010];

void print(int a[]) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}

bool set[10];

void run() {
    for (int i = 0; i < n; ++i) {
        set[0] = set[1] = set[2] = set[3] = 0;
        set[a[i]] = 1;
        set[a[(i + 1) % n]] = 1;
        set[a[(i + n - 1) % n]] = 1;
        for (int v = 0; v <= 3; ++v) {
            if (!set[v]) {
                b[i] = v;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i] = b[i];
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    for(int i = 0; i < n; ++i) {
        if(a[i] > 3)
            a[i] = 3;
    }
    
    if(k <= lim) {
        for(int rnd = 1; rnd <= k; ++rnd) {
            run();
        }
        print(a);
    } else {
        if(k & 1) {
            for(int rnd = 1; rnd <= lim - 1; ++rnd)
                run();
        } else {
            for(int rnd = 1; rnd <= lim; ++rnd)
                run();
        }
        print(a);
    }

    return 0;
}