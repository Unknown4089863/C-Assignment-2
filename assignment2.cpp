#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Student
{

    string name;
    int rollNo;
    float marks;

public:
    void inputDetails()
    {
        cout << "Enter Name of Student : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number of Student : ";
        cin >> rollNo;
      do
    {
        cout << "Enter Marks (Total Marks = 100) : ";
        cin >> marks;
        if (marks < 0 || marks > 100){
            cout << "Invalid marks! Please enter a value between 0 and 100." << endl;
        }
    }while (marks < 0 || marks > 100);
    saveToFile();
    }
    void displayDetails()
    {
        cout << "Name : " << name << endl;
        cout << "Roll Number : " << rollNo << endl;
        cout << "Marks : " << marks << endl;
    }

    void saveToFile()
    {
        ofstream saveFile;
        ofstream save("student.txt",ios::app);
        string fileName = to_string(rollNo) + ".txt";
        saveFile.open(fileName);
        saveFile << name << "\n"
                 << rollNo << "\n"
                 << marks;
        save << name << "\n"
             << rollNo << "\n"
             << marks;
        saveFile.close();
    }

    void loadFromFile()
    {
        string fileName = to_string(rollNo) + ".txt";
        string data;
        ifstream File(fileName);
        while (File.eof() == 0)
        {
            getline(File, data);
            cout << data<<endl;
        }
    }
};
void loadFromFile(int roll)
{
    string fileName = to_string(roll) + ".txt";
    string data;
    ifstream File(fileName);
     if (!File)
    {
        cout << "File not found for roll number: " << roll << endl;
        return;
    }
    while (File.eof() == 0)
    {
        getline(File, data);
        cout << data<<endl;
    }
}
void loadFromFile(string fileName)
{
    string data;
    ifstream File(fileName);
    while (File.eof() == 0)
    {
        getline(File, data);
        cout << data<<endl;
    }
}

void options()
{
   cout << "\n********** Student Management System **********\n";
    cout << "1. Add New Student(s)\n";
    cout << "2. Display All Students\n";
    cout << "3. Search for a Student by Roll Number\n";
    cout << "0. Exit\n";
    cout << "***********************************************\n";
    cout << "Enter Your Choice  ===> : ";
}


int main(){
    vector<Student> students;
    int option;
    do
    {
        options();
        cin >> option;
        switch (option)
        {
        case 1:
            int n;
    cout << "Enter Number of Students you Want to Add: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student student;
        student.inputDetails();
        students.push_back(student);
    }
            break;
            case 2: loadFromFile("student.txt");
            break;
            case 3:int roll;
            cout<<"Enter Roll Number : ";
            cin>>roll;
            loadFromFile(roll);
            break;
            case 0:cout<<"Exit Program"<<endl;
            break;
default:cout<<"\nEnter valid Choice ! "<<endl;

        }
    } while (option != 0);
     return 0;
}