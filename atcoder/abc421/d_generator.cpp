#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <random>
#include <algorithm>
typedef long long int64;

std::random_device random_device;
std::mt19937_64 mt19937(random_device());

char f(int x) {
    switch (x)
    {
    case 0:
        return 'U';
        break;
    case 1:
        return 'D';
        break;
    case 2:
        return 'L';
        break;
    case 3:
        return 'R';
        break;
    
    default:
    return '\0';
        break;
    }
}

int main() {
    std::uniform_int_distribution rand1e9((int)-10, (int)10);
    std::uniform_int_distribution rand1e14(1ll, (int64)1e14);
    std::uniform_int_distribution rand4(0, 3);
    for(int i=1;i<=4;++i) 
        printf("%d ", rand1e9(mt19937));
    printf("\n");
    int64 n = rand1e14(mt19937);
    std::vector<int64> va, vb;
    std::uniform_int_distribution randsp(1ll, n);
    for(int i=1;i<=1e5-1;++i)
        va.push_back(randsp(mt19937));
    va.push_back(n);
    std::sort(va.begin(), va.end());
    va.resize(std::unique(va.begin(), va.end()) - va.begin());
    for(int i=1;i<=1e5-1;++i)
        vb.push_back(randsp(mt19937));
    vb.push_back(n);
    std::sort(vb.begin(), vb.end());
    vb.resize(std::unique(vb.begin(), vb.end()) - vb.begin());
    printf("%lld %d %d\n", n, (int)va.size(), (int)vb.size());
    int64 prevSp;
    prevSp = 0;
    for(auto it=va.begin();it!=va.end();++it) {
        printf("%c %lld\n", f(rand4(mt19937)), *it - prevSp);
        prevSp = *it;
    }
    prevSp = 0;
    for(auto it=vb.begin();it!=vb.end();++it) {
        printf("%c %lld\n", f(rand4(mt19937)), *it - prevSp);
        prevSp = *it;
    }



    return 0;
}