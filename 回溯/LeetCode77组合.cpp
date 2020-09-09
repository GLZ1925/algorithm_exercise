class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    //������ȣ��ݹ���
    void dfs(int start,int end,int k)
    {
        //ʣ�����ֲ��㣬���֦
        if(temp.size() + end - start + 1 < k)
        {
            return;
        }
        //�չ�����������
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        //��start�������
        temp.push_back(start);
        dfs(start + 1, end, k);
        //����start�������
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
