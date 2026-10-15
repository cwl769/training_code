#include <cstdio>
#include <vector>
#include <queue>

std::vector<int> vec = {0, 3, 6, 9, 12, 15, 5, 10};

void test(int x) {
    for (int y = 0; y < 16; y += 3) {
        bool can = false;
        for(auto t : vec) {
            int xx = x ^ t;
            int yy = y ^ t;
            if(xx % 3 == 0 && yy % 3 == 0) {
                printf("%d %d ok %d\n", x, y, t);
                can = true;
                break;
            }
        }
        if(!can)
            printf("fatal: cannot %d %d\n", x, y);
    }
}

int main() {
    test(5);
    test(10);

    return 0;
}