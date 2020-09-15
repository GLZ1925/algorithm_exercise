# 解数独
## 1.题目描述
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

## 2.解题思路
![](https://github.com/GLZ1925/algorithm_exercise/blob/master/pic/37.jpg)

## 3.代码
```cpp
class Solution {
private:
    bool block[3][3][9]; //存每一个3*3区块中数字的使用情况
    bool line[9][9]; //存每一行中数字的使用情况
    bool col[9][9];//存每一列中数字的使用情况
    vector<pair<int,int>> spaces; //存储空白位置 
    bool finish; //记录是否搜索完成
    void dfs(vector<vector<char>>& board,int pos)
    {
        //搜索完成
        if(pos == spaces.size())
        {
            finish = true;
            return;
        }
        //存储当前空白格子的坐标
        int r = spaces[pos].first;
        int c = spaces[pos].second;
        //遍历所有可选的数字
        for(int i = 1; i < 10;i++)
        {
            if(finish) break; //完成了则跳出
            //如果满足三个约束条件
            if(!block[r/3][c/3][i-1] && !line[r][i-1] && !col[c][i-1])
            {
                //填入该数，并记录
                block[r/3][c/3][i-1] = true;
                line[r][i-1] = true;
                col[c][i-1] = true;
                board[r][c] = i + '0';
                dfs(board,pos+1);
                //回退
                block[r/3][c/3][i-1] = false;
                line[r][i-1] = false;
                col[c][i-1] = false;
            }
        }
        return;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 初始化
        memset(block,0,sizeof(block));
        memset(line,0,sizeof(block));
        memset(col,0,sizeof(col));
        finish = false;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    line[i][num-1] = true;
                    col[j][num-1] = true;
                    block[i/3][j/3][num-1] = true;
                }
                else
                {
                    pair<int,int> tmp(i,j);
                    spaces.push_back(tmp);
                }
            }
        }
        dfs(board,0);
    }
};
```