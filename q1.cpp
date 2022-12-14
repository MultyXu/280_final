#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Store {
public:
  static const int MAX_RECORDS = 500;

private:
  struct ItemRecord {
    string name;
    T item;
    int times_bought;
  };

  // An array with the capacity to store up to MAX_RECORDS items.
  // INVARIANT: All ItemRecords in the array have different names.
  ItemRecord catalog[MAX_RECORDS];

  // The number of items currently in the array
  // INVARIANT: 0 <= num_item_records <= MAX_RECORDS
  int num_item_records;

  // index_mp - short for "index most popular"
  // INVARIANT: The item at index_mp has been bought >= the
  // number of times any other item has been bought. If the
  // Store does not contain ANY items, index_mp is -1.
  int index_mp;

public:
  Store() : num_item_records(0), index_mp(-1) {}

  // REQUIRES: there is at least one item in the Store
  // EFFECTS:  returns the item that has been bought the
  // most times (or if there are multiple items that are
  // "tied", any one of those most popular items)
  const T & most_popular() const;

  // MODIFIES: this Store
  // EFFECTS: Attempts to buy an item from the Store. If an
  // item with the given name is found, increases its times
  // bought counter by 1, also making sure to maintain the
  // "most popular" invariant. If no item with the given
  // name is found, this function does nothing.
  void buy(const string &name) {
    for (int i = 0; i < num_item_records; i++) {
      if (catalog[i].name == name) {
        // found the item with same name
        catalog[i].times_bought++; 
        if (catalog[i].times_bought > catalog[index_mp].times_bought) {
          // after increase, the times bought is greater than max
          index_mp = i;
        }
      }
    }
  }

  // MODIFIES: this Store
  // EFFECTS: Adds an item T, with the given name to the Store,
  // unless an entry with the same name already exists, in which
  // case nothing happens.
  void add_item_to_catalog(const string &name, const T &item);

  Store &operator+=(Store &other_store) {
    for (int i = 0; i < other_store.num_item_records; ++i) {
      const ItemRecord &other_item = other_store.catalog[i];
      this->add_item_to_catalog(other_item.name, other_item.item);
    }
    return *this;
  }
};



int main() {
  bool thing = (string)"a" < (string)"b";
  cout << thing << endl;
}