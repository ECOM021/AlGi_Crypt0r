#ifndef ENCODE_HPP
#define ENCODE_HPP

using namespace std;

#include "Globals.hpp"
#include "Tree.hpp"

class Encode {
 public:
         Encode(string input, string output = "");
         bool loadMedia();
         void countBytes();
         void buildRepresent( Node * subtree );
         void buildCodes( Node * subtree , vector<bool> coding );
         void codingFile();
         vector<ulong_64> getOccur() const;
         unordered_map< uchar, vector<bool> > getCodes() const;
         vector<uchar> getRepresentation() const;
         string SplitFilename (string str);
         string getOutput();
 private:
         string m_iPath;
         string m_oPath;
         fstream m_input;
         fstream m_output;
         vector<ulong_64> occur;
         Tree * m_tree;
         unordered_map< uchar , vector<bool> > m_codes;
         vector<uchar> m_represent;
};

#endif // !ENCODE_HPP