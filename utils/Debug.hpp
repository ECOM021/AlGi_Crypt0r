#pragma once

#include "../inc/Globals.hpp"
#include "../inc/Encode.hpp"

class Debug {
 public:
         static void printOccur(vector<ulong_64> occur);
         static void printRepresentation(vector<uchar> rep);
         static void printCodes(unordered_map<uchar, vector<bool> > codes);
};
