#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Directory
{
private:
  string dir_name; // name of the directory
  int num_files;   // actual number of files in the directory
  int capacity;    // maximum possible number of files in the directory
  File *file_arr;  // a dynamically sized array of files
public:
  // Takes in a vector of files and constructs a directory of those
  // files
  // REQUIRES: The vector size is <= 100.
  Directory(const string &dir_name_in, const vector<File> &files_in);
  //*You will implement this in part (2a)*
  // EFFECTS: Performs clean-up of memory of the Directory object
  ~Directory();
  //*You will implement this function in part (2d)*
  // EFFECTS: Performs a deep copy from other into this Directory
  Directory &operator=(const Directory &other);
  //*This function is implemented in part (2c)*
  // EFFECTS: Resizes the directory so the array of files is at minimal
  // possible size to hold all data
  // The new capacity of the directory is equal to the
  // number of files in the directory
  // Appends “_compressed” to the directory name
  void shrink()
  {
    //*This function is implemented in part (2b)*
  }
};

class File
{
private:
  string file_name;

public:
  File(string name_in) : file_name(name_in) {}
  File() {}
};


Directory::Directory(const string &dir_name_in, const vector<File> &files_in):
  dir_name(dir_name_in), capacity(100), num_files(files_in.size()) {
  file_arr = new File[capacity]; // create dynamic array on heap with capacity = 100
  for (size_t i = 0; i < num_files; i++) {
    file_arr[i] = files_in[i];
  }
}

Directory::~Directory() {
  delete[] file_arr;
}