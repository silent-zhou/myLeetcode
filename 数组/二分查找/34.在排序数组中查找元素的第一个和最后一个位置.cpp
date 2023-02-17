/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
/*
三种情况：
- 超出数组的左、右边界，返回[-1,-1]
- 在数组范围内，找不到target值，返回[-1,-1]
- 在数组范围内，存在target，范围[左边界，右边界]
*/

// @lc code=start
class Solution
{
public:
  // 方法一：
  // vector<int> searchRange(vector<int> &nums, int target)
  // {
  //   int ans[2] = {getLeftBord(nums, target), getRightBord(nums, target)};
  //   // 情况一：超出数组的左、右边界，返回[-1,-1]
  //   if (ans[0] == -2 || ans[1] == -2)
  //   {
  //     return vector<int>{-1, -1};
  //   }
  //   //情况三： 在数组范围内，存在target，范围[左边界，右边界]
  //   if (ans[1]-ans[0]>1)
  //   {
  //     return vector<int>{ans[0]+1,ans[1]-1};
  //   }

  //   // 情况二: 在数组范围内，找不到target值，返回[-1,-1]
  //     return vector<int>{-1,-1};
  // }

  // 方法二：
  vector<int> searchRange(vector<int> &nums, int target)
  {
    return vector<int>{ getBorder(nums, target, "left"), getBorder(nums, target, "right")};
  }

private:
  int getRightBord(vector<int> &nums, int target)
  {
    int left = 0;
    int right = nums.size() - 1;
    int rightBord = -2;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target)
      {
        left = mid + 1;
        rightBord = left;
      }
      else
      {
        right = mid - 1;
      }
    }
    return rightBord;
  }
  int getLeftBord(vector<int> &nums, int target)
  {
    int left = 0;
    int right = nums.size() - 1;
    int leftBorder = -2;
    while (left <= right)
    {
      int mid = left + ((right - left) / 2);
      if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
        leftBorder = right;
      }
    }
    return leftBorder;
  }
  int getBorder(vector<int> &nums, int target, std::string border)
  {
    int left = 0, right = nums.size() - 1;
    int res = -1;
    while (left <= right)
    {
      int mid = (left + right) >> 1;
      if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else if (nums[mid] > target)
      {
        right = mid - 1;
      }
      else
      {
        res = mid;
        if (border == "left")
        {
          right = mid - 1;
        }
        else if (border == "right")
        {
          left = mid + 1;
        }
      }
    }
    return res;
  }
};
// @lc code=end
