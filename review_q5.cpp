#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T> // Note: T must support ==
class Replacer {
private:
  const T target;
  const T replacement;

public:
  Replacer(T target_in, T replacement_in): target(target_in), replacement(replacement_in) {

  }

  T operator()(T data) const {
    if (data == target) {
      return replacement
    } else {
      return data;
    }
  }
};


// REQUIRES: the sequence specified by 'out' has room for the results
template <typename InIter, typename Functor, typename OutIter>
void map(InIter begin, InIter end, Functor fn, OutIter out) {
  while (begin != end) {
    *out = fn(*begin);
    ++begin;
    ++out;
  }
}

// EFFECTS: Replaces all instances of the word 'target' in the 'words'
//          vector with the string 'replacement'.
void replaceAll(vector<string> &words, const string &target, const string &replacement) {
  Replacer rep = Replacer(target, replacement);
  map(words.begin(), words.end(), rep, words.begin());
}