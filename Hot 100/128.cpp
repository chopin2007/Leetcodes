#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

// 示例 1：

// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 示例 2：

// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9
// 示例 3：

// 输入：nums = [1,0,1,2]
// 输出：3
 

// 提示：

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hp;
        if(nums.empty()) return 0;
        int maxlen=1;
        for(int i=0;i<nums.size();i++){
            if(hp.count(nums[i])) continue;
            int l=(hp.count(nums[i]-1))?hp[nums[i]-1]:0;
            int r=(hp.count(nums[i]+1))?hp[nums[i]+1]:0;
            int sum=l+r+1;
            hp[nums[i]-l]=sum;
            hp[nums[i]+r]=sum;
            hp[nums[i]]=sum;
            maxlen=max(maxlen,sum);
        }
        return maxlen;
    }
};

int main(int argc,char ** argv){
    Solution sol;

    //case 1
    vector<int> num1={100,4,200,1,3,2};
    int m1=sol.longestConsecutive(num1);
    cout << "示例1：" << m1 << endl;

    //case 2
    vector<int> num2={0,3,7,2,5,8,4,6,0,1};
    int m2=sol.longestConsecutive(num2);
    cout << "示例2：" << m2 << endl;

    //case 3
    vector<int> num3={1,0,1,2};
    int m3=sol.longestConsecutive(num3);
    cout << "示例3：" << m3 << endl;
}