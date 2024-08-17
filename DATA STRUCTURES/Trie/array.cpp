#include <bits/stdc++.h>

using namespace std;

const int NUMER_OF_NODES = 1e5 + 5;

class Trie {
private:
    struct Node {
        int child[26];
        int cnt;
        int exist;

        Node() : cnt(0), exist(0) {
            memset(child, -1, sizeof child);
        }
    };

    Node trie[NUMER_OF_NODES];
    int cur_node;
public:
    Trie() : cur_node(0) {
        trie[0] = Node();
    };

    void insert(const string& s) {
        int root = 0;
        for (auto c : s) {
            int nxt = c - 'a';
            if (trie[root].child[nxt] == -1) {
                trie[root].child[nxt] = ++cur_node;
                trie[cur_node] = Node();
            }
            root = trie[root].child[nxt];
            trie[root].cnt++;
        }
        trie[root].exist++;
    }

    bool find(const string& s) {
        int root = 0;
        for (auto c : s) {
            int nxt = c - 'a';
            if (trie[root].child[nxt] == -1) return false;
            root = trie[root].child[nxt];
        }
        return trie[root].exist > 0;
    }

    bool erase(const string& s) {
        if (!find(s)) return false;
        return !erase_recursive(0, s, 0);
    }

    bool erase_recursive(int current, const string& s, int idx) {
        if (idx != s.size()) {
            int nxt = s[idx] - 'a';
            bool is_child_deleted = erase_recursive(trie[current].child[nxt], s, idx + 1);
            if (is_child_deleted) trie[current].child[nxt] = -1;
        } else {
            trie[current].exist--;
        }

        if (current != 0) {
            trie[current].cnt--;
            if (trie[current].cnt == 0) {
                return true;
            }
        }
        return false;
    }
};

Trie tree = Trie();

int main() {
    vector<string> words = {"abc", "a", "ab", "cba", "zzz", "aaa"};

    for (auto word : words) {
        tree.insert(word);
    }
    cout << tree.erase("c") << endl;
    cout << tree.find("abc");
}