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
        char * in = new char[READMAX];
        unsigned int trash, sizeTree, sizeName;
        m_input.readsome(in, 3);
        trash = (in[0]&255)>>5;
        sizeTree = in[0]&31;
        sizeTree = (sizeTree<<8)|(in[1]&255);
        sizeName = in[2];
        cout << "Lixo: " << trash <<"\t\tÁrvore: " << sizeTree << "\t\tsizeName: " << sizeName << endl;
        string name;
        // MUDAR AQUI O TAMANHO
        m_input.readsome(in, 4);
        for (int i = 0; i < 4 ; i++) {
          name += (char)(in[i]&255);
        }
        m_input.readsome(in, sizeTree);
        for (int i = 0; i < sizeTree ; i++) {
          m_represent.push_back( in[i] );
        }
        cout << "Name " << name << "\t" << name.size() << "\t\t" << "Representação " << m_represent.size() << endl;
        list<bool> binary;
        cout << endl << "AQUI" << endl;
        ofstream file(m_oPath);
        m_tree = new Tree(m_represent);
        cout << endl << "AQUI" << endl;
        Node * fd = m_tree->getRoot();
        cout << "Terminando o arquivo" << endl;
        while( m_input.readsome(in, READMAX) ) {
          for( int i = 0 ; i < m_input.gcount() ; ++i  ) {
            for( int j = 0 ; j < 8 ; ++j ) {
              binary.push_back( in[i]&(1<<(7-j)) );
            }
          }
          cout << "LENDO " << m_input.gcount() << "\t\t Binary " << binary.size() << endl;
          while ( binary.size() >= m_tree->getHeigth() + trash ) {
            if( binary.front() )
              fd = fd->getRight();
            else
              fd = fd->getLeft();
            if( fd->isLeaf() ) {
              file << fd->getSymb();
              fd = m_tree->getRoot();
            }
            binary.pop_front();
          }
        }
        for( int i = 0 ; i < trash ; ++i )
          binary.pop_back();
        while ( binary.size() )
        {
            if( binary.front() )
              fd = fd->getRight();
            else
              fd = fd->getLeft();
            if( fd->isLeaf() ) {
              file << fd->getSymb();
              fd = m_tree->getRoot();
            }
            binary.pop_front();
        }
        cout << endl;
        file.close();
        delete []in;
}

vector<uchar> Decode::getRepresentation() const{
        return m_represent;
}
