#include <cstdio>
#include <queue>

int main() {
    int n;scanf("%d", &n);
    std::priority_queue<int, std::vector<int>, std::greater<int> > heap;

    for(int i=1;i<=n;++i) {
        int op;scanf("%d", &op);
        if(op==1) {
            int x;scanf("%d", &x);
            heap.push(x);
        } else if(op==2) {
            printf("%d\n", heap.top());
        } else {
            heap.pop();
        }
    }

    return 0;
}
