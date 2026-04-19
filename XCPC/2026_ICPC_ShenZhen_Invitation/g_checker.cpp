#include <cstdio>
#include <cstring>
#include <random>
#include <algorithm>
#include <set>
#include <queue>

std::random_device random_device;
std::mt19937 gen(random_device());

struct Pos {
    int x, y;

    Pos operator + (Pos b) {
        return {x + b.x, y + b.y};
    }

    bool operator == (Pos b) {
        return x == b.x && y == b.y;
    }

    bool operator < (Pos b) const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
};


int rand(int l, int r) {
    return gen() % (r - l + 1) + l;
}

Pos choose(std::set<Pos> set) {
    int n = set.size();
    int d = rand(0, n-1);
    auto it = set.begin();
    for(int i=0;i<d;++i) {
        ++it;
    }
    return *it;
}

Pos delta(char c) {
    switch(c) {
        case 'U':
            return {-1, 0}; 
            break;
        case 'D':
            return {+1, 0}; 
            break;
        case 'L':
            return {0, -1}; 
            break;
        case 'R':
            return {0, +1}; 
            break;
    }
    return {0, 0};
}

char ans[1000010];

int main() {
    FILE * flog = fopen("g.log", "w");
    int T = 10000;
    printf("%d\n", T);
    fflush(stdout);
    while(T--) {
        int n = 5, m = 5;
        int sx = rand(1, n);
        int sy = rand(1, m);
        printf("%d %d %d %d\n", n, m, sx, sy);
        fflush(stdout);
        fprintf(flog, "--------------------\nnew game with [%d, %d, %d, %d]\n", n, m, sx, sy);
        fflush(flog);
        fprintf(stderr, "--------------------\nnew game with [%d, %d, %d, %d]\n", n, m, sx, sy);
        fflush(stderr);

        std::set<Pos> emp;
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) {
            if(i!=sx || j!=sy) {
                emp.insert({i, j});
            }
        }

        std::queue<Pos> body;
        body.push({sx, sy});

        for(int rnd=1;rnd<n*m;++rnd) {
            Pos app = choose(emp);
            printf("%d %d\n", app.x, app.y);
            fflush(stdout);
            fprintf(flog, "put an apple at {%d, %d}\n", app.x, app.y);
            fflush(flog);
            scanf("%s", ans+1);
            fprintf(flog, "receive operation string:\n%s\n", ans+1);
            fflush(flog);
            int len = strlen(ans+1);
            if(len > n * m) {
                perror("answer length limit exceeded\n");
                return 1;
            }
            for(int i=1;i<=len;++i) {
                Pos next = body.back() + delta(ans[i]);
                if(next.x < 1 || next.x > n || next.y < 1 || next.y > m) {
                    perror("out of map\n");
                    return 2;
                }
                if(i == len) {
                    if(!(next == app)) {
                        perror("didn't reach the apple\n");
                        return 5;
                    }
                    emp.erase(next);
                    body.push(next);
                    break;
                }
                if(next == body.front()) {
                    body.push(next);
                    body.pop();
                } else if(next == app) {
                    perror("reach apple before last step\n");
                    return 3;
                } else {
                    if(emp.find(next) == emp.end() ) {
                        perror("touch the body\n");
                        return 4;
                    } else {
                        emp.erase(next);
                        emp.insert(body.front());
                        body.push(next);
                        body.pop();
                    }
                }
            }
        }
    }

    fclose(flog);
    return 0;
}