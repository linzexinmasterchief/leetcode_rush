// problem link: https://leetcode-cn.com/problems/add-two-numbers/
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // add value of l1 node to l2 node
        (*l2).val = (*l1).val + (*l2).val;
        // carry
        int carry = 0;
        if ((*l2).val >= 10) {
            carry = (*l2).val / 10;
            (*l2).val = (*l2).val % 10;
        }
        if (carry > 0) {
            // check if current l2 node has next node to store carry
            if (l2 -> next == NULL){
                // if no, create a new node and assign carry as it's value
                (*l2).next = new ListNode(carry);
            }else{
                // if yes, add carry to the value of the next node
                (*(l2 -> next)).val += carry;
            }
        }
        // make sure if one list ended earlier than the other one,
        // fill the empty space with a temp node with val 0
        if (l1 -> next != NULL && l2 -> next != NULL) {
            (*l2).next = addTwoNumbers(l1 -> next, l2 -> next);
        }else if (l1 -> next == NULL && l2 -> next != NULL) {
            (*l2).next = addTwoNumbers(new ListNode(0), l2 -> next);
        }else if (l1 -> next != NULL && l2 -> next == NULL) {
            (*l2).next = addTwoNumbers(l1 -> next, new ListNode(0));
        }else if (l1 -> next == NULL && l2 -> next == NULL) {
            // only exit when both list are ended
            return l2;
        }
        return l2;
    }
};

// generate link list from number
ListNode* num_to_link_list(int num) {
    // ListNode* np = (ListNode*) malloc(sizeof(ListNode));
    ListNode* np = new ListNode(0);
    ListNode node = ListNode(num % 10);
    if (num > 10){
        node.next = num_to_link_list(num / 10);
    }
    cout << node.next << endl;
    // np = &node;
    *np = node;
    cout << (*np).val << endl;
    return np;
}

void print_link_list(ListNode* node) {
    if (node -> next) {
        print_link_list(node -> next);
    }
    cout << (*node).val;
}

int main(void){
    int a = 2334;
    int b = 843;
    cout << "lalalallalalla" << endl;

    ListNode* l1 = num_to_link_list(a);
    ListNode* l2 = num_to_link_list(b);

    auto s = Solution();
    auto ans = s.addTwoNumbers(l1, l2);
    cout << "----------------" << endl;
    print_link_list(ans);

    return 0;
}