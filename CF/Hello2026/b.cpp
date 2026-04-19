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

void add(int x, std::multiset<int>& set, std::set<int>& emp) {
    if(set.find(x) == set.end()) {
        emp.erase(x);
    }
    set.insert(x);
}

void del(int x, std::multiset<int>& set, std::set<int>& emp) {
    set.erase(set.find(x));
    if(set.find(x) == set.end()) {
        emp.insert(x);
    }
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n, k;readInt(n, k);
        std::vector<int> a(n+1);
        for(int i=1;i<=n;++i)
            readInt(a[i]);
        std::multiset<int> set;
        std::set<int> emp;
        for(int i=0;i<=n+1;++i)
            emp.insert(i);
        
        for(int i=1;i<=n;++i)
            add(a[i], set, emp);
        int ans = std::min(k-1, *emp.begin());
        printf("%d\n", ans);
    }

    return 0;
}