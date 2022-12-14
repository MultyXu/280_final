#include <vector>

using namespace std;

class IntRange {
public:
  IntRange(int start_in, int stop_in);
  class Iterator {
    public:
    Iterator() {

    }
  };
  Iterator begin() const;
  Iterator end() const;
};

//​ ​REQUIRES:​ ​'begin'​ ​and​ ​'end'​ ​are​ ​valid​ ​iterators
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​'begin'​ ​is​ ​before​ ​or​ ​equal​ ​to​ ​'end'
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​IterType​ ​fulfills​ ​the​ ​standard​ ​iterator​ ​interface
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​Predicate​ ​fulfills​ ​the​ ​standard​ ​predicate​ ​interface
//​ ​MODIFIES:​ ​the​ ​input​ ​vector​ ​'dest'
//​ ​EFFECTS:​ ​​ ​For​ ​each​ ​item​ ​from​ ​'begin'​ ​to​ ​'end',
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​appends​ ​that​ ​item​ ​to​ ​the​ ​given​ ​vector​ ​'dest'
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​if​ ​Predicate​ ​'pred'​ ​returns​ ​true​ ​for​ ​that​ ​item
//​ ​EXAMPLE:​ ​​ ​begin​ ​and​ ​end​ ​define​ ​a​ ​sequence​ ​containing​ ​{1,​ ​8,​ ​3,​ ​4} 
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​and​ ​pred​ ​=​ ​IsEven,​ ​where​ ​IsEven(x)​ ​is​ ​true​ ​if​ ​x​ ​is​ ​even 
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​Appends​ ​the​ ​items​ ​8​ ​and​ ​4​ ​to​ ​an​ ​input​ ​vector<int>​ ​'dest' 

template <typename IterType, typename Predicate, typename T>
void filtered_copy(IterType begin, IterType end, Predicate pred, vector<T> &dest) {
  for (IterType it = begin; it != end; ++it) {
    if (pred(*it)) {
      dest.push_back(*it);
    }
  }
}

//​ ​REQUIRES:​ ​num​ ​>​ ​0,​ ​base​ ​>​ ​0
//​ ​EFFECTS:​ ​Returns​ ​true​ ​if​ ​'num'​ ​is​ ​a​ ​power​ ​of​ ​'base' 
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​(num​ ​=​ ​base^exp​ ​for​ ​some​ ​integer​ ​exp​ ​>​ ​0) 
//​ ​EXAMPLE:​ ​is_power_of(16,​ ​4)​ ​is​ ​true,
//​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​is_power_of(9,​ ​2)​ ​is​ ​false
bool is_power_of(int num, int base);

class IsPowerOfBase {
public: 
  IsPowerOfBase(int base_in): base(base_in) {

  }

  bool operator()(int n) {
    return is_power_of(n, base);
  }

private:
  int base;
};

int main(){
  vector<int> powers_of_three;
  IsPowerOfBase power_of_three(3);
  IntRange range(1, 1000);

  filtered_copy(range.begin(), range.end(), power_of_three, powers_of_three);
}
