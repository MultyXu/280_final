// You may assume type T supports ==, !=, <, <=, >, and >=
template <typename T>
class MinQueue { 
public:
  MinQueue() : size(0) { } // default ctor

  // REQUIRES: the MinQueue is not empty
  // EFFECTS: Returns the minimum item, but
  // does not remove it from the MinQueue
  const T & min() const;

  // REQUIRES: the MinQueue is not empty
  // EFFECTS: Removes the minimum item from the MinQueue
  void popMin();

  // REQUIRES: the MinQueue is not full
  // EFFECTS: Adds 'item' to the MinQueue
  // 6 5 4 2 1
  void push(const T &item) {
    for (int i = 0; i < size; i++) {
      if (item > data[i]) {
        size++;
        for (int j = size; j > i; j--) {
          data[j] = data[j - 1];
        }
        data[i] = item;
        break;
      }
    }
  }

private:
  // For simplicity, we assume a fixed capacity
  // and that the user of a MinQueue never exceeds
  // this. This isn't a dynamic memory question :).
  int data[10];

  // number of valid items in the data array
  int size;
};

template <typename T>
MinQueue<T> &operator+=(MinQueue<T> &q, int &n) {
  q.push(n);
  return q;
}
