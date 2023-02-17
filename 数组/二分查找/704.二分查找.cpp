/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * - 需要满足升序、不重复条件
- 确认target在那个区间，[]还是[ )
- 判断区间左右两端数值更新
 */

// @lc code=start
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    // **********方法1：左闭、右闭区间 ********
    // int left = 0;
    // int right = nums.size() - 1;
    // while (left <= right)
    // {
    //   int mid = left + ((right - left) >> 1); // zh 位操作，避免left+right超过int的数据范围导致溢出
    //   if (nums[mid] > target)
    //   {
    //     right = mid - 1;
    //   }
    //   else if (nums[mid] < target)
    //   {
    //     left = mid + 1;
    //   } else {
    //     return mid;
    //   }
    // }

    // **********方法2：左闭、右开区间 ********
    int left = 0;
    int right = nums.size();
    while (left < right)
    {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] < target)
      {
        left = mid + 1;
      } else if (nums[mid] > target)
      {
        right = mid;
      } else
      {
        return mid;
      }   
    }
    
    return -1;
  }
};
// @lc code=end
