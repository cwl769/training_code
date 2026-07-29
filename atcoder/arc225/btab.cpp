#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>

int sg[1024];

bool valid(int s) {
    if (s == 0)
        return false;
    for (int i = 1; i < 30; ++i) {
        if (((s >> i) & 1) && ((s >> (i - 1)) & 1))
            return false;
    }
    return true;
}

int mex(std::set<int> &set) {
    int ans = 0;
    for (auto x : set) {
        if (x == ans) {
            ++ans;
        } else {
            break;
        }
    }
    return ans;
}

void printBit(int x, int width) {
    for (int i = width - 1; i >= 0; --i) {
        putchar('0' + ((x>>i)&1));
    }
}

int main() {
    memset(sg, -1, sizeof(sg));
    int n = 8;
    int cov = (1 << n);
    sg[0] = 0;
    for (int s = 0; s < cov; ++s) {
        if (~sg[s])
            continue;
        std::set<int> set;
        for (int t = s;; t = (t - 1) & s) {
            int dif = (t ^ s);
            if (valid(dif)) {
                set.insert(sg[t]); 
            }
            if (t == 0)
                break;
        }
        sg[s] = mex(set);
    }
    for (int s = 0; s < cov; ++s) {
        printf("[%3d] %2d %c ", s, sg[s], (sg[s] == 0) ? '#' : ' ');
        printBit(s, n);
        printf("\n");
    }
    printf("n = %d\n", n);

    return 0;
}
