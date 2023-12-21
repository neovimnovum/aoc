#include "Trie.hpp"

using namespace libaoc;

TrieNode::TrieNode(const char v, int_fast8_t p, bool t) : val{v}, pos{p}, term{t}, cvec(52) {};

Trie::Trie(vector<string> &svec) : root('\0', -1, false), cur{root}
{
    
};