#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if(seen.find(need) != seen.end()){
                return {seen[need], i};
            }
            seen[nums[i]] = i;
        }
    }
};
int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution s;
    vector<int> hasil = s.twoSum(nums, target);
    for (int x : hasil) {
        cout << x << " ";
    }
}