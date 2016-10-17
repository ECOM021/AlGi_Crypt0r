#ifndef DECODE_HPP
#define DECODE_HPP

using namespace std;
#include "Globals.hpp"
#include "Tree.hpp"

class Decode {
 public:
         Decode(string input, string output = "");
         bool loadMedia();
         void getHeader();
         void decodeFile();
         vector<uchar> getRepresentation() const;
         string getOutput();
 private:
         string m_iPath;
         int m_trash;
         string m_oPath;
         fstream m_input;
         fstream m_output;
         Tree * m_tree;
         vector<uchar> m_represent;
};

#endif // !DECODE_HPP