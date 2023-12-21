#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <list>

static inline void file_to_strs(const char *fname, std::list<std::string> &slist) {
    std::ifstream ifl (fname);
    std::string src;

    if (ifl.is_open())
    {
        while (std::getline(ifl, src))
        {
            slist.push_back(src);
        }
    } else
    {
        throw std::runtime_error("Failed to open file.");
    }
    return;
}

static inline void file_to_strs(const char *fname, std::vector<std::string> &svec) {
    std::ifstream ifl (fname);
    std::string src;

    if (ifl.is_open())
    {
        while (std::getline(ifl, src))
        {
            svec.push_back(src);
        }
    } else
    {
        throw std::runtime_error("Failed to open file.");
    }
    return;
}

static inline void file_to_ints(const char *fname, std::vector<int> &svec) {
    std::ifstream ifl (fname);
    std::string src;

    if (ifl.is_open())
    {
        while (std::getline(ifl, src))
        {
            svec.push_back(std::stoi(src));
        }
    } else
    {
        throw std::runtime_error("Failed to open file.");
    }
    return;
}