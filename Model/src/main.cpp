#include "../../View/inc/Window.hpp"

int main(int argc, char *argv[]) {
        auto app = Gtk::Application::create(argc, argv);
        Window window;
        return app->run(window);
}
