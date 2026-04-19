#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <queue>
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

struct dsu {
    int *fa;
    int N;
    dsu(int n) {
        N = n+10;
        fa = (int*)malloc(N*sizeof(int));
        for(int i=0;i<N;++i)
            fa[i] = i;
    }
    ~dsu() {free(fa);}
    int get(int x) {
        if(fa[x] == x)return x;
        return fa[x] = get(fa[x]);
    }
    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if(x==y)return;
        fa[x] = y;
    }
};

// bool check(int k, int n, std::vector<int>& a, std::vector<std::pair<int, int> >& sta, std::set<int>& set) {
//     for(int i=0;i<n;++i) {
//         int x = a[i];
//         int y = sta[i].first;
//         if(x==y)continue;
//         if(x > y) {continue;}
//         if( y-x>=k || 
//             set.lower_bound(y+k)!=set.end() || 
//             set.upper_bound(x-k)!=set.begin() || 
//             ( set.lower_bound(x+k)!=set.end() && set.upper_bound(y-k)!=set.begin() ))
//             continue;
//         else 
//             return false;
//     }
//     return true;
// }

int get(int x, std::vector<int>& fa) {
    if(fa[x] == x)return x;
    return fa[x] = get(fa[x], fa);
}

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        std::vector<int> a(n);
        std::vector<std::pair<int, int> > sta(n);
        for(int i=0;i<n;++i)
            readInt(a[i]);
        for(int i=0;i<n;++i)
            sta[i] = {a[i], i+1};
        std::sort(sta.begin(), sta.end());
        std::vector<int> fa[20], faa(n+1), val(n+1, 1e9+10);
        fa[0].resize(n+1);
        for(int i=1;i<=n;++i){
            fa[0][i] = i;
            faa[i] = i;
        }
        std::priority_queue< std::pair<int, std::pair<int, int> > > heap;
        for(int i=0;i<n-1;++i) {
            heap.push({sta[n-1].first - sta[i].first, {i, n-1}});
        }
        while((int)fa[0].size() < n*2) {
            auto tmp = heap.top();heap.pop();
            int x = sta[tmp.second.first].second;
            int y = sta[tmp.second.second].second;
            x = get(x, faa);
            y = get(y, faa);
            if(x!=y) {
                int rt = fa[0].size();
                fa[0][x] = rt;
                fa[0][y] = rt;
                faa[x] = rt;
                faa[y] = rt;
                fa[0].push_back(rt);
                faa.push_back(rt);
                val.push_back(tmp.first);
            }
            if(tmp.second.first != tmp.second.second - 1) {
                int i = tmp.second.first;
                int j = tmp.second.second - 1;
                heap.push({sta[j].first - sta[i].first, {i, j}});
            }
        }
        for(int i=1;i<20;++i)
            fa[i].resize(n*2);
        for(int t=1;t<20;++t)
        for(int i=0;i<n*2;++i) {
            fa[t][i] = fa[t-1][fa[t-1][i]];
        }
        auto lca = [](int x, int y)-> int {
            
        };
    }

    return 0;
}