#include <iostream>
#include <bitset>

int main()
{
    int a, b;
    std::cout << "Введите 2 числа через пробел: " << std::endl;
    std::cin >> a >> b;
    std::bitset<32> bs1(a), bs2(b);
    std::cout << "Первое число в двичном коде: " << bs1 << std::endl;
    std::cout << "Второе число в двочином коде: " << bs2 << std::endl << std::endl;

    std::bitset<64> reg;
    for (int i = 0; i < bs1.size(); ++i)
        reg[i] = bs1[i];
    std::cout << "Регистр: " << reg << std::endl << std::endl;

    for (int i = 0; i < 32; ++i)
    {
        std::cout << "Шаг #" << i + 1 << std::endl;
        std::cout << "Сдвиг вправо: " << std::endl;
        int lsb = reg[0];
        reg >>= 1;
        std::cout << reg << std::endl;
        if (lsb == 1)
        {
            std::cout << std:: endl << "Добавляем:" << std::endl;
            std::cout << " " << reg << std::endl;
            std::cout << "+" << std::endl;
            std::cout << " " << bs2 << std::endl;
            std::cout << "----------------------------------------------------------------" << std::endl;

            std::bitset<32> a;
            for (int k = 0; k < 32; ++k)
                a[k] = reg[31 + k];

            std::bitset<32> m("1"), result;
            for (int j = 0; j < 32; ++j)
            {
               std::bitset<32> const diff(((a >> j)& m).to_ullong() + ((bs2 >> j)& m).to_ullong() + (result >> j).to_ullong());
               result ^= (diff ^ (result >> j)) << j;
            }

            for (int k = 0; k < 32; ++k)
                reg[k + 31] = result[k];
            std::cout << " " << reg <<  std::endl;
        }
        else
        std::cout << std::endl;
    }

    std::cout << std::endl << "Результат в двоичном коде: " << reg << std::endl;
    std::cout << "Результат: " << (int)reg.to_ullong() << std::endl;
    std::cout << "Multiplication result for " << a << " and " << b << " is " << a * b << std::endl;

    return 0;
}