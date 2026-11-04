#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

bool vsd[26][100010];
bool vac[26][100010];
int sd[26], ac[26];

bool sta[26];
bool ans[26];

struct Submission {
    int team, prob, res, time;
};

bool check(int time, int prob) {
    if(time >= 240) return true;
    if(ac[prob] >= 50)return true;
    if(sd[prob] > 0 && 5 * ac[prob] >= sd[prob])
        return true;
    return false;
}

int main() {
    int n, m, q;scanf("%d%d%d", &n, &m, &q);
    std::map<std::string, int> map;
    std::vector<Submission> sub(q);
    for (int i = 0; i < q; ++i) {
        std::string name, prob, res;int time;
        std::cin >> name >> prob >> res >> time;
        // printf("[%d] \n", i);
        if(map.find(name) == map.end()) {
            sub[i].team = map.size();
            map[name] = sub[i].team;
        } else {
            sub[i].team = map[name];
        }
        sub[i].prob = prob[0] - 'A';
        sub[i].res = (int)(res == "AC");
        sub[i].time = time;
    }
    auto it = sub.begin();
    for (int t = 1; t <= 299; ++t) {
        while(it != sub.end() && it->time == t) {
            if(!vsd[it->prob][it->team]) {
                vsd[it->prob][it->team] = 1;
                ++sd[it->prob];
            }
            if(it->res) {
                if(!vac[it->prob][it->team]) {
                    vac[it->prob][it->team] = 1;
                    ++ac[it->prob];
                }
            }

            ++it;
        }
        for (int prob = 0; prob < n; ++prob) {
            bool cur = check(t, prob);
            if(sta[prob] && !cur)
                ans[prob] = 1;
            sta[prob] = cur;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if(ans[i]) ++cnt;
    if(cnt == 0) {
        printf("-");
    } else {
        for (int i = 0; i < n; ++i)
            if(ans[i])
                printf("%c", 'A' + i);
    }
    printf("\n");


    return 0;
}