#include <cstdio>
#include <random>

std::random_device random_device;
std::mt19937 gen(random_device());

bool map[2010][2010];

int main() {
    int n = 10, sup = 10;
    int tot = (1<<n);
    for(int i=0;i<sup;++i) {
        int x = gen() % tot;
        int y = gen() % tot;
        if(x == y)continue;
        map[x][y] = map[y][x] = 1;
    }
    int m = 0;
    for(int i=0;i<tot;++i)
    for(int j=i+1;j<tot;++j)
        if(map[i][j]) {
            ++m;
        }
    printf("%d %d\n", n, m);

    for(int i=0;i<tot;++i)
    for(int j=i+1;j<tot;++j)
        if(map[i][j]) {
            printf("%d %d\n", i, j);
        }

    return 0;
}