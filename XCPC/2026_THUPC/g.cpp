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

char str[500010];

int main() {
    int T;readInt(T);
    for(;T;--T) {
        int n;readInt(n);
        scanf("%s", str+1);
        std::vector<int> a, b;
        std::vector<int> s[2]{std::vector<int>(n+1), std::vector<int>(n+1)};
        for(int i=1;i<=n;++i) {
            s[str[i]-'0'][i] = s[str[i]-'0'][i-1]+1;
            s[(str[i]-'0')^1][i] = s[(str[i]-'0')^1][i-1];
        }
        for(int i=n;i>=1;--i) {
            // if(a.size()==b.size()) {
            //     int j=i;
            //     for(;j>0&&str[j]=='1';--j) {
            //         if(i-j+1>=s[1][j-1]) {
            //             --j;
            //             break;
            //         }
            //     }
            //     if(j==i) {
            //         a.push_back(0);
            //     } else {
            //         for(int t=j+1;t<=i;++t)
            //             a.push_back(1);
            //         i = j+1;
            //     }
            //     continue;
            // }
            if(str[i] == '1') {
                if(a.size() < s[1][i])
                    a.push_back(1);
                else
                    b.push_back(1);
            } else {
                a.push_back(0);
            }
        }
        a.resize(std::max(a.size(), b.size()));
        b.resize(std::max(a.size(), b.size()));
        // for(auto x:a)
        //     printf("%d", x);
        // printf("\n");
        // for(auto x:b)
        //     printf("%d", x);
        // printf("\n");
        std::vector<int> ans;
        int tmp = 0;
        for(int i=0;i<(int)a.size();++i) {
            ans.push_back(a[i] ^ b[i] ^ tmp);
            if(a[i] + b[i] + tmp > 1) {
                tmp = 1;
            } else {
                tmp = 0;
            }
        }
        ans.push_back(tmp);
        while((int)ans.size()>1&&ans.back()==0)ans.pop_back();
        for(auto it=ans.rbegin();it!=ans.rend();++it) {
            printf("%d", *it);
        }
        printf("\n");
    }

    return 0;
}