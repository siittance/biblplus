#include <iostream>
#include <string>
#include <windows.h>
#include <iostream>
#pragma execution_character_set("utf-8")
using namespace std;

typedef bool(*CheckCharactersFunction)(const char*, const char*);

int main() {
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF-8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF-8

    cout << "Введите строчку для поиска символов: ";
    string str;
    getline(cin, str);

    cout << "Введите символы для поиска в строке: ";
    string sim;
    getline(cin, sim);

    HINSTANCE hDLL = LoadLibrary(L"LibDLL.dll");
    typedef bool (*serchstr)(const char*, const char*);

    serchstr findCharsInString = (serchstr)GetProcAddress(hDLL, "serchstr");

    bool res = findCharsInString(str.c_str(), sim.c_str());

    if (res) {
        cout << "Все нашло" << endl;
    }
    else {
        cout << "Не все нашло" << endl;
    }

    FreeLibrary(hDLL);

    return 0;
}

