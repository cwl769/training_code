#include <cstdio>
#include <random>
#include <vector>
#include <map>
#include <set>
std::random_device random_device;
std::mt19937 Rand(random_device());

int main() {
    std::uniform_int_distribution<int> distr(1, 100);
    int t = 1e8;
    int p = 1;
    int last = 0;
    std::map<int, int> ans;
    int sum = 0;
    for(int i=1;i<=t;++i) {
        int rd = distr(Rand);
        if(rd <= p) {
            ++ans[i-last];
            ++sum;
            last = i;
        }
    }
    for(int i=1;i<=100;++i){
        printf("[%03d]%7.4lf", i, 1.0*ans[i]/sum);
        printf("|");
        for(int j=1;j<=1000.0*ans[i]/sum;++j)
            printf("#");
        printf("\n");
    }
    double exp = 0;
    for(auto x:ans) {
        exp += 1.0 * x.first * (1.0 * x.second / sum);
    }
    printf("E:%.10lf\n", exp);

    return 0;
}