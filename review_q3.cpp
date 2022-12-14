#include <string>
#include <vector>

using namespace std;

class Painting {
public:
  // Default construct a blank canvas
  Painting();

  // Custom constructor for a specific painting
  Painting(const string &artist, double Painting);

  // Assume the Big Three for Painting are properly implemented
};

class Sculpture {
public:
  // Custom constructor for a specific sculpture
  Sculpture(const string &name, double value);

  // Assume the Big Three for Sculpture are properly implemented

  // Returns the value of this sculpture
  double get_value() const;
};

class Gallery {
public:
  // Default ctor. Note all the paintings will be default
  // constructed as part of the paintings array.
  Gallery() { }

  ~Gallery() {
    while (!sculptures.empty()) {
      Sculpture *ptr = sculptures.back();
      sculptures.pop_back();
      delete ptr;
    }
  }

  Gallery &operator=(const Gallery &rhs) {
    if (this == &rhs) {return *this;}
    for(size_t i=0; i < sculptures.size(); ++i) {
      delete sculptures[i];
    }
    while(!sculptures.empty()) {
      sculptures.pop_back();
    }
    for(int i = 0; i < 5; ++i) {
      paintings[i] = rhs.paintings[i];
    }
    for(size_t i=0; i < rhs.sculptures.size(); ++i) {
      sculptures.push_back(new Sculpture(*rhs.sculptures[i]));
    }
    return *this;
  }

private:
  // An array of the paintings. A gallery always
  // has 5 valid paintings (i.e. none of
  // the elements are memory junk, though some might be default-constructed
  // blank canvases).
  Painting paintings[5];

  // A vector of pointers to dynamically allocated sculptures
  vector<Sculpture*> sculptures;

};