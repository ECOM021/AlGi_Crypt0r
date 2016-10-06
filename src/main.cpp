#include "../utils/Debug.hpp"
using namespace std;

int main() {
        TEST
                Encode *ptr = new Encode("./test/test");

                Debug::printOccur(ptr->getOccur());
                Debug::printCodes(ptr->getCodes());
                Debug::printRepresentation(ptr->getRepresentation());

                Decode *ptd = new Decode("./test/test.huff");

                Debug::printRepresentation(ptd->getRepresentation());

                delete ptr;
                delete ptd;
        END
        return 0;
}
