#include <cstdlib>
#include <forward_list>
#include "getfile.hpp"
#include "Trie.hpp"

using namespace libaoc;

static inline void walk_trie(Trie &t, std::forward_list<char> &cl, char dig[], std::string &dstr)
{
    int node = NO_NODE;
    while (!cl.empty())
    {
        t.reset();
        for (char &c : cl)
        {
            node = t.next(c);
            if (TERM_NODE == node)
            {
                dstr.push_back(dig[t.cur_val()]);
            } else if (NO_NODE == node)
                break;
        }
        cl.pop_front();
    }
}

int main(int argc, char *argv[])
{
    std::vector<string> svc{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<int> vvc{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::forward_list<char> clist{};
    std::forward_list<char>::iterator cit;
    char dig[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    Trie trie{svc, vvc};
    if (argc < 2)
    {
        std::cerr << "Too few arguments, pass input file path.";
        return EXIT_FAILURE;
    }
    try
    {
        int total = 0;
        std::vector<std::string> svec;

        file_to_strs(argv[1], svec);
        for (std::string &lstr : svec)
        {
            std::string dstr = "";
            std::string gstr = "";
            for (const char &c : lstr)
            {
                if (std::isdigit(c))
                {
                    walk_trie(trie, clist, dig, dstr);
                    dstr.push_back(c);
                    cit = clist.end();
                } else
                {
                    if (clist.empty())
                    {
                        clist.push_front(c);
                        cit = clist.begin();
                    } else
                    {
                        clist.insert_after(cit, c);
                        cit++;
                    }
                }
            }
            walk_trie(trie, clist, dig, dstr);
            if (!dstr.empty())
            {
                gstr.push_back(dstr.front());
                gstr.push_back(dstr.back());
                total += std::stoi(gstr);
            }
        }
        std::cout << total;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
