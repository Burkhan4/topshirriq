#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU_RU.UTF-8");

    string isimlar[400] = {"Ahmad", "Abdulla", "Ahror"};
    int Baho[400] = {4, 5, 5};
    int choise;
    int count = 3;

    while (true) {
        cout << "\n\no'quvchilar va ularning baholarini ko'rsh uchun (1)\nO'quvchi qo'shish uchun (2)\nO'quvchi qidirish uchun (3) \nO'rtacha, eng yuqori va eng past bahoni bilish uchun (4)\n Programmani tugatish uchun (5) ni kiriting: " ;
        cin >> choise;
        if(choise == 1) {
            cout << "O'quvchi        Baho\n";
            for(int i = 0; i < count; i++) {
                cout << isimlar[i] << "            " << Baho[i] << endl;
            }
        } 
        else if (choise == 2)
        {
            cout << "\nO'quvchi ishmini kiriting: ";
            cin >> isimlar[count];
            cout << "O'quvchi bahosini kiriting: ";
            cin >> Baho[count];
            count++;
        }
        else if(choise == 3) {
            int choise2;
            cout << "\nO'qivchi ismi bo'yicha qidirish uchun (1)\nO'quvchini bahosi bo'yicha qidirish uchun (2) ni kiriting: ";
            cin >> choise2;
            if(choise2 == 1) {
                string isim;
                cout << "\nO'quvchini ismini kiritig: ";
                cin >> isim;
                for(int i = 0; i < count; i++) {
                    if(isim == isimlar[i]) {
                        cout << "\nO'quvchi ismi: " << isim << "\nO'quvchining bahosi: " << Baho[i] << "\nO'quvchinig jurnaldagi o'rni: " << i+1 << endl;
                    }
                }
            }
            else if(choise2 == 2) {
                int bahosi;
                cout << "O'quvchini bahosini kiriting: ";
                cin >> bahosi;
                for(int i = 0; i < count; i++) {
                    if(bahosi == Baho[i]) {
                        cout << "\nO'quvchi ismi: " << isimlar[i] << "\nO'quvchining bahosi: " << Baho[i] << "\nO'quvchinig jurnaldagi o'rni: " << i+1 << endl;
                    }
                }
            }

        }
        else if(choise == 4) {
            int summa = 0;
            int kichik = Baho[0];
            int katta = Baho[0];
            for(int i = 0; i < count; i++) {
                summa += Baho[i];
                if(kichik > Baho[i]) {
                    kichik = Baho[i];
                }
                if(katta < Baho[i]) {
                    katta = Baho[i];
                }
            }
            float ortacha = (float)summa / count;
            cout << "\nO'rtacha baho: " << ortacha << "\nEng kichik baho: " << kichik << "\nEng katta baho: " << katta << endl;
        }
        else if(choise == 5) {
            break;
        }
        

    }
}