#pragma once
using namespace std;
#include "Globals.hpp"
#include "Tree.hpp"


class Decode {
 public:
         Decode(string input, string output = "");
         bool loadMedia();
         void getHeader();
 private:
         string m_iPath;
         string m_oPath;
         fstream m_input;
         fstream m_output;
         Tree * m_tree;
         vector<uchar> m_represent;
};
