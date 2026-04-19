#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
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

char op[10];

void print0b(int x, int width) {
    if(width<=0)return;
    print0b(x>>1, width-1);
    putchar('0'+(x&1));
}

int rev(int x) {
    int ans = 0;
    for(int i=0;i<8;++i)
        ans |= (((x>>i)&1)<<(7-i));
    return ans;
}

int main() {
    std::map<int, int> set;
    for(int x=0;x<=0xff;++x) {
        int cnth=0, cntl=0;
        for(int i=0;i<4;++i) {
            if((x>>i)&1)
                ++cntl;
        }
        for(int i=4;i<8;++i) {
            if((x>>i)&1)
                ++cnth;
        }
        if(cnth > cntl) {
            set[x] = set.size();
        }
    }
    // for(auto x:set) {
    //     printf("{%d, %d}\n", x.first, x.second);
    // }
    scanf("%s", op);
    if(strcmp(op, "write")==0) {
        int v;readInt(v);
        v -= 1923;
        if(v<93) {
            auto it = set.begin();
            for(int i=0;i<v;++i)
                ++it;
            print0b(it->first, 8);
        } else {
            v -= 93;
            int x = 0;
            for(int i=0;i<4;++i) {
                if((v>>i)&1) {
                    x |= (1<<i);
                    x |= (1<<(7-i));
                }
            }
            print0b(x, 8);
        }
    } else {
        int x=0;
        scanf("%s", op);
        for(int i=0;i<8;++i)
            x = ((x<<1)|(op[i]-'0'));
        int cnth=0, cntl=0;
        for(int i=0;i<4;++i) {
            if((x>>i)&1)
                ++cntl;
        }
        for(int i=4;i<8;++i) {
            if((x>>i)&1)
                ++cnth;
        }
        if(cnth == cntl) {
            printf("%d\n", 1923+93+(x&0x0f));
        } else {
            if(cnth < cntl) {
                x = rev(x);
            }
            printf("%d\n", set[x]+1923);
        }
    }

    return 0;
}