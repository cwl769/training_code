#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > heap;

int main() {
    int q;scanf("%d", &q);
    for(;q;--q) {
        int t;scanf("%d", &t);
        if(t == 1) {
            int x;scanf("%d", &x);
            heap.push(x);
        } else {
            int ans = heap.top();
            heap.pop();
            printf("%d\n", ans);
        }
    }


    return 0;
}