#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//White paper is the best teacher
//class none
//fun verb
//bool isOpen

vector<string> readFile(ifstream file) {
    vector<string> lines;
    if(file.is_open()) {
        string line = "";
        while(getline(file, line)) {
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

int power(int base, int exponet) {
    if(exponet < 1) {
        return 1;
    } else {
        return base * power(base, exponet - 1);
    }
}

int stringToInt(string score) {
    int result = 0;
    for(int i = score.size() - 1; i >= 0; i--) {
        result += (score[i] - '0') * power(10, score.size() - 1 - i);
    }
    return result;
}

vector<int> decode(vector<string> lines) {
    vector<int> scores; //{{1,0,0},{1,2}...
    for(int i = 0; i < lines.size(); i++) {
        scores.push_back(stringToInt(lines[i]));
    }
    return scores;
}


// //10점이 하나일때 별표 add
// //10s: *
// //20s: **
// //...
// //90s: **
// //100: ****

class Score {
public:
    Score(string inputText) {
        text = inputText;
        count = 0;
    }
    string text;
    int count;
};

// stringToInt
// vector<Score> generateScoreBoard() {
//     vector<Score> result; {text, count}
//     for(int i = 0; i <= 10; i++) {
//         if(i < 10) {
//             Score temp(intToString(i) + "0s: ");
//             result.push_back(temp);
//         } else {
//             Score temp(intToString(i) + "0: ");
//             result.push_back(temp);
//         }
//     }
//     return result;
// }

void displayScores(vector<int> numbers) {
    // vector<Score> board = generateScoreBoard();
    // for(int i = 0; i < numbers.size(); i++) {
    //     if(number < 10) {
    //         board[0].count++;
    //     } else if(number < 20) {
    //         board[1].count++;
    //     } else if(number < 30) {
    //         board[1].count++;
    //     }
    // }

    // for(int i = 0; i < board.size(); i++) {
    //     cout << board[i].text; //"10s:"
    //     for(int j = 0; j < board[i].count; j++)) {
    //         cout << "*";
    //     }
    // }

    // vecotr<Score> scores;
    // scores[0].count++;

    string scores[40];
    string number = "";

    scores[0] = "100: ";
    for(int i = 1; i < 20; i++) {
        number = i + '0';
        scores[i * 2] = number + "0s: ";
    }

    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] == 100) {
            scores[1] += "*";
        } else if(numbers[i] < 20 ) {
            scores[3] += "*";
        } else if(numbers[i] < 30 ) {
            scores[5] += "*";
        } else if(numbers[i] < 40 ) {
            scores[7] += "*";
        } else if(numbers[i] < 50 ) {
            scores[9] += "*";
        } else if(numbers[i] < 60 ) {
            scores[11] += "*";
        } else if(numbers[i] < 70 ) {
            scores[13] += "*";
        } else if(numbers[i] < 80 ) {
            scores[15] += "*";
        } else if(numbers[i] < 90 ) {
            scores[17] += "*";
        } else if(numbers[i] < 100 ) {
            scores[19] += "*";
        }
    }

    for(int i = 1; i < 20; i += 2) {
        cout << scores[i - 1] << scores[i] << endl;
    }
}

//When we make a return fuction, this is the starting format
// int foo() {
//     int result = 10; //<- make result, initial value
//     return result; //return
// }

//0 + '0' 10^0
//0 + '0' 10^1
//1 + '0' 10^2
//all add

int main() {
    ifstream file("score.text");
    //vector<int> numbers = {100, 12, 15, 13, 20, 30, 50, 100, 96, 80, 78, 55, 22, 33, 54, 76, 40};
    // readFile(file);
    vector<string> lines;
    if(file.is_open()) {
        string line = "";
        while(getline(file, line)) {
            lines.push_back(line);
        }
    }
    file.close();
    vector<int> numbers = decode(lines);
    displayScores(numbers);

    // return lines;
    return 0;
}