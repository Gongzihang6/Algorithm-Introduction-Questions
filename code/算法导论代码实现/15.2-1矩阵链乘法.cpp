
#include <iostream>
#include <vector>
#include <climits>
#include <format>
#include <iomanip>

using namespace std;

// 辅助函数：打印最优括号方案
void PrintOptimalParens(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// 矩阵链乘法最优解算法
void MatrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;  // 矩阵数量

    // 创建动态规划数组
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    // 子链长度从2开始，最大到n
    for (int l = 2; l <= n; l++) {
        cout << "当子链长度为：" << l << "时：" << endl;

        // 遍历所有可能的子链起点
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;  // 子链终点
            m[i][j] = INT_MAX;  // 初始化为最大值

            cout << format("m[{},{}]:", i, j) << endl;

            // 尝试所有可能的分割点k
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                // 详细输出每一步计算过程
                cout << format("  k取{}时:", k) << endl;
                cout << format("    q = m[{},{}] + m[{},{}] + p[{}]p[{}]p[{}]",
                    i, k, k + 1, j, i - 1, k, j) << endl;
                cout << format("    q = {} + {} + {} = {}",
                    m[i][k], m[k + 1][j], p[i - 1] * p[k] * p[j], q) << endl;

                if (q < m[i][j]) {
                    m[i][j] = q;     // 更新最小代价
                    s[i][j] = k;     // 记录最优分割点

                    cout << format("    更新: m[{},{}] = {}", i, j, q) << endl;
                }
            }
            cout << endl;
        }
        cout << "-------------------------------------------" << endl;
    }

    // 打印最小代价
    cout << "最小标量乘法次数: " << m[1][n] << endl;

    // 打印最优括号方案
    cout << "最优括号方案: ";
    PrintOptimalParens(s, 1, n);
    cout << endl;
}

int main() {
    // 给定的矩阵维度序列：5, 10, 3, 12, 5, 50, 6
    vector<int> p = { 5, 10, 3, 12, 5, 50, 6 };

    MatrixChainOrder(p);

    return 0;
}
