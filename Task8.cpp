#include <iostream>

void cont();
void menu(short number, short var);
int ifInt();

int main() {
    menu(8, -1);
    std::cout << "Вычислить a(0) -2a(1) +4a(2) -8a(3) +...+ 2 ^ (n - 1) * (- 1) ^ (n - 1) a(n-1)\n"
"Входные данные таковы, что результат может быть вычислен без переполнения. Использование вещественной арифметики запрещено.\n";
    long long sum = 0;
    long long coefficient = 1;
    int a;
    
    std::cout << "Введите количество элементов: ";
   int n = ifInt();
    std::cout << "Введите числа по порядку: ";
    for (int i = 0; i < n; ++i) {
        //std::cout << "Введите a(" << i << ") элемент - ";
        a = ifInt();
        a = a << i;
        if (coefficient < 0) sum -= a;
        else sum += a;
        coefficient = -coefficient;
    }
    std::cout << "Результат: " << sum << std::endl;
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
    std::cout << "Problem: ";
    } 
}
int ifInt() {
    int num;
    char after;
    while (true) {
        if (std::cin >> num && 
            ((after = std::cin.peek()) == ' ' || after == '\n')) {
            std::cin.get(after); // читаем пробел или \n
            return num;
        }
        
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}



