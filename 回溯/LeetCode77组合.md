# 组合



## 1. 题目描述

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。



示例:



    输入: n = 4, k = 2

    输出:

    [

      [2,4],

      [3,4],

      [2,3],

      [1,2],

      [1,3],

      [1,4],

    ]



## 2.题解思路

![](https://github.com/GLZ1925/algorithm_exercise/blob/master/pic/77.jpg)

## 3. 代码
```cpp
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    //深度优先，递归解决
    void dfs(int start,int end,int k)
    {
        //剩下数字不足，则剪枝
        if(temp.size() + end - start + 1 < k)
        {
            return;
        }
        //凑够数量则加入答案
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        //将start加入队列
        temp.push_back(start);
        dfs(start + 1, end, k);
        //不讲start加入队列
        temp.pop_back();
        dfs(start + 1, end, k);
        return;
    }        
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return ans;
    }
};
```