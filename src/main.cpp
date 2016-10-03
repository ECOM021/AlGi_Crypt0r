#include "../utils/Debug.hpp"
using namespace std;

int main() {
        Encode *ptr = new Encode("/home/gio/workspace/AlGi_Crypt0r/test/test");

        TEST
                Debug::printOccur(ptr->getOccur());
                Debug::printCodes(ptr->getCodes());
                Debug::printRepresentation(ptr->getRepresentation());
        END
        
        return 0;
}
