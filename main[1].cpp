#include <iostream>
#include <fstream>
#include <string>
#include "function.h"
using namespace std;

int main() {
  const int arrsize = 100;
  int array[arrsize]; //setting the array for the numbers in .txt file
  
  //read file to fill array
  readfile(array);
  cout << endl;
  cout << "STARTING ARRAY: " << endl;
  printarr(array, arrsize);

  //searching array for a value
  int value; 
  cout << "---SEARCHING FOR A VALUE--- " << endl << "Enter a number:" << endl; //getting value from user to find in array
  cin >> value;
  int index = check_and_return_value(array, value); //search the array for the index, 
  if (index == -1){ //the value does not exist
    cout << "Value " << value << " not found in array." << endl;
  }else { //the value exists
    cout << "Value " << value << " found at index: " << index << endl;
  }
  cout << endl;
  
  //modifying value in array
  cout << "---CHANGING A VALUE OF AN INDEX IN AN ARRAY---" << endl;
  index = 0; //resetting index
  try{
    modify_value(array, index, arrsize);
  }catch(runtime_error excpt){
    cout << excpt.what() << endl;
    return -1;
  }catch(out_of_range expt){
    cout << expt.what() << endl;
    return -1;
  }catch(...){
    cout << "Program ran into an error in modify_value function." << endl;
    return -1;
  }
  cout << endl;
  cout << "CURRENT ARRAY: " << endl;
  printarr(array, arrsize);

  //making a new array to add more values
  cout << "---MAKING THE NEW ARRAY TO ADD MORE VALUES--- " << endl << "Please enter an array size, must be greater than 100." << endl;
  int newarrsize;
  cin >> newarrsize;
  
  int newarray[newarrsize]; //defining array with predefined size
  read_into_new_array(array, newarray, arrsize); //making the new array with values from the old array
  cout << endl;

  //adding more values to the new array
  int userval;
  cout << "---ADDING A VALUE TO THE END OF THE ARRAY---" << endl;
  cout << "Please enter a numerical value:" << endl; 
  try{
    cin >> userval;//taking in user input for the new value
    if (cin.fail()){
      throw runtime_error("Input is not an integer.");
    }
    cout << endl;
    add_value(newarray, userval, arrsize, newarrsize); //adding the value to the end of the array
    cout << endl;
    cout << "CURRENT ARRAY: " << endl;
    printarr(newarray, newarrsize);
  }catch(runtime_error excpt){
    cout << excpt.what() << endl;
    return -1;
  }catch(...){
    cout << "Program ran into an error.";
    return -1;
  }

  //setting a value at user defined index to the value 0
  index = 0; //resetting the index to prepare for user input
  cout << "---CHANGING A VALUE AT AN INDEX TO 0 (REMOVING THE VALUE)---" << endl;
  cout << "Please enter in an index: " << endl;
  cin >> index; //taking in index from user
  cout << endl;
  zero_value(newarray, index, newarrsize); //calling function to change the value at user provided index to 0
  cout << endl;
  cout << "FINAL ARRAY: " << endl;
  printarr(newarray, newarrsize);

  cout << endl;
  cout << "END OF PROGRAM.";
}