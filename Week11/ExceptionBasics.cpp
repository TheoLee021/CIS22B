#include <iostream>
using namespace std;

int main() {
    int weightVal;
    int heightVal;
    float bmiCalc;
    char quitCmd;

    quitCmd = 'a';
    while (quitCmd != 'q') {
        try {
            // Get user data
            cout << "Enter weight (in pounds): ";
            cin >> weightVal;

            // Error checking, non-negative weight
            if (weightVal < 0) {
                throw runtime_error("Invalid weight.");
            }

            cout << "Enter height (in inches): ";
            cin >> heightVal;

            // Error checking, non-negative height
            if (heightVal < 0) {
                throw runtime_error("Invalid height.");
            }

            // Calculate BMI and print user health info if no input error
            // Source: http://www.cdc.gov/
            bmiCalc = (static_cast<float>(weightVal) / static_cast<float>(heightVal * heightVal)) * 703.0;
            cout << "BMI: " << bmiCalc << endl;
            cout << "(CDC: 18.6-24.9 normal)" << endl;
        }
        catch (runtime_error &excpt) {
            // Prints the error message passed by throw statement
            cout << excpt.what() << endl;
            cout << "Cannot compute health info." << endl;
        }

        // Prompt user to continue/quit
        cout << endl << "Enter any key ('q' to quit): ";
        cin >> quitCmd;
    }
    
    return 0;
}