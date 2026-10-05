#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU_RU.UTF-8");

    string taxta[3][3] = {
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"}
    };

    bool is_x = true;
    string tanlov;
    bool yutdi = false;

    for (int yurish = 0; yurish < 9; yurish++) {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << taxta[i][j] << " | ";
            }
            cout << endl;
        }

        string belgi = is_x ? "X" : "O";
        cout << "\nNavbat: " << belgi << ". Qaysi katakka yozmoqchisiz (1-9): ";
        cin >> tanlov;

        bool topildi = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (taxta[i][j] == tanlov && tanlov != "X" && tanlov != "O") {
                    taxta[i][j] = belgi;
                    topildi = true;
                    break;
                }
            }
            if (topildi) break;
        }

        if (!topildi) {
            cout << "Noto'g'ri tanlov yoki bu katak band! Qaytadan urinib ko'ring.\n";
            yurish--;
            continue;
        }

        for (int i = 0; i < 3; i++) {
            if (taxta[i][0] == belgi && taxta[i][1] == belgi && taxta[i][2] == belgi) yutdi = true;
            if (taxta[0][i] == belgi && taxta[1][i] == belgi && taxta[2][i] == belgi) yutdi = true;
        }

        if (taxta[0][0] == belgi && taxta[1][1] == belgi && taxta[2][2] == belgi) yutdi = true;
        if (taxta[0][2] == belgi && taxta[1][1] == belgi && taxta[2][0] == belgi) yutdi = true;

        if (yutdi) {
            cout << "\n";
            for (int i = 0; i < 3; i++) {
                cout << "| ";
                for (int j = 0; j < 3; j++) cout << taxta[i][j] << " | ";
                cout << endl;
            }
            cout << "\nTabriklaymiz! '" << belgi << "' g'alaba qozondi!\n";
            break;
        }

        is_x = !is_x;
    }

    if (!yutdi) {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) cout << taxta[i][j] << " | ";
            cout << endl;
        }
        cout << "\nDurang! Hech kim yutmadi.\n";
    }

    return 0;
}