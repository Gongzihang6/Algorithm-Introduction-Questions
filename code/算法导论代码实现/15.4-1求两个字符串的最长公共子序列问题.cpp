#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();     // m为text1的长度
        int n = text2.length();     // n为text2的长度
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));     // dp[i][j]表示text1的前i个字符和text2的前j个字符的最长公共子序列的长度
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){       // 边界条件,dp[0][j]和dp[i][0]都为0
                    dp[i][j] = 0;
                }else if(text1[i-1] == text2[j-1]){     // 如果text1[i-1]和text2[j-1]相同,则最长公共子序列长度为dp[i-1][j-1]+1
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{                                  // 如果text1[i-1]和text2[j-1]不同,则最长公共子序列长度为max(dp[i-1][j],dp[i][j-1])
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int index = dp[m][n];   
        string result(index,' ');   // 最长公共子序列的结果,初始化为index个空格
        int i = m, j = n;
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                result[index-1] = text1[i-1];
                i--;
                j--;
                index--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string text1 = "10010101";
    string text2 = "010110110110";
    cout << s.longestCommonSubsequence(text1, text2) << endl;
    cout<<"最长公共子序列的长度为: "<<s.longestCommonSubsequence(text1, text2).length()<<endl;
    return 0;
}