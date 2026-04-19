#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

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

struct Monster {
    int blood, value;
};

bool operator < (const Monster& a, const Monster& b) {
    if(a.blood == b.blood)
        return a.value > b.value;
    return a.blood < b.blood;
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, m;readInt(n, m);
        std::multiset<int> sword;
        for(int i=1;i<=n;++i) {
            int x;readInt(x);
            sword.insert(x);
        }
        std::vector<int> b(m+1), c(m+1);
        std::vector<Monster> vec1;
        std::vector<int> vec2;
        for(int i=1;i<=m;++i)
            readInt(b[i]);
        for(int i=1;i<=m;++i)
            readInt(c[i]);
        for(int i=1;i<=m;++i) {
            if(c[i]==0) {
                vec2.push_back(b[i]);
            } else {
                vec1.push_back((Monster){
                    .blood = b[i],
                    .value = c[i]
                });
            }
        }
        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());
        int ans = 0;
        for(auto mons:vec1) {
            auto it = sword.lower_bound(mons.blood);
            if(it==sword.end())
                break;
            ++ans;
            if(*it < mons.value) {
                sword.erase(it);
                sword.insert(mons.value);
            }
        }
        for(auto mons:vec2) {
            auto it = sword.lower_bound(mons);
            if(it==sword.end())
                break;
            ++ans;
            sword.erase(it);
        }
        printf("%d\n", ans);
    }

    return 0;
}