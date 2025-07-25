#include <iostream>
#include <map>

using namespace std;

int main() {
    // Declare a map with string keys and int values
    map<string, int> FamilyAge;

    FamilyAge["Shaaban"] = 45;
    FamilyAge["Howaida"] = 45;
    FamilyAge["Mohamed"] = 20;
    FamilyAge["Doha"] = 10;
    FamilyAge["Shaimaa"] = 19;
    FamilyAge["Reda"] = 15;
   
   
    cout << "\nPrinting all map values..\n\n";
    // Iterating over the map
    for (const auto& pair : FamilyAge) {
        cout << "Student: " << pair.first << ", Grade: " << pair.second << endl;
    }

    cout << "\nFinding Fadi's Grad in the Map..\n";
    // Finding the grade for a specific student
    string studentName = "Doha";
    if (FamilyAge.find(studentName) != FamilyAge.end()) {
        cout << studentName << "'s grade: " << FamilyAge[studentName] << endl;
    }
    else {
        cout << "Grade not found for " << studentName << endl;
    }

    cout << "\nFinding Omar's Grad in the Map..\n";
    // Finding the grade for a specific student
    studentName = "Mohamed";
    if (FamilyAge.find(studentName) != FamilyAge.end()) {
        cout << studentName << "'s grade: " << FamilyAge[studentName] << endl;
    }
    else {
        cout << "Grade not found for " << studentName << endl;
    }

    return 0;
}
