#pragma once
#include <vector>
#include "struct node.hpp"

using std::vector;

class CreateList {
public:
    ListNode* createList (vector<int> nums){
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int _ = 0; _ < nums.size(); _++){
            ListNode* nodeBaru = new ListNode();
            nodeBaru->val = nums[_];
            if (head == nullptr){
                head = nodeBaru;
                tail = nodeBaru;
            } else {
                tail->next = nodeBaru;
                tail = nodeBaru;
            }
        }
        return head;
    }
};