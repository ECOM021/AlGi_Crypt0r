#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../../Model/libs/libhuffman/inc/Decode.hpp"
#include "../../Model/libs/libhuffman/inc/Encode.hpp"
#include "../../Model/libs/librsa/inc/Decrypt.hpp"
#include "../../Model/libs/librsa/inc/Encrypt.hpp"

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

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
  void on_button_okay_clicked();
  void on_infobar_response(int response);
  void on_keybar_response(int response);


  //Child widgets:
  Gtk::InfoBar m_InfoBar;
  Gtk::Label m_Message_Label;

  Gtk::InfoBar m_KeyBar;
  Gtk::Label m_Key_Label;

  Gtk::Box m_VBox_areas, m_VBox_info, m_VBox_key;
  Gtk::Box m_HBox_input, m_HBox_output, m_HBox_command;
  
  Gtk::Entry m_input, m_output;
  Gtk::Button m_Button_File, m_Button_Folder;
  
  Gtk::Button m_Button_Encrypt, m_Button_Decrypt;

  Gtk::Box m_VBox_inputKey;
  Gtk::Entry m_keyP, m_keyQ, m_keyD;
  Gtk::Button m_Button_okay;

private:
  string m_file;
  string m_folder;
  ulong_64 m_p, m_q, m_d;
};

#endif //WINDOW_HPP