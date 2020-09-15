# 和等于 k 的最长子数组长度

#1. 题目描述
给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。如果不存在任意一个符合要求的子数组，则返回 0。

注意:
 nums 数组的总和是一定在 32 位有符号整数范围之内的。

示例 1:

    输入: nums = [1, -1, 5, -2, 3], k = 3
    输出: 4 
    解释: 子数组 [1, -1, 5, -2] 和等于 3，且长度最长。
示例 2:

    输入: nums = [-2, -1, 2, 1], k = 1
    输出: 2 
    解释: 子数组 [-1, 2] 和等于 1，且长度最长。

#2. 解题思路
1.暴力思路：$n^2$复杂度遍历nums，寻找所有子数组的可能nums[i:j]，再计算数组和。$T(n) = O(n^3)$

2.hash前缀和法:一次遍历，记录前缀和sum(nums[0:i])：用hash表以sum(nums[0:i])的值为key，i为value。但只记录第一个出现key的value，因为选择后续的必然导致答案变小，和取最长不符合。如果当前的sum - k 存在于hash中，即sum(nums[0:i]) - sum(nums[0:j]) = k,则找到一个符合要求的子数组，可以进行长度比较。如果当前sum本身就是k，那么[0:i]也为一个合法子数组，可以进行长度比较。
$T(n) = O(n)$ 存储前缀和省去了计算数组和的遍历，使用hash存储将两次遍历降低为一次遍历。

**如果数组全为正则可以使用滑动窗口法：和小于目标则向右增大窗口，大于目标则向左减小窗口 **

# 3.代码
```cpp
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int,int> preSumHash;
        int sum = 0;
        int maxlen = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            sum += nums[i];
            // 记录0--i的前缀和,只记录最早的，后面的肯定使得答案更小
            if(preSumHash.find(sum) == preSumHash.end())
            {
                preSumHash[sum] = i;
            }
            //如果sum直接是答案，则比较记录
            if(sum == k)
            {
                if(maxlen < i + 1)
                {
                    maxlen = i + 1;
                }
            }
            //如果存在值为sum-k的前缀则符合要求，记录下来
            if(preSumHash.find(sum-k) != preSumHash.end())
            {
                if(maxlen < i - preSumHash[sum-k])
                {
                    maxlen = i - preSumHash[sum-k];
                }
            }
        }
        return maxlen;
    }
};
```
