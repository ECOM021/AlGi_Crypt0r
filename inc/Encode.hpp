#pragma once

#include "Globals.h"

class Encode {
 public:
         Encode(std::string input, std::std output = "");
         bool loadMedia();
         void countBytes();

 private:
         std::string m_iPath;
         std::string m_oPath;
         FILE* m_input;
         FILE* m_output;
         vector<ulong_64> occur;

};
