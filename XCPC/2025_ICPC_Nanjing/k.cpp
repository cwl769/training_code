#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

int dp[20][20][20][20][2];

int cal(int x0, int y0, int x1, int y1, int z) {
    if(dp[x0][y0][x1][y1][z] != -1)
        return dp[x0][y0][x1][y1][z];
    int ans = 1;
    if(x0 + 2 <= 9 && !(x0 + 1 == x1 && y0 == y1)) {
        if(y0 + 1 <= 10) {
            ans &= cal(x0 + 2, y0 + 1, x1, y1, z ^ 1);
        }
        if(y0 - 1 >= 1) {

        }
    }
    if(x0 - 2 >= 1 && !(x0 - 1 == x1 && y0 == y1)) {
        if(y0 + 1 <= 10) {

        }
        if(y0 - 1 >= 1) {
            
        }
    }
    if(y0 + 2 <= 10 && !(x0 == x1 && y0 + 1 == y1)) {
        if(x0 + 1 <= 9) {

        }
        if(x0 - 1 >= 1) {
            
        }
    }
    if(y0 - 2 >= 1 && !(x0 == x1 && y0 - 1 == y1)) {
        if(x0 + 1 <= 9) {

        }
        if(x0 - 1 >= 1) {
            
        }
    }
}

int main() {
    for(int x0 = 1; x0 <= 9; ++x0)
    for(int y0 = 1; y0 <= 10; ++y0)
    for(int x1 = 1; x1 <= 9; ++x1)
    for(int y1 = 1; y1 <= 10; ++y1) {
        int z;
        z = 0;
        
    }


    return 0;
}