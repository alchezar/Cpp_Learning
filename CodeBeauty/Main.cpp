#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
// Row contains order, answer and which is correct
struct Variant {
    int Order = 0;
    string Answer;
    bool isCorrect = false;
};
// Contains question and 3 answer variants
struct Question {
    string Name;
    Variant Option[3];
};
// Set questions name and variants
void AssingTestQuestins(Question& Test, string Name, string Answer1, bool isCorrect1, string Answer2, bool isCorrect2, string Answer3, bool isCorrect3) {
    Test.Name = Name;
    Test.Option[0].Order = 1;
    Test.Option[0].Answer = Answer1;
    Test.Option[0].isCorrect = isCorrect1;
    Test.Option[1].Order = 2;
    Test.Option[1].Answer = Answer2;
    Test.Option[1].isCorrect = isCorrect2;
    Test.Option[2].Order = 3;
    Test.Option[2].Answer = Answer3;
    Test.Option[2].isCorrect = isCorrect3;
}
// Convert string text 1 and 0 into boolean true or false
bool String2Convert(string isTrue) {
    if (isTrue == "1") {
        return true;
    } else if (isTrue == "0") {
        return false;
    } else {
        return false;
    }
}
// Check number of rows and columns in csv
void RowsAndCells(string Link, int& Row, int& Cell) {
    fstream File;
    string Rows;
    string Cells;
    vector<string> line;
    vector<string> one;
    File.open(Link);
    if (File.is_open()) {
        while (getline(File, Rows, '\n')) {
            line.push_back(Rows);
        }
        Row = line.size();

        for (int i = 0; i < Row; i++) {
            stringstream SS(line.at(i));
            while (SS.good()) {
                getline(SS, Cells, ';');
                one.push_back(Cells);
            }
            Cell = one.size() - 1;
            one.clear();
        }
        File.close();
    }
}
// Read values from external file and write them into questions
void AssingFromFile(Question Test[], int Quantity, string Link, int Cells) {
    string QueLine;
    vector<string> arrCell;
    // Open file
    fstream File;
    File.open(Link);
    // Convert file to array
    if (File.is_open()) {
        while (getline(File, QueLine, ';')) {
            arrCell.push_back(QueLine);
        }
        for (int i = 0; i < Quantity; i++) {
            int j = i * Cells;
            AssingTestQuestins(Test[i], arrCell.at(j + 0), arrCell.at(j + 1), String2Convert(arrCell.at(j + 2)), arrCell.at(j + 3), String2Convert(arrCell.at(j + 4)), arrCell.at(j + 5), String2Convert(arrCell.at(j + 6)));
        }
        arrCell.clear();
        File.close();
    }
}
// Print to console question with 3 answers, get user guess, check is it right and count sum of right answers
void PrintTest(Question Test[], int Quantity) {
    int Guess = -1;
    int RightCount = 0;
    for (int i = 0; i < Quantity; i++) {
        cout << Test[i].Name << endl;
        for (int j = 0; j < 3; j++) {
            cout << Test[i].Option[j].Order << ". " << Test[i].Option[j].Answer << endl;
        }
        cout << "Choose 1-3: ";
        cin >> Guess;
        if (Test[i].Option[Guess - 1].isCorrect && Guess > 0 && Guess < 4) {
            RightCount++;
            cout << "Correct =)\n"
                 << endl;
        } else {
            cout << "Wrong =(\n"
                 << endl;
        }
    }
    cout << "You have " << RightCount << " right answers!!!" << endl;
}

int main() {
    int Cells;
    int Rows;
    // Read from file and set numbers of Rows and Cells
    RowsAndCells("Questions.csv", Rows, Cells);
    // According to numbers of rows create Questions array
    Question* Test = new Question[Rows];
    // Assing questions and answers from file and print to console
    AssingFromFile(Test, Rows, "Questions.csv", Cells);
    PrintTest(Test, Rows);
}