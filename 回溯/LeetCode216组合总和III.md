# 组合总和III
## 1.题目描述
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

<li>所有数字都是正整数。</li>
<li>解集不能包含重复的组合。 </li>

示例 1:

    输入: k = 3, n = 7
    输出: [[1,2,4]]
示例 2:

    输入: k = 3, n = 9
    输出: [[1,2,6], [1,3,5], [2,3,4]]


## 2.解题思路
![](https://github.com/GLZ1925/algorithm_exercise/blob/master/pic/216.jpg)

## 3.代码
```cpp
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> tmp,int st,int k,int n)
    {
        //剩余可选数字为0，return
        if(k <= 0) return;
        //当前遍历到的数字超过目标或者超出上界，return
        if(st > n || st > 9) return;
        //剩余1个数字且当前遍历数字为答案，加入答案
        if(k == 1 && st == n)
        {
            tmp.push_back(st);
            ans.push_back(tmp);
            return;
        }
        //选择st
        tmp.push_back(st);
        dfs(tmp,st+1,k-1,n-st);
        //不选择st
        tmp.pop_back();
        dfs(tmp,st+1,k,n);
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(tmp,1,k,n);
        return ans;
    }
};
```