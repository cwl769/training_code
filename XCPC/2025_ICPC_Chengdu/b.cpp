#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <map>

#define getbit(x, i) (((x)>>(i))&1)
#define INF ((LLONG_MAX) >> 2)

typedef long long int64;

template<typename T>
void readInt(T& x) {
    static bool f;
    x = 0;f = false;
    char c = getchar();
    for(;c<'0' || c>'9';c=getchar())if(c=='-')f=!f;
    for(;'0'<=c&&c<='9';c=getchar()) {
        x = x * 10 + c - '0';
    }
    if(f)x = -x;
}
template<typename T, typename ...Args>
void readInt(T& x, Args&... args) {
    readInt(x);
    readInt(args...);
}

struct Matrix {
    int N, M;
    int64 *dat;
    Matrix(int n, int m) {
        N = n;
        M = m;
        dat = (int64*)calloc(N*M, sizeof(int64));
    }
    Matrix(const Matrix& b) {
        N = b.N;
        M = b.M;
        dat = (int64*)malloc(N*M*sizeof(int64));
        memcpy(dat, b.dat, N*M*sizeof(int64));
    }
    Matrix(Matrix&& b) {
        N = b.N;
        M = b.M;
        dat = b.dat;
        b.dat = NULL;
    }
    Matrix& operator = (const Matrix& b) {

        N = b.N;
        M = b.M;
        free(dat);
        dat = (int64*)malloc(N*M*sizeof(int64));
        memcpy(dat, b.dat, N*M*sizeof(int64));
        return *this;
    }
    Matrix& operator = (Matrix&& b) {
        N = b.N;
        M = b.M;
        free(dat);
        dat = b.dat;
        b.dat = NULL;
        return *this;
    }
    ~Matrix() {
        free(dat);
    }
    int64* operator [] (size_t x) const {
        return dat + x*M;
    }
    Matrix operator * (const Matrix& b) const {
        assert(M==b.N);
        Matrix ans(N, b.M);
        for(int i=0;i<ans.N;++i)
        for(int j=0;j<ans.M;++j) {
            ans[i][j] = -INF;
            for(int k=0;k<M;++k)
                ans[i][j] = std::max(ans[i][j], (*this)[i][k] + b[k][j]);
        }
        return ans;
    }

    Matrix operator ^ (int64 b) const {
        Matrix ans(N, M);
        for(int i=0;i<N;++i)
        for(int j=0;j<M;++j) {
            if(i==j)ans[i][j] = 0;
            else ans[i][j] = -INF;
        }
        Matrix base = (*this);
        for(;b;b>>=1) {
            if(b&1) ans = ans * base;
            base = base * base;
        }
        return ans;
    }

    void print() {
        printf("-------print matrix begin-------\n");
        for(int i=0;i<N;++i) {
            for(int j=0;j<M;++j)
                printf("%20lld ", (*this)[i][j]);
            printf("\n");
        }
        printf("-------print matrix end---------\n");
    }
};

int main() {
    /*Matrix A(3, 3), B(3, 3);
    A[0][0] = 1;A[0][1] = 2;A[0][2] = 3;
    A[1][0] = 2;A[1][1] = 3;A[1][2] = 1;
    A[2][0] = 0;A[2][1] = 0;A[2][2] = 0;

    B[0][0] =         0;B[0][1] = -INF;B[0][2] = -INF;
    B[1][0] = -INF;B[1][1] =         0;B[1][2] = -INF;
    B[2][0] = -INF;B[2][1] = -INF;B[2][2] =         0;

    A.print();B.print();
    (A^2).print();*/
    int T;readInt(T);
    for(;T;--T) {
        int n, m, k, R;readInt(n, m, k, R);
        std::vector<int> a(n), c(n);
        for(int i=0;i<n;++i)
            readInt(a[i], c[i]);
        int cov = (1<<n);
        std::vector<std::vector<int> > valid;
        std::vector<int> ss;
        std::vector<int64> val;
        for(int s=0;s<cov;++s) {
            // printf("s:%d\n", s);
            std::vector<int> tmp;
            for(int t=0;t<cov;++t) {
                int sum = 0;
                for(int i=0;i<n;++i) {
                    if(getbit(s, i)) {
                        sum += c[i];
                        if(getbit(t, i))
                            sum += k;
                    }
                }
                if(sum<=m)
                    tmp.push_back(t);
            }
            if(tmp.size()) {
                valid.push_back(tmp);
                ss.push_back(s);
                int64 sval = 0;
                for(int i=0;i<n;++i)
                    if(getbit(s, i))
                        sval += a[i];
                val.push_back(sval);
            }
        }

        Matrix A(valid.size(), valid.size());
        for(int i=0;i<A.N;++i)
        for(int j=0;j<A.M;++j)
            A[i][j] = -INF;
        for(int i=0;i<A.N;++i) {
            for(auto t:valid[i]) {
                auto it = std::lower_bound(ss.begin(), ss.end(), t);
                if(it==ss.end() || *it!=t) {
                    continue;
                }
                A[i][it-ss.begin()] = val[i];
            }
        }
        // A.print();
        Matrix f(valid.size(), 1);
        for(int i=0;i<(int)valid.size();++i)
            f[i][0] = 0;
        // (A^2).print();
        f = (A^R) * f;
        int64 ans = 0;
        for(int i=0;i<(int)valid.size();++i)
            ans = std::max(ans, f[i][0]);
        printf("%lld\n", ans);
    }

    return 0;
}