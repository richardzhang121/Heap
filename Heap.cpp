#include "Heap.h"
#include <iostream>


using namespace std;

int leftChild(int i){ //returns the leftChild
  return 2*i+1;
}
int rightChild(int i){ //returns the rightChild
  return 2*i+2;
}
int parent(int i){//returns the parent
  return (i-1)/2;
}
void Heap::bubbleDown(int i){ //puts a number in its place by moving it down
  int swapIndex = -1;
  if (leftChild(i) <= count-1 &&
      rightChild(i) <= count-1){

    swapIndex = (data[rightChild(i)] > data[leftChild(i)]) ? rightChild(i) : leftChild(i);
  }
  else if(leftChild(i) <= count-1){
    swapIndex = leftChild(i);
  }
  if(data[swapIndex] > data[i] && i != -1){
    int temp = data[i];
    data[i] = data[swapIndex];
    data[swapIndex] = temp;
    bubbleDown(swapIndex);
  }
}
void Heap::bubbleUp(int i){ //puts a number in its place by moving it up
  if(i != 0){
    if(data[i] > data[parent(i)]){
      int temp = data[i];
      data[i] = data[parent(i)];
      data[parent(i)] = temp;
      bubbleUp(parent(i));
    }
  }
}
Heap::Heap(){
  size = 128;
  count = 0;
  data = new int[size];

}
Heap::~Heap(){
  delete data;
}
void Heap::print(int i, int indent){

  if (i < count){
    print(leftChild(i),indent+1);
    for(int j = 0; j <= indent; j++){
      cout << "   ";
    }
    cout << data[i] << endl;
    print(rightChild(i),indent+1);
  }
}
  void Heap::add(int newInt){

  data[count] = newInt;
  bubbleUp(count);
  count++;
}
int Heap::pop(){ //pops off the largest nu mber and resorts
  int toReturn = data[0];
  data[0] = data[count-1];
  bubbleDown(0);
  count--;
  return toReturn;
}
int Heap::getCount(){
  return count;
}