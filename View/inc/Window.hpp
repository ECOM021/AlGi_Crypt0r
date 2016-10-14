#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../../libhuffman/inc/Decode.hpp"
#include "../../libhuffman/inc/Encode.hpp"
#include "../../librsa/inc/Decrypt.hpp"
#include "../../librsa/inc/Encrypt.hpp"

#include <gtkmm.h>
#include <string>

using namespace std;

class Window : public Gtk::Window
{
public:
  Window();
  virtual ~Window();

  string getFileName();
  string getFolderName();
protected:
  //Signal handlers:
  void on_button_file_clicked();
  void on_button_folder_clicked();

  //Child widgets:
  Gtk::ButtonBox m_ButtonBox;
  Gtk::Button m_Button_File, m_Button_Folder;
private:
  string m_file;
  string m_folder;
};

#endif //WINDOW_HPP