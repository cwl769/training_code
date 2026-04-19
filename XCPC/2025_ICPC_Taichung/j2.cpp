#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

typedef long long int64;
typedef unsigned long long uint64;

// struct HJT {
//     struct Node {
//         int v;
//         Node *son[2];
//         Node():v(),son{NULL, NULL}{}
//         Node(const Node *p) {
//             if(p==NULL) {
//                 v = 0;
//                 son[0] = son[1] = NULL;
//             } else {
//                 v = p->v;
//                 son[0] = p->son[0];
//                 son[1] = p->son[1];
//             }
//         }
//         void update() {
//             v = 0;
//             if(son[0]!=NULL) {
//                 v += son[0]->v;
//             }
//             if(son[1]!=NULL) {
//                 v += son[1]->v;
//             }
//         }
//         int query(int l, int r, int ql, int qr) {
//             if(ql<=l&&r<=qr) {
//                 return this->v;
//             }
//             int mid = ((l+r)>>1);
//             int ans = 0;
//             if(ql<=mid) {
//                 if(son[0]!=NULL)
//                     ans += son[0]->query(l, mid, ql, qr);
//             }
//             if(qr>mid) {
//                 if(son[1]!=NULL)
//                     ans += son[1]->query(mid+1, r, ql, qr);
//             }
//             return ans;
//         }
//     };
//         Node * add(const Node *old, int l, int r, int x, int v) {
//             Node *cur = new Node(old);
//             if(l==r) {
//                 ++ cur->v;
//                 return cur;
//             }
//             int mid = ((l+r)>>1);
//             if(x<=mid)
//                 cur->son[0] = add(((old==NULL)?NULL:old->son[0]), l, mid, x, v);
//             else 
//                 cur->son[1] = add(((old==NULL)?NULL:old->son[1]), mid+1, r, x, v);
//             cur->update();
//             return cur;
//         }
//     int L, R;
//     std::vector<Node*> root;
//     HJT(int l, int r) {
//         L = l;
//         R = r;
//         root.push_back(new Node());
//     }
//     void add(int x, int v) {
//         root.push_back(add(root.back(), L, R, x, v));
//     }
//     int query(int version, int l, int r) {
//         return root[version]->query(L, R, l, r);
//     }
// };

struct Segtree {
    struct Node {
        int64 tag;
        Node *son[2];
        Node():tag(),son{NULL, NULL}{}
        void add(int l, int r, int ql, int qr, int64 v) {
            if(ql<=l&&r<=qr) {
                tag += v;
                return;
            }
            int mid = ((l+r)>>1);
            if(ql<=mid) {
                if(son[0]==NULL) son[0] = new Node;
                son[0]->add(l, mid, ql, qr, v);
            }
            if(qr>mid) {
                if(son[1]==NULL) son[1] = new Node;
                son[1]->add(mid+1, r, ql, qr, v);
            }
        }
        int64 query(int l, int r, int x) {
            if(l==r) {
                return tag;
            }
            int mid = ((l+r)>>1);
            if(x<=mid) {
                if(son[0]==NULL)return tag;
                else return tag + son[0]->query(l, mid, x);
            } else {
                if(son[1]==NULL)return tag;
                else return tag + son[1]->query(mid+1, r, x);
            }
        } 
    };
    Node *root;
    int L, R;
    Segtree(int l, int r) {
        root = new Node;
        L = l;
        R = r;
    }
    void add(int l, int r, int v) {
        root->add(L, R, l, r, v);
    }
    int64 query(int x) {
        return root->query(L, R, x);
    }
};

struct BIT {
    int *c, cnt0;
    int N;
    BIT(int n) {
        N = n;
        cnt0 = 0;
        c = (int*)calloc(n+1, sizeof(int));
    }
    void add(int x, int v) {
        if(x==0) {
            cnt0 += v;
            return;
        }
        for(;x<=N;x+=(x&(-x)))
            c[x] += v;
    }
    int query(int x) {
        if(x==0)return cnt0;
        int ans = 0;
        for(;x;x-=(x&(-x)))
            ans += c[x];
        return ans+cnt0;
    }
};

struct Command {
    int val, type, pos;
};

bool operator < (const Command& a, const Command& b) {
    if(a.val == b.val) {
        return a.type > b.type;
    }
    return a.val > b.val;
}

int n;

std::map<std::pair<int, int>, int> cntMap;

void calCntMap(std::vector<Command>& op, std::vector<int> a) {
    std::map<int, int> map;
    std::vector<std::pair<int, int> > list;
    map[0] = 0;
    map[n] = 0;
    for(auto com:op) {
        int v = com.val;
        int p = com.pos;
        // printf("command: %d %d %d\n", v, com.type, p);
        auto it = map.lower_bound(p);
        --it;
        auto it_bef = it;
        ++it;
        int sp = it->first;
        int sp_bef = it_bef->first;
        if(com.type) {
            // ++map[sp];
        } else {
            // map[sp] = cnt(p+1, sp, v);
            // map[p] = cnt(sp_bef+1, p, v);
            map[p] = 0;
            if(v>0) {
                list.push_back({p, v});
                list.push_back({sp, v});
                list.push_back({sp_bef, v});
            }
        }
    }
    std::sort(list.begin(), list.end());
    BIT bit(n);
    auto it = list.begin();
    for(;it!=list.end()&&it->first==0;++it) {
        cntMap[*it] = 0;
    }
    for(int i=1;i<=n;++i) {
        bit.add(a[i], 1);
        // for(int i=1;i<=n;++i) {
        //     printf("%d ", bit.query(i));
        // }
        // printf("\n");
        for(;it!=list.end()&&it->first==i;++it) {
            cntMap[*it] = bit.query(n) - bit.query(it->second-1);
            // printf("{%d %d} %d\n", it->first, it->second, bit.query(n) - bit.query(it->second-1));
        }
    }
}

int cnt(int l, int r, int v) {
    if(v==0)return r - l + 1;
    return cntMap[{r, v}] - cntMap[{l-1, v}];
}

void ansadd(Segtree& tree, int l, int r, int v) {
    if(l>r)return;
    // printf("ansadd(%d %d %d)\n", l, r, v);
    tree.add(l, r, v);
}

int main() {
    scanf("%d", &n);
    std::vector<int> a(n+1);
    std::vector<int> h(n);
    for(int i=1;i<=n;++i)
        scanf("%d", &a[i]);
    for(int i=1;i<n;++i)
        scanf("%d", &h[i]);
    
    // printf("ver size: %d\n", (int)hjt.root.size());
    Segtree ans(1, n);
    std::vector<Command> op;
    for(int i=1;i<=n;++i) {
        op.push_back((Command){
            .val = a[i],
            .type = 1,
            .pos = i
        });
    }
    for(int i=1;i<n;++i) {
        op.push_back((Command){
            .val = h[i],
            .type = 0,
            .pos = i
        });
    }
    std::map<int, int> map;
    map[0] = 0;
    map[n] = 0;
    std::sort(op.begin(), op.end());

    //cal cntMap
    calCntMap(op, a);

    for(auto com:op) {
        int v = com.val;
        int p = com.pos;
        // printf("command: %d %d %d\n", v, com.type, p);
        auto it = map.lower_bound(p);
        --it;
        auto it_bef = it;
        ++it;
        int sp = it->first;
        int sp_bef = it_bef->first;
        if(com.type) {
            ansadd(ans, sp - map[sp], sp - map[sp], v);
            ++map[sp];
        } else {
            ansadd(ans, sp - map[sp] + 1, sp, -v);
            map[p] = cnt(sp_bef+1, p, v);
            map[sp] = cnt(p+1, sp, v);
            printf("%d %d ", map[p], map[sp]);
            ansadd(ans, p-map[p]+1, p, v);
            ansadd(ans, sp-map[sp]+1, sp, v);
        }
        // for(auto x:map) {
        //     printf("{%d, %d}", x.first, x.second);
        // }
        // printf("\n");
    }
    printf("\n");
    for(int i=1;i<=n;++i) {
        printf("%lld ", ans.query(i));
    }
    printf("\n");

    return 0;
}