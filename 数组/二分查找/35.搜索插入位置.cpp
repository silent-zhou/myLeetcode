/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int left = 0;
    int right = nums.size() - 1;
    if (nums[left] > target)
    {
      return 0;
    }
    if (nums[right] < target)
    {
      return  right + 1;
    }
    while (left <=right)
    {
      int mid = left + ((right-left) >> 1);
      if (nums[mid] < target)
      {
        left = mid +1;
      } else if (nums[mid] > target ) {
        right = mid -1;
      } else
      return mid;
    }
    return left; // zh 不需要前面两个边界值的判断
    
  }
};
// @lc code=end
