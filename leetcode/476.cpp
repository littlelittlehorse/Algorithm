#include <bits/stdc++.h>

using namespace std;


class TrieNode {
public:
    vector<TrieNode*> children;
    bool flag;
    TrieNode() {
        flag = false;
        children.resize(26, nullptr);
    }
    ~TrieNode() {
        for (auto& c : children) delete c;
    }
};


class WordDictionary {
public:
    TrieNode* root;
    string word_;
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < int(word.size()); i++) {
            int c = word[i] - 'a';
            if (node->children[c] == nullptr)
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->flag = true;
    }

    bool search(string word) {
        word_ = word;
        TrieNode* node = root;
        return dfs(node, 0);
    }

    bool dfs(TrieNode *node, int d) {
        if (d == word_.size())
            return node->flag;

        if (word_[d] == '.') {
            for (int i = 0; i < 26; i++) {
                if ((node->children[i] != nullptr) && dfs(node->children[i], d + 1))
                    return true;
            }
            return false;
        } else {
            int c = word_[d] - 'a';
            if ((node->children[c] != node) && dfs(node->children[c], d + 1))
                return true;
            return false;
        }

    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("abc");
    wordDictionary.addWord("bcd");
    wordDictionary.addWord("cde");
    cout << wordDictionary.search("cde") << endl;
    cout << wordDictionary.search("c.e") << endl;
}
