#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <assert.h>
#include <algorithm>

struct Pos {
    int x, y;
};

bool operator == (Pos a, Pos b) {
    return a.x == b.x && a.y == b.y;
}

void GEN(int n, int m, std::vector<Pos>& ans) {
    for(int i=1;i<=n;++i) {
        ans.push_back({i, 1});
    }

    for(int i=n;i>=1;--i) {
        if(i&1) {
            for(int j=m;j>=2;--j)
                ans.push_back({i, j});
        } else {
            for(int j=2;j<=m;++j)
                ans.push_back({i, j});
        }
    }
}

void gen(int n, int m, std::vector<Pos>& ans) {
    if((n&1) == 0) {
        GEN(n, m, ans);
    } else {
        GEN(m, n, ans);
        for(int i=0;i<(int)ans.size();++i) {
            std::swap(ans[i].x, ans[i].y);
        }
    }
}

char move(Pos a, Pos b) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    if(dx == 0) {
        if(dy == 1) {
            return 'R';
        } else {
            return 'L';
        }
    } else {
        if(dx == 1) {
            return 'D';
        } else {
            return 'U';
        }
    }
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        int n, m;Pos last;
        scanf("%d%d%d%d", &n, &m, &last.x, &last.y);
        if((n&1) && (m&1)) {
            std::vector<Pos> ring0, ring1;

            for(int j=2;j<=m;++j)
                ring0.push_back({1, j});
            for(int j=m;j>=3;--j) {
                if(j&1) {
                    for(int i=2;i<=n;++i) {
                        ring0.push_back({i, j});
                    }
                } else {
                    for(int i=n;i>=2;--i) {
                        ring0.push_back({i, j});
                    }
                }
            }
            for(int i=n;i>=3;--i) {
                if(i&1) {
                    ring0.push_back({i, 2});
                    ring0.push_back({i, 1});
                } else {
                    ring0.push_back({i, 1});
                    ring0.push_back({i, 2});
                }
            }
            ring0.push_back({2, 1});
            ring1 = ring0;
            ring0.push_back({2, 2});
            ring1.push_back({1, 1});

            int len = n * m - 1;
            for(int i=0;i<len;++i) {
                ring0.push_back(ring0[i]);
            }
            for(int i=0;i<len;++i) {
                ring1.push_back(ring1[i]);
            }

            Pos cur;
            for(int rnd=1;rnd<n*m;++rnd) {
                scanf("%d%d", &cur.x, &cur.y);
                std::vector<Pos> &ring = ((cur == (Pos){1, 1})?ring1:ring0);
                if(last == (Pos){1, 1}) {
                    putchar('R');
                    last = {1, 2};
                }
                if(last == (Pos){2, 2}) {
                    putchar('U');
                    last = {1, 2};
                }

                if(!(last == cur)) {
                    for(int st=0;st<len;++st) {
                        if(ring[st] == last) {
                            for(int cc=st+1;;++cc) {
                                putchar(move(ring[cc-1], ring[cc]));
                                if(ring[cc] == cur) {
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }

                last = cur;
                putchar('\n');
                fflush(stdout);
            }
        } else {
            std::vector<Pos> ring;
            gen(n, m, ring);
            int len = n * m;
            for(int i=0;i<len;++i) {
                ring.push_back(ring[i]);
            }

            for(int rnd=1;rnd<n*m;++rnd) {
                Pos cur;scanf("%d%d", &cur.x, &cur.y);
                for(int st=0;st<len;++st) {
                    if(ring[st] == last) {
                        for(int cc=st+1;;++cc) {
                            putchar(move(ring[cc-1], ring[cc]));
                            if(ring[cc] == cur) {
                                break;
                            }
                        }
                        break;
                    }
                }

                last = cur;
                putchar('\n');
                fflush(stdout);
            }
        }
    }


    return 0;
}