#ifndef FILTER_HPP
#define FILTER_HPP

#include <string>

class Filter {
public:
        Filter(std::string file, std::string folder, std::string ext);
        std::string getOutput();
        std::string getInput();
private:
        std::string input, output;
};

#endif //FILTER_HPP
