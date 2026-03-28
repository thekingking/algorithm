#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 矩阵结构体
struct Matrix {
    ll mat[2][2];
    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
    }
};

// 矩阵乘法
Matrix multiply(Matrix A, Matrix B, ll mod) {
    Matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % mod;
            }
        }
    }
    return C;
}

// 矩阵快速幂
Matrix power(Matrix A, ll n, ll mod) {
    Matrix res;
    res.mat[0][0] = 1; res.mat[1][1] = 1; // 单位矩阵
    while (n > 0) {
        if (n & 1) res = multiply(res, A, mod);
        A = multiply(A, A, mod);
        n >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<ll> ans(T);
    Matrix m;
    ll a, n, x, c;
    m.mat[1][0] = 0;
    m.mat[1][1] = 1;
    for (int i = 0; i < T; ++i) {
        cin >> x >> a >> n >> c;
        m.mat[0][0] = a;
        m.mat[0][1] = -a;

        Matrix matrix = power(m, n, c);
        ll res = (matrix.mat[0][0] * x % c + matrix.mat[0][1] % c + c) % c;
        ans[i] = res;
    }
    for (const ll &x : ans) {
        cout << x << endl;
    }
}
