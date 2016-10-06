#include "../inc/Decode.hpp"

Decode::Decode(string input, string output) {
  m_iPath = input;

  if(output == "")
    m_oPath = input + ".huff";
  else
    m_oPath = output;
  if( !loadMedia() )
    return;
    getHeader();
}

bool Decode::loadMedia() {
        m_input.open(m_iPath, fstream::in | std::fstream::binary);
        if(m_input.is_open())
                return true;
        return false;
}

void Decode::getHeader() {
        char * in = new char[1024];
        unsigned int trash, sizeTree, sizeName;
        m_input.getline(in, 3);
        trash = (in[0]&255)>>5;
        sizeTree = in[0]&31;
        sizeTree = (sizeTree<<8)|(in[1]&255);
        sizeName = in[2];
        cout << "Lixo: " << trash <<"\tÁrvore: " << sizeTree << "\tsizeName: " << sizeName << endl;
        delete []in;
}
