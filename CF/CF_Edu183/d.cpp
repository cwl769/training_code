#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

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

int f[40][510];
std::vector<std::pair<int, int> > item(1);

void print(int n, int k) {
    if(f[n][k] == -1) return;
    int t = f[n][k];
    print(n - item[t].first, k - item[t].second);
    int c = item[t].first;
    if(n==c) {
        for(int i=1;i<n;++i)
            printf("%d ", i);
    } else {
        printf("%d ", n-1);
        for(int i=n-c;i<=n-2;++i)
            printf("%d ", i);
    }
}

int main() {
    for(int i=1;i<30;++i)
        item.push_back({i+1, i*(i+1)/2});
    // for(auto t:item) {
    //     printf("item:%d %d\n", t.first, t.second);
    // }
    f[0][0] = -1;
    for(int i=1;i<=30;++i)
    for(int j=1;j<=500;++j) {
        for(int t=0;t<item.size();++t) {
            int c = item[t].first;
            int v = item[t].second;
            if(i-c < 0 || j-v < 0)break;
            if(f[i-c][j-v]) {
                f[i][j] = t;
                break;
            }
        }
    }
    // for(int i=0;i<=5;++i) {
    //     for(int j=0;j<=10;++j)
    //         printf("%02d ", f[i][j]);
    //     printf("\n");
    // }
    int T;readInt(T);
    for(;T;--T) {
        int n, k;readInt(n, k);
        k = (n-1)*n/2 - k;
        // printf("query %d %d \n", n, k);
        int i=n;
        for(;i>1;--i) {
            if(f[i][k]) {
                print(i, k);
                for(int j=n;j>=i;--j)
                    printf("%d ", j);
                break;
            }
        }
        if(i==1) {
            if(k == 0) {
                for(int i=n;i>0;--i)
                    printf("%d ", i);
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}