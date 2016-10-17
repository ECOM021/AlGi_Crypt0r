#include "../inc/Decode.hpp"

Decode::Decode(string input, string output) {
        m_iPath = input;
        m_oPath = output;
        //Pick FilePath
        std::size_t dash = m_iPath.find_last_of("/\\");
        if(m_oPath == "")
              m_oPath = m_iPath.substr(0,dash);
        else 
              m_oPath = output;            
        if( !loadMedia() )
                return;
        getHeader();
        m_oPath += "/" + m_name;
        cout << "Name do arq " << m_oPath << endl;
        m_tree = new Tree(m_represent);
        decodeFile();
}

bool Decode::loadMedia() {
        m_input.open(m_iPath, fstream::in | std::fstream::binary);
        if(m_input.is_open())
                return true;
        return false;
}

void Decode::decodeFile(){
        char * in = new char[READMAX];
        list<bool> binary;
        ofstream file(m_oPath);
        Node * fd = m_tree->getRoot();
        while( m_input.readsome(in, READMAX) )
        {
          for( int i = 0 ; i < m_input.gcount() ; ++i  )
          {
            for( int j = 0 ; j < 8 ; ++j )
            {
              binary.push_back( in[i]&(1<<(7-j)) );
            }
          }
          while ( binary.size() >= m_tree->getHeigth() + m_trash )
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
        }
        for( int i = 0 ; i < m_trash ; ++i )
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
        file.close();
        delete []in;
}

void Decode::getHeader() {
        char * in = new char[READMAX];
        unsigned int sizeTree, sizeName;
        m_input.readsome(in, 3);
        m_trash = (in[0]&255)>>5;
        sizeTree = in[0]&31;
        sizeTree = (sizeTree<<8)|(in[1]&255);
        sizeName = in[2];
        m_input.readsome(in, sizeName);
        for (int i = 0; i < sizeName ; i++) {
          m_name += (char)(in[i]&255);
        }
        m_input.readsome(in, sizeTree);
        for (int i = 0; i < sizeTree ; i++) {
          m_represent.push_back( in[i] );
        }
        delete []in;
}

vector<uchar> Decode::getRepresentation() const{
        return m_represent;
}

string Decode::getOutput() {
  return m_oPath;
}