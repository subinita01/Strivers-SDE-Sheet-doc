//LC: Question 146
//Implement LRU Cache

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // helper: insert node right after head
    void addNode(Node* newNode) {
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }

    // helper: remove node from list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // helper: print current cache state
    void printCache() {
        cout << "Cache state (MRU -> LRU): ";
        Node* temp = head->next;
        while (temp != tail) {
            cout << "(" << temp->key << "," << temp->val << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* resNode = mp[key];
            int res = resNode->val;

            // move accessed node to front
            deleteNode(resNode);
            addNode(resNode);

            mp[key] = head->next;

            cout << "get(" << key << ") -> " << res << endl;
            printCache();
            return res;
        }
        cout << "get(" << key << ") -> -1" << endl;
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // key exists → update value & move to front
            Node* existingNode = mp[key];
            existingNode->val = value;
            deleteNode(existingNode);
            addNode(existingNode);
            mp[key] = head->next;
        } else {
            // new key
            if (mp.size() == cap) {
                // remove least recently used (node before tail)
                Node* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
                delete lru; // free memory
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            mp[key] = newNode;
        }

        cout << "put(" << key << "," << value << ")" << endl;
        printCache();
    }
};

int main() {
    LRUCache cache(2); // capacity = 2

    cache.put(1, 1);   // [1]
    cache.put(2, 2);   // [2, 1]
    cache.get(1);      // returns 1 → [1, 2]
    cache.put(3, 3);   // evicts 2 → [3, 1]
    cache.get(2);      // returns -1
    cache.put(4, 4);   // evicts 1 → [4, 3]
    cache.get(1);      // returns -1
    cache.get(3);      // returns 3 → [3, 4]
    cache.get(4);      // returns 4 → [4, 3]

    return 0;
}
