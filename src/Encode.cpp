#include <../inc/Encode.hpp>

Encode::Encode(std::string input, std::std output) {
        m_iPath = input;
        m_oPath = output;
        occur.resize(256, 0);
}

bool Encode::loadMedia() {
        if((m_input = fopen(m_iPath)) != NULL)
                return false;
        return true;
}

void Encode::countBytes() {
        short c;
        unsigned short uc;
        while((c = (uc = fgetc(m_input))) != EOF)
                ++occur[uc];
}

void Encode::printOccur() {
        std::cout << "ASCII\tOCCUR\n";
        for(int i = 0; i < 256; ++i)
                if(occur[i])
                        std::cout << i << '\t' << occur[i] << '\n';
}
