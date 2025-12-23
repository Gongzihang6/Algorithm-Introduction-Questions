#include <iostream>  
#include <cmath>  
#include <vector>  
#include <iomanip>  
#include <functional>  
using namespace std;

long long jiecheng(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * jiecheng(n - 1);
}

long long max_problem_size(function<long long(long long)> f, long long t) {
    long long low = 1, high = 1e30;  // 假设一个合理的上限  
    while (low < high) {
        long long mid = (low + high + 1) / 2;  // 向上取整  
        if (f(mid) <= t) {
            low = mid;  // mid 是可行的，尝试更大的  
        }
        else {
            high = mid - 1;  // mid 不可行，尝试更小的  
        }
    }
    return low;  // 返回最大可行规模  
}

int main() {
    vector<long double> time_constraints = { 1e3, 6e4, 3.6e6, 8.64e7, 2.592e9, 3.1104e10, 3.1104e12 };

    vector<function<long long(long long)>> functions;
    //functions.push_back([](long long n) { return log2(n); });
    functions.push_back([](long long n) { return pow(n, 0.5); });
    functions.push_back([](long long n) { return n; });
    functions.push_back([](long long n) { return n * log2(n); });
    functions.push_back([](long long n) { return n * n; });
    functions.push_back([](long long n) { return n * n * n; });
    functions.push_back([](long long n) { return pow(2, n); });
    functions.push_back([](long long n) { return jiecheng(n); });

    vector<string> function_names = {  "sqrt(n)", "n", "n * log2(n)", "n^2", "n^3", "2^n", "n!" };

    for (int i = 0; i < time_constraints.size(); i++) {
        cout << "时间限制为" << time_constraints[i] << "时：" << endl;
        for (int j = 0; j < functions.size(); j++) {
            long long max_n = max_problem_size(functions[j], time_constraints[i]);
            cout << "复杂度为" << function_names[j] << "的最大问题规模为" << max_n << endl;
        }
    }
    return 0;
}