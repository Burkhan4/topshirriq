#include <iostream>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

const int MAX_ITEMS = 50;

void showProducts(const Product items[], int count) {
    if (count == 0) {
        cout << "\nSklad bo'sh!\n";
        return;
    }

    cout << "\n================= SKLADDAGI TOVARLAR ================\n";
    cout << "ID\tNomi\t\tNarhi\t\tSoni\n";
    cout << "---------------------------------------------------\n";
    
    for (int i = 0; i < count; i++) {
        cout << items[i].id << "\t" 
             << items[i].name << "\t\t" 
             << items[i].price << " som\t" 
             << items[i].quantity << " ta.\n";
    }
    cout << "===================================================\n";
}

void searchProduct(const Product items[], int count) {
    if (count == 0) {
        cout << "\nSklad bo'sh.\n";
        return;
    }

    cout << "\nTovarni nomini kiriting: ";
    string searchName;
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (items[i].name == searchName) {
            cout << "\nTovar topildi!\n";
            cout << "ID: " << items[i].id << "\n";
            cout << "Nomi: " << items[i].name << "\n";
            cout << "Narhi: " << items[i].price << " сум\n";
            cout << "Qolgani: " << items[i].quantity << " шт.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nBu nomli tovar \"" << searchName << "\" topilmadi.\n";
    }
}

void addProduct(Product items[], int &count) {
    if (count >= MAX_ITEMS) {
        cout << "\nSklad to'lgan boshqa tovar sig'maydi.\n";
        return;
    }

    Product newProduct;
    newProduct.id = count + 1;

    cout << "\nTovdarni nomini kiriting(bitta so'z): ";
    cin >> newProduct.name;

    cout << "Narhini kiriting: ";
    cin >> newProduct.price;

    cout << "Boshlang'ich sonini kiriting: ";
    cin >> newProduct.quantity;

    items[count] = newProduct;
    count++;

    cout << "\nTovar qo'shildi!\n";
}

void sellProduct(Product items[], int count) {
    if (count == 0) {
        cout << "\nSklad bo'sh!\n";
        return;
    }

    cout << "\nTovarni ID sini kiriting: ";
    int targetId;
    cin >> targetId;

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (items[i].id == targetId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "\nBunday ID lik tovar yo'q.\n";
        return;
    }

    cout << "Tanlangan tovar: " << items[foundIndex].name 
         << " (Hozir: " << items[foundIndex].quantity << " ta bor.)\n";
    cout << "Nechta sotiladi?: ";
    int amount;
    cin >> amount;

    if (amount <= 0) {
        cout << "Son 0 dan katta bo'lishi shart!\n";
    } else if (amount > items[foundIndex].quantity) {
        cout << "Skladda buncha tovar yo'q!\n";
    } else {
        items[foundIndex].quantity -= amount;
        double totalPrice = amount * items[foundIndex].price;
        cout << "\nSotuv amalga oshirildi!\n";
        cout << "To'lov: " << totalPrice << " som\n";
        cout << "Skladda: " << items[foundIndex].quantity << " ta qoldi.\n";
    }
}

int main() {
    Product warehouse[MAX_ITEMS];
    int productCount = 0;

    warehouse[0] = {1, "Arduino_Uno", 120000, 10};
    warehouse[1] = {2, "Motor_L298N", 45000, 15};
    productCount = 2;

    int choice;

    do {
        cout << "\n========= Robototexnika sklad menyusi =========\n";
        cout << "1. Hamma tovarlarni ko'rsatish\n";
        cout << "2. Yangi tovar qo'shish\n";
        cout << "3. Tovarni nomi bo'yicha topish\n";
        cout << "4. Sotish\n";
        cout << "0. Chiqish\n";
        cout << "Tanlovingizni kiriting: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showProducts(warehouse, productCount);
                break;
            case 2:
                addProduct(warehouse, productCount);
                break;
            case 3:
                searchProduct(warehouse, productCount);
                break;
            case 4:
                sellProduct(warehouse, productCount);
                break;
            case 0:
                cout << "\nProgramma to'xtadi. Hayir!\n";
                break;
            default:
                cout << "\nMenyuda bunaqa narsa yo'q.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}