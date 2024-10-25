#include <iostream>
using namespace std;
int ifInt(int n) {
    int num;
    char after;
    
    cout << "Введите целое число: ";
    while (true) {
        if (cin >> num) {  // проверяем, что ввели число
            if (cin.get(after) && after == '\n') {  // проверяем, что после числа только перенос строки
                break;  // если все условия выполнены, выходим из цикла
            }
        }
        cout << "Ошибка! Введите целое число: ";
        cin.clear();  // сбрасываем состояние потока
        //cin.ignore(10000, '\n');  // очищаем буфер
    }
    
    cout << "Вы ввели правильное целое число: " << num << endl;
    return 0;
}

double ifDouble(double n) {
    double num;
    char after;
    
    cout << "Введите целое число: ";
    while (true) {
        if (cin >> num) {  // проверяем, что ввели число
            if (cin.get(after) && after == '\n') {  // проверяем, что после числа только перенос строки
                break;  // если все условия выполнены, выходим из цикла
            }
        }
        cout << "Ошибка! Введите целое число: ";
        cin.clear();  // сбрасываем состояние потока
        //cin.ignore(10000, '\n');  // очищаем буфер
    }
    
    cout << "Вы ввели правильное целое число: " << num << endl;
    return 0;
}

int main() {
    int num;
    bool cin1 = (std::cin >> num);
    std::cout << cin1;
}