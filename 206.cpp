#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverseList(ListNode* head) {
    ListNode *previous = nullptr;
    ListNode *temp_next = nullptr;

    while(head){
        temp_next = head->next;
        head->next = previous;
        previous = head;
        head = temp_next;
    }

    return previous;
}

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " , ";
        head = head->next;
    }

    cout << endl;
}

ListNode* createLinkedList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

int main()
{   
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = createLinkedList(nums);
    printList(head);
    ListNode* new_head = reverseList(head);
    printList(new_head);


    cout << "done testing" << endl;
    return 0;
}
