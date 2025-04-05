#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// �������Ŷ���������
void OPTIMAL_BST(const vector<double>& p, const vector<double>& q, int n,
    vector<vector<double>>& e, vector<vector<double>>& w,
    vector<vector<int>>& root) {
    // ��ʼ�� e �� w ��
    e.resize(n + 2, vector<double>(n + 1, 0));
    w.resize(n + 2, vector<double>(n + 1, 0));
    root.resize(n + 1, vector<int>(n + 1, 0));

    // ��ʼ�� e[i][i-1] �� w[i][i-1]
    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // ��̬�滮��� e, w �� root ��
    for (int l = 1; l <= n; ++l) {  // l ��������ĳ���
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            // �������п��ܵĸ��ڵ� r
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

// �ݹ鹹�����Ŷ����������Ľṹ
void CONSTRUCT_SUBTREE(const vector<vector<int>>& root, int i, int j,
    const string& parent, const string& direction) {
    if (i > j) {
        if (parent != "NIL") {
            cout << "d_" << j << " Ϊ " << parent << " �� " << direction << "����" << endl;
        }
        else {
            cout << "d_" << j << " Ϊ��" << endl;  // ͨ�����ᷢ��
        }
        return;
    }

    int r = root[i][j];
    if (parent == "NIL") {
        cout << "k_" << r << " Ϊ��" << endl;
    }
    else {
        cout << "k_" << r << " Ϊ " << parent << " �� " << direction << "����" << endl;
    }

    // �ݹ鹹����������������
    CONSTRUCT_SUBTREE(root, i, r - 1, "k_" + to_string(r), "��");
    CONSTRUCT_SUBTREE(root, r + 1, j, "k_" + to_string(r), "��");
}

// ������Ŷ����������Ľṹ
void CONSTRUCT_OPTIMAL_BST(const vector<vector<int>>& root, int n) {
    CONSTRUCT_SUBTREE(root, 1, n, "NIL", "NIL");
}

int main() {
    // ʾ�����ݣ�ͼ15-10�еĸ��ʣ�
    //vector<double> p = { 0, 0.15, 0.10, 0.05, 0.10, 0.20 };  // p[1..n]
    //vector<double> q = { 0.05, 0.10, 0.05, 0.05, 0.05, 0.10 }; // q[0..n]
    //int n = 5;  // �ؼ��ֵ�����


    // ϰ��15.5-2������
    vector<double> p = { 0, 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14 };  // p[1..n]
    vector<double> q = { 0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05 }; // q[0..n]
    int n = 7;  // �ؼ��ֵ�����

    vector<vector<double>> e, w;
    vector<vector<int>> root;

    // �������Ŷ���������
    OPTIMAL_BST(p, q, n, e, w, root);

    //������Ŷ�����������������������
    cout<<"���Ŷ�����������������������Ϊ�� " << e[1][n] << endl;
    // ������Ŷ����������Ľṹ
    cout << "���Ŷ����������Ľṹ��" << endl;
    CONSTRUCT_OPTIMAL_BST(root, n);

    return 0;
}