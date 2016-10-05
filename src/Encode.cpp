#include "../inc/Encode.hpp"

Encode::Encode(string input, string output) {
        flag = 1;
        m_iPath = input;
        m_oPath = output;
        occur.resize(256, 0);
        if( !loadMedia() )
                return;
        countBytes();
        m_tree = new Tree( occur );
        buildRepresent(m_tree->getRoot());
        cout << endl;
        buildCodes(m_tree->getRoot(), vector<bool>() );
        cout << endl;
        loadMedia();
	m_output.open(m_oPath, fstream::out | std::fstream::binary);
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
        cout << "Flag " << flag++ << endl;
        if( subtree->isLeaf() ) {
                if( subtree->getSymb() == '*'
                        || subtree->getSymb() == '!' )
                        m_represent.push_back('!'), cout << "!";
                m_represent.push_back( subtree->getSymb() );
                cout << subtree->getSymb();
        } else {
                m_represent.push_back('*');
                cout << "*";
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
                coding.pop_back();
        }
}

void Encode::codingFile() {
        char * in = new char[1024];

        while(m_input.getline(in, 1024)) {
		vector<bool> binary;
                for (int i = 0; i < m_input.gcount() ; i++) {
			binary.insert( binary.end() , m_codes[ (uchar)in[i] ].begin(), m_codes[ (uchar)in[i] ].end() );
		}
		while( binary.size() >= 8 ) {

		}
	}
        delete []in;
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
