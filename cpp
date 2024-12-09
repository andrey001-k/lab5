#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Завдання 1
void task1() {
    double r;

    cout << "Введіть радіус кола r (додатне число): ";
    while (!(cin >> r) || r <= 0) {
        cout << "Некоректне значення. Введіть додатне число для r: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double circleArea = M_PI * r * r;         
    double triangleArea = r * r / 2;         
    double figureArea = triangleArea + circleArea / 2;

    cout << "\nРезультати обчислень для радіуса r = " << r << ":\n";
    cout << "1. Площа одного кола: " << circleArea << endl;
    cout << "2. Площа одного трикутника: " << triangleArea << endl;
    cout << "3. Площа жовтої частини фігури: " << figureArea << endl;
}

// Завдання 2
void task2() {
    double x;
    int n;

    cout << "Введіть значення x (у радіанах): ";
    while (!(cin >> x)) {
        cout << "Помилка введення! Будь ласка, введіть число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введіть кількість членів суми n (натуральне число): ";
    while (!(cin >> n) || n <= 0) {
        cout << "Помилка введення! Будь ласка, введіть натуральне число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double expr = -1 + cos(x);
    if (abs(expr) <= 1) {
        cout << "Умова | -1 + cos(x) | > 1 не виконується. Завершення програми.\n";
        return;
    }

    double logPart = log(expr);
    double sumPart = 0.0;

    for (int k = 1; k <= n; ++k) {
        sumPart += pow(-1, k) / (k * pow(expr, k));
    }

    double result = logPart - sumPart;
    cout << "Результат обчислення: " << result << endl;
}

// Функція для обчислення факторіалу
long long factorial(int num) {
    long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

// Функція для обчислення добутку у знаменнику
long long productDenominator(int n) {
    long long product = 1;
    for (int i = 0; i < n; ++i) {
        product *= (100 + 2 * i);
    }
    return product;
}

// Завдання 3
void task3() {
    int N;

    cout << "Введіть кількість членів суми (натуральне число): ";
    while (!(cin >> N) || N <= 0) {
        cout << "Помилка введення! Будь ласка, введіть натуральне число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double sum = 0.0;
    for (int n = 1; n <= N; ++n) {
        long long numerator = factorial(3 * n - 2);
        long long denominator = productDenominator(n);
        sum += static_cast<double>(numerator) / denominator;
    }

    cout << "Результат обчислення суми для " << N << " членів: " << sum << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== Меню вибору задачі ===\n";
        cout << "1. Обчислення площі кола і трикутника\n";
        cout << "2. Обчислення логарифмічної суми\n";
        cout << "3. Обчислення суми факторіалів\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 0:
                cout << "Вихід із програми.\n";
                return 0;
            default:
                cout << "Некоректний вибір! Спробуйте ще раз.\n";
        }
    }

    return 0;
}
