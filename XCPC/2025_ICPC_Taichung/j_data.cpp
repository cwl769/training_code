#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <random>

std::random_device random_device;
std::mt19937 Rand(random_device());

int main() {
    int n = 500000;
    printf("%d\n", n);
    for(int i=1;i<=n;++i) {
        printf("%d ", Rand()%n+1);
    }
    printf("\n");
    for(int i=1;i<n;++i) {
        printf("%d ", Rand()&(n-1)+1);
    }
    printf("\n");

    return 0;
}