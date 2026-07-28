#pragma once
#include <string>
#include "utils/struct node.hpp"

using namespace std;
class Solution {
public:
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
        ListNode* hasilHead = nullptr;
        ListNode* hasilTail = nullptr;
        string carry = "";
        string keep = "";

        while (l1!= nullptr || l2 != nullptr)
        {
            ListNode* nodeBaru = new ListNode();
            if (l1 == nullptr)
            {
                nodeBaru->val += l2->val;
                l2 = l2->next;
            }
            else if (l2 == nullptr)
            {
                nodeBaru->val += l1->val;
                l1 = l1->next;
            }
            else
            {
                nodeBaru->val = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            if (carry.length() == 1)
            {
                nodeBaru->val += stoi(carry);
                carry.erase(0, 1);
            }

            if (to_string(nodeBaru->val).length() == 2)
            {
                carry = to_string(nodeBaru->val); carry.erase(1, 1);
                keep = to_string(nodeBaru->val); keep.erase(0, 1);
                
                nodeBaru->val = stoi(keep);
            }
            if(hasilHead == nullptr)
            {
                hasilHead = nodeBaru;
                hasilTail = nodeBaru;
            }
            else
            {
                hasilTail->next = nodeBaru;
                hasilTail = nodeBaru;
            }
        }
        if (l1 == nullptr && l2 == nullptr && carry.length() == 1){
            ListNode* nodeCarryAkhir = new ListNode();
            nodeCarryAkhir->val = stoi(carry);
            hasilTail->next = nodeCarryAkhir;
            hasilTail = nodeCarryAkhir;
        }
        return hasilHead;  
    }
};