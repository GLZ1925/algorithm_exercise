class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> tmp,int st,int k,int n)
    {
        //ʣ���ѡ����Ϊ0��return
        if(k <= 0) return;
        //��ǰ�����������ֳ���Ŀ����߳����Ͻ磬return
        if(st > n || st > 9) return;
        //ʣ��1�������ҵ�ǰ��������Ϊ�𰸣������
        if(k == 1 && st == n)
        {
            tmp.push_back(st);
            ans.push_back(tmp);
            return;
        }
        //ѡ��st
        tmp.push_back(st);
        dfs(tmp,st+1,k-1,n-st);
        //��ѡ��st
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
