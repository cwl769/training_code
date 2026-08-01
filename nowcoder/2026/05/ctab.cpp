#include <algorithm>
#include <cstdio>
#include <vector>

void print(std::vector<int> &v) {
    for (auto x : v)
        printf("%d ", x);
    printf("\n");
}

int main() {
    int n = 12;
    std::vector<int> a(n);
    // for (int i = 0; i < n; ++i) {
    //     a[i] = i;
    // }
    a[0] = n - 1;
    a[1] = 0;
    for(int i = 2; i < n; i += 2) {
        a[i] = n - (i / 2) - 1;
        a[i+1] = n - 1 - a[i];
        
    }
    int cnt = 0;
    //do {
        std::vector<int> b = a;
        // if (!std::next_permutation(b.begin(), b.end()))
        //     continue;
        
        do {
            std::vector<int> c(n + 1);
            std::vector<int> d(n + 1);
            for (int i = 0; i < n; ++i) {
                int t = c[i] + b[i] + a[i];
                if (t >= n) {
                    ++c[i+1];
                    ++d[i+1];
                    c[i] = t - n;
                } else {
                    c[i] = t;
                }
            }
            std::vector<bool> vis(n + n);
            for (int i = 0; i < n; ++i)
                vis[c[i]] = 1;
            bool pm = true;
            for (int i = 0; i < n; ++i) {
                if (!vis[i] || a[i] == b[i] || a[i] == c[i] || b[i] == c[i]) {
                    pm = false;
                    break;
                }

                if ((i & 1) != d[i])
                {
                    pm = false;
                    break;
                }
            }
            if (pm && b[0] + b[1] == n - 1) {
                ++cnt;
                ///*
                print(a);
                print(b);
                print(c);
                print(d);
                printf("-------------------\n");
                //*/
            }
        } while(std::prev_permutation(b.begin(), b.end()));
    //} while(std::next_permutation(a.begin(), a.end()));
    printf("%d\n", cnt);

    return 0;
}
