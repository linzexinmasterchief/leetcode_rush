// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <string.h>
#include <string>
#include <iostream>

// use a linked list of linked list for this problem
using namespace std;

class Node
{
    char c;
    Node* next_node = NULL;
    public:
    Node(char _c){
        c = _c;
    };

    Node* get_next(){
        return next_node;
    }

    void add_node(char c){
        Node* this_node = this;
        while (this_node -> next_node != NULL){
            this_node = this_node -> next_node;
        }
        Node* new_node = new Node(c);
        this_node -> next_node = new_node;
    }

    Node get_node(int index){
        int cur = 0;
        Node* this_node = this;
        while (this_node){
            if (cur < index){
                this_node = this_node -> next_node;
                index ++;
                continue;
            }
            return *this_node;
        }
        return NULL;
    }

    char get_char(int index){
        return get_node(index).c;
    }
};


class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        return 0;
    }
};

int main(){

    //string target_str = "abababcdabc";
    Node n('a');
    n.add_node('b');
    n.add_node('c');

    cout << n.get_char(2) << endl;

    // Solution s = Solution();
    // s.lengthOfLongestSubstring(target_str);
    return 0;
}