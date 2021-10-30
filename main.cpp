/** @file main.cpp Client application for LinkedQueue 
    @author Emily Louk 
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "LinkedQueue.h" // ADT Queue operations
const string INPUT_FILE = "officers.txt";
using namespace std;

void countOff(LinkedQueue<string> officers, int count){
   string officerName;
   int posCount = 1; //keeps track of how many officers are counted
   
   cout << "The officers leaving the queue are: " << endl;
   while(!officers.isEmpty()){

      officerName = officers.peekFront();
      officers.dequeue();

      //if 'count' number of officers have been counted and queue is not empty,
      //display that the officer is leaving the queue
      if(posCount == count){
         if(!officers.isEmpty()){
            cout << officerName << endl;
            posCount = 0;
         }
      }
      else
         officers.enqueue(officerName);
      
      posCount++;
   }
   
   cout << " " << endl;
   cout << "The officer going for help is: " << endl;
   cout << officerName << endl;
}


//reads officers from file and adds them to linked queue
void readFile(LinkedQueue<string> &officers)
{
   ifstream inFile(INPUT_FILE); // declare and open the input file
   string officerName; // name of officer input from file

   getline(inFile, officerName); //prime read

   //add each name to the queue
   while (!inFile.eof())
   {
      officers.enqueue(officerName);
      getline (inFile, officerName);
   }
   inFile.close();  
}


int main()
{
   ifstream inFile(INPUT_FILE); 
   int count; 
   LinkedQueue<string> officers; 
   string front; 
   string first; 
   
   readFile(officers); //fill queue with list of original officers from file

   //Display queue filled by readFile
   cout << "Officers in original queue: " << endl;
   first = officers.peekFront();
   cout << first << endl;
   officers.dequeue();
   officers.enqueue(first);
   front = officers.peekFront();

   while (first != front)
   {
      cout << front << endl;
      officers.dequeue();
      officers.enqueue(front);
      front = officers.peekFront();
   }
   
   // Testing for countOff() method
   count = 5;
   cout << endl << endl<< "Count is: " << count << endl;
   countOff (officers, count);
   count = 8;
   cout << endl << endl << "Count is: " << count << endl;
   countOff (officers, count);
   
   return 0;
}  // end main

