#include "../inc/Encode.hpp"

Encode::Encode(string input, string output) {

        m_iPath = input;
        cout << "Name ---- " << endl;
        if(output == "")
                m_oPath = input + ".huff";
        else
                m_oPath = output;

        occur.resize(ASCII_SIZE, 0);
        if( !loadMedia() ){
                return;
        }
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
        char * in = new char[READMAX];

        while(m_input.readsome(in, READMAX))
                for (int i = 0; i < m_input.gcount() ; i++)
                        ++occur[(uchar) in[i] ];

        delete []in;
}

void Encode::buildRepresent( Node * subtree ) {

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
        char * in = new char[READMAX];
        ofstream file(m_oPath);
        list<bool> binary;
        file << 0x00;
        file << 0x00;
        file << 0x00;
        uchar nameSize = SplitFilename(m_iPath).size();
        file << SplitFilename(m_iPath);
        for (auto p : m_represent )
                file << p;
        while(m_input.readsome(in, READMAX)) {
                for (int i = 0; i < m_input.gcount() ; i++) {
			for( auto bin : m_codes[ (uchar)in[i] ] )
                                binary.push_back(bin);
		}
		while( binary.size() >= 8 ) {
                        uchar value = 0;
                        for( int i = 0 ; i < 8 ; ++i ) {
                                value = (value<<1) | binary.front();
                                binary.pop_front();
                        }
                        file << value;
		}
	}
        uchar trash = 0;
        if( binary.size() ) {
                trash = 8 - binary.size();
                while ( binary.size() < 8 )
                        binary.push_back(false);
                uchar value = 0;
                for( int i = 0 ; i < 8 ; ++i ) {
                        value = (value<<1) | binary.front();
                        binary.pop_front();
                }
                file << value;
        }
        file.seekp(0);
        string twobytes = "";
        twobytes += ((trash<<5)|(((int)m_represent.size())>>8));
        twobytes += (m_represent.size()&255);
        file << twobytes;
        file << nameSize;
        delete []in;
        file.close();
}

string Encode::SplitFilename (string str) {
        size_t found = str.find_last_of("/\\");
        return str.substr(found+1);
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
