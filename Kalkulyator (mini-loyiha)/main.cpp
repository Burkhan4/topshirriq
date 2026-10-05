#include <iostream>

using namespace std;

int main() {
    float a, b;
    char amal;
    char davomEtish;
    do {
        cout << "Salom! Bu kalkulyator" << endl;
        cout << "Birinchi sonni kiriting: ";
        cin >> a;
        cout << "Amalni kiriting (+, -, *, /): ";
        cin >> amal;
        cout << "Ikkinchi sonni kiriting: ";
        cin >> b;

        switch (amal) {
            case '+':
                cout << "Natija: " << a + b << endl;
                break;
            case '-':
                cout << "Natija: " << a - b << endl;
                break;
            case '*':
                cout << "Natija: " << a * b << endl;
                break;
            case '/':
                if (b != 0) {
                    cout << "Natija: " << a / b << endl;
                } else {
                    cout << "Xato: Nolga bo'lish mumkin emas!" << endl;
                }
                break;
            default:
                cout << "Xato: Noto'g'ri amal! faqat +, -, *, / amallari ishlaydi." << endl;
        }
        cout << "Davom etishni istaysizmi? (y/n): ";
        cin >> davomEtish;
    } while (davomEtish == 'y' || davomEtish == 'Y');

    cout << "Dastur tugadi." << endl;
    return 0;

}