#include <cstdio>
#include <vector>
#include <random>
#include <queue>
#include <algorithm>
#include <functional>
typedef std::vector<double> vecd;

std::mt19937_64 gen(std::random_device{}());
std::uniform_real_distribution urd(0.0, 1.0);

void solve(int n, int k, vecd &res) {
    std::priority_queue<double> heap;
    for (int i = 0; i < n; ++i) {
        heap.emplace(urd(gen));
    }
    for (int i = 0; i < k; ++i) {
        res[i] += heap.top();
        heap.pop();
        heap.emplace(urd(gen));
    }
}

double func(int t, int k) {
    vecd tmp(t);
    for (int i = 0; i < t; ++i)
        tmp[i] = urd(gen);
    std::nth_element(tmp.begin(), tmp.begin()+k-1, tmp.end(), std::greater<double>());
    return *(tmp.begin() + k - 1);
}

int main() {
    int km = 10;
    int cnt = 1000000;
    for(int n = 1; n <= 10; ++n) {
        vecd res(km);
        for(int rnd = 0; rnd < cnt; ++rnd) {
            // printf("n = %d rnd = %d\n", n, rnd);
            solve(n, km, res);
        }
        for (int i = 0; i < km; ++i)
            res[i] /= cnt;
        printf("-------[%d]-------\n", n);
        for (int i = 0; i < km; ++i)
            printf("%7.5lf ", res[i]);
        printf("\n");
        // printf ("        ");
        // for (int i = 1; i < km; ++i)
        //     printf("%7.5lf ", res[i-1] - res[i]);
        // printf("\n");
    }

    // int t = 9;
    // for (int k = 1; k <= 9; ++k) {
    //     double sum = 0;
    //     for(int rnd = 0; rnd < cnt; ++rnd)
    //         sum += func(t, k);
    //     sum /= cnt;
    //     printf("(t = %d, k = %d) %.10lf\n", t, k, sum);
    // }


    return 0;
}