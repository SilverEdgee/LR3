#include <iostream>
#include <cmath>

void cont();
void menu(short number, short var);
int ifInt();

int main() {
    menu(7, -1);
    std::cout << "Напишите программу, которая выводит все числа Армстронга, меньше введённого\n"
"пользователем числа.\n";
    std::cout << "Введите x = ";
    int x = ifInt();
    for (int i = 0; i <= x; i++) {
        int original_number = i;
        int sum = 0;
        int temp = i;
        int num_digits = log10(i) + 1;
        while (temp > 0) {
            int digit = temp % 10;
            sum += pow(digit, num_digits);
            temp /= 10;
        }

        if (sum == original_number) {
            std::cout << original_number << " является числом Армстронга" << std::endl;
        }
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
