#include "../inc/Encode.hpp"

string path = "/home/gio/workspace/AlGi_Crypt0r/test/test";

 int main(int argc, char const *argv[]) {
         Encode *ptr = new Encode(path);

         ptr->loadMedia();
         ptr->countBytes();
         ptr->printOccur();

         return 0;
 }
