#include "../utils/Debug.hpp"
using namespace std;

int main() {
        TEST

                Encode *ptr = new Encode("./test/rfc1157.txt");

                Debug::printOccur(ptr->getOccur());
                Debug::printCodes(ptr->getCodes());
                Debug::printRepresentation(ptr->getRepresentation());

                // Decode *ptd = new Decode("./test/rfc1157.txt.huff");
                //
                // Debug::printRepresentation(ptd->getRepresentation());

                delete ptr;
                //delete ptd;
        END
        return 0;
}
