#include <iostream>
#include <stdexcept>
using namespace std;

float calcTriPerimeter(float towerHeight, float towerLength) { //calculates the perimeter of the triangle
    float side = (float)(0.5 * (sqrt(pow(towerLength, 2) + (4 * pow(towerHeight, 2))))); //calculation that finds the sides of an isosceles triangle.
    float perimeter = (2 * side) + towerLength;
    return perimeter;
}
void printTriangle(float towerHeight, float towerLength) { //prints the triangle using stars
    if (((int)towerLength % 2 == 0) || (towerLength > (2 * towerHeight))) //checks if triangle can be printed
        cout << "Can not print triangle\n";
    else {
        // Print triangle tower pattern using stars
        if (towerLength >= 4) { // Check if the tower length is 4 or greater
            int rowsPerSection = ((int)towerHeight - 2) / (((int)towerLength - 2) / 2); // Calculate rows per section
            int topRowRemainder = ((int)towerHeight - 2) % (int)((towerLength - 2) / 2); // Calculate remainder for top row
            int numSections = (towerLength / 2) + 1; // Calculate number of sections
            int numStars = 1, numRows; // Initialize number of stars and rows
            for (int section = 0; section < numSections; section++) { // Loop through each section
                if (section == 0 || section == (numSections - 1)) numRows = 1; // Set number of rows for first and last sections
                else if (section == 1) numRows = rowsPerSection + topRowRemainder; // Set number of rows for second section
                else numRows = rowsPerSection; // Set number of rows for remaining sections
                for (int row = 0; row < numRows; row++) { // Loop through each row in the section
                    int numSpaces = (towerLength - numStars) / 2; // Calculate number of spaces before stars
                    for (int space = 0; space < numSpaces; space++) // Loop to print spaces
                        cout << " ";
                    for (int star = 0; star < numStars; star++) { // Loop to print stars
                        cout << "*";
                    }
                    cout << endl;
                }
                numStars = numStars + 2; // Increment number of stars for next section
            }
        }
        else {
            if (towerLength == 1) { // Check if tower length is 1
                for (int row = 0; row < towerHeight; row++) { // Print single star for each row
                    cout << "*\n";
                }
            }
            else
                if (towerLength == 3) { // Check if tower length is 3
                    for (int row = 0; row < towerHeight; row++) { // Print triangle pattern with three stars
                        cout << " *\n";
                    }
                    cout << "***\n";
                }
        }
    }
}
float calcRecArea(float height, float length) { //calculates the area of the rectangle
    float area = height * length;
    return area;
}
float calcRecPerimeter(float height, float length) { //calculates the perimeter of the rectangle 
    float perimeter = 2 * (height + length);
    return perimeter;
}
float calculateRec(float height, float length) { //checks if the perimeter or the area of the rectangle should be returned
    float isRectangle = abs(height - length);
    if (isRectangle == 0 || isRectangle > 5) {
        cout << "The rectangles area is: ";
        return calcRecArea(height, length);
    }
    cout << "The rectangles perimeter is: ";
    return calcRecPerimeter(height, length);
}


int main() {
    float height, length;
    int choice = 0;
    while (choice != 3) { //list of options for the user to pick from
        cout << "Please enter a number of your choice:\n" <<
            "1- To a rectangular tower\n" <<
            "2- To a triangle tower\n" <<
            "3- Exit\n";
        try {
            cin >> choice;
            if (cin.fail()) {
                cin.clear(); // clear the failbit flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the invalid input
                throw invalid_argument("Invalid input: must be an integer value");
            }
        }
        catch (invalid_argument& e) {
            cout << e.what() << endl;
        }
        if (choice == 3) //if the user picks 3 it ends the program
            return 0;
        if (choice == 1 || choice == 2) { //gets the height and length messurments 
            cout << "Enter the height of the tower\n";
            try {
                cin >> height;
                if (cin.fail()) {
                    cin.clear(); // clear the failbit flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the invalid input
                    throw invalid_argument("Invalid input: must be an integer value");
                }
            }
            catch (invalid_argument& e) {
                cout << e.what() << endl;
            }
            if (height <= 2) {
                cout << "Must be a height bigger then 2\n";
                continue;
            }
            cout << "Enter the length of the tower\n";
            try {
                cin >> length;
                if (cin.fail()) {
                    cin.clear(); // clear the failbit flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the invalid input
                    throw invalid_argument("Invalid input: must be an integer value");
                }
            }
            catch (invalid_argument& e) {
                cout << e.what() << endl;
            }
            if (length <= 0) {
                cout << "Must be a length equal or bigger then 0\n";
                continue;
            }
        }
        if (choice == 1) //prints information about the rectangle
            cout << calculateRec(height, length) << endl;
        else if (choice == 2) { //prints information about the triangle
            int flag = 0;
            while (flag == 0) { //repeats again if an invalid option was chosen
                cout << "Pick an option:\n" <<
                    "1 - print triangle perimeter\n" <<
                    "2 - print triangle\n";
                int choice;
                try {
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear(); // clear the failbit flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the invalid input
                        throw invalid_argument("Invalid input: must be an integer value");
                    }
                }
                catch (invalid_argument& e) {
                    cout << e.what() << endl;
                }
                flag++;
                if (choice == 1) //prints the perimeter of the triangle
                    cout << "the Triangles perimeter is: " << calcTriPerimeter(height, length) << endl;
                else if (choice == 2) //prints the triangle
                    printTriangle(height, length);
                else {
                    cout << "invalid input\n"; //repeats the option in the event of an invalid input
                    flag = 0;
                }
            }
        }
    }
    return 0;
}