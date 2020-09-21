# 对角线遍历
## 1.题目描述

给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

示例:

    输入:
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]

    输出:  [1,2,4,7,5,3,6,8,9]

## 2.解题思路
设对角线从左上到右下共k条，每条对角线包含点(i,j)：
	<li>k为偶数 i = k,k-1,...,0; j = 0,1,...,k</li>
    <li>k为奇数 i = 0,1,...,k; j = k,k-1,...,0</li>
    <li>i+j == k 且 i,j都在[0,m-1]和[0,n-1]</li>

## 3.代码
```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> ans;
        if(m <= 0) return ans;
        int n = matrix[0].size();
        // 设对角线从左上到右下共k条
        // 每条对角线包含点(i,j)
        // k为偶数 i = k,k-1,...,0; j = 0,1,...,k
        // k为奇数 i = 0,1,...,k; j = k,k-1,...,0
        // i+j == k 且 i,j都在[0,m-1]和[0,n-1]
        for(int k = 0 ; k < m + n - 1;k++)
        {
            if(k % 2 == 0)
            {
                for(int i = min(m-1,k);i >= 0;i--)
                {
                    int j = k - i;
                    if(j < 0 || j >= n) break;
                    //cout << i << " " << j << endl;
                    //cout << matrix[i][j];
                    ans.push_back(matrix[i][j]);
                }
            }
            if(k % 2 == 1)
            {
                for(int j = min(n-1,k); j >= 0;j--)
                {
                    int i = k - j;
                    if(i < 0 || i >= m) break;
                    //cout << i << " " << j << endl;
                    //cout << matrix[i][j];
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};
```