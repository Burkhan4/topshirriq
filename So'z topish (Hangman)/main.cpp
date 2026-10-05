#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU_RU.UTF-8");
    string sozlar[36] = {"robot", "daraxt", "osmon", "kalit", "davlat", "kitob", "quyosh", "daryo", "shahar", "qalam", "oyna", "telefon", "gul", "yulduz", "mashina", "xona", "eshik", "suv", "daftar", "samolyot", "tog'", "soat", "ko'cha", "dengiz", "chiroq", "shamol", "mushuk", "yomg'ir", "stol", "olma", "uy", "non", "bolg'a", "qush", "yo'l"};
    srand(time(NULL));
    int tasodifiy = 1 + rand() % 35;
    string oylangan_soz = sozlar[tasodifiy];
    cout << "\nSo'z topish o'yiniga hush kelibsiz!\nO'ylangan so'zni toping" << endl;
    int leng = oylangan_soz.length();
    string Foydalanuvchi(leng, '_');
    cout << "Oylangan so'zning uzunligi: " << leng;
    int son;
    char harif;
    int loose = 0;
    while (true)
    {
        cout << endl << Foydalanuvchi << endl;
        cout << "Biror harif kiriting(kichik harif): ";
        cin >> harif;
        son = 0;
        for(int i = 0; i < leng; i++) {

            if(harif == oylangan_soz[i]) {
                Foydalanuvchi[i] = harif;
                son++;
            }
        }
        if (son > 0) {
            cout << "Bu harifdan " << son << " ta bor!";
        }
        else {
            cout << "Bu harf yo'q!";
            loose++;
        }
        if (Foydalanuvchi == oylangan_soz) {
            cout << "\n\nTabriklaymiz siz '" << Foydalanuvchi << "' so'zni topdingiz!";
            break;
        }
        else if(loose >= leng * 2) {
            cout << "\nSIZ YUTQAZDIZ!\n";
            break;
        }
    }
    

    return 0;
}