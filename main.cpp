#include "./libhuffman/inc/Decode.hpp"
#include "./libhuffman/inc/Encode.hpp"
#include "./librsa/inc/Decrypt.hpp"
#include "./librsa/inc/Encrypt.hpp"
#include "./View/inc/Window.hpp"
using namespace std;

int main(int argc, char *argv[]) {
        auto app = Gtk::Application::create(argc, argv, "AlGi_Crypt0r");
        Window window;
        return app->run(window);
}
