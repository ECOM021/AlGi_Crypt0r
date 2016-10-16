#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../../Model/libs/libhuffman/inc/Decode.hpp"
#include "../../Model/libs/libhuffman/inc/Encode.hpp"
#include "../../Model/libs/librsa/inc/Decrypt.hpp"
#include "../../Model/libs/librsa/inc/Encrypt.hpp"

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
  void on_button_encrypt_clicked();
  void on_button_decrypt_clicked();
  void on_infobar_response(int response);

  //Child widgets:
  Gtk::InfoBar m_InfoBar;
  Gtk::Label m_Message_Label;

  Gtk::Box m_VBox_areas, m_VBox_info;
  Gtk::Box m_HBox_input, m_HBox_output, m_HBox_command;
  
  Gtk::Entry m_input, m_output;
  Gtk::Button m_Button_File, m_Button_Folder;
  
  Gtk::Button m_Button_Encrypt, m_Button_Decrypt;
private:
  string m_file;
  string m_folder;
};

#endif //WINDOW_HPP