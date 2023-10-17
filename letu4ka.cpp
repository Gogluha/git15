#include <iostream>

// Ошибки по стилю кода:
// Правлю первый и последний раз
// 1. Необходимо использовать camelCase либо under_score
// 2. Необходимо использовать const там, где это возможно
// 3. Добавляйте в .gitignore файлы, которые не должны попадать в репозиторий к примеру файлы сборки
// 4. Не называйте letu4ka.cpp, а называйте по смыслу например int_to_dec.cpp
// 5. Не используйте using namespace std;
// 6. Не используйте std::endl, а используйте \n
// 7. Не используйте std::cout, а используйте std::printf

// Можем собраться и подумать
// getbanka - название функции не соответствует ее действию -> правильно getIntLength
// Нужна ли нам эта функция вообще
// Максимальное int число 2147483647 -> 10 символов, следовательно мы можем выделить 11 + 3 символов
// 10 для числа 1 для знака два для 0x и один для \0
// Зато сложность нашего алгоритма будет O(n) где n - длина числа
// Мы же проходим по числу дважды, следовательно сложность O(2n), что конечно в глобальном смысле роли не играет
// Но все же

// Программа не собирается
// Отсутствует CMake проект
// Необходимо добавить в .gitignore файлы сборки
// Необходимо написать тесты используя assert()

// хау ту юз ассерт ?
// #include <cassert>
// assert(1 == 2);

int getlen(int num) {
    int length = 0;
    while (num > 0) {
        num = num / 10;
        length = length + 1;
    }
    return length;
}

char *intToDec(int num) {
    bool is_negative = (num < 0) ? true : false;
    int total_length;

    if (is_negative) {
        total_length = getlen(num) + 3;
    } else {
        total_length = getlen(num) + 2;
    }

    char *result = new char[total_length + 1];
    result[total_length + 1] = 0;

    /// Пригород Нью-Йорка
    /// Поднью-Йорк?

    /// Дополнительные символ
    /// Допсаймболс !!!!!
    int dopsymbols;
    if (is_negative) {
        num = num * (-1);
        result[0] = '-';
        result[1] = '0';
        result[2] = 'd';
        dopsymbols = getlen(num) + 2;
    } else {
        result[0] = '0';
        result[1] = 'd';
        dopsymbols = getlen(num) + 1;
    }

    while (num > 0) {
        int ost = num % 10;
        char resultdel;

        resultdel = 48 + ost;
        result[dopsymbols] = resultdel;

        num = num / 10;
        dopsymbols = dopsymbols - 1;
    }

    return result;
}

int main() {
    int number = 1000;

    std::printf("%s\n", intToDec(number));
    std::cout << intToDec(number) << std::endl;

}