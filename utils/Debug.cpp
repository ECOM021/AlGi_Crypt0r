#include "Debug.hpp"

void Debug::printOccur(vector<ulong_64> occur) {
        cout << "ASCII\tOCCUR\n";
        for(int i = 0; i < ASCII_SIZE; ++i)
                if(occur[i])
                        cout << i << "\t" << occur[i] << "\n";
}

void Debug::printRepresentation(vector<uchar> rep) {
        cout << "Representation:\t" << rep.size() << endl;
        for( auto p : rep )
                cout << p;
        cout << endl;
}

void Debug::printCodes(unordered_map<uchar, vector<bool> > codes) {
        for( auto p : codes ) {
                cout << p.first << " : ";
                for( auto q : p.second )
                        cout << (q&1);
                cout << endl;
        }
}
