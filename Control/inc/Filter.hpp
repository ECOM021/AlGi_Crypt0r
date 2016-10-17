#ifndef FILTER_HPP
#define FILTER_HPP

#include <string>

class Filter {
public:
        Filter(std::string file, std::string folder);

        //Encrypt
        void filterEnc1();
        void filterEnc2();

        //Decrypt  
        void filterDec1();
        void filterDec2();
private:
        std::string input;
        std::string output;

        std::string CompressIn;
        std::string EncryptIn;

        std::string DecompressIn;
        std::string DecryptIn;
};

#endif //FILTER_HPP
