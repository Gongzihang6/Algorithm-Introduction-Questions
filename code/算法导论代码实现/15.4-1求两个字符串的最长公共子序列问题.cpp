#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();     // mΪtext1�ĳ���
        int n = text2.length();     // nΪtext2�ĳ���
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));     // dp[i][j]��ʾtext1��ǰi���ַ���text2��ǰj���ַ�������������еĳ���
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){       // �߽�����,dp[0][j]��dp[i][0]��Ϊ0
                    dp[i][j] = 0;
                }else if(text1[i-1] == text2[j-1]){     // ���text1[i-1]��text2[j-1]��ͬ,������������г���Ϊdp[i-1][j-1]+1
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{                                  // ���text1[i-1]��text2[j-1]��ͬ,������������г���Ϊmax(dp[i-1][j],dp[i][j-1])
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int index = dp[m][n];   
        string result(index,' ');   // ����������еĽ��,��ʼ��Ϊindex���ո�
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
    cout<<"����������еĳ���Ϊ: "<<s.longestCommonSubsequence(text1, text2).length()<<endl;
    return 0;
}