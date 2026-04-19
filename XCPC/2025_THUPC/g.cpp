#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

template<typename T>
void readInt(T& x) {
    bool f = 0;
    x = 0;
    char c = getchar();
    for(;c<'0'||c>'9';c=getchar()){if(c=='-')f=!f;}
    for(;'0'<=c&&c<='9';c=getchar())
        x = x * 10 + (c - '0');
    if(f)x = -x;
}

template<typename T, typename ...ARGS>
void readInt(T& x, ARGS&... args) {
    readInt(x);
    readInt(args...);
}

char str[100010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        scanf("%s", str+1);
        int n = strlen(str+1);
        int w = 0, m = 0, w2 = 0, m2 = 0, wm = 0;
        int cntw = 0, cntm = 0;
        bool st = 0;//0--w, 1--m
        for(int i=1;i<=n;++i) {
            if(str[i] == 'X') {
                if(cntw + cntm) {
                    if(cntw == 0) {
                        ++m;
                    } else if(cntm == 0) {
                        ++w;
                    } else {
                        bool ed = (str[i-1] == 'M');
                        if(st ^ ed) ++wm;
                        else {
                            if(st)++m2;
                            else ++w2;
                        }
                    }
                    cntw = cntm = 0;
                }
            } else {
                if(cntw == 0 && cntm == 0) {
                    st = (str[i]=='M');
                }
                if(str[i] == 'W')
                    ++cntw;
                else
                    ++cntm;
            }
        }
        if(cntw + cntm) {
            if(cntw == 0) {
                ++m;
            } else if(cntm == 0) {
                ++w;
            } else {
                bool ed = (str[n] == 'M');
                if(st ^ ed) ++wm;
                else {
                    if(st)++m2;
                    else ++w2;
                }
            }
            cntw = cntm = 0;
        }
        bool wf = true;
        if(wm&1) {
            m += 1;
            wf ^= 1;
        } else {
        }
        
    }

    return 0;
}