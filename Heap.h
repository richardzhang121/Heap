class Heap{
 private:
  int* data;
  int size;
  int count;
  void bubbleDown(int i);
  void bubbleUp(int i);
 public:
  Heap();
  ~Heap();
  void print(int i=0, int indent=0);
  void add(int newInt);
  int pop(); // returns the largest value
  int getCount(); //returns how many ints are in the array
};