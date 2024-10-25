#include <iostream>
#include <cmath>

void cont();
void menu(short number, short var);

int main() {
    menu(2, -1);
    std::cout << "Используя цикл do while найти сумму ряда с точностью 𝜀 = 10^-3\n"
    "член которого 𝑑𝑛 = 1/2^n + 1/3^n. При составлении программы считать, что\n"
    "точность достигнута, если 𝑑𝑛 < 𝜀\n";
    const double e = 1e-3;
    long double sum = 0, d = 0;
    long double number1 = 1;
    long double number2 = 1;
    do {
        number1 /= 2.0;
        number2 /= 3.0; 
        d = number1 + number2;
        sum += d;
    }
    while (d >= e);
    std::cout << "Результат выражения - " << sum << std::endl;
    cont();
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