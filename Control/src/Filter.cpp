#include "../inc/Filter.hpp"

Filter::Filter(std::string file, std::string folder, std::string ext) {
        input = file;
        output = folder;

        //Pick FilePath
        std::size_t dash = input.find_last_of("/\\");
        if(output == "")
                output = input.substr(0, dash);

        output += "/" + input.substr(dash+1);

        //Pick FileName 
        std::size_t dot = output.find_last_of(".");
        output = output.substr(0, dot);
        output += "."+ext;
}

std::string Filter::getOutput() {
        return output;
}

std::string Filter::getInput() {
        return input;
}


