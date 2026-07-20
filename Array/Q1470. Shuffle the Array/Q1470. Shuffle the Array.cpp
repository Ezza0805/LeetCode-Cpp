#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums, int n) {
        
        vector<int>ans = {};

        for (int i = 0; i < n; i++){
            ans.push_back(nums[i]);
            if (i < n) {
                ans.push_back(nums[i+n]);
            }
        };        
        return ans;
    }
};
int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int n = 3;

    Solution s;
    vector<int> hasil = s.getConcatenation(nums, n);
    for (int x : hasil) {
        cout << x << " ";
    }
}