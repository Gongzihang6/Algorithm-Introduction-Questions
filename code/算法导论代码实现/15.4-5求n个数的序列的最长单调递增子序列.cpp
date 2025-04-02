#include <iostream>
#include <vector>

using namespace std;

vector<int>  LIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    vector<int> res;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (dp[i] > max_len) {
            max_len = dp[i];
            res.clear();
            res.push_back(nums[i]);
        } else if (dp[i] == max_len) {
            res.push_back(nums[i]);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> res = LIS(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}   