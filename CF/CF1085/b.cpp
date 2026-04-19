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

// bool check(int x, int n, int m, int l, const std::vector<int>& a) {

// }

int main() {
    int T;readInt(T);
    while(T--) {
        int n, m, ed;readInt(n, m, ed);
        std::vector<int> a(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        std::reverse(a.begin(), a.end());
        std::multiset<int> set;
        for(int i=1;i<=std::min(n+1, m);++i)
            set.insert(0);
        for(int t=1;t<=ed;++t) {
            auto it = set.begin();
            int x = *it;
            set.erase(it);
            set.insert(x+1);

            if(!a.empty() && t == a.back()) {
                int v = *set.rbegin();
                set.erase(set.find(v));

                a.pop_back();

                if((int)set.size() < std::min(m, (int)a.size() + 1))
                    set.insert(0);
            }
        }
        printf("%d\n", *set.begin());
    }

    return 0;
}