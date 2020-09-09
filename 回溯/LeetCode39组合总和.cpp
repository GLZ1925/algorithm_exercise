class Solution {
private:
    vector<vector<int>> comb;
    static bool cmp(int i, int j)
    {
        return i<=j;
    }
    void dfs(vector<int> cand,vector<int> cur,int target,int st,int sum)
    {
        //��������������
        if(st >= cand.size()) return;
        //�ҵ�һ�ִ�
        if(sum + cand[st] == target)
        {
            cur.push_back(cand[st]);
            comb.push_back(cur);
            return;
        }
        //��ǰ��С��Ŀ��
        if(sum + cand[st] < target)
        {
            //���뵱ǰ����
            cur.push_back(cand[st]);
            dfs(cand,cur,target,st,sum+cand[st]);
            //������ǰ����
            cur.pop_back();
            dfs(cand,cur,target,st+1,sum);
        }
        return;
    }    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return comb;
        //����
        sort(candidates.begin(),candidates.end(),cmp);
        vector<int> cur;
        dfs(candidates,cur,target,0,0);
        return comb;
    }
};
