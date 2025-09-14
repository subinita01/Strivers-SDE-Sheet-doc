// link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        if (head == NULL) {
            return head;
        }

        Node* curr = head;
        while (curr != NULL) {
            // if child exist
            if (curr->child != NULL) {
                // store, to connect it later to child's end node
                Node* next = curr->next;
                // flatten child node
                curr->next = flatten(curr->child);
                // suppose yha head return ho gya, now aage ka process
                curr->next->prev = curr;
                curr->child = NULL;
                // find tail
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                // attach tail with next node, if next is not null
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            // else part
            curr = curr->next;
        }
        return head;
    }
};