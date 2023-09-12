#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//PRE-CONDITIONS: file needs to be read and stored into the array for function to sort through
int check_and_return_value(int array[], int value){
  for (int i = 0; i < 100; i++){ //searching through array
    if (value == array[i]){
      return i; //returning index if value is found
    }
  }
  return -1; // returning zero if no value is returned (value is not in array)
}
//POST-CONDITIONS: if value is in array, index should be read back to the user, if not, zero is returned with a printed error message.

//PRE-CONDITIONS: array needs to have values stored in it in order to find/change the value that the user wants
void modify_value(int array[], int index, int arrsize){
  cout << "Enter in the index that you would like to change the value at:" << endl;;
  cin >> index; //taking in user provided index
  if (cin.fail()){
    throw runtime_error("Input is not an integer. Please try again.");
  }else if (index > arrsize){
    throw out_of_range("Input is higher than array size. Please try again.");
  }
  cout << endl;
  for (int i = 0; i < 100; i++){
    if (i == index){ //checking if the current i value matches the index
      cout << "Previous Value: " << array[index] << endl; //user is shown old value
      cout << "Enter in new value: " << endl;
      int value;
      cin >> value; //taking in new value from user
      if (cin.fail()){
        throw runtime_error("Input is not an integer. Please try again.");
      }
      array[index] = value; //changing the value in the array
      cout << "New Value at index " << index << ": " << array[index] << endl; //returning the new value to the user
    }
  }
}

//POST-CONDITIONS: array needs to have new value stored into it (value provided from user). No return value.

//PRE-CONDITIONS: Need to have the old array (array[]) and the new array (newarr[]) to take values from array[] and store into newarr[], which will have a bigger size for space to add new elements
void read_into_new_array(int array[], int newarr[], int arrsize){
  for (int i = 0; i < arrsize; i++){
    newarr[i] = array[i];
  } 
}
//POST-CONDITIONS: the new array should have more space to allow for more values 

//PRE-CONDITIONS: array needs to be passed into the function in order to add more values to the end of the array. 
void add_value(int array[], int value, int arrsize, int newarrsize){
  for (int i = 0; i < newarrsize; i++){
    if (i == arrsize){
      array[i] = value; //adding the value onto the end of the array
    }else if (i > arrsize && i < newarrsize){
      array[i] = 0; //filling the rest of the array with 0.
    }
  }
}
//POST-CONDITIONS: array will have a new value added to the end of it, followed by spaces for more values to be entered into. 

//PRE-CONDITIONS: at this point, the new array should be used to pass into the function for the user to replace a certain index value with 0.
void zero_value(int array[], int index, int newarrsize){
  for (int i = 0; i < newarrsize; i++){
    if (i == index){ //the current index should match the user provided index
      cout << "Old value at index " << index << ": " << array[i] << endl;
      array[i] = 0; //setting value at index to 0
      cout << "New value at index " << index << ": " << array[i] << endl;
    }
  }
}
//POST-CONDITIONS: the new array will have an updated value, at the user chosen index, of 0 instead of the original integer.

//PRE-CONDITIONS: array needs to be defined before calling function
void readfile(int array[]){
  string filename = "integers.txt"; //setting a file name to pass into .open()
  ifstream inFile; 
  inFile.open(filename); //opening the file 
  if (!inFile.is_open()){ //verifying that the file opens 
    cout << "File cannot be opened. Please verify file name." << endl;
    return; //returns if file cannot be found
  }
  for (int i = 0; i < 100; i++){ //reading the integers from the file into an array
    inFile >> array[i];
  }
}
//POST-CONDITIONS: after calling the function, the defined array will be filled with integers from the text file to now be used in other functions

//PRE-CONDITIONS: the array passed needs to be defined and have values
void printarr(int array[], int size){
  for (int i = 0; i < size; i++){
    cout << array[i] << " ";
  }
  cout << endl;
  cout << endl;
}
//POST-CONDITONS: the array should appear to the user's screen