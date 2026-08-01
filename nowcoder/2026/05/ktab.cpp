#include <cassert>
#include <cstdio>
#include <set>

int n = 10, k = 10;
int a[100];
int b[100];

void print() {
    printf("[");

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    
    printf("]\n");
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

int cal() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = ((ans << 2) | a[i]);
    }
    return ans;
}

int ans[100];

int main() {
    for (int sta = 0; sta < (1 << (n + n)); ++sta) {
        for (int i = 0, tmp = sta; i < n; ++i) {
            a[i] = (tmp & 0b11);
            tmp >>= 2;
        }
        ans[0] = cal();
        printf("##############################\n");
        print();
        for (int rnd = 1; rnd <= k; ++rnd) {
            run();
            print();
            ans[rnd] = cal();
            if (rnd >= 5) {
                assert(ans[rnd] == ans[rnd-2]);
            }
        }
    }

    return 0;
}
