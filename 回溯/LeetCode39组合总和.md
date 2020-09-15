# 组合总和
## 1.题目描述
给定一个**无重复元素**的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

    所有数字（包括 target）都是正整数。
    解集不能包含重复的组合。 
示例 1：

    输入：candidates = [2,3,6,7], target = 7,
    所求解集为：
    [
      [7],
      [2,2,3]
    ]
示例 2：

    输入：candidates = [2,3,5], target = 8,
    所求解集为：
    [
      [2,2,2,2],
      [2,3,3],
      [3,5]
    ]
 

提示：

<li>1 <= candidates.length <= 30</li>
<li>1 <= candidates[i] <= 200</li>
<li>candidate 中的每个元素都是独一无二的。</li>
<li>1 <= target <= 500</li>

## 2.解题思路
![](https://github.com/GLZ1925/algorithm_exercise/blob/master/pic/39.jpg)

## 3.代码
```cpp
class Solution {
private:
    vector<vector<int>> comb;
    static bool cmp(int i, int j)
    {
        return i<=j;
    }
    void dfs(vector<int> cand,vector<int> cur,int target,int st,int sum)
    {
        //遍历完所有数字
        if(st >= cand.size()) return;
        //找到一种答案
        if(sum + cand[st] == target)
        {
            cur.push_back(cand[st]);
            comb.push_back(cur);
            return;
        }
        //当前仍小于目标
        if(sum + cand[st] < target)
        {
            //加入当前数字
            cur.push_back(cand[st]);
            dfs(cand,cur,target,st,sum+cand[st]);
            //跳过当前数字
            cur.pop_back();
            dfs(cand,cur,target,st+1,sum);
        }
        return;
    }    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return comb;
        //排序
        sort(candidates.begin(),candidates.end(),cmp);
        vector<int> cur;
        dfs(candidates,cur,target,0,0);
        return comb;
    }
};
```
