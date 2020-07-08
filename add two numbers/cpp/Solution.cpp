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
        ListNode* ans;
        ListNode node = *ans;
        node.val = l1 -> val + l2 -> val;
        if (l1 != NULL && l2 != NULL) {
            node.next = addTwoNumbers(l1 -> next, l2 -> next);
        }
        
        return ans;
        
    }
};

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

int main(void){
    int a = 123;
    int b = 234;
    cout << "lalalallalalla" << endl;

    ListNode* l1 = num_to_link_list(a);
    ListNode* l2 = num_to_link_list(b);

    auto s = Solution();
    auto ans = s.addTwoNumbers(l1, l2);
    cout << "----------------" << endl;
    ListNode l = ListNode(0);
    ListNode *np = ans;
    while (np != NULL) {
        l = *np;
        cout << l.val << endl;
        np = l.next;
    }

    return 0;
}