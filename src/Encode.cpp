#include "../inc/Encode.hpp"

Encode::Encode(string input, string output) {
        m_iPath = input;
        m_oPath = output;
        occur.resize(256, 0);
}

bool Encode::loadMedia() {
        m_input.open(m_iPath, fstream::in | std::fstream::binary);
        if(m_input.is_open())
                return true;
        return false;
}

void Encode::countBytes() {
        char * in = new char[1024];

        while(m_input.getline(in, 1024))
                for (int i = 0; i < m_input.gcount() ; i++)
                        ++occur[(uchar) in[i] ];

        delete in;
}

void Encode::printOccur() {
        cout << "ASCII\tOCCUR\n";
        for(int i = 0; i < 256; ++i)
                if(occur[i])
                        cout << i << '\t' << occur[i] << '\n';
}
