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
