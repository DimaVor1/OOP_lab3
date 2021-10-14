#define _USE_MATH_DEFINES
#define _CRTDBG_MAP_ALLOC

#define MS 10
#include "C:\Users\User\source\repos\oop_lab3\Libary\IntVector.h"  

using namespace P3_1;

int addvector();

IntVector Vectors[MS];
int CS = 0;

int main() {
    std::cout << "Hello, what do you want?"<< std::endl;
    int d;
    addvector();
    int CV = 0;
    const char* msgs1[] = { "0. Quit", "1. Change vector", "2. Print vector", "3. Sum vectors", "4. Part of the vector", "5. Add element", "6. Sort vector", "7. Max element", "8. Add new vector" };
    while (1) {
        std::cout << std::endl << "Current vector is [" << CV << "], What do you want?" << std::endl;
        for (int i = 0; i < 9; i++) {
            std::cout << msgs1[i] << std::endl;
        }
        P3_1::getNum(d);
        switch (d) {
        case 0:
            std::cout << "Bye" << std::endl;
            return 0;
        case 1: 
        {
            int num;
            std::cout << "Enter vector number: ";
            getNum(num);
            while (num < 0 || num >= CS) {
                std::cout << "No such vector, enter new number: ";
                getNum(num);
            }
            CV = num;
            continue;
        }
        case 2:
        {
            try {
                Vectors[CV].print(std::cout, 0, Vectors[CV].getCSz());
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            continue;
        }
        case 3:
        {
            if (CS == 1) {
                std::cout << "No vectors to sum" << std::endl;
                continue;
            }
            int num;
            std::cout << "Enter vector number: ";
            getNum(num);
            while (num < 0 || num >= CS|| num == CV) {
                std::cout << "No such vector, enter new number: ";
                getNum(num);
            }
            Vectors[CV].sum(Vectors[num]);
            continue;
        }
        case 4:
        {
            int s;
            std::cout << "Enter start element: ";
            getNum(s);
            int l;
            std::cout << "Enter len: ";
            getNum(l);
            try {
                Vectors[CV].print(std::cout, s, l);
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            continue;
        }
        case 5:
        {
            int e;
            std::cout << "Enter element: ";
            getNum(e);
            try {
                Vectors[CV].addEl(e);
                std::cout << "Success" << std::endl;
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            continue;
        }
        case 6:
        {
            Vectors[CV].sort(0,Vectors[CV].getCSz()-1);
            continue;
        }
        case 7:
        {
            try {
                std::cout << "Max element in current vector: " << Vectors[CV].maxNum() << std::endl;
                }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
                }
            continue;
        }
        case 8:
        {
            if (CS >= MS) {
                std::cout << "Can't add more vectors" << std::endl;
                continue;
            }
            else {
                int q = addvector();
                if (q == -1)
                    return 0;
            }
            continue;
        }
        default:

            std::cout << "Error!" << std::endl;
            continue;

        }
    }
    return 0;
}

int addvector() {
    const char* msgs[] = { "0. Quit", "1. Create empty vector", "2. Create 1 element vector", "3. Create normal vector" };
    int d, m = 1;
    while (m) {
        for (int i = 0; i < 4; i++) {
            std::cout << msgs[i] << std::endl;
        }
        P3_1::getNum(d);
        switch (d) {
        case 0:
            std::cout << "Bye" << std::endl;
            return -1;
        case 1: {
            IntVector a;
            Vectors[CS] = a;
            CS++;
            m = 0;
            break;
        }
        case 2:
        {
            int el;
            std::cout << "Enter element: ";
            getNum(el);
            IntVector a(el);
            Vectors[CS] = a;
            CS++;
            m = 0;
            break;
        }
        case 3:
        {
            int s;
            std::cout << "How many elements you want to add?";
            getNum(s);
            int els[30];
            int el1;
            for (int i = 0; (i < s && i < MS); i++) {
                std::cout << "Enter element: ";
                getNum(el1);
                els[i] = el1;
            }
            try {
                IntVector a(s, els);
                Vectors[CS] = a;
                CS++;
                m = 0;
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            break;
        }
        default:
            std::cout << "Error!" << std::endl;
            continue;

        }
    }
    return 0;
}

