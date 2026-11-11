#include <cstdio>
#include <algorithm>
#include <vector>
typedef std::pair<int, int> PII;

int main() {
    std::vector<PII> set;
    for (int a = 2; a <= 100000; ++a) {
        for (int d = 1; d <= 150; ++d) {
            set.emplace_back(a, a + d);
        }
    }
    printf("%d\n", set.size());
    for(auto [x, y] : set)
        printf("%d %d\n", x, y);

    return 0;
}