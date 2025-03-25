#include <iostream>  
#include <vector>  
using namespace std;

// 定义矩阵结构体  
struct Matrix {
    int rows, cols;
    vector<vector<int>> data;
    // 矩阵构造函数，初始化为全0矩阵
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}
};

// 矩阵乘法函数  
Matrix Multiply(const Matrix& A, const Matrix& B) {
    if (A.cols != B.rows) {
        throw runtime_error("不可进行矩阵乘法");
    }

    Matrix result(A.rows, B.cols);
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < B.cols; ++j) {
            for (int k = 0; k < A.cols; ++k) {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return result;
}

// 矩阵链乘法递归实现  
Matrix MATRIX_CHAIN_MULTIPLY(vector<Matrix>&A, vector<vector<int>>&s, int i, int j) {
    if (i == j) {
        return A[i - 1];  // 注意下标从0开始  
    }
    else {
        int k = s[i][j];
        Matrix left = MATRIX_CHAIN_MULTIPLY(A, s, i, k);
        Matrix right = MATRIX_CHAIN_MULTIPLY(A, s, k + 1, j);
        return Multiply(left, right);
    }
}

// 15.2-1中的矩阵链乘法最优解算法，返回最优括号方案s
vector<vector<int>> MatrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;  // 矩阵数量

    // 创建动态规划数组
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    // 子链长度从2开始，最大到n
    for (int l = 2; l <= n; l++) {
        // 遍历所有可能的子链起点
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;  // 子链终点
            m[i][j] = INT_MAX;  // 初始化为最大值

            // 尝试所有可能的分割点k
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;     // 更新最小代价
                    s[i][j] = k;     // 记录最优分割点
                }
            }
        }
    }
    return s;
}



int main() {
    // 示例：A1(5*10)、A2(10*3)、A3(3*12)、A4(12*5)、A5(5*50)、A6(50*6)  
    // 矩阵只给出了形状，没有具体数值，具体数值默认初始化全部为0
    vector<Matrix> matrices = {
        Matrix(5, 10),   // A1  
        Matrix(10, 3),   // A2  
        Matrix(3, 12),   // A3  
        Matrix(12, 5),   // A4  
        Matrix(5, 50),   // A5  
        Matrix(50, 6)    // A6  
    };
    vector<int> p = { matrices[0].rows, matrices[1].rows, matrices[2].rows, matrices[3].rows, matrices[4].rows, matrices[5].rows, matrices[0].cols };
    // 预先计算的最优分割点表  
    vector<vector<int>> s = MatrixChainOrder(p);

    // 计算最终结果  
    Matrix result = MATRIX_CHAIN_MULTIPLY(matrices, s, 1, 6);

    // 输出结果维度  
    cout << "最终结果矩阵维度: " << result.rows << " x " << result.cols << endl;

    return 0;
}