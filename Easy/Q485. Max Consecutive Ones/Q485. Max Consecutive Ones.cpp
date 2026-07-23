#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
            int final = 0;
            int temp = 0;

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 1){
                    temp += 1;
                        if(temp > final){
                        final = temp;
                    }
                } else {
                    temp = 0;
                }
            }
            return final;
    }
};
int main(){
    //nums just using 1 & 0
    vector<int> nums = {1,0,1,1,0,1};

    Solution s;
    int hasil = s.findMaxConsecutiveOnes(nums);
    cout << hasil;
}