#include <iostream>
#include <time.h>
using namespace std;

int main() {
    int taxmin;
    srand(time(0));
    int tasodifiy_son = rand() % 100 + 1;
    cout << "Salom! Number Hunt o'yiniga xush kelibsiz!" << endl;
    cout << "1 dan 100 gacha son o'yladim. Topa olasizmi?" << endl;
    cout << "Iltimos, taxminingizni kiriting: ";
    cin >> taxmin;
    int urinishlar_soni = 1;

    while (taxmin != tasodifiy_son) {
        if (taxmin < tasodifiy_son) {
            cout << "Sizning taxminingiz juda kichik. Yana urinib ko'ring: ";
        } else {
            cout << "Sizning taxminingiz juda katta. Yana urinib ko'ring: ";
        }
        cin >> taxmin;
        urinishlar_soni++;
    }
    cout << "Tabriklaymiz! Siz topdingiz." << endl;
    cout << "Siz " << urinishlar_soni << " urinishda topdingiz." << endl;
    return 0;
}