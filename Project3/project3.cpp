/**
 *Author: Houston Walley
 *File name: project3.cpp
 *Used Dr. Li's source code.
 *Compile using g++
 */

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/* Checks to see if the file exists. */
bool check_file(string);

/* Reads in the file. */
vector<int> read_file(string);

/* Writes a file and saves it. */
void write_file(string, vector<int>);

/* Sorts the two vectors into one vector. */
vector<int> merge(vector<int>, vector<int>);

/*Display the values of a given vector
 *
 *Param: file Name of the file to display. (string)
 *Param: v Vector containing values to display. (vector<int>)
 */
void to_string(string, vector<int>);

/* */
int main() {
   
   //variables
   string file1;//first input
   string file2;//second input
   string file3;//output file
   vector<int> file_vec1;//vector from first file
   vector<int> file_vec2;//vector from second file
   vector<int> out_vec;//sorted vector
   
   //Header
   cout << "*** Welcome to Houston's sorting program ***" << endl;
   
   //Gets the name of the first file
   cout << "Enter the first input file name: ";
   cin >> file1;
   while (cin.fail() || !check_file(file1)) {
      cout << "Enter the first input file name: ";
      cin >> file1;
   }
   
   //Gets and displays the numbers from file 1
   file_vec1 = read_file(file1);
   to_string(file1, file_vec1);
   cout << endl;
   
   //Gets the name of the second file
   cout << "Enter the second input file name: ";
   cin >> file2;
   while (cin.fail() || !check_file(file2)) {
      cout << "Enter the second input file name: ";
      cin >> file2;
   }
   
   //Gets and displays the numbers from file 2
   file_vec2 = read_file(file2);
   to_string(file2, file_vec2);
   cout << endl;
   
   //Combines vectors and displays the sorted result
   out_vec = merge(file_vec1, file_vec2);
   cout << "The sorted list of " << out_vec.size() << " is:";
   for (int i = 0; i < out_vec.size(); i++) {
      cout << ' ' << out_vec[i];
   }
   cout << endl;
   
   //Gets name of the output file
   cout << "Enter the output file name: ";
   cin >> file3;
   
   //Writes combined vector to the output file
   write_file(file3, out_vec);
   cout << "*** Please check the new file - " << file3 << " ***" << endl;
   cout << "*** Goodbye. ***" << endl;
   
   return 0;
}


//done
bool check_file(string file) {

   //Input file stream. (ifstream)
   ifstream stream;
   
   //Checks whether file exists
   stream.open(file.c_str());
   if (stream.fail()) {
      return false;
   }
   stream.close();
   
   return true;
}

//done
vector<int> read_file(string file) {
   //Input file stream. (ifstream)
   ifstream stream;
   
   //Vector containing numbers from fiile. (vector<int>)
   vector<int> v;
   
   //Integer read from file. (int)
   int i;
   
   //Adds each number in the file to a vector
   stream.open(file.c_str());
   stream >> i;
   while (stream.good()) {
      v.push_back(i);
      stream >> i;
   }
   stream.close();
   return v;
}

//done
void write_file(string file, vector<int> v) {
   //Output file stream. (ofstream)
   ofstream outFile(file.c_str(), ios::out);
   for (int i = 0; i < v.size(); i++) {
      outFile << v[i] << endl;
   }
   outFile.close();
}

//done
vector<int> merge(vector<int> v1, vector<int> v2) {
   
   //Variables
   int front1 = 0;
   int front2 = 0;
   vector<int> merged;
   
   //Compare both vectors
   while(!(v1.size() == front1) && !(v2.size() == front2)) {
      if (v1[front1] > v2[front2]) {
         merged.push_back(v2[front2]);
         front2++;
      }
      else {
         merged.push_back(v1[front1]);
         front1++;
      }
   }
   
   //Adds what is left in v1
   while (!(v1.size() == front1)) {
      merged.push_back(v1[front1]);
         front1++;
   }
   
   //Adds what is left in v2
   while (!(v2.size() == front2)) {
      merged.push_back(v2[front2]);
         front2++;
   }
   
   return merged;
}


void to_string(string file, vector<int> v) {

   //Vector iterator number. (unsigned short)
   unsigned short i;
   
   //Display the numbers contained in a vector
   cout << "The list of " << v.size() << " numbers in file "
      << file << " is:" << endl;
   for (i = 0; i < v.size(); i++) {
      cout << v[i] << endl;
   }
}
