#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define itn int
typedef long long int64;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

#define debug(...) fprintf(stderr, __VA_ARGS__)

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

/*
bool check(i64 m, veci64 arr, const veci64& a, const int k) {
    for(auto x:a) {
        int i = k - 1;
        while(i >= 0 && arr[i] + x > m)
            --i;
        if(i < 0)
            return false;
        arr[i] += x;
        for(;i<k-1;++i) {
            if(arr[i] <= arr[i+1])
                break;
            else
                std::swap(arr[i], arr[i+1]);
        }
    }
    return true;
}

veci64 gh(veci64 arr, int sta, const veci64& aa, const int n, const int k) {
    // printf("gh(%d)\ngh", sta);
    // for(auto x:arr)
    //     printf("%lld ", x);
    // printf("\n");
    veci64 a;
    for(int i=0;i<n;++i)
        if(!((sta>>i)&1)) {
            a.push_back(aa[i]);
        }
    // for(auto x:a)
    //     printf("%lld ", x);
    // printf("\n");
    std::sort(a.begin(), a.end(), std::greater<i64>());
    i64 vl = 0, vr = 2e10;
    while(vl < vr) {
        i64 mid = ((vl+vr)>>1);
        if(check(mid, arr, a, k))
            vr = mid;
        else
            vl = mid + 1;
    }
    i64 m = vl;
    // printf("gh%lld\n", m);
    for(auto x:a) {
        arr[0] += x;
        for(int i=0;i<k-1;++i) {
            if(arr[i] <= arr[i+1])
                break;
            else
                std::swap(arr[i], arr[i+1]);
        }
    }
    return arr;
}
*/

i64 gh(veci64 arr, int sta, const veci64& aa, const int n, const int k) {
    i64 ans = arr.back();
    for(int i=0;i<n;++i)
        if(!((sta>>i)&1)) {
            ans += (aa[i]);
        }
    return ans;
}

struct CMP {
    bool operator () (const std::pair<veci64, int>& a, const std::pair<veci64, int>& b) {
        return a.first.back() < b.first.back();
    }
};

void solve() {
    int n, k;readInt(n, k);
    veci64 a(n);
    for(int i=0;i<n;++i)
        readInt(a[i]);
    std::priority_queue<std::pair<i64, int>/*, std::vector<std::pair<i64, int> >, CMP */> heap;
    // heap.emplace(veci64(k, 0), 0);
    heap.emplace(0, 0);
    std::vector<bool> vis(1<<n);
    std::vector<veci64> dis(1<<n);
    dis[0] = veci64(k, 0);
    std::vector<i64> disv(1<<n);
    while(heap.size()) {
        int sta = heap.top().second;
        i64 arr = heap.top().first;
        heap.pop();
        printf("[%d]", sta);
        for(auto x:dis[sta])
            printf("%lld ", x);
        printf("\n");
        if(vis[sta])continue;
        vis[sta] = 1;
        if(sta == (1<<n) - 1) {
            printf("%lld\n", arr);
            break;
        }
        for(int i=0;i<n;++i) {
            if((sta>>i)&1)continue;
            veci64 tmp = dis[sta];
            tmp[0] += a[i];
            for(int i=0;i<k-1;++i) {
                if(tmp[i] <= tmp[i+1])
                    break;
                else
                    std::swap(tmp[i], tmp[i+1]);
            }
            int stay = (sta|(1<<i));
            auto curgh = gh(tmp, stay, a, n, k);
            if(curgh > disv[stay]) {
                dis[stay] = tmp;
                disv[stay] = curgh;
                heap.emplace(curgh, stay);
                printf("%d -> %d\n", sta, stay);
                for(auto x:dis[stay])
                    printf("%d ", x);
                printf("\n");
            }
        }
    }
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}