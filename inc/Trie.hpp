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
        char val;
        bool term;
        int pos;
        vector<TrieNode *> cvec;
    public:
        TrieNode(const char v, int_fast8_t p, bool t);
        void set_next(char c, bool t);
        TrieNode *get_next(char c);
        bool is_term();
    };

    class Trie
    {
    private:
        TrieNode root;
        TrieNode *cur;
    public:
        Trie(vector<string> &svec);
        void add_str(string s);
        int next(char c);
        void reset();
    };
} // namespace libaoc

#endif
