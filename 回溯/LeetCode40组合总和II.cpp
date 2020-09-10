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
            //��һ��ȥ�أ���������ظ��𰸣�Ч�ʽϵ�
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
        //�������ظ�
        if(st > 0 && candi[st] == candi[st-1])
        {
            //��ͬ���ֱ���Ӳſ������
            if(f[st-1])
            {
                //����
                tmp.push_back(candi[st]);
                f[st] = 1;
                dfs(candi,tmp,st+1,target-candi[st],f);
                tmp.pop_back();
                f[st] = 0;
            }
            //������    
            dfs(candi,tmp,st+1,target,f);
        }
        else
        {
            //����
            tmp.push_back(candi[st]);
            f[st] = 1;
            dfs(candi,tmp,st+1,target-candi[st],f);
            tmp.pop_back();
            f[st] = 0;
            //������
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
