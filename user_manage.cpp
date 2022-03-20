#include "myLib.h"

void hat_user() {
    cout << "------------------------------------------------------------" << endl;
    cout << "|   ID   |       Login       |         Password            |" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void add_user() {
    fstream file;
    int fl;
    int i = 0, Id;
    string p, l;
    cout << "\n";
    for (; i < 3; i++) {
        cout << "Логин: ";
        cin >> l;
        fl = password_check(l);
        if (fl)
            break;
    }
    if (i == 3) {
        cout << "     - Это была последняя попытка -" << endl;
        return;
    }
    encryption(l, 1);
    for (i = 0; i < 3; i++) {
        cout << "Пароль: ";
        cin >> p;
        fl = password_check(p);
        if (fl)
            break;
    }
    if (i == 3) {
        cout << "     - Это была последняя попытка -" << endl;
        return;
    }
    encryption(p, 1);
    Id = id(file, file_users);
    User user(Id, l, p);
    file.open(file_users, ios::app);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }
    file << user.get_id() << "   " << user.get_login() << "   " << user.get_password() << endl;
    file.close();
    cout << "----------------------\n";
    cout << "Новый пользователь был успешно добавлен" << endl;
}


void edit_user() {

    show_user();
    string buf, log, pas;
    int ID, Id, a = 0, i, fl;
    string l, p;
    fstream file;
    file.open(file_users, ios::in);
    if (!file) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }
 
    while (true) {
        for (i = 0; i < 3; i++) {
            cout << "Введите ID редактируемого пользователя: ";
            cin >> ID;
            fl = check(ID);
            if (fl)
                break;
        }
        if (i == 3) {
            cout << "     - Это была последняя попытка -" << endl;
            return;
        }
        while (file >> Id >> l >> p) {
            User user(Id, l, p);
            if (ID == user.get_id()) {
                a = 1;
                switch (user_editing_menu()) {
                case 1: {
                    for (i = 0; i < 3; i++) {
                        cout << "\nЛогин: ";
                        cin >> log;
                        fl = password_check(log);
                        if (fl)
                            break;
                    }
                    if (i == 3) {
                        cout << "     - Это была последняя попытка -" << endl;
                        return;
                    }
                    encryption(log, 1);
                    user.set_login(log);
                    break;
                }
                case 2: {
                    for (i = 0; i < 3; i++) {
                        cout << "\nПароль: ";
                        cin >> pas;
                        fl = password_check(pas);
                        if (fl)
                            break;
                    }
                    if (i == 3) {
                        cout << "     - Это была последняя попытка -" << endl;
                        return;
                    }
                    encryption(pas, 1);
                    user.set_password(pas);
                    break;
                }
                case 3: {
                    return;
                }
                default: {
                    cout << "Ошибочный выбор\n";
                }
                }
            }
            buf += to_string(user.get_id()) + "   " + user.get_login() + "   " + user.get_password() + "\n";
        }
        file.close();

        if (a == 0) {
            cout << "Пользователя с таким ID не существует!\n";
            buf = "";
            file.close();
            file.open(file_users, ios::in);
            if (!file) {
                cerr << "Ошибка при открытии файла!" << endl;
                return;
            }
        }
        else {
            file.open(file_users, ios::out);
            file << buf;
            file.close();
            break;
        }
    }
    cout << "----------------------\n";
    cout << "Пользователь с ID " << ID << " был успешно отредактирован" << endl;
}


void delete_user() {
    show_user();
    string buf;
    int Id, ID, a = 0, i, fl;
    string l, p;
    fstream file(file_users, ios::in | ios::out);
    while (true) {
        for (i = 0; i < 3; i++) {
            cout << "Введите ID пользователя: ";
            cin >> ID;
            fl = check(ID);
            if (fl)
                break;
        }
        if (i == 3) {
            cout << "     - Это была последняя попытка -" << endl;
            return;
        }
        while (file >> Id >> l >> p) {
            User user(Id, l, p);
            if (ID == user.get_id()) {
                a = 1;
            }
            else
                buf += to_string(user.get_id()) + "   " + user.get_login() + "   " + user.get_password() + "\n";
        }
        if (a == 0) {
            cout << "Пользователя с таким ID не существует!\n";
            buf = "";
            file.close();
            file.open(file_users, ios::in);
        }
        else
            break;
    }
    file.close();

    file.open(file_users, ios::out);
    file << buf;
    file.close();
    cout << "----------------------\n";
    cout << "Пользователь с ID " << ID << " был успешно удален" << endl;
}


void show_user() {
    int Id;
    string l, p;
    ifstream show(file_users);
    if (!show) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }
    cout << "\n";
    hat_user();
    while (show >> Id >> l >> p) {
        encryption(l, 2);
        encryption(p, 2);
        User user(Id, l, p);
        cout << "| " << setup << setw(6) << user.get_id() << " | " << setw(17) 
            << user.get_login() << " | " << setw(27) << user.get_password() << " | \n";
        cout << "------------------------------------------------------------\n";
    }
    show.close();
}

int id(fstream& file, const string name) {
    string lin, l, p;
    int id, n = 0, num = 0, i = 0;
    int* arr;

    file.open(name, ios::in);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return 1;
    }
    while (getline(file, lin)) {
        n++;
    }
    file.close();
    arr = new int[n];

    file.open(name, ios::in);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return 1;
    }
    for (i = 0; i < n; i++) {
        file >> id >> l >> p;
        arr[i] = id;
    }

    file.close();

    shell(arr, n);

    for (i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            num = i + 1;
            break;
        }
    }
    if (!num)
        num = n + 1;
    delete[] arr;
    return num;
}

