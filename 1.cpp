#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

// 你可以按任意顺序返回答案。

 

// 示例 1：

// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 示例 2：

// 输入：nums = [3,2,4], target = 6
// 输出：[1,2]
// 示例 3：

// 输入：nums = [3,3], target = 6
// 输出：[0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hp;
        for(int i=0;i<nums.size();i++){
            if(hp.count(nums[i])){
                return {i,hp[nums[i]]};
            }
            else{
                hp[target-nums[i]]=i;
            }
        }
        return {};
    }
};

int main(int argc,char **argv){
    Solution sol;

    //case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "示例1: [" << res1[0] << ", " << res1[1] << "]" << endl;

    //case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "示例2: [" << res2[0] << ", " << res2[1] << "]" << endl;

    //case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> res3 = sol.twoSum(nums3, target3);
    cout << "示例3: [" << res3[0] << ", " << res3[1] << "]" << endl;

    return 0;
}