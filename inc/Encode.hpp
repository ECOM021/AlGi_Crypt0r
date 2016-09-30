#pragma once

#include "Globals.hpp"

class Encode {
 public:
         Encode(string input, string output = "");
         bool loadMedia();
         void countBytes();
         void printOccur();

 private:
         string m_iPath;
         string m_oPath;
         fstream m_input;
         fstream m_output;
         vector<ulong_64> occur;

};
