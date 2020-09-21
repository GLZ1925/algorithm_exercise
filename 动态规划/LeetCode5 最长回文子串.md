# 最长回文子串
## 1.题目描述
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。
示例 2：

    输入: "cbbd"
    输出: "bb"

## 2.题解思路
对于子串s[i:j],如果s[i] == s[j],那么回文子串的长度等于s[i+1:j-1]+2(如果s[i+1:j-1]是一个回文子串)

由于s[i:j]的内容要依赖s[i+1:j-1]，因此遍历
j从0---n
i从j-1---0

## 3.代码
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (n,0)); 
        int maxLen = 0;
        int maxI = 0,maxJ = -1;
        for(int i = 0 ; i < n; i++)
        {
            dp[i][i] = 1;
            if(dp[i][i] > maxLen)
            {
                maxLen = dp[i][i];
                maxI = i;
                maxJ = i;
            }
        }
        for(int j = 0; j < n ; j++)
        {
            for(int i = j - 1; i >= 0; i--)
            {
                if(s[i] == s[j])
                {
                    if(j-1 >= i+1 && dp[i+1][j-1] > 0)
                    {
                        dp[i][j] = dp[i+1][j-1] + 2;
                        if(dp[i][j] > maxLen)
                        {
                            maxLen = dp[i][j];
                            maxI = i;
                            maxJ = j;
                        }
                    }
                    if(j-i == 1)
                    {
                        dp[i][j] =  2;
                        if(dp[i][j] > maxLen)
                        {
                            maxLen = dp[i][j];
                            maxI = i;
                            maxJ = j;
                        }
                    }
                }
            }
        }
        for(int k = maxI; k <= maxJ;k++)
        {
            ans += s[k];
        }
        return ans;
    }
};
```