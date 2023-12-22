#include "Trie.hpp"
#include <stdexcept>
#include <ranges>
#include <iostream>

using namespace libaoc;

TrieNode::TrieNode(const char k, int p, bool t) : key{k}, term{t}, pos{p}, val{0}, cvec(52, nullptr) {};

bool TrieNode::get_term() { return term; }
void TrieNode::set_term(bool t) { term = t; }

int TrieNode::get_pos() { return pos; }

char TrieNode::get_key() { return key; }

int TrieNode::get_val() { return val; }

void TrieNode::set_val(int v)
{
    val = v;
}

void TrieNode::set_next(char c, bool t)
{
    TrieNode *targ{nullptr};
    int i;
    if ((c <= 'z') && (c >= 'a'))
    {
        i = c - 'a';
        targ = cvec[i];
    } else if ((c <= 'Z') && (c >= 'A'))
    {
        i = c - 'A';
        targ = cvec[i];
    } else
        throw std::invalid_argument("Non-alphabetical character encountered.");
    if (nullptr != targ)
    {
        if (!targ->get_term())
            targ->set_term(t);
        return;
    }
    cvec[i] = new TrieNode(c, pos + 1, t);
    return;
}

TrieNode *TrieNode::get_next(char c)
{
    if ((c <= 'z') && (c >= 'a'))
    {
        return cvec[c - 'a'];
    } else if ((c <= 'Z') && (c >= 'A'))
    {
        return cvec[c - 'A'];
    } else
        throw std::invalid_argument("Non-alphabetical character encountered.");
}

TrieNode::~TrieNode()
{
    for (size_t i = 0; i < cvec.size(); i++)
    {
        if (nullptr != cvec[i])
        {
            delete cvec[i];
            cvec[i] = nullptr;
        }
    }
}

Trie::~Trie()
{
    reset();
}

Trie::Trie(vector<string> &svec, vector<int> &vals) : root('\0', -1, false), cur{&root}
{
    for (auto [s, v] : ranges::zip_view(svec, vals))
    {
        add_str(s, v);
    }
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
        return cur->get_term() ? TERM_NODE : REG_NODE;
    } else
        throw std::invalid_argument("Non-alphabetical character encountered.");
}

int Trie::cur_val()
{
    return cur->get_val();
}
void Trie::add_str(string &s, int &v)
{
    reset();
    for (char c : s)
    {
        cur->set_next(c, false);
        next(c);
    }
    cur->set_term(true);
    cur->set_val(v);
    reset();
}
