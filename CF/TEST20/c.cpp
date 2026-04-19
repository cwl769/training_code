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

char op[10];

int main() {
    scanf("%s", op);
    if(strcmp(op, "first")==0) {
        int T;readInt(T);
        for(;T;--T) {
            int x;readInt(x);--x;
            int xorsum = 0;
            std::vector<int> ans;
            for(int i=0;i<15;++i) {
                if((x>>i)&1) {
                    ans.push_back(i);
                    xorsum ^= i+1;
                }
            }
            int cnt = 0;
            for(int i=0;i<4;++i) {
                if((xorsum>>i)&1) {
                    ans.push_back(15+i);
                    cnt ^= 1;
                }
            }
            if(cnt)
                ans.push_back(19);
            printf("%d\n", (int)ans.size());
            for(int i=0;i<(int)ans.size();++i)
                printf("%d ", ans[i]+1);
            printf("\n");
        }
    } else {
        int T;readInt(T);
        for(;T;--T) {
            int n;readInt(n);
            int val = 0;
            for(int i=1;i<=n;++i) {
                int x;readInt(x);
                val |= (1<<(x-1));
            }
            int cnt = 0;
            for(int i=0;i<4;++i) {
                if((val>>(i+15))&1) {
                    cnt ^= 1;
                }
            }
            int xorsum = 0;
            for(int i=0;i<15;++i) {
                if((val>>i)&1) {
                    xorsum ^= i+1;
                }
            }
            // printf("val:%x cnt:%d xorsum:%d\n", val, cnt, xorsum);
            if((cnt&1)==((val>>19)&1) && (xorsum^((val>>15)&0x0f)) ) {
                printf("%d\n", 1 + ((val ^ (1<<((xorsum^((val>>15)&0x0f))-1))) & ((1<<15)-1)));
            } else {
                printf("%d\n", 1 + (val & ((1<<15)-1)));
            }
        }
    }

    return 0;
}