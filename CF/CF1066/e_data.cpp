#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <random>

typedef long long int64;

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

std::random_device random_device;
std::mt19937 Rand(random_device());

int main() {
    int T = 100000;
    printf("%d\n", T);
    for(int id=1;id<=T;++id) {
        int n = 4, k = Rand()%4+1;
        printf("%d %d\n", n, k);

        for(int i=1;i<=n;++i)
            printf("%d ", Rand()%(n*2)+1);
        printf("\n");
    }

    // int rest = n;
    // while(1) {
    //     int cnt = Rand() % 7 + 1;
    //     int v = Rand() % (n*2) + 1;
    //     if(cnt >= rest) {
    //         for(int i=1;i<=rest;++i)
    //             printf("%d ", v);
    //         break;
    //     } else {
    //         for(int i=1;i<=cnt;++i)
    //             printf("%d ", v);
    //         rest -= cnt;
    //     }
    // }

    return 0;
}