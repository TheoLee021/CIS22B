#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> examGrades(4);
    double averageGrade;

    for (double &gradeVal : examGrades) {
        double userGrade;

        cin >> userGrade;
        gradeVal = userGrade;
    }

    averageGrade = 0.0;
    for (double gradeVal : examGrades) {
        averageGrade += gradeVal;
    }
    averageGrade = averageGrade / examGrades.size();

    cout << "Average grade: " << averageGrade << endl;

    return 0;
}