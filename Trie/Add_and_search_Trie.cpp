
#include <iostream>
#include <vector>
#include "unordered_map"
using namespace std;


struct RW_TrieNode {
	bool isKey;
    RW_TrieNode(): isKey(false), next(26,nullptr) {};
    vector<RW_TrieNode *>  next;
};
class WordDictionary {
private:
    RW_TrieNode *root;
    bool search_Trie(string word, RW_TrieNode *root) {
        auto curr = root;
        for(int i =0; i< word.size(); i++ ){
            if(!curr) return false;
            else if(word[i] == '.') {
                for(int j = 0; j< 26; j++){
                    if(search_Trie(word.substr(i+1),curr->next[j])) return true;
                }
            }
            curr = curr->next[word[i] - 'a'];
        }
        return (curr && curr->isKey);
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new RW_TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto curr = root;
        for(auto c:word) {
            if(curr->next[c - 'a'] == nullptr)  curr->next[c - 'a'] = new RW_TrieNode();
            curr = curr->next[c - 'a'];
        }
        curr->isKey = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_Trie(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
