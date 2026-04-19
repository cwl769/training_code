#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <deque>

template<typename T> 
void readInt(T& x) {
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9')c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * (T)10 + (c - '0');
    }
}
template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

struct Pers {
    int x, y, d;
    int id;
};

bool cmp(Pers a, Pers b) {
    return a.x < b.x;
}

std::deque<int> ans;

bool solve(std::vector<Pers>& vec, int n) {
    std::sort(vec.begin(), vec.end(), cmp);
    for(int cur=0,i=0;i<n;++i) {
        if(vec[i].y < cur)
            return false;
        cur = vec[i].y;
    }
    for(int cur=0,cd=0,i=0;i<n;++i) {
        // printf("[%d](cur:%d)%d %d %d %d\n", i, cur, vec[i].x, vec[i].y, vec[i].d, vec[i].id);
        if(vec[i].x < cur) {
            if(vec[i].d != cd)
                return false;
        } else {
            cd = vec[i].d;
        }
        cur = vec[i].y;
    }
    for(int cur=0,cd=0,i=0;i<n;++i) {
        if(vec[i].x < cur) {
            
        } else {
            cd = vec[i].d;
        }
        cur = vec[i].y;
        if(cd) {
            ans.push_back(vec[i].id);
        } else {
            ans.push_front(vec[i].id);
        }
    }
    return true;
}

int main() {
    int n;readInt(n);
    std::vector<Pers> vec(n);
    for(int i=0;i<n;++i) {
        readInt(vec[i].x, vec[i].y);
        vec[i].id = i+1;
        if(vec[i].x > vec[i].y) {
            std::swap(vec[i].x, vec[i].y);
            vec[i].d = 1;
        } else vec[i].d = 0;
    }
    bool ret = solve(vec, n);
    if(ret) {
        printf("Yes\n");
        for(auto it=ans.begin();it!=ans.end();++it) {
            printf("%d ", *it);
        }
    } else {
        printf("No\n");
    }


    return 0;
}