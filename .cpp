#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    double R;
    cout << "Vvedit parametr R: ";
    if (!(cin >> R) || R <= 0) {
        cout << "Pomylka vvedennya R!" << endl;
        return 1;
    }

    srand(static_cast<unsigned>(time(NULL)));

    cout << "\n=== 1 Sposib: Vvedennya z klaviatury (10 postriliv) ===\n";
    for (int i = 0; i < 10; i++) {
        double x, y;
        cout << "Postril " << i + 1 << " (x y): ";
        cin >> x >> y;

        bool part1 = (x >= -R && x <= 0) && (y >= 0 && y <= R) && ((x + R) * (x + R) + (y - R) * (y - R) >= R * R);
        bool part2 = (x >= 0 && y <= 0) && (x * x + y * y <= R * R);

        if (part1 || part2) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    cout << "\n=== 2 Sposib: Vypadkovi koordinaty [ -R ; R ] (10 postriliv) ===\n";
    cout << fixed << setprecision(4);

    for (int i = 0; i < 10; i++) {
        // Генерація випадкових чисел у діапазоні [-R; R]
        double x = (2.0 * rand() / RAND_MAX - 1.0) * R;
        double y = (2.0 * rand() / RAND_MAX - 1.0) * R;

        bool part1 = (x >= -R && x <= 0) && (y >= 0 && y <= R) && ((x + R) * (x + R) + (y - R) * (y - R) >= R * R);
        bool part2 = (x >= 0 && y <= 0) && (x * x + y * y <= R * R);

        cout << setw(8) << x << " " << setw(8) << y << " ";
        if (part1 || part2) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
