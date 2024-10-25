#include <iostream>
#include <cmath>
// lgcoshx - tanhx + 0.5 x [0;2]
void cont();
void menu(short number, short var);
double func(double x);
double ifDouble();
int ifInt();

int main()
{
    menu(5, 9);
    std::cout << "Необходимо приближенно найти корень уравнения f(x) = 0 для функции lgcoshx - tanhx + 0.5;\n" 
    "Корень нужно найти по следующему алгоритму: перебираем значения от начала до конца интервала\n"
    "с некоторым шагом и ищем значение функции, минимальное по модулю. Аргумент, при котором оно\n"
    "достигается, считаем корнем уравнения. Программа должна запросить у пользователя, на сколько\n"
    "частей разделить область поиска корня, вычислить шаг, с которым нужно проходить значения, пройти\n" 
    "в цикле нужные значения, найти корень и вывести его.\n";
    double a = 0, b = 2, root;
    std::cout << "Введите количество частей для разбиение интервала = ";
    int c = ifInt();
    double step = (b - a) / static_cast<double>(c);
    double min_x = a;
    double min_y = std::abs(func(a));

    for (double i = a; i <= b; i += step) {
        double fx = std::abs(func(i));
        if (min_y > fx) {
            min_y = fx;
            root = i;
        }
    }
    std::cout << "Приближенное значение корня: " << root << std::endl;
    std::cout << "Значение функции в точке: " << func(root) << std::endl;
    cont();
    return 0;
}

double func(double x) {
    return log10(cosh(x)) - tanh(x) + 0.5;
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