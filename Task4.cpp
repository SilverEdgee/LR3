#include <iostream>
#include <cmath>

void cont();
void menu(short number, short var);
double row(double x, int terms);
double real(double x);
double ifDouble();
int ifInt();

int main() {
    menu(4, 12);
    std::cout << "Необходимо разложить функцию Y(x) (x^2 / 4 + x / 4 + 1) * e^(x / 2) в ряд S(x),\n"
    "затем с помощью полученного ряда найти значение функции и сравнить его со\n"
    "значением, вычисленным с помощью стандартных функций. программа\n"
    "должна запросить у пользователя количество членов ряда (n), затем запросить\n"
    "у пользователя количество чисел, от которых он хочет посчитать функцию,\n"
    "затем пользователь вводит по одному числу (x от 0.1, до 1), программа считает\n"
    "значение функции с помощью ряда и с помощью стандартных функций и выводит оба значения. \n";
    for (int i = 0; i < 20; i++) std::cout << "x";
    std::cout << "\n";
    std::cout << "Введите количество членов ряда n = ";
    int n = ifInt();
    std::cout << "\nВведите количество чисел = ";
    int count = ifInt();
for (int i = 0; i < count; i++) {
    double x;
    do {
        std::cout << "Введите число x = ";
        x = ifDouble();
        if (x < 0.1 || x > 1) {
            std::cout << "Введите число в диапазоне [0.1, 1] пж\n";
        }
    } while (x < 0.1 || x > 1);
    std::cout << row(x, n) << "\t" << real(x) << std::endl;
}
    cont();
}
double row(double x, int terms) {
    double sum = 0;
    double term_exp = 1; // Член экспоненты e^(x/2), начинаем с 1
    double poly = (x * x) / 4 + x / 2 + 1; // Полином (x^2 / 4 + x / 2 + 1)
    
    for (int i = 0; i < terms; ++i) {
        sum += poly * term_exp; // Добавляем текущий член ряда
        term_exp *= x / (2 * (i + 1)); // Следующий член экспоненты (x/2)^i / i!
    }
    
    return sum;
}
double real(double x) {
    return (pow(x, 2) / 4 + x / 2 + 1) * exp(x / 2);
}
void cont() {
    char c;
        while(true) {
        std::cout << "Wanna continue? (Y/N) ";
        std::cin >> c;
        if (c == 'Y') {
            main();
            break;
        }
        else if (c == 'N') {
            break;
        }
        else {
            std::cout << "Wrong input. POZOR\n";
            std::cin.ignore(10000, '\n');
        }
    }
}
void menu(short number, short var) {
    std::cout << "Task " << number << " made by Denis Pometko\n";
    for (int i = 0; i < 20; i++) {
        std::cout << "x";
    }
    std::cout << "\n";
    if (var != -1) {
        std::cout << "Variant " << var << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "x";
    }
    std::cout << "\n";
    } 
    std::cout << "Problem: ";
}

int ifInt() {
    int num;
    char after;
    
    while (true) {
        if (std::cin >> num) {  // проверяем, что ввели число
            if (std::cin.get(after) && after == '\n') {  // проверяем, что после числа только перенос строки
                break;  // если все условия выполнены, выходим из цикла
            }
        }
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();  // сбрасываем состояние потока
        std::cin.ignore(10000, '\n');  // очищаем буфер
    }
    return num;
}

double ifDouble() {
    double num;
    char after;
    while (true) {
        if (std::cin >> num) {  // проверяем, что ввели число
            if (std::cin.get(after) && after == '\n') {  // проверяем, что после числа только перенос строки
                break;  // если все условия выполнены, выходим из цикла
            }
        }
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();  // сбрасываем состояние потока
        std::cin.ignore(10000, '\n');  // очищаем буфер
    }
    return num;
}