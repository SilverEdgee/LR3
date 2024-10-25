#include <iostream>

void cont();
void menu(short number, short var);

int main() {
    menu(1, -1);
    std::cout << "Вычислить N = ∑(a_i - b_i) для i от 1 до 30, где:\n\n";
    std::cout << "a_i = {\n";
    std::cout << "    i,          если i нечётное\n";
    std::cout << "    i^2,       если i чётное\n";
    std::cout << "}\n\n";
    std::cout << "b_i = {\n";
    std::cout << "    i/2,       если i чётное\n";
    std::cout << "    i,          если i нечётное\n";
    std::cout << "}\n\n";;
    for (int i = 0; i < 20; i++) std::cout << "x";
    std::cout << "\n";    
    int i = 1;
    double s = 0, a, b;
    while (i <= 30) {
        if (i % 2 == 0) {
            a = i / 2;
            b = i * i;
        }
        else {
            a = i;
            b = i * i * i;
        }
        s += (a - b) * (a - b);
        i++;
    }   
    std::cout << "Сумма - " << s << "\n";
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