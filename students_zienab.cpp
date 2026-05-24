#include <iostream>
using namespace std;
double findAverage(int scores[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + scores[i];
    }
    return (double)sum / size;
}
int main()
{
    // Variables
    string studentName;
    int scores[3];
    double average;
    cout << "Enter student name: ";
    cin >> studentName;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter mark " << i + 1 << ": ";
        cin >> scores[i];
    }
    average = findAverage(scores, 3);
    cout << "\nStudent Name: " << studentName << endl;
    cout << "Average Marks: " << average << endl;
    if (average >= 50)
    {
        cout << "Status: PASS" << endl;
    }
    else
    {
        cout << "Status: FAIL" << endl;
    }
    return 0;
}