#include <cstdio>
#include <vector>

typedef std::vector<int> veci;

std::vector<std::pair<veci, veci> > func(int tot) {
    std::vector<std::pair<veci, veci> > ans(tot-1);
    if(tot == 2) {
        ans[0].first.push_back(0);
        ans[0].second.push_back(1);
        return ans;
    }
    if(tot == 4) {
        ans[0].first = {0, 1};
        ans[0].second = {2, 3};
        ans[1].first = {0, 2};
        ans[1].second = {1, 3};
        ans[2].first = {0, 3};
        ans[2].second = {1, 2};
        return ans;
    }
    auto prev = func(tot / 2);
    int tot2 = tot/2;
    int tot4 = tot2/2;
    if(tot == 8) {
        for(int i=0,cur=0;i<tot2;++i,++cur) {
            ans[i].first.push_back(cur);
            ans[i].second.push_back(cur+tot2);
            for(int x=0;x<tot2;++x) {
                if(x == cur)
                    continue;
                ans[i].first.push_back(x+tot2);
                ans[i].second.push_back(x);
            }
        }
    } else {
        for(int i=0;i<tot4;++i)
            ans[i] = prev[i];
        int len = tot4;
        for(int i=0;i<tot4;++i) {
            for(int j=0;j<len;++j)
                ans[i].first.push_back(ans[i].second[j]+tot2);
            for(int j=0;j<len;++j)
                ans[i].second.push_back(ans[i].first[j]+tot2);
        }
        for(int i=0;i<tot4;++i) {
            // ans[i+tot4]
            for(auto x:prev[i].first) {
                if(x<tot4) {
                    ans[i+tot4].first.push_back(x);
                    ans[i+tot4].first.push_back(x+tot4);
                } else {
                    ans[i+tot4].first.push_back(x+tot4);
                    ans[i+tot4].first.push_back(x+tot4+tot4);
                }
            }
            for(auto x:prev[i].second) {
                if(x<tot4) {
                    ans[i+tot4].second.push_back(x);
                    ans[i+tot4].second.push_back(x+tot4);
                } else {
                    ans[i+tot4].second.push_back(x+tot4);
                    ans[i+tot4].second.push_back(x+tot4+tot4);
                }
            }
        }
    }

    for(int i=tot2;i<tot-1;++i) {
        for(auto x:prev[i-tot2].first) {
            ans[i].first.push_back(x);
        }
        for(auto x:prev[i-tot2].first) {
            ans[i].first.push_back(x+tot2);
        }
        for(auto x:prev[i-tot2].second) {
            ans[i].second.push_back(x);
        }
        for(auto x:prev[i-tot2].second) {
            ans[i].second.push_back(x+tot2);
        }
    }
    return ans;
}

typedef long long i64;

i64 f[2010][2010];

int main() {
    int n = 10;
    int tot = (1<<n);
    
    auto query = func(tot);
    for(auto &[vec1, vec2]:query) {
        for(int i=0;i<tot;++i)
        for(int j=0;j<tot;++j) {
            if(i == j)continue;
            ++f[i][j];
        }
        for(auto x:vec1)
        for(auto y:vec2) {
            ++f[x][y];
            ++f[y][x];
        }
    }

    for(int i=0;i<tot;++i) {
        for(int j=0;j<tot;++j)
            printf("%3lld ", f[i][j]);
        printf("\n");
    }

    // for(auto &[vec1, vec2]:query) {
    //     for(auto x:vec1)
    //         printf("%d ", x);
    //     printf("\n");
    //     for(auto x:vec2)
    //         printf("%d ", x);
    //     printf("\n");
    //     printf("-----------------\n");
    // }

    return 0;
}