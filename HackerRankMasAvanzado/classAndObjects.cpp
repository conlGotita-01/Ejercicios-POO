#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    vector<int> scores;

public:
    // Function to read scores from stdin
    void input() {
        int score;
        for (int i = 0; i < 5; i++) {
            cin >> score;
            scores.push_back(score);
        }
    }

    // Function to calculate the total grade
    int calculateTotalScore() const {
        int totalScore = 0;
        for (int i = 0; i < 5; i++) {
            totalScore += scores[i];
        }
        return totalScore;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    // Read scores for each student
    for (int i = 0; i < n; i++) {
        students[i].input();
    }

    // Get Kristen's total grade
    int kristenTotalScore = students[0].calculateTotalScore();

    int betterStudentsCount = 0;
    // Count the number of students with total grades greater than Kristen's
    for (int i = 1; i < n; i++) {
        int totalScore = students[i].calculateTotalScore();
        if (totalScore > kristenTotalScore) {
            betterStudentsCount++;
        }
    }

    // Print the number of students with higher grades than Kristen's
    cout << betterStudentsCount << endl;

    return 0;
}
