#ifndef LIBAOC_H_INCLUDED
#define LIBAOC_H_INCLUDED
#include <vector>
#include <string>

#define TERM_NODE 2
#define REG_NODE 1
#define NO_NODE 0

using namespace std;

namespace libaoc
{
    class TrieNode
    {
    private:
        char key;
        bool term;
        int pos;
        int val;
        vector<TrieNode *> cvec;
    public:
        TrieNode(const char k, int p, bool t);
        ~TrieNode();
        void set_next(char c, bool t);
        TrieNode *get_next(char c);
        bool get_term();
        void set_term(bool t);
        int get_pos();
        char get_key();
        int get_val();
        void set_val(int v);
    };

    class Trie
    {
    private:
        TrieNode root;
        TrieNode *cur;
    public:
        Trie(vector<string> &svec, vector<int> &vals);
        ~Trie();
        void add_str(string &s, int &v);
        int next(char c);
        int cur_val();
        void reset();
    };
} // namespace libaoc

#endif
