//Simple Heap program that takes in input from a file or by console
//Then can print the tree and output


#include <iostream>
#include <fstream>
#include "Heap.h"

using namespace std;

void toLower(char* a){ //converts words to lower case
  while(*a){
    *a = tolower(*a);
    a++;
  }
}
void configureInput(ifstream &stream, bool &isFile){ 
  //Asks whether to take in input from text or from file
  //outputs through ifstream parameter

  char input[128];
  isFile = false;

  cout << "Read from File or Input text?" << endl;
  cin.getline(input,128);
  toLower(input);

  if(input[0] == 'f'){
    cout << "What file?" << endl;
    cin.getline(input,128);
    stream.open(input);
    if(stream.is_open()){
      isFile = true;
    }
    else{
      cout << "Could not open file" << endl;
      cout << "Enter by command line" << endl;
    }
  }
  else{
    cout << "Enter by command line" << endl;
  }
}
void addNumbers(istream &from, Heap* heap){
  //goes through a stream and adds them to the heap
  int newInput;
  from >> newInput;
  heap->add(newInput);
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){
      from >> newInput;
      heap->add(newInput);
     }
    else{
      from.ignore();
    }
  }
}


int main(){
  //main program loop
  Heap heap;
  char input[128];
  bool running = true;


  while(running){
   
    cin.getline(input, 128);
    toLower(input);
    
    if(input[0] == 'a') {
      ifstream stream;
      bool isFile;
      configureInput(stream, isFile);
      addNumbers(isFile ? stream : cin, &heap);      
      if(isFile) stream.close();
      cin.ignore();
      
    }
    else if(input[0] == 'o'){
      while(heap.getCount() > 0){
        cout << heap.pop() << " ";
       }
      cout << endl;
    } 
    else if(input[0] == 't'){
      heap.print();
    } 
    else if(input[0] == 'q'){
      running = false;
    }
    else{
      cout << "I don't understand" << endl;
      cout << "The possible commands are:\nAdd\nOutput\nTree\nQuit" << endl;
    }
  }
}