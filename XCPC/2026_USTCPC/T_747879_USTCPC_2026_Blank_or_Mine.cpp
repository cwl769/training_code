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
typedef std::vector<int> vector;

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

char str[300010];
char ans[300010];

int n;

void update_left(int x) {
    while (x - 3 > 0 && ans[x - 3] == '?') {
        if(str[x-1]=='*' || str[x-2]=='*')
            break;
        int d = str[x-1] - str[x-2];
        if(d == 1) {
            ans[x-3] = '.';
        } else if(d == 0) {
            ans[x-3] = ans[x];
        } else if(d == -1) {
            ans[x-3] = '*';
        }
        x -= 3;
    }
}

void update_right(int x) {
    while (x + 3 <= n && ans[x + 3] == '?') {
        if(str[x+1] == '*' || str[x+2] == '*')
            break;
        int d = str[x+2] - str[x+1];
        if(d == 1) {
            ans[x + 3] = '*';
        } else if(d == 0) {
            ans[x + 3] = ans[x];
        } else if(d == -1) {
            ans[x + 3] = '.';
        }
        x += 3;
    }
}

void update(int x) {
    update_left(x);
    update_right(x);
}

void solve() {
    scanf("%s", str+1);
    n = strlen(str+1);

    for(int i=1;i<=n;++i) {
        if(str[i] == '*')
            continue;
        int cnt = 0;
        if(i>1 && str[i-1] == '*')
            ++cnt;
        if(i<n && str[i+1] == '*')
            ++cnt;
        str[i] -= cnt;
    }

    for(int i=1;i<=n;++i) {
        ans[i] = '?';
    }
    ans[0] = ans[n+1] = '.';
    update_right(0);
    update_left(n+1);

    for(int i=2;i<=n-2;++i) {
        if(str[i]!='*' && str[i+1]!='*') {
            int d = str[i+1] - str[i];
            if(d == 1) {
                ans[i-1] = '.';
                ans[i+2] = '*';
                update_left(i-1);
                update_right(i+2);
            } else if(d == -1) {
                ans[i-1] = '*';
                ans[i+2] = '.';
                update_left(i-1);
                update_right(i+2);
            }
        }
    }



    bool conti = true;
    while (conti) {
        conti = false;
        for(int i=1;i<=n;++i) {
            if(str[i] == '*')
                continue;
            int mine = str[i] - '0';
            if(i>1 && ans[i-1] == '*')
                --mine;
            if(i<n && ans[i+1] == '*')
                --mine;
            if(ans[i] == '*')
                --mine;
            int sp = 3-(str[i] - '0');
            if(i == 1)
                --sp;
            if(i == n)
                --sp;
            if(i>1 && ans[i-1] == '.')
                --sp;
            if(i<n && ans[i+1] == '.')
                --sp;
            if(ans[i] == '.')
                --sp;
            int cnt = 0;
            if(i>1 && ans[i-1] == '?')
                ++cnt;
            if(i<n && ans[i+1] == '?')
                ++cnt;
            if(ans[i] == '?')
                ++cnt;
            if(cnt == mine) {
                for(int d=-1;d<=1;++d) {
                    if(ans[i+d] == '?') {
                        ans[i+d] = '*';
                        update(i+d);
                        conti = true;
                    }
                }
            }
            if(sp == cnt) {
                for(int d=-1;d<=1;++d) {
                    if(ans[i+d] == '?') {
                        ans[i+d] = '.';
                        update(i+d);
                        conti = true;
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;++i)
        putchar(ans[i]);
    putchar('\n');
}

int main() {
    int T;readInt(T);
    while(T--) {
        solve();
    }

    return 0;
}