#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>

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

std::vector<int> prime;
bool pvis[2000010];

void Euler() {
    pvis[0] = pvis[1] = 1;
    for(int x=2;x<2000010;++x) {
        if(!pvis[x]) {
            prime.push_back(x);
        }
        for(int j=0;;++j) {
            int64 t = 1ll * prime[j] * x;
            if(t>=2000010)
                break;
            pvis[t] = 1;
            if(x%prime[j] == 0)
                break;
        }
    }
}

int main() {
    // Euler();
    int T;readInt(T);
    while(T--) {
        int n, m;readInt(n, m);
        std::vector<int> a(n), b(m);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        for(int i=0;i<m;++i)
            readInt(b[i]);
        std::sort(a.begin(), a.end());
        a.resize(std::unique(a.begin(), a.end()) - a.begin());
        int size = n + m + 10;
        std::vector<int> vis(size);
        for(auto x:a) {
            for(int j=1;j*x<size;++j) {
                ++vis[j*x];
            }
        }
        int alice = 0, bob = 0, pub = 0;
        for(auto y:b) {
            if(vis[y] == (int)a.size())
                ++alice;
            else if(vis[y] == 0)
                ++bob;
            else
                ++pub;
        }
        if(pub&1)++alice;
        pub = 0;
        if(alice > bob)
            printf("Alice\n");
        else 
            printf("Bob\n");
    }

    return 0;
}