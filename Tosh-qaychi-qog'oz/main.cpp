#include <iostream>
#include <time.h>
using namespace std;

int main() {

    srand(time(0));
    cout << "Tosh, Qaychi, Qog'oz o'yiniga xush kelibsiz!" << endl;
    int hisob = 0;
    int kompyuterHisob = 0;
    
    for (int i = 0; i < 3; i++) {
        int tanlov;
        int random = rand() % 3 + 1;
        cout << "hisob: " << hisob << " | kompyuter: " << kompyuterHisob << endl;
        cout << "tanlovingizni kiriting (1 - Tosh, 2 - Qaychi, 3 - Qog'oz): ";
        cin >> tanlov;
        if (tanlov < 1 || tanlov > 3) {
            cout << "Noto'g'ri tanlov! Iltimos, 1, 2 yoki 3 ni kiriting." << endl;
            i--;
            continue;
        } else if (tanlov == random) {
            cout << "Durrang!" << endl;
        } else if ((tanlov == 1 && random == 2) || (tanlov == 2 && random == 3) || (tanlov == 3 && random == 1)) {
            cout << "Siz yutdingiz!" << endl;
            hisob++;
        } else {
            cout << "Kompyuter yutdi!" << endl;
            kompyuterHisob++;
        }
    }
    cout << "O'yin tugadi! hisob: siz: " << hisob << ", kompyuter: " << kompyuterHisob << endl;

    return 0;
}