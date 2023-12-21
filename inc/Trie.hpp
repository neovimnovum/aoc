#include <vector>
#include <string>
#include <memory>

using namespace std;

namespace libaoc
{
    class TrieNode
    {
    private:
        char val;
        int_fast8_t pos;
        bool term;
        vector<unique_ptr<TrieNode>> cvec;
    public:
        TrieNode(const char v, int_fast8_t p, bool t);
    };

    class Trie
    {
    private:
        TrieNode root;
        TrieNode &cur;
    public:
        Trie(vector<string> &svec);
        void add_str(string s);
        int get_next(char c);
        void reset();
    };
} // namespace libaoc
