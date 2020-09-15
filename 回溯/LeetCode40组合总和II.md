# 组合总和II
## 1.题目描述
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

<li>所有数字（包括目标数）都是正整数。</li>
<li>解集不能包含重复的组合。 </li>
示例 1:

    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    所求解集为:
    [
      [1, 7],
      [1, 2, 5],
      [2, 6],
      [1, 1, 6]
    ]
示例 2:

    输入: candidates = [2,5,2,1,2], target = 5,
    所求解集为:
    [
      [1,2,2],
      [5]
    ]

## 2.解题思路
![](https://github.com/GLZ1925/algorithm_exercise/blob/master/pic/40.jpg)

## 3.代码
```cpp
class Solution {
private:
    static bool cmp(int i , int j)
    {
        return i < j;
    }
    vector<vector<int>> ans;
    void dfs(vector<int> candi,vector<int>tmp, int st, int target,vector<bool> f)
    {
        if(st >= candi.size()) return;
        if(candi[st] > target) return;
        if(candi[st] == target)
        {
            tmp.push_back(candi[st]);
            //第一种去重，检查所有重复答案，效率较低
            // for(int i = 0; i < ans.size();i++)
            // {
            //     if(ans[i] == tmp)
            //     {
            //         return;
            //     }
            // }
            ans.push_back(tmp);
            return;
        }
        //当出现重复
        if(st > 0 && candi[st] == candi[st-1])
        {
            //相同数字被添加才可以添加
            if(f[st-1])
            {
                //加入
                tmp.push_back(candi[st]);
                f[st] = 1;
                dfs(candi,tmp,st+1,target-candi[st],f);
                tmp.pop_back();
                f[st] = 0;
            }
            //不加入    
            dfs(candi,tmp,st+1,target,f);
        }
        else
        {
            //加入
            tmp.push_back(candi[st]);
            f[st] = 1;
            dfs(candi,tmp,st+1,target-candi[st],f);
            tmp.pop_back();
            f[st] = 0;
            //不加入
            dfs(candi,tmp,st+1,target,f);
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return ans;
        vector<bool> f;
        for(int i = 0; i < candidates.size();i++) f.push_back(0);
        sort(candidates.begin(),candidates.end(),cmp);
        vector<int> tmp;
        dfs(candidates,tmp,0,target,f);
        return ans;
    }
};
```