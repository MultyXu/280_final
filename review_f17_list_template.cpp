

template <typename T>
class List
{
public:
  List() : first(nullptr), last(nullptr) {}

  // ​ ​MODIFIES:​ ​*this
  // ​ ​EFFECTS:​ ​If​ ​'item'​ ​is​ ​in​ ​the​ ​list,​ ​removes​ ​the​ ​first​ ​appearance​ ​of 
  //​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​'item'​ ​and​ ​all​ ​elements​ ​that​ ​follow​ ​from​ ​the​ ​list.
  // ​ ​EXAMPLE:​ ​If​ ​'list'​ ​contains​ ​[2,​ ​3,​ ​1,​ ​4,​ ​1],​ ​then​ ​list.truncate(1) 
  //​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​modifies​ ​'list'​ ​to​ ​contain​ ​[2,​ ​3].
  // ​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​If​ ​'list'​ ​contains​ ​[2,​ ​3,​ ​1,​ ​4,​ ​1],​ ​then​ ​list truncate(5) 
  //​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​does​ ​not​ ​change​ ​'list'.
  void truncate(const T &item) {
    Node *victim = find(item);
    // missing part 
    if (victim != nullptr) {
      last = victim->prev;
      if (last == nullptr) {
        // meaning that victim is the only elements in the list
        first = nullptr;
      } else {
        last->next = nullptr;
      }
    }
    // end missing part
    while (victim != nullptr) {
      Node *temp = victim; 
      victim = victim->next; 
      delete temp;
    }
  }

private:
  struct Node
  {
    T datum;
    Node *next;
    Node *prev;
  };

  Node *first;
  Node *last;

  // ​ ​EFFECTS:​ ​Returns​ ​a​ ​pointer​ ​to​ ​the​ ​first​ ​node​ ​that​ ​contains​ ​'item',
  // ​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​or​ ​nullptr​ ​if​ ​'item'​ ​is​ ​not​ ​in​ ​the​ ​list.
  Node *find(const T &item)
  {
    Node *ptr = first;
    while (ptr != nullptr)
    {
      if (ptr->datum == item)
      {
        return ptr;
      }
      ptr = ptr->next;
    }
    return nullptr;
  }
};
