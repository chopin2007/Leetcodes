#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

// 示例 1：

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：

// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
// 示例 3：

// 输入：intervals = [[4,7],[1,4]]
// 输出：[[1,7]]
// 解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& x,const vector<int>& y){return x[0]<y[0];});
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1]=max(intervals[i+1][1],intervals[i][1]);
                intervals.erase(intervals.begin()+i+1);
                i--;
            }
        }
        return intervals;
    }
};

int main(int argc,char ** argv){
    Solution sol;

    //case 1
    vector<vector<int>> intervals1={{1,3},{2,6},{8,10},{15,18}};
    sol.merge(intervals1);
    cout << "示例1：[";
    for(int i=0;i<intervals1.size()-1;i++){
        cout << "[" << intervals1[i][0] << "," << intervals1[i][1] << "],";
    }
    cout << "[" << intervals1.back()[0] << "," << intervals1.back()[1] << "]]" << endl;

    //case 2
    vector<vector<int>> intervals2={{1,4},{4,5}};
    sol.merge(intervals2);
    cout << "示例2：[";
    for(int i=0;i<intervals2.size()-1;i++){
        cout << "[" << intervals2[i][0] << "," << intervals2[i][1] << "],";
    }
    cout << "[" << intervals2.back()[0] << "," << intervals2.back()[1] << "]]" << endl;

    //case 3
    vector<vector<int>> intervals3={{4,7},{1,4}};
    sol.merge(intervals3);
    cout << "示例3：[";
    for(int i=0;i<intervals3.size()-1;i++){
        cout << "[" << intervals3[i][0] << "," << intervals3[i][1] << "],";
    }
    cout << "[" << intervals3.back()[0] << "," << intervals3.back()[1] << "]]" << endl;
}