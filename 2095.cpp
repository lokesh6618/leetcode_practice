#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return nullptr;  // If 1 node, return nullptr

    ListNode *first = head, *second = head, *previous = nullptr;

    while (second && second->next) {
        previous = first;
        first = first->next;
        second = second->next->next;
    }

    previous->next = first->next;

    return head;
}

void findMid(ListNode* head){
    ListNode *first, *second, *previous = nullptr;

    first = head;
    previous = first;

    second = (head && head->next) ? head->next->next : nullptr;

    if(second == nullptr){
        first->next = nullptr;
        return;
    }

    while(second != nullptr){
        previous = first;
        first = first->next;
        second = (second->next) ? second->next->next : nullptr;
    }

    cout << "middle value " << first->val << endl;

    previous->next = (first->next != nullptr) ? first->next : nullptr;

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
    vector<int> nums = {1,2,3,4};
    ListNode* head = createLinkedList(nums);
    printList(head);
    deleteMiddle(head);
    printList(head);


    cout << "done testing" << endl;
    return 0;
}
