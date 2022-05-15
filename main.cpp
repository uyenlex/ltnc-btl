#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

bool block[5][5], selectedBlock[5][5];
bool board[10][10];
bool gameOver = false;
int score = 0;

bool possiblePlace(bool block[5][5]) {
    //check if there are still possible places to put blocks
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 1) continue;
            bool possible = false;
            for (int m = 0; m < 5; m++) {
                for (int n = 0; n < 5; n++) {
                    if (board[i+m][j+n] == 1 and block[m][n] == 1)
                        possible = true;
                        break;
                }
            }
            if (possible) continue;
            return true;
        }
    }
    return false;
}
void printBlock(bool block[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // cout << block[i][j];
            if (block[i][j] == 1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void RandomBlock () { //19 types of block
    memset(block, 0, sizeof(block));
    int stt = rand() % 19;
    switch (stt) {
        case 1: 
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) block[i][j] = 1;
            }
            break;
        case 2:
            for (int i = 0; i < 3; i++) {
                block[0][i] = 1;
                block[i][0] = 1;
            }
            break;
        case 3: 
            for (int i = 2; i >= 0; i--) {
                block[i][2] = 1;
                block[0][i] = 1;
            }
            break;
        case 4: 
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) block[i][j] = 1;
            }
            break;
        case 5: 
            for (int i = 0; i < 3; i++) block[0][i] = 1;
            break;
        case 6:
            for (int i = 0; i < 2; i++) block[0][i] = 1;
            break;
        case 7: 
            block[0][0] = 1;
            break;
        case 8: 
            for (int i = 0; i < 2; i++) {
                block[0][i] = 1;
                block[i][0] = 1;
            }
            break;
        case 9: 
            for (int i = 1; i >= 0; i--) {
                block[i][1] = 1;
                block[0][i] = 1;
            }
            break;
        case 10:
            for (int i = 0; i < 2; i++) block[i][0] = 1;
            break;
        case 11:
            for (int i = 0; i < 3; i++) block[i][0] = 1;
            break;
        case 12:
            for (int i = 0; i < 4; i++) block[i][0] = 1;
            break;
        case 13: 
            for (int i = 0; i < 5; i++) block[i][0] = 1;
            break;
        case 14:
            for (int i = 0; i < 4; i++) block[0][i] = 1;
            break;
        case 15: 
            for (int i = 0; i < 5; i++) block[0][i] = 1;
            break;
        case 16:
            for (int i = 0; i < 3; i++) {
                block[i][0] = 1;
                block[2][i] = 1;
            }
            break;
        case 17:
            for (int i = 0; i < 2; i++) {
                block[i][0] = 1;
                block[1][i] = 1;
            }
            break;
        case 18:
            for (int i = 0; i < 3; i++) {
                block[i][2] = 1;
                block[2][i] = 1;
            }
            break;
        case 0:
            for (int i = 0; i < 2; i++) {
                block[i][1] = 1;
                block[1][i] = 1;
            }
            break;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            selectedBlock[i][j] = block[i][j];
        }
    }
}
void printMap() { 
    // print the board after putting block on it
    system("cls");
    cout << "Your score: " << score << endl << endl;
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < 10; i++) {
        cout << setw(2) << i+1 << " ";
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 0) cout << setw(2) << ". ";
            else cout << setw(2) << "# ";
        }
        cout << endl;
    }
    cout << endl << endl;
}
void fillBlockinMap(bool block[5][5], const int& x, const int& y) { 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) 
            if (block[i][j] == 1) board[x+i-1][y+j-1] = 1;
    }
}
bool checkBlockinMap (bool block[5][5], const int& x, const int& y) { 
    //check if (x,y) is a possible place to put block
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) 
            if (block[i][j] == 1 and board[x+i-1][y+j-1] == 1) 
                return false;
    }
    return true;
}
void getPoint() {
    bool check = true;
    //check row
    for (int i = 0; i < 10; i++) {
        bool check = true;
        if(board[i][0] == 1) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] != 1) {
                    check = false;
                    break;
                }
            }
            if (check == true) {
                for (int j = 0; j < 10; j++) board[i][j] = 0;
                score =+ 10;
            }
        }
    }

    //check column
    for (int i = 0; i < 10; i++) {
        bool check = true;
        if(board[0][i] == 1) {
            for (int j = 0; j < 10; j++) {
                if (board[j][i] != 1) {
                    check = false;
                    break;
                }
            }
            if (check == true) {
                for (int j = 0; j < 10; j++) board[j][i] = 0;
                score += 10;
            }
        }
    }
}
void displayGame() {
    bool valid = false;
    bool tmpBlock[3][5][5];
    srand((unsigned)time(NULL));
    for (int stt = 0; stt < 3; stt++) {
        RandomBlock();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tmpBlock[stt][i][j] = selectedBlock[i][j];
            }
        }
        if (possiblePlace(tmpBlock[stt])) valid = true;
    }
    for (int stt = 0; stt < 3; stt++) printBlock(tmpBlock[stt]);
    if (!valid) {
        gameOver = true;
        return;
    }
    int choice;
    while (choice <= 0 or choice >= 4) {
        cout << "Please enter the block you want to choose: ";
        cin >> choice;
    }
    memset(block, 0, sizeof(block));
    memcpy(block, tmpBlock[choice-1], sizeof(tmpBlock[choice-1]));
}

int main() {
    printMap();
    displayGame();
    
enter:
    int x, y;
    cout << "Enter the left corner coordinate: ";
    cin >> x >> y;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((x + i - 1 > 9 and block[i][j] == 1) or (y + j - 1 > 9 and block[i][j] == 1)) {
                cout << "invalid" << endl;
                goto enter;
            }
        }
    }
    if (!checkBlockinMap(block, x, y)) {
        cout << "invalid" << endl;
        goto enter;
    }

run: 
    fillBlockinMap(block, x, y);
    printMap();
    getPoint();
    printMap();
    displayGame();
    if (gameOver) goto end;
    goto enter;

end:
    cout << "Game Over!" << endl;
    cout << "Your score is: " << score;

    return 0;
}