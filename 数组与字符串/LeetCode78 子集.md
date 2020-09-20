# 子集
## 1.题目描述
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

    输入: nums = [1,2,3]
    输出:
    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]

## 2.解题思路
初始设置子集集合只有一个空集。从前往后遍历，读到1个数则遍历所有子集集合里已经有的子集，把他们加上这个数后加入集合。

## 3.代码
```cpp
class Solution {  
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // 初始加入一个空集
        vector<int> empty;
        ans.push_back(empty);
        // 遍历读取
        for(int i = 0 ; i < nums.size();i++)
        {
            // 将这个数加入已有的所有子集
            // 得到本轮要增加的新子集，将其加入ans
            int n = ans.size();
            for(int j = 0; j < n;j++)
            {
                vector<int> tmp(ans[j]);
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
};
```
