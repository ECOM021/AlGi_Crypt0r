#include "../inc/Window.hpp"
#include <iostream>

using namespace std;

Window::Window()
: m_VBox_areas(Gtk::ORIENTATION_VERTICAL),
  m_HBox_command(Gtk::ORIENTATION_HORIZONTAL),
  m_HBox_input(Gtk::ORIENTATION_HORIZONTAL),
  m_HBox_output(Gtk::ORIENTATION_HORIZONTAL),
  m_Button_File  ("Browse"),
  m_Button_Folder("Browse"),
  m_Button_Encrypt("Encrypt"),
  m_Button_Decrypt("Decrypt")
{
  set_title("AlGi_crypt0r");
  set_position(Gtk::WIN_POS_CENTER);
  set_border_width(10);

  add(m_VBox_areas);
  m_VBox_areas.pack_start(m_VBox_info);
  m_VBox_areas.pack_start(m_VBox_key);
  m_VBox_areas.pack_start(m_HBox_input);
  m_VBox_areas.pack_start(m_HBox_output);
  m_VBox_areas.pack_start(m_HBox_command);

  auto infoBarContainer =
    dynamic_cast<Gtk::Container*>(m_InfoBar.get_content_area());
  if (infoBarContainer)
    infoBarContainer->add(m_Message_Label);

  m_InfoBar.add_button("_OK", 0);
  m_VBox_info.pack_start(m_InfoBar, Gtk::PACK_SHRINK);
  m_InfoBar.signal_response().connect(sigc::mem_fun(*this,
              &Window::on_infobar_response) );

  auto keyBarContainer =
    dynamic_cast<Gtk::Container*>(m_KeyBar.get_content_area());
  if (keyBarContainer)
    keyBarContainer->add(m_Key_Label);
  
  m_KeyBar.add_button("_OK", 0);
  m_VBox_key.pack_start(m_KeyBar, Gtk::PACK_SHRINK);
  m_KeyBar.signal_response().connect(sigc::mem_fun(*this,
              &Window::on_keybar_response) );

  m_HBox_input.pack_start(m_input);
  m_input.set_max_length(128);
  m_input.set_text("");
  m_input.set_placeholder_text("Input");
  m_input.select_region(0, m_input.get_text_length());

  m_HBox_input.pack_start(m_Button_File);
  m_Button_File.signal_clicked().connect(sigc::mem_fun(*this,
              &Window::on_button_file_clicked) );
  
  m_HBox_output.pack_start(m_output);
  m_output.set_max_length(128);
  m_output.set_text("");
  m_output.set_placeholder_text("Output");
  m_output.select_region(0, m_output.get_text_length());

  m_HBox_output.pack_start(m_Button_Folder);
  m_Button_Folder.signal_clicked().connect(sigc::mem_fun(*this,
              &Window::on_button_folder_clicked) );

  m_HBox_command.pack_start(m_Button_Encrypt);
  m_Button_Encrypt.signal_clicked().connect(sigc::mem_fun(*this,
              &Window::on_button_encrypt_clicked) );
  
  m_HBox_command.pack_start(m_Button_Decrypt);
  m_Button_Decrypt.signal_clicked().connect(sigc::mem_fun(*this,
              &Window::on_button_decrypt_clicked) );

  show_all_children();
  m_InfoBar.hide();
  m_KeyBar.hide();
}

Window::~Window()
{
}

string Window::getFileName() {
  return m_file;
}

string Window::getFolderName(){
  return m_folder;
}

void Window::on_button_folder_clicked()
{
  Gtk::FileChooserDialog dialog("Please choose a folder",
          Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
  dialog.set_transient_for(*this);

  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("Select", Gtk::RESPONSE_OK);

  int result = dialog.run();

  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      cout << "Select clicked." << endl;
      m_folder = dialog.get_filename();
      cout << "Folder selected: " << m_folder << endl;
      m_output.set_text(m_folder);
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
      cout << "Cancel clicked." << endl;
      break;
    }
    default:
    {
      cout << "Unexpected button clicked." << endl;
      break;
    }
  }
}

void Window::on_button_file_clicked()
{
  Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("_Open", Gtk::RESPONSE_OK);

  auto filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog.add_filter(filter_text);

  auto filter_cpp = Gtk::FileFilter::create();
  filter_cpp->set_name("C/C++ files");
  filter_cpp->add_mime_type("text/x-c");
  filter_cpp->add_mime_type("text/x-c++");
  filter_cpp->add_mime_type("text/x-c-header");
  dialog.add_filter(filter_cpp);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  int result = dialog.run();

  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      cout << "Open clicked." << endl;

      m_file = dialog.get_filename();
      cout << "File selected: " <<  m_file << endl;
      m_input.set_text(m_file);
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
      cout << "Cancel clicked." << endl;
      break;
    }
    default:
    {
      cout << "Unexpected button clicked." << endl;
      break;
    }
  }
}

 ulong_64 gcd( ulong_64 a, ulong_64 b ) {
	  if( !b ) return a;
	  return gcd( b, a%b );
  }

void Window::on_button_encrypt_clicked() {
  cout << "Encrypt: " << m_file << " into folder " << m_folder << endl;

  Encode comp(m_file, m_folder);
  Encrypt enc(comp.getOutput(), m_folder);
  Encode agin(enc.getOutput(), m_folder);
  std::remove(enc.getOutput().c_str());

  m_Message_Label.set_text("Encrypt ended");
  m_InfoBar.set_message_type(Gtk::MESSAGE_INFO);
  m_InfoBar.show();

  m_Key_Label.set_text("Keys: \nP: " + to_string(enc.getKeyP()) +
                             "\nQ: " + to_string(enc.getKeyQ()) +
                             "\nE: " + to_string(enc.getKeyE()) +
                             "\nD: " + to_string(enc.getKeyD()));

  m_p = enc.getKeyP();
  m_q = enc.getKeyQ();
  m_d = enc.getKeyD();

  m_KeyBar.set_message_type(Gtk::MESSAGE_INFO);
  m_KeyBar.show();
}

void Window::on_button_decrypt_clicked() {
  cout << "Decrypt: " << m_file << " into folder " << m_folder << endl;

  Decode  decomp(m_file, m_folder);
  Decrypt decrypt(decomp.getOutput(), m_folder, m_p, m_q, m_d);
  Decode  decom(decrypt.getOutput(), m_folder);
  std::remove(decrypt.getOutput().c_str());
  m_Message_Label.set_text("Decrypt Ended");
  m_InfoBar.set_message_type(Gtk::MESSAGE_INFO);
  m_InfoBar.show();
}

void Window::on_infobar_response(int response) {
  m_Message_Label.set_text("");
  m_InfoBar.hide();
}

void Window::on_keybar_response(int response) {
  m_Key_Label.set_text("");
  m_KeyBar.hide();
}