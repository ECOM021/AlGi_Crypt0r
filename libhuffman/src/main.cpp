#include "../utils/Debug.hpp"
using namespace std;

int main() {
        TEST

                //Encode *ptr = new Encode("./test/What's Up - Sense8.mp4");

                //Debug::printOccur(ptr->getOccur());
                //Debug::printCodes(ptr->getCodes());
                //Debug::printRepresentation(ptr->getRepresentation());

                Decode *ptd = new Decode("./test/What's Up - Sense8.mp4.huff");
                //
                //Debug::printRepresentation(ptd->getRepresentation());

                //delete ptr;
                delete ptd;
        END
        return 0;
}
