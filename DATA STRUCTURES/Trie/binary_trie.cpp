#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct Node {
        Node* child[2];
        int cnt;
        int exist;

        Node() : cnt(0), exist(0) {
            for (int ch = 0; ch < 2; ++ch) 
                child[ch] = nullptr;
        }

        ~Node() {
            for (int ch = 0; ch < 2; ++ch)
                delete child[ch];
        }
    };
    Node* root;
public:
    Trie() : root(new Node()) {}

    ~Trie() {
        delete root;
    }

    void insert(const int& num) {
        Node* cur = root;
        for (int i = 31; i >= 0; --i) {
            int nxt = (num >> i) & 1;
            if (cur->child[nxt] == nullptr) {
                cur->child[nxt] = new Node();
            }
            cur = cur->child[nxt];
            cur->cnt++;
        }
        cur->exist++;
    }

    bool find(const int& num) {
        Node* cur = root;
        for (int i = 31; i >= 0; --i) {
            int nxt = (num >> i) & 1;
            if (cur->child[nxt] == nullptr) return false;
            cur = cur->child[nxt];
        }
        return cur->exist > 0;
    }

    bool erase_recursive(Node* current, const int& num, int idx) {
        if (idx != 0) {
            int nxt = (num >> idx) & 1;
            bool is_child_deleted = erase_recursive(current->child[nxt], num, idx - 1);
            if (is_child_deleted) current->child[nxt] = nullptr;
        } else {
            current->exist--;
        }

        if (current != root) {
            current->cnt--;
            if (current->cnt == 0) {
                delete current;
                return true; // deleted
            }
        }
        return false;
    }

    bool erase(const int& num) {
        if (!find(num)) return false;
        return !erase_recursive(root, num, 31);        
    }

    int find_max_xor(const int& num) {
        Node* cur = root;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int nxt = (num >> i) & 1;
            if (cur->child[nxt ^ 1] != nullptr) {
                cur = cur->child[nxt ^ 1];
                res |= (1 << i);
            } else {
                cur = cur->child[nxt];
            }
        }
        return res;
    }
};

Trie trie = Trie();

int main() {
    vector<int> nums = {3,10,5,25,2,8};
    for (auto num : nums) {
        trie.insert(num);
    }
    cout << trie.erase(10) << endl;
    cout << trie.find_max_xor(5) << endl;
}