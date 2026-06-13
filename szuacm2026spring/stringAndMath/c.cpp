#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

void manacher(char *str, int *d) {
    int n = strlen(str);
    int l = 0, r = -1;
    for(int i=0;i<n;++i) {
        if(r < i) {
            d[i] = 1;
        } else {
            d[i] = std::min(d[r+l-i], r - i + 1);
        }
        while(i-d[i]>=0 && i+d[i]<n && str[i-d[i]] == str[i+d[i]])
            ++d[i];
        if(i+d[i]-1 > r) {
            r = i + d[i] - 1;
            l = i - d[i] + 1;
        }
    }
}

char tmp[200010];
char str[200010];
int d[200010];

const int inf = 0x3f3f3f3f;

int main() {
    scanf("%s", tmp+1);
    int n = strlen(tmp+1);
    for(int i=1;i<=n;++i) {
        str[i*2-1] = tmp[i];
        str[i*2] = '#';
    }
    str[0] = '#';
    n <<= 1;
    manacher(str, d);

    // printf("%s\n", str+1);
    // for(int i=1;i<=n;++i)
    //     printf("%d", d[i]);
    // printf("\n");
    
    std::vector<std::pair<int, int> > opl, opr;

    for(int i=1;i<=n;++i) {
        int l = i+1, r = i+d[i];
        // printf("[%d, %d) add %d opl\n", l, r, i);
        //[l, r)
        opl.emplace_back(l,-i);
        opl.emplace_back(r, i);
    }
    for(int i=1;i<=n;++i) {
        int l = i-d[i], r = i-1;
        // printf("(%d, %d] add %d opr\n", l, r, i);
        //(l, r]
        opr.emplace_back(r, i);
        opr.emplace_back(l, -i);
    }

    std::sort(opl.begin(), opl.end());
    std::sort(opr.begin(), opr.end(), std::greater<std::pair<int, int> >());

    std::vector<int> mn(n+2, inf), mx(n+2, -inf);
    std::set<int> set;
    std::vector<std::pair<int, int> >::iterator it;
    
    set.clear();
    it = opl.begin();
    for(int i=1;i<=n;++i) {
        while(it!=opl.end() && it->first == i) {
            int val = it->second;
            if(val < 0)
                set.insert(-val);
            else
                set.erase(val);
            ++it;
        }
        if(set.size())
            mn[i] = std::min(mn[i], *set.begin());
    }

    set.clear();
    it = opr.begin();
    for(int i=n;i>=1;--i) {
        while(it!=opr.end() && it->first == i) {
            int val = it->second;
            if(val > 0)
                set.insert(val);
            else
                set.erase(-val);
            ++it;
        }
        if(set.size())
            mx[i] = std::max(mx[i], *set.rbegin());
    }

    // for(int i=1;i<=n;++i)
    //     printf("%d ", mn[i]);
    // printf("\n");
    // for(int i=1;i<=n;++i)
    //     printf("%d ", mx[i]);
    // printf("\n");

    int ans = 0;
    for(int i=2;i<=n;i+=2) {
        if(mn[i] == inf || mx[i] == -inf)
            continue;
        ans = std::max(ans, i - mn[i] + mx[i] - i);
    }
    printf("%d\n", ans);

    return 0;
}