#include <cstdio>
#include <algorithm>
#include <set>
#include <random>

int a[1000010];
int b[1000010];
int c[1000010];

void solve(int n) {
    int n2 = n / 2;
    for(int i = 0; i < n2; ++i) {
        a[i * 2 + 1] = i;
        a[i * 2] = n - 1 - a[i * 2 + 1];
        
        if(i + 1 < n2) {
            b[i * 2 + 1] = i + 1;
            b[i * 2] = n - 1 - b[i * 2 + 1];
        } else {
            b[i * 2] = a[0];
            b[i * 2 + 1] = a[1];
        }

        if(i + 1 == n / 4) {
            std::swap(b[i * 2], b[i * 2 + 1]);
        }
    }

    for(int i = 0 ; i <= n; ++i)
        c[i] = 0;
    for (int i = 0; i < n; ++i) {
        int t = c[i] + b[i] + a[i];
        if (t >= n) {
            ++c[i+1];
            c[i] = t - n;
        } else {
            c[i] = t;
        }
    }
    // for(int i = 0; i < n; ++i)
    //     printf("%d ", a[i]);
    // printf("\n");
    // for(int i = 0; i < n; ++i)
    //     printf("%d ", b[i]);
    // printf("\n");
    // for(int i = 0; i < n; ++i)
    //     printf("%d ", c[i]);
    // printf("\n");

}

bool is_per(int *arr, int n) {
    std::set<int> set;
    for (int i = 0; i < n; ++i)
        set.emplace(arr[i]);
    if((int)set.size() == n && *set.begin() == 0 && *set.rbegin() == n - 1)
        return true;
    return false;
}

int d[1000010];

bool check(int n) {
    if (!is_per(a, n)) 
        return false;
    if (!is_per(b, n)) 
        return false;
    if (!is_per(c, n)) 
        return false;
    for (int i = 0; i < n; ++i)
        if(a[i] == b[i] || a[i] == c[i] || b[i] == c[i])
            return false;
    for(int i = 0; i <= n; ++i)
        d[i] = 0;
    for(int i = 0; i < n; ++i) {
        int t = a[i] + b[i] + 
    }
    return true;
}

std::mt19937 Rand(std::random_device{}());

int rand(int l, int r) {
    return Rand() % (r - l + 1) + l;
}

int main() {
    for(;;) {
        int n = (rand(2, 500000) << 1);
        solve(n);
        if(!check(n)) {
            printf("wrong when n = %d\n", n);
            return 0;
        }
    }


    return 0;
}