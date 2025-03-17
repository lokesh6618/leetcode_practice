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

ListNode* findMid(ListNode* head){
    ListNode *first, *second = nullptr;

    first = head;

    second = (head && head->next) ? head->next->next : nullptr;

    while(second){
        first = first->next;
        second = (second->next) ? second->next->next : nullptr;
    }

    return first;
}

int pairSum(ListNode* head) {
    ListNode *mid_node = findMid(head);
    ListNode *last_node = reverseList(mid_node->next);

    int max_sum = 0;
    int current_sum = 0;

    while(last_node){
        current_sum = last_node->val + head->val;

        max_sum = max(max_sum, current_sum);

        last_node = last_node->next;
        head = head->next;
    }

    return max_sum;
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
    vector<int> nums = {5,4,2,1};
    ListNode* head = createLinkedList(nums);
    printList(head);

    cout << pairSum(head) << endl;

    cout << "done testing" << endl;
    return 0;
}
