#include "../inc/Encode.hpp"

Encode::Encode(string input, string output) {
        flag = 1;
        m_iPath = input;

        if(output == "")
                m_oPath = input + ".huff";
        else
                m_oPath = output;

        occur.resize(256, 0);
        if( !loadMedia() )
                return;
        countBytes();
        m_tree = new Tree( occur );
        buildRepresent(m_tree->getRoot());
        buildCodes(m_tree->getRoot(), vector<bool>() );
        m_input.close();
        loadMedia();
        codingFile();
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
        ofstream file(m_oPath);
        vector<bool> binary;
        file << 0x00;
        file << 0x00;
        for (auto p : m_represent )
                file << p;
        while(m_input.getline(in, 1024)) {
                for (int i = 0; i < m_input.gcount() ; i++) {
			binary.insert( binary.end() , m_codes[ (uchar)in[i] ].begin(), m_codes[ (uchar)in[i] ].end() );
		}
		while( binary.size() >= 8 ) {
                        uchar value = 0;
                        for( int i = 0 ; i < 8 ; ++i )
                                value = (value<<1) | binary[i];
                        file << value;
                        binary.erase( binary.begin() , binary.begin()+8 );
		}
	}
        uchar trash = 0;
        cout << "TRASH " << binary.size() << endl;
        if( binary.size() ) {
                trash = 8 - binary.size();
                while ( binary.size() < 8 )
                        binary.push_back(false);
                uchar value = 0;
                for( int i = 0 ; i < 8 ; ++i )
                        value = (value<<1) | binary[i];
                file << value;
                binary.erase( binary.begin() , binary.begin()+8 );
        }
        file.seekp(0);
        string twobytes = "";
        twobytes += ((trash<<5)|(((int)m_represent.size())>>8));
        twobytes += (m_represent.size()&255);
        file << twobytes;
        //file << ((char)((trash&255)<<5)|((((int)m_represent.size())&255)>>8));
        //file << (m_represent.size()&255);
        delete []in;
        file.close();
}

void Encode::write() {

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
