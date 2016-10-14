#include "../inc/Window.hpp"
#include <iostream>

using namespace std;

Window::Window()
: m_ButtonBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_File("Choose File"),
  m_Button_Folder("Choose Folder")
{
  set_title("Gtk::FileSelection example");

  add(m_ButtonBox);

  m_ButtonBox.pack_start(m_Button_File);
  m_Button_File.signal_clicked().connect(sigc::mem_fun(*this,
              &Window::on_button_file_clicked) );

  m_ButtonBox.pack_start(m_Button_Folder);
  m_Button_Folder.signal_clicked().connect(sigc::mem_fun(*this,
              &Window::on_button_folder_clicked) );

  show_all_children();
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

  //Add response buttons the the dialog:
  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("Select", Gtk::RESPONSE_OK);

  int result = dialog.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      cout << "Select clicked." << endl;
      m_folder = dialog.get_filename();
      cout << "Folder selected: " << m_folder << endl;
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

  //Add response buttons the the dialog:
  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("_Open", Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:

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

  //Show the dialog and wait for a user response:
  int result = dialog.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      cout << "Open clicked." << endl;

      //Notice that this is a string, not a Glib::ustring.
      m_file = dialog.get_filename();
      cout << "File selected: " <<  m_file << endl;
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