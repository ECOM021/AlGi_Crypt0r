#include "../inc/Encode.hpp"

Encode::Encode(string input, string output) {
        m_iPath = input;
        m_oPath = output;
        occur.resize(256, 0);
        if( !loadMedia() )
                return;
        countBytes();
        m_tree = new Tree( occur );
        buildRepresent(m_tree->getRoot());
        buildCodes(m_tree->getRoot(), vector<bool>() );
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

        delete []in;
}

void Encode::buildRepresent( Node * subtree ) {
        if( subtree->isLeaf() ) {
                if( subtree->getSymb() == (uchar)'*'
                        || subtree->getSymb() == (uchar)'!' )
                        m_represent.push_back('!');
                m_represent.push_back( subtree->getSymb() );
        } else {
                m_represent.push_back('*');
                buildRepresent(subtree->getLeft());
                buildRepresent(subtree->getRight());
        }
}

void Encode::buildCodes(Node *subtree, vector<bool> coding) {
        if( subtree->isLeaf() ) {
                m_codes[ subtree->getSymb() ] = coding;
        } else {
                coding.push_back(false);
                buildCodes(subtree->getLeft(), coding);
                coding.pop_back();
                coding.push_back(true);
                buildCodes(subtree->getRight() , coding);
        }
}

vector<ulong_64> Encode::getOccur() const {
        return occur;
}

unordered_map< uchar, vector<bool> > Encode::getCodes() const {
        return m_codes;
}

vector<uchar> Encode::getRepresentation() const{
        return m_represent;
}
