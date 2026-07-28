#include <iostream>
#include <vector>
#include "solution/solution.hpp"


int main(){
    Solution s;
    CreateList l;
    

    // masukkan angka pada vector
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    
    ListNode* l1 = l.createList(nums1);
    ListNode* l2 = l.createList(nums2);

    ListNode* nodel1 = l1;

    ListNode* hasil = s.addTwoNumber(l1, l2);

    while(hasil != nullptr){
        cout << hasil -> val << " ";
        hasil = hasil->next;
    }


}