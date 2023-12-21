#include <cstdlib>
#include <unordered_map>
#include "getfile.hpp"



int main(int argc, char *argv[])
{
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
            std::string sstr = "";
            std::string dstr = "";
            std::string gstr = "";
            for (const char &c : lstr)
            {
                if (std::isdigit(c))
                {
                    sstr.clear();
                    dstr.push_back(c);
                } else
                {
                    sstr.push_back(c);
                }
            }
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