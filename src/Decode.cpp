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
  m_tree = new Tree(m_represent);
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
        m_input.readsome(in, 3);
        trash = (in[0]&255)>>5;
        sizeTree = in[0]&31;
        sizeTree = (sizeTree<<8)|(in[1]&255);
        sizeName = in[2];
        cout << "Lixo: " << trash <<"\t\tÁrvore: " << sizeTree << "\t\tsizeName: " << sizeName << endl;
        string name;
        m_input.readsome(in, 4);
        for (int i = 0; i < 4 ; i++) {
          name += (char)(in[i]&255);
        }
        m_input.readsome(in, sizeTree);
        for (int i = 0; i < sizeTree ; i++) {
          m_represent.push_back( in[i] );
        }
        cout << "Name " << name << "\t" << name.size() << "\t\t" << "Representação " << m_represent.size() << endl;
        vector<bool> binary;
        ofstream file(m_oPath);
        cout << "Terminando o arquivo" << endl;
        while( m_input.readsome(in, 1024) ){
          cout << "LEU" << endl;
          for( int i = 0 ; i < m_input.gcount() ; ++i  ) {
            for( int j = 0 ; j < 8 ; ++j ) {
              binary.push_back( in[i]&(1<<(7-j)) );
            }
          }
        }
        cout << endl;
        delete []in;
}

vector<uchar> Decode::getRepresentation() const{
        return m_represent;
}
