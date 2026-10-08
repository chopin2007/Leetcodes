#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

 

// 示例 1：

// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 示例 2：

// 输入：nums = [1], k = 1
// 输出：[1]

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> index;
        for(int r=0;r<nums.size();r++){
            while(!index.empty() && nums[r]>nums[index.back()]){
                index.pop_back();
            }
            index.push_back(r);
            int l=r-k+1;
            while(index.front()<l){
                index.pop_front();
            }
            if(r>=k-1){
                res.push_back(nums[index.front()]);
            }
        }
        return res;
    }
};

int main(int argc,char ** argv){
    Solution sol;

    //case 1
    vector<int> nums1={1,3,-1,-3,5,3,6,7};
    int k1=3;
    vector<int> res1=sol.maxSlidingWindow(nums1,k1);
    cout << "示例1：[";
    for(int i=0;i<res1.size()-1;i++){
        cout << res1[i] << ",";
    }
    cout << res1.back() << "]" << endl;

    //case 2
    vector<int> nums2={1};
    int k2=1;
    vector<int> res2=sol.maxSlidingWindow(nums2,k2);
    cout << "示例2：[";
    for(int i=0;i<res2.size()-1;i++){
        cout << res2[i] << ",";
    }
    cout << res2.back() << "]" << endl;
}