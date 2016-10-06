#include "../utils/Debug.hpp"
using namespace std;

int main() {
        Encode *ptr = new Encode("./test/rfc1157.txt");

        TEST
                Debug::printOccur(ptr->getOccur());
                Debug::printCodes(ptr->getCodes());
                Debug::printRepresentation(ptr->getRepresentation());
        END

        //Decode *ptd = new Decode("./test/What's Up - Sense8.mp4.huff");

        return 0;
}
