#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

double F(double x, double a, double b, double c) {
    if ((a || b) && (a || c) != 0) {
        if (x < 0 && b != 0) {
            return a * x * x + b;
        }
        else if (x > 0 && b == 0) {
            return (x - a) / (x - c);
        }
        else {
            return x / c;
        }
    }
    else {
        if (x < 0 && b != 0) {
            return static_cast<int>(a * x * x + b);
        }
        else if (x > 0 && b == 0) {
            return static_cast<int>((x - a) / (x - c));
        }
        else {
            return static_cast<int>(x / c);
        }
    }
}

void enter(double& a, double& b, double& c, double& x_start, double& x_end, double& dx) {
    cout << "Введите значение a, b, c: ";
    cin >> a >> b >> c;

    cout << "\nВведите значение Xнач и Xкон: ";
    cin >> x_start >> x_end;

    cout << "\nВведите dx (шаг): ";
    cin >> dx;
    system("cls");
}

int main() {
    setlocale(LC_ALL, "RU");
    double a, b, c;
    double x_start, x_end;
    double dx;
    enter(a, b, c, x_start, x_end, dx);

    const int line_length = 37;

    cout << string(line_length, '-') << endl;
    cout << "| " << left << setw(15) << "x" << " | " << left << setw(15) << "F(x)" << " |" << endl;
    cout << string(line_length, '-') << endl;

    for (double x = x_start; x <= x_end; x += dx) {
        double result = F(x, a, b, c);

        cout << "| " << left << setw(15) << x << " | " << left << setw(15) << result << " |" << endl;
        cout << string(line_length, '-') << endl;

    }

    cout << "| " << "a = " << left << setw(2) << a << " | " << "b = " << left << setw(2) << b << " | " << "c = " << left << setw(2) << c << " | " << "dx = " << left << setw(1) << dx << " |" << endl;
    cout << string(line_length, '-') << endl;

    return 0;
}
