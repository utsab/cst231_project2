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
void printAllStudents(student allStudents[], int numStudents) {
    
    cout << "Iterate over all the students.  Print out a user-friendly message for each attribute of the student." << endl; 
    for (int i = 0; i < numStudents; i++) {
        cout << allStudents[i].firstName << " " << allStudents[i].lastName
             << " has made " << allStudents[i].numAttempts << " attempts and has an average of "
             << allStudents[i].average << endl; 
    }
}

// Version 1: prints name of the first matching student and then exits
// void searchForStudentByFirstName(student allStudents[], int numStudents) {
    
//     string targetName = ""; 
    
//     cout << "Enter first name of student: " << endl; 
//     cin >> targetName; 
    
//     for (int i = 0; i < numStudents; i++) {
//         if (targetName == allStudents[i].firstName) {
//             cout << allStudents[i].firstName << " " << allStudents[i].lastName
//              << " has made " << allStudents[i].numAttempts << " attempts and has an average of "
//              << allStudents[i].average << endl; 
             
//              return; 
//         }
//     }
    
//     cout << "Cannot find student" << endl; 
// }


// Version 2: Prints all matching students
void searchForStudentByFirstName(student allStudents[], int numStudents) {
    
    string targetName = ""; 
    bool isMatchFound = false; 
    
    cout << "Enter first name of student: " << endl; 
    cin >> targetName; 
    
    for (int i = 0; i < numStudents; i++) {
        if (targetName == allStudents[i].firstName) {
            cout << allStudents[i].firstName << " " << allStudents[i].lastName
             << " has made " << allStudents[i].numAttempts << " attempts and has an average of "
             << allStudents[i].average << endl; 
             
            isMatchFound = true; 
        }
    }
    
    if (!isMatchFound) {
        cout << "Cannot find student" << endl; 
    }
}


void searchForStudentByLastName(student allStudents[], int numStudents) {
    
    string targetName = ""; 
    bool isMatchFound = false; 
    
    cout << "Enter last name of student: " << endl; 
    cin >> targetName; 
    
    for (int i = 0; i < numStudents; i++) {
        if (targetName == allStudents[i].lastName) {
            cout << allStudents[i].firstName << " " << allStudents[i].lastName
             << " has made " << allStudents[i].numAttempts << " attempts and has an average of "
             << allStudents[i].average << endl; 
             
            isMatchFound = true; 
        }
    }
    
    if (!isMatchFound) {
        cout << "Cannot find student" << endl; 
    }
}



void readStudentsFromFile(student allStudents[], int numStudents) {
    cout << "Declare a input file stream which we will use to read in the student data" << endl; 
    ifstream myReadFile;
    
    cout << "Open the file.  Student data is stored in studentData.txt" << endl; 
    myReadFile.open("studentData.txt");
    
    cout << "Every time we read something in from the file, we'll store it inside of this variable" << endl;  
    string input;
    
     cout << "Check if the file successfully opened...." << endl; 
     if (myReadFile.is_open()) {
        // pseudocode
        // Loop 27 times, once for each student struct in our array
        // inside the loop, read in four values from our file 
        // set the corresponding variable in the student struct 
        
        for (int i = 0; i < numStudents && myReadFile.eof() == 0; i++) {
            myReadFile >> allStudents[i].firstName; 
            myReadFile >> allStudents[i].lastName; 
            myReadFile >> allStudents[i].numAttempts;
            myReadFile >> allStudents[i].average; 
        }
     }
    
     cout << "Close the input file stream" << endl; 
     myReadFile.close();
}

// This function prints all of our student data back into a file. 
void writeStudentsToFile(student allStudents[], int numStudents) {
    ofstream writeStudentDataFile ("studentData.txt", ios::out | ios::trunc); // clear contents

    for (int i = 0; i < numStudents; i++) {
        writeStudentDataFile << allStudents[i].firstName;
        writeStudentDataFile << " ";
        writeStudentDataFile << allStudents[i].lastName;
        writeStudentDataFile << " ";
        writeStudentDataFile << allStudents[i].numAttempts;
        writeStudentDataFile << " ";
        writeStudentDataFile << allStudents[i].average;
        writeStudentDataFile << endl; 
    }
    
    writeStudentDataFile.close();
}

// Picks one student randomly from the student array.  
/* Allows teacher to input a new score for that student. 
void pickRandomStudent(student list[], int n) {
    student picked; // Declare a local variable for the picked student
    int r1; // declare a variable for the random index I am going to use to pick the student
    
    // Mod operation is a reminder after division operation
    r1 = rand()%n; // Pick r1 randomly between 0 and n-1
    picked = list[r1]; // accessing the random entry from the array in the picked variable

    cout << "Student name: " << picked.firstName << " " << picked.lastName 
         << ", Average: " << picked.average << ", numAttempts: " << picked.numAttempts << endl;
            
    int gradeForThisAttempt; 
    
    cout << "Enter new grade for student: " << endl; 
    cin >> gradeForThisAttempt; 
    
    
    picked.average = ((picked.average * picked.numAttempts) + gradeForThisAttempt)/(picked.numAttempts+1); 
    picked.numAttempts++; 
    
    cout << "UPDATED INFO: Student name: " << picked.firstName << " " << picked.lastName 
         << ", Average: " << picked.average << ", numAttempts: " << picked.numAttempts << endl;
    
    
    list[r1] = picked; //This is necessary because the struct was copied by value into 'picked'
    
    writeStudentsToFile(list, n); 
}
*/


/* show a menu with two items: 1) List all students with averages  2) Pick a random student
     
void showMenu(student allStudents[], int numStudents) {
    char choice; 
    while (true) {
        
        cout << "*********************************************" << endl 
             << "Choose from the following options: " << endl
             << "1) Show all student averages " << endl
             << "2) Pick a random student " << endl
             << "Or type 'q' to quit" << endl 
             << "*********************************************" << endl; 
    
    
        cin >> choice; 
     
        if (choice == '1') {
           printAllStudents(allStudents, numStudents);   
        } else if (choice == '2') {
            pickRandomStudent(allStudents, numStudents);
        } else if (choice == 'q') {
            break; 
        } else  {
             cout << "That is not a valid option" << endl; 
        }
    }
}
*/

void pickRandomStudent(student students[], int num) {
    // Pick a random number between 0 and num - 1
    int r1 = rand()%num;
    
    // Pick that particular entry from the students array as the picked student
    student picked;
    picked = students[r1];
    
    // Print the picked student information on the screen
    cout << "Student name: " << picked.firstName << " " << picked.lastName 
         << ", Average: " << picked.average << ", numAttempts: " << picked.numAttempts << endl;
    
    // Ask instructor for new grade for the picked student & read it into a variable
    int newGrade;
    cout << "Enter new grade for the picked student: ";
    cin >> newGrade;
    
    // Calculate new average for picked student - increase number of attempts for picked student
    picked.average = ((picked.average * picked.numAttempts) + newGrade)/(picked.numAttempts+1); 
    picked.numAttempts++;
    cout << "UPDATED INFO: Student name: " << picked.firstName << " " << picked.lastName 
         << ", Average: " << picked.average << ", numAttempts: " << picked.numAttempts << endl;
         
    // Update the array with the new info - call write to file function to push this data on to the file
    students[r1] = picked;
    writeStudentsToFile(students, num);
    
}

void showMenu (student sArray[], int num) {
    char choice;
    while (true) {
        // Print the menu option I want to provide
        cout << "1 - Print all student info" << endl 
             << "2 - Pick Random Student to Engage" << endl 
             << "3 - Search for student by first name" << endl
             << "4 - Search for student by last name" << endl
             << "q - Quit" << endl;
        cout << "Enter your choice you esteemed user: ";
        // Read user input
        cin >> choice;
        // Based on the input - call different functions to have different responses
        // 1 -> printAllStudents
        // 2 -> pickRandomStudent
        // 3 -> searchForStudentByFirstName
        // q - return - get out
        // anything else in the input - print an error and go back to get an input again
        if (choice == '1') {
            printAllStudents(sArray, num);
        } else if (choice == '2')
                    pickRandomStudent(sArray, num);
                else if (choice == 'q')
                        return;
                      else if (choice == '3')
                                searchForStudentByFirstName(sArray, num); 
                           else if (choice == '4')
                                    searchForStudentByLastName(sArray, num); 
                                else 
                                    cout << "I don't understand the choice" << endl;
        }
}

int main() {
    
    const int numStudents = 28; 
    student allStudents[numStudents];
    readStudentsFromFile(allStudents, numStudents); 
    
    srand(time(NULL));
    
    // Call function for showing menu and interacting with the user
    showMenu(allStudents, numStudents); 
    
    return 0; 
}