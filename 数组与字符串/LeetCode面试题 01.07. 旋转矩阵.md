# 矩阵旋转
## 1.题目描述
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

    给定 matrix = 
    [
      [1,2,3],
      [4,5,6],
      [7,8,9]
    ],

    原地旋转输入矩阵，使其变为:
    [
      [7,4,1],
      [8,5,2],
      [9,6,3]
    ]
示例 2:

    给定 matrix =
    [
      [ 5, 1, 9,11],
      [ 2, 4, 8,10],
      [13, 3, 6, 7],
      [15,14,12,16]
    ], 

    原地旋转输入矩阵，使其变为:
    [
      [15,13, 2, 5],
      [14, 3, 4, 1],
      [12, 6, 8, 9],
      [16, 7,10,11]
    ]

## 2.解题思路
**利用额外空间的很容易，给出不利用额外空间的**

核心公式：
$$M[i][j] -> M[j][n-1-i]$$
即：
$$M[j][n-1-i] = M[i][j]$$

旋转90度四次可以返回原样，因此公式推导四次可以形成一个环，那么只需要用tmp记录第一个数字，后面按序列赋值就可以:
```cpp
int tmp = matrix[i][j];
matrix[i][j] = matrix[n - j - 1][i];
matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
matrix[j][n - i - 1] = tmp;
```

对于奇数大小矩阵，由于最中心那个不会改变，因此枚举长n+1/2，宽n/2的范围即可
对于偶数大小矩阵：枚举长宽各为n/2的范围

## 3.代码
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2;i++)
        {
            for(int j = 0; j < (n+1)/2;j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }
};
```
