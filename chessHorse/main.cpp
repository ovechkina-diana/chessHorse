////
//  main.cpp
//  chessHorse
//
//  Created by Diana Ovechkina on 16.02.2022.
//

#include <iostream>
#include <iomanip>
using namespace std;


const int N = 8;

int moveX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; //сдвиг по x
int moveY[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; //сдвиг по y


void outputField(int mas[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << mas[i][j]; // setw подключен через библиотеку iomanip, выделяет 3 клетки
        }
        cout << endl;
    }
}

void horse(int field[N][N], int moveNumber, int i0, int j0) {

    static int count = 0;
    count++; // сколько раз заходил в функцию, то есть количество попыток
    field[i0][j0] = moveNumber++;

//    cout << count << endl; // можно раскомментировать, чтобы посмотреть как выполнялись ходы и их количество (получится много)
//    outputField(mas);
//    cout << endl;

    for (int i = 0; i < 8; i++) { // 8 - количество вариантов ходов
        int iNew = i0 + moveY[i];
        int jNew = j0 + moveX[i];

        if (moveNumber > N * N) {
            outputField(field);
            exit(0);
            // break;
        }

        if (iNew < 0 || iNew > N - 1 || jNew < 0 || jNew > N - 1 || field[iNew][jNew] != 0) {
            continue; // если условие выполняется, то ход меняется
        }

        horse(field, moveNumber, iNew, jNew);
        field[iNew][jNew] = 0; // если некуда ходить, то ставим 0 в текущую клетку

    }

}


int main() {
    setlocale(LC_ALL, "rus");
    int field[N][N] = {};
    
    int col = -1;
    int row = -1;
    
    while (col > N || col < 0 || row > N || row < 0) {
        cout << "Введите столбец: "; cin >> col;
        cout << "Введите строку: "; cin >> row;
    }
    horse(field, 1, col - 1, row - 1);
    // если ничего не выводится => с этого положения невозможно обойти всю доску
    return 0;
}
