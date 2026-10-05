#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

 

// 示例 1:

// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

// 解释：

// 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
// 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
// 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
// 示例 2:

// 输入: strs = [""]

// 输出: [[""]]

// 示例 3:

// 输入: strs = ["a"]

// 输出: [["a"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> hp;
        vector<vector<string>> result;
        if(strs.size()<1) return result;
        if(strs.size()==1){
            result.push_back(strs);
            return result;
        }
        vector<string> mirror=strs;
        for(int i=0;i<strs.size();i++){
            sort(mirror[i].begin(),mirror[i].end());
            if(hp.count(mirror[i])){
                hp[mirror[i]].push_back(i);
            }
            else{
                hp[mirror[i]]={i};
            }
        }
        for(const auto& item:hp){
            vector<string> s;
            for(const auto& index:item.second){
                s.push_back(strs[index]);
            }
            result.push_back(s);
        }
        return result;
    }
};

int main(int argc,char ** argv){
    Solution sol;

    //case 1
    vector<string> str1={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res1=sol.groupAnagrams(str1);
    cout << "示例1：[";
    for(int i=0;i<res1.size();i++){
        cout << "[";
        for(int j=0;j<res1[i].size()-1;j++){
            cout << "\"" << res1[i][j] << "\",";
        }
        cout << "\"" << res1[i].back() << "\"]";
    }
    cout << "]" << endl;

    //case 2
    vector<string> str2={""};
    vector<vector<string>> res2=sol.groupAnagrams(str2);
    cout << "示例2：[";
    for(int i=0;i<res2.size();i++){
        cout << "[";
        for(int j=0;j<res2[i].size()-1;j++){
            cout << "\"" << res2[i][j] << "\",";
        }
        cout << "\"" << res2[i].back() << "\"]";
    }
    cout << "]" << endl;

    //case 3
    vector<string> str3={"a"};
    vector<vector<string>> res3=sol.groupAnagrams(str3);
    cout << "示例2：[";
    for(int i=0;i<res3.size();i++){
        cout << "[";
        for(int j=0;j<res3[i].size()-1;j++){
            cout << "\"" << res3[i][j] << "\",";
        }
        cout << "\"" << res3[i].back() << "\"]";
    }
    cout << "]" << endl;
}