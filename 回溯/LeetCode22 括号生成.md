# 括号生成

# 1.题目描述
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：

    输入：n = 3
    输出：[
           "((()))",
           "(()())",
           "(())()",
           "()(())",
           "()()()"
         ]

# 2.题目思路
##括号匹配
括号匹配中，有以下情况不匹配：
1.左右括号数量根本不等（这个在本题中不存在）
2.从左往右看，存在一个时刻右括号多于左括号，例如:

	)
    ())
因此dfs时的约束条件就是左右括号不超过规定上限，而且右括号不多于左括号

# 3.代码
```cpp
class Solution {
private:
    vector<string> ans;
    void dfs(string s,int l, int r,int n)
    {
        // 括号匹配字符串扩张中，只要全过程中左括号>=右括号即可
        // 并且保证左右括号数量不超过n
        if(l < r || l > n || r > n) return;
        //如果找到答案
        if(l == n && r == n)
        {
            ans.push_back(s);
            return;
        }
        // 下一个字符加入左括号
        dfs(s+"(",l+1,r,n);
        // 下一个字符加入左括号
        dfs(s+")",l,r+1,n);
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(s,0,0,n);
        return ans;
    }
};
```