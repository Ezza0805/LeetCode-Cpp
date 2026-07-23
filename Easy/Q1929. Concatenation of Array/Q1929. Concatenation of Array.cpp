#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        };        
        return nums;
    }
};
int main(){
    vector<int> nums = {1, 2, 3};

    Solution s;
    vector<int> hasil = s.getConcatenation(nums);
    for (int x : hasil) {
        cout << x << " ";
    }
}


