#include <iostream>
#include <cmath> 

void cont();
void menu(short number, short var);
int IfInt(int n);
double IfDouble(double n);

int main() {
    menu(3, -1);
    std::cout << "Используя цикл for составить программу вычисления значений\n"
    "функции y = sin(x) - cos(x) на отрезке [A, B] в точках 𝑋𝑖 = 𝐴 + 𝑖 ∗ 𝐻,\n"
    "где H = (B - A) / M, M = 20, A = 0, B = π / 2.\n";
    const int M = 20;
    const double A = 0.0;
    const double B = M_PI / 2;
    const double H = (B - A) / M;

    for (int i = 0; i <= M; ++i) {
        double Xi = A + i * H;           
        double Yi = sin(Xi) - cos(Xi);
        std::cout << "f(" << Xi << ") = " << Yi << std::endl;
    }
    cont();
    return 0;
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

int ifInt(int n) {
    int num;
    char after;
    
    std::cout << "Введите целое число: ";
    while (true) {
        if (std::cin >> num) {  // проверяем, что ввели число
            if (std::cin.get(after) && after == '\n') {  // проверяем, что после числа только перенос строки
                break;  // если все условия выполнены, выходим из цикла
            }
        }
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();  // сбрасываем состояние потока
        //cin.ignore(10000, '\n');  // очищаем буфер
    }
    
    std::cout << "Вы ввели правильное целое число: " << num << std::endl;
    return 0;
}

double ifDouble(double n) {
    double num;
    char after;
    
    std::cout << "Введите целое число: ";
    while (true) {
        if (std::cin >> num) {  // проверяем, что ввели число
            if (std::cin.get(after) && after == '\n') {  // проверяем, что после числа только перенос строки
                break;  // если все условия выполнены, выходим из цикла
            }
        }
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();  // сбрасываем состояние потока
        //cin.ignore(10000, '\n');  // очищаем буфер
    }
    
    std::cout << "Вы ввели правильное целое число: " << num << std::endl;
    return 0;
}