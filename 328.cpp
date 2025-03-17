#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* oddEvenList(ListNode* head) {
    ListNode *odd = nullptr;
    ListNode *even = nullptr; 
    ListNode *next = nullptr; 
    ListNode *first_even = nullptr; 
    ListNode *first_odd = nullptr;

    int counter = 1;

    while(head){
        next = head->next;

        if(counter%2 == 0){
            if(even){
                even->next = head;
                even = even->next;
            }else{
                even = head;
                first_even = even;
            }
            
        }else{
            if(odd){
                odd->next = head;
                odd = odd->next;
            }else{
                odd = head;
                first_odd = odd;
            }
        }

        head = next;
        counter++;
    }

    if(odd){
        odd->next = first_even;
    }
    

    return first_odd ? first_odd : first_even;
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
    ListNode* new_head = oddEvenList(head);
    printList(new_head);


    cout << "done testing" << endl;
    return 0;
}
