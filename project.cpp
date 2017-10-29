#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std; 


struct student {
    string firstName; 
    string lastName; 
    int numAttempts;
    float average;
};


// Function that takes the array of students and prints out all the values in a user-friendly way: 
// Example output: "Utsab Saha has made 0 attempts and has an average of 0"; 
void printStudents(student allStudents[], int numStudents) {
    
    cout << "Iterate over all the students.  Print out a user-friendly message for each attribute of the student." << endl; 
    for (int i = 0; i < numStudents; i++) {
        cout << allStudents[i].firstName << " " << allStudents[i].lastName
             << " has made " << allStudents[i].numAttempts << " attempts and has an average of "
             << allStudents[i].average << endl; 
    }
}

// This function prints all of our student data back into a file. 
void writeStudentsToFile(student allStudents[], int numStudents) {
    ofstream writeStudentDataFile ("studentData.txt", ios::out | ios::trunc); // clear contents

    for (int i = 0; i < numStudents; i++) {
        writeStudentDataFile << allStudents[i].firstName << " " << allStudents[i].lastName << " " 
                             << allStudents[i].numAttempts << " " << allStudents[i].average << endl; 
    }
    
    writeStudentDataFile.close();
}

// return list[rand()%n];
// Picks one student randomly from the student array
student pickRandomStudent(student list[], int n) {
    student picked; // Declare a local variable for the picked student
    int r1; // declare a variable for the random index I am going to use to pick the student
    
    
    r1 = rand()%n; // Pick r1 randomly between 0 and n-1
    picked = list[r1]; // accessing the random entry from the array in the picked variable
    return picked; // return the picked variable
}



int main() {
    
    int numStudents = 27; 
    student allStudents[numStudents], rStudent;
    
    cout << "Declare a input file stream which we will use to read in the student data" << endl; 
    ifstream myReadFile;
    
    cout << "Open the file.  Student data is stored in studentData.txt" << endl; 
    myReadFile.open("studentData.txt");
    
    srand(time(NULL));

    cout << "Every time we read something in from the file, we'll store it inside of this variable" << endl;  
    string input;
    
     cout << "Check if the file successfully opened...." << endl; 
     if (myReadFile.is_open()) {
        // pseudocode
        // Loop 27 times, once for each student struct in our array
        // inside the loop, read in four values from our file 
        // set the corresponding variable in the student struct 
        
        cout << "loop over each student times..." << endl; 
        for (int i = 0; i < numStudents && myReadFile.eof() == 0; i++) {
            myReadFile >> allStudents[i].firstName; 
            myReadFile >> allStudents[i].lastName; 
            myReadFile >> allStudents[i].numAttempts;
            myReadFile >> allStudents[i].average; 
        }
     }
     
     
    // Randomize somehow and pick one student
    
     cout << "Close the input file stream" << endl; 
     myReadFile.close();
     
     
     // show a menu with two items: 1) List all students with averages  2) Pick a random student
     
     char choice; 
     
     cout << "*********************************************" << endl 
          << "Choose from the following options: " << endl
          << "1) Show all student averages " << endl
          << "2) Pick a random student " << endl
          << "*********************************************" << endl; 
    
     cin >> choice; 
     
     if (choice == '1') {
       printStudents(allStudents, numStudents);   
     }  else if (choice == '2') {
        rStudent = pickRandomStudent(allStudents, numStudents);
        cout << "Student name: " << rStudent.firstName << " " << rStudent.lastName << endl;
     } else  {
         cout << "That is not a valid option" << endl; 
     }
     
    return 0; 
}