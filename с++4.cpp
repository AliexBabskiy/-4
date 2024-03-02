#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    string word;
    int choice;

    do {
        cout << "Введите слово: ";
        cin >> word;
        cout << "Меню:\n";
        cout << "1. Слово выводится задом наперед\n";
        cout << "2. Вывести слово без гласных\n";
        cout << "3. Вывести слово без согласных\n";
        cout << "4. Рандомно раскидывать буквы заданного слова\n";
        cout << "5. Выход\n";
        
        cin >> choice;

        switch (choice) {
        case 1:
            reverse(word.begin(), word.end());
            cout << "Реверсивное слово: " << word << endl;
            main();
        case 2:
            for (char& c : word) {
                if (string("ёуеыаоэяиюЁУЕЫАОЭЯИЮ").find(c) != string::npos) {
                    c = '_';
                }
            }
            cout << "Слово без гласных: " << word << endl;
            main();
        case 3:
            for (char& c : word) {
                if (string("цкнгшщзхфвпрлджчсмтбЦКНГШЩЗХФВПРЛДЖЧСМТБ").find(c) != string::npos) {
                    c = '_';
                }
            }
            cout << "Слово без согласных: " << word << endl;
            main();
        case 4:
            random_device rd;
            shuffle(word.begin(), word.end(), rd);
            cout << "Перемешанное слово: " << word << endl;
            main();
        }
    } while (choice != 5);
}

