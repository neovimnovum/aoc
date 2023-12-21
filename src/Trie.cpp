#include "Trie.hpp"
#include <stdexcept>

using namespace libaoc;

TrieNode::TrieNode(const char v, int_fast8_t p, bool t) : val{v}, pos{p}, term{t}, cvec(52, nullptr) {};

bool TrieNode::is_term() { return term; }

TrieNode *TrieNode::get_next(char c)
{

}

Trie::Trie(vector<string> &svec) : root('\0', -1, false), cur{&root}
{
    
};

void Trie::reset()
{
    cur = &root;
    return;
}

int Trie::next(char c)
{
    if (cur == nullptr)
    {
        throw std::out_of_range("Null current TrieNode, call reset()");
    }
    if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')))
    {
        cur = cur->get_next(c);
        if (cur == nullptr)
        {
            reset();
            return NO_NODE;
        }
        return cur->is_term() ? TERM_NODE : REG_NODE;
    } else
        throw std::invalid_argument("Non-alphabetical character encountered.");
}

void Trie::add_str(string s)
{
    reset();
    for (char c : s)
    {

    }
}
