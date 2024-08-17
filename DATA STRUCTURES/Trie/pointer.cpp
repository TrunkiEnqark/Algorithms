#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct Node {
        Node* child[26];
        int cnt;
        int exist;

        Node() : cnt(0), exist(0) {
            for (int ch = 0; ch < 26; ++ch) 
                child[ch] = nullptr;
        }

        ~Node() {
            for (int ch = 0; ch < 26; ++ch)
                delete child[ch];
        }
    };
    Node* root;
public:
    Trie() : root(new Node()) {}

    ~Trie() {
        delete root;
    }

    void insert(const string& s) {
        Node* cur = root;
        for (auto c : s) {
            int nxt = c - 'a';
            if (cur->child[nxt] == nullptr) {
                cur->child[nxt] = new Node();
            }
            cur = cur->child[nxt];
            cur->cnt++;
        }
        cur->exist++;
    }

    bool find(const string& s) {
        Node* cur = root;
        for (auto c : s) {
            int nxt = c - 'a';
            if (cur->child[nxt] == nullptr) return false;
            cur = cur->child[nxt];
        }
        return cur->exist > 0;
    }

    bool erase_recursive(Node* current, const string& s, int idx) {
        if (idx != s.size()) {
            int nxt = s[idx] - 'a';
            bool is_child_deleted = erase_recursive(current->child[nxt], s, idx + 1);
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

    bool erase(const string& s) {
        if (!find(s)) return false;
        return !erase_recursive(root, s, 0);        
    }
};

Trie trie = Trie();

int main() {
    vector<string> words = {"abc", "a", "ab", "cba", "zzz", "aaa"};

    for (auto word : words) {
        trie.insert(word);
    }
    cout << trie.erase("b") << endl;  
    cout << trie.find("abc");
}