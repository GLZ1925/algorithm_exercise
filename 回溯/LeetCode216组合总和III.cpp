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
