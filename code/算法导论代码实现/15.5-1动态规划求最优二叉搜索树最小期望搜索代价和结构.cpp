#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// 构建最优二叉搜索树
void OPTIMAL_BST(const vector<double>& p, const vector<double>& q, int n,
    vector<vector<double>>& e, vector<vector<double>>& w,
    vector<vector<int>>& root) {
    // 初始化 e 和 w 表
    e.resize(n + 2, vector<double>(n + 1, 0));
    w.resize(n + 2, vector<double>(n + 1, 0));
    root.resize(n + 1, vector<int>(n + 1, 0));

    // 初始化 e[i][i-1] 和 w[i][i-1]
    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // 动态规划填充 e, w 和 root 表
    for (int l = 1; l <= n; ++l) {  // l 是子问题的长度
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            // 尝试所有可能的根节点 r
            for (int r = i; r <= j; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}

// 递归构建最优二叉搜索树的结构
void CONSTRUCT_SUBTREE(const vector<vector<int>>& root, int i, int j,
    const string& parent, const string& direction) {
    if (i > j) {
        if (parent != "NIL") {
            cout << "d_" << j << " 为 " << parent << " 的 " << direction << "孩子" << endl;
        }
        else {
            cout << "d_" << j << " 为根" << endl;  // 通常不会发生
        }
        return;
    }

    int r = root[i][j];
    if (parent == "NIL") {
        cout << "k_" << r << " 为根" << endl;
    }
    else {
        cout << "k_" << r << " 为 " << parent << " 的 " << direction << "孩子" << endl;
    }

    // 递归构建左子树和右子树
    CONSTRUCT_SUBTREE(root, i, r - 1, "k_" + to_string(r), "左");
    CONSTRUCT_SUBTREE(root, r + 1, j, "k_" + to_string(r), "右");
}

// 输出最优二叉搜索树的结构
void CONSTRUCT_OPTIMAL_BST(const vector<vector<int>>& root, int n) {
    CONSTRUCT_SUBTREE(root, 1, n, "NIL", "NIL");
}

int main() {
    // 示例数据（图15-10中的概率）
    //vector<double> p = { 0, 0.15, 0.10, 0.05, 0.10, 0.20 };  // p[1..n]
    //vector<double> q = { 0.05, 0.10, 0.05, 0.05, 0.05, 0.10 }; // q[0..n]
    //int n = 5;  // 关键字的数量


    // 习题15.5-2的数据
    vector<double> p = { 0, 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14 };  // p[1..n]
    vector<double> q = { 0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05 }; // q[0..n]
    int n = 7;  // 关键字的数量

    vector<vector<double>> e, w;
    vector<vector<int>> root;

    // 构建最优二叉搜索树
    OPTIMAL_BST(p, q, n, e, w, root);

    //输出最优二叉搜索树的期望搜索代价
    cout<<"最优二叉搜索树的期望搜索代价为： " << e[1][n] << endl;
    // 输出最优二叉搜索树的结构
    cout << "最优二叉搜索树的结构：" << endl;
    CONSTRUCT_OPTIMAL_BST(root, n);

    return 0;
}