#include <iostream>
#include <cmath>
const long double PI = 3.14159265358979323846;
const long double TWO_PI = 2 * PI;
long double cosinus(long double x);
long double calculateLnAbs(long double x);
long double sinus(long double x);
long double normalizeAngle(long double x);
void cont();
void menu(short number, short var);
long double ifDouble();

int main() {
    menu(6, -1);
    std::cout << "Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при\n"
"заданном х, определить и вывести на экран дисплея минимальное значение.\n"
"Использование стандартных математических методов запрещено.\n";
    std::cout << "Введите x = ";
    long double x = ifDouble();
    long double a = sinus(x);
    long double b = cosinus(x);
    long double c = calculateLnAbs(x);
    std::cout << "sin_mine = " << sinus(x) << '\t' << "sin_cmath = " << sin(x) << '\n' << "cos_mine = " << cosinus(x) << '\t';
    std::cout << "cos_cmath = " << cos(x) << '\n' << "ln_mine = " << calculateLnAbs(x) << '\t' << "ln_cmath = " << log(fabs(x)) << "\n"; 
    if (a < b && a < c) {
        std::cout << "Минимальное значение - " << a << " (синус)" << std::endl;
    } else if (b < c) {
        std::cout << "Минимальное значение - " << b << " (косинус)" << std::endl;
    } else {
        std::cout << "Минимальное значение - " << c << " (натуральный логарифм от |x|)" << std::endl;
    }
    cont();
    return 0;
}

long double normalizeAngle(long double x) {
    double d = 2 * PI;
    while (d <= x)
        d *= 2;
    while (d >= 2 * PI) {
        while (x >= d)
            x -= d;
        d /= 2;
    }
    return x;
}

long double sinus(long double x) {
    x = normalizeAngle(x);
    long double coef = x, sum = coef;
    int n = 1;
    for(int i = 0; i < 5000; i++) {
        coef *= -1 * x * x / ((2 * n) * (2 * n + 1)); // Формула для следующего члена ряда Тейлора
        sum += coef; // Добавляем новый член в сумму
        n++; // Увеличиваем счетчик
    }
    return sum;
}

long double calculateLnAbs(long double x) {
    if (x > 0 && x < 0.1) return -calculateLnAbs(1/x);
    if (x < 0.0)
        x = -x; // Приводим к положительному значению, так как нужен ln(abs(x))
    int A = 0;
    const long double E = 2.71828182846; // Значение числа e (основание натурального логарифма)
    // Пока x >= 2, уменьшаем его, разделяя на e и увеличиваем счетчик A
    while (x >= 2.0) {
        A++;
        x /= E;
    }
    // Применяем разложение ln(1 + t), где t = x - 1
    long double t = x - 1;
    long double u = t; // Первый член ряда
    long double lnabsx = u;
    int n = 1;
    for(int i = 0; i < 5000; i++) {
        u *= -((n - 1) * t) / n; // Следующий член ряда
        lnabsx += u;         
    }
    return A + lnabsx;
}

long double cosinus(long double x) {
    x = normalizeAngle(x);
    long double coef = 1, sum = coef, accuracy = 1e-10;
    int n = 1;
    for (int i = 0; i < 5000; i++) {
        coef *= -1 * x * x / ((2 * n) * (2 * n - 1));
        sum += coef;
        ++n;
    }
    return sum;
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

long double ifDouble() {
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