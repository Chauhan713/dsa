#include <bits/stdc++.h>
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    char division;
};

void addStudentInfo() {
    ofstream outFile("studentInfo.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(student.name, 50);
    cout << "Enter Division: ";
    cin >> student.division;
    outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    outFile.close();
}

void deleteStudentInfo(int rollNo) {
    ifstream inFile("studentInfo.txt", ios::binary);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    ofstream tempFile("temp.txt", ios::binary);
    if (!tempFile) {
        cerr << "Error creating temporary file!" << endl;
        return;
    }

    Student student;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo != rollNo) {
            tempFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }
    inFile.close();
    tempFile.close();

    remove("studentInfo.txt");
    rename("temp.txt", "studentInfo.txt");

    if (!found) {
        cout << "Student with Roll No " << rollNo << " not found!" << endl;
    } else {
        cout << "Student with Roll No " << rollNo << " deleted successfully!" << endl;
    }
}

void searchStudentInfo(int rollNo) {
    ifstream inFile("studentInfo.txt", ios::binary);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Student student;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo == rollNo) {
            found = true;
            cout << "Roll No: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            break;
        }
    }
    inFile.close();
    if (!found) {
        cout << "Student with Roll No " << rollNo << " not found!" << endl;
    }
}

int main() {
    int choice;
    int rollNo;
    while (true) {
        cout << "1. Add student information" << endl;
        cout << "2. Delete student information" << endl;
        cout << "3. Search student information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentInfo();
                break;
            case 2:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteStudentInfo(rollNo);
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                searchStudentInfo(rollNo);
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
