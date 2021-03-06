
#ifndef FSTREAM_NAMD_H
#define FSTREAM_NAMD_H

#include <iostream>
#include <sstream>

class ofstream_namd : public std::ostringstream {

private:
  int fd;
  std::string fname;

public:

  ofstream_namd() : fd(0) { ; }

  explicit ofstream_namd(const char *_fname) : fd(0) {
    open(_fname);
  }

  void open(const char *_fname);

  bool is_open() const { return ! ! fd; }

  ofstream_namd& flush();

  void close();

  ~ofstream_namd() {
    if ( fd ) close();
  }

  bool good() const { return true; }
  bool fail() const { return false; }
  bool bad() const { return false; }
  bool operator!() const { return false; }
  operator bool() const { return true; }
  void clear() { ; }

};

#endif  // FSTREAM_NAMD_H

