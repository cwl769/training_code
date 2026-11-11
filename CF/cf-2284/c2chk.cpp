#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<i64> veci64;

int main() {
    FILE * input = fopen("c.in", "r");
    FILE * answ = fopen("c.out", "r");
    int T;fscanf(input, "%d", &T);
    while(T--) {
        i64 a, b;
        fscanf(input, "%lld%lld", &a, &b);
        int cc;
        fscanf(answ, "%d", &cc);
        veci64 chain;chain.emplace_back(a);
        for(int i = 1; i <= cc; ++i) {
            i64 d;fscanf(answ, "%lld", &d);
            chain.emplace_back(chain.back() + d);
        }
        if(chain.back() != b) {
            printf("wrong %lld %lld\n", a, b);
            return 1;
        }
        for (int i = 1; i < (int)chain.size(); ++i) {
            if(std::__gcd(chain[i - 1], chain[i]) != 1) {
                printf("wrong gcd %lld %lld\n", a, b);
                return 2;
            }
        }
    }


    return 0;
}