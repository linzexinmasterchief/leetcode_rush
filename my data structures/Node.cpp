#include <iostream>

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