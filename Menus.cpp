#include "myLib.h"

void Main_menu() {
    int choice;
    bool flag;
    while (true) {
        system("cls");

        cout << "\n\n";
        cout << "\t\t   Главное меню" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * \n\n";
        cout << "\t1. Директор\n";//вход в качестве директора турфирмы
        cout << "\t2. Менеджер\n";//вход в качестве менеджера 
        cout << "\t3. Выход\n" << endl;
        do{
            cout << "\t   Ваш выбор: ";
            cin >> choice;
            flag = check(choice);
        } while (!flag);

        switch (choice) {
            case 1: {
                Authentication(1);
                break;
            }
            case 2: {
                Authentication(2);
                break;
            }
            case 3: {
                return;
            }
            default: {
                if (flag)
                    cout << "\t   Ошибочный выбор!\n";
                break;
            }
        }
    }
}


void admin_menu() {
    int choice;
    bool flag;

    while (true) {
        cout << "\n";
        cout << "\t    Меню директора\n";
        cout << "* * * * * * * * * * * * * * * * * *\n";
        cout << "1. Просмотреть данные в табличной форме\n";
        cout << "2. Фильтрация данных о заказах\n";
        cout << "3. Сортировка данных о заказах\n";
        cout << "4. Поиск заказа по конкретным данным\n";
        cout << "5. Вывести наиболее востребованный тур\n";//задача
        cout << "6. Управление пользователями\n";
        cout << "7. Сравнение туров по стоимости\n";
        cout << "8. Завершить работу\n\n";
        do {
            cout << "   Ваш выбор: ";
            cin >> choice;
            flag = check(choice);
        } while (!flag);

        ifstream main_file;
        switch (choice) {
        case 1: {
            show_orders();
            break;
        }
        case 2: {
            filtration();
            break;
        }
        case 3: {
            sort();
            break;
        }
        case 4: {
            search();
            break;
        }
        case 5: {
            task();
            break;
        }
        case 6: {
            user_manage_menu();
            break;
        }
        case 7: {
            compare_tours();
            break;
        }
        case 8: {
            return;
        }
        default: {
            if (flag)
                cout << "   Ошибочный выбор!\n";
            break;
        }
        }
    }
}

void manager_menu() {
    int choice, flag;
    ifstream us_file;

    while (true) {
        cout << "\n\n";
        cout << "\t     Меню менеджера\n";
        cout << "* * * * * * * * * * * * * * * * * * *\n";
        cout << "1. Просмотреть данные в табличной форме\n";
        cout << "2. Фильтрация данных о заказах\n";
        cout << "3. Сортировка данных о заказах\n";
        cout << "4. Поиск заказа по конкретным данным\n";
        cout << "5. Добавить заказ\n";
        cout << "6. Удалить заказ\n";
        cout << "7. Редактировать заказ\n";
        cout << "8. Завершить работу\n";

        do {
            cout << "   Ваш выбор: ";
            cin >> choice;
            flag = check(choice);
        } while (!flag);

        switch (choice) {
        case 1: {
            show_orders();
            break;
        }
        case 2: {
            filtration();
            break;
        }
        case 3: {
            sort();
            break;
        }
        case 4: {
            search();
            break;
        }
        case 5: {
            add_order();
            break;
        }
        case 6: {
            delete_order();
            break;
        }
        case 7: {
            edit_order();
            break;
        }
        case 8: {
            return;
        }
        default: {
            if (flag)
                cout << "   Ошибочный выбор!\n";
            break;
        }
        }
    }
}


void user_manage_menu() {
    int choice, flag;

    while (true) {
        cout << "\n\n";
        cout << "\tМеню управления пользователями" << endl;
        cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "1. Добавить пользователя" << endl;
        cout << "2. Редактировать пользовательские данные" << endl;
        cout << "3. Удалить пользователя" << endl;
        cout << "4. Просмотреть данные в табличной форме" << endl;
        cout << "5. Выход в меню администратора\n" << endl;
        do {
            cout << "   Ваш выбор: ";
            cin >> choice;
            flag = check(choice);
        } while (!flag);

        switch (choice) {
        case 1: {
            add_user();
            break;
        }
        case 2: {
            edit_user();
            break;
        }
        case 3: {
            delete_user();
            break;
        }
        case 4: {
            show_user();
            break;
        }
        case 5: {
            return;
        }
        default: {
            if (flag)
                cout << "   Ошибочный выбор!\n";
            break;
        }
        }
    }
}

int user_editing_menu() {
    int choice, flag;

    cout << "\n";
    cout << "\tМеню редактирования данных пользователя" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "1. Логин" << endl;
    cout << "2. Пароль" << endl;
    cout << "3. Выход к меню управления пользователями\n" << endl;
    do {
        cout << "   Ваш выбор: ";
        cin >> choice;
        flag = check(choice);
    } while (!flag);

    return choice;
}

int order_editing_menu() {
    int choice, flag;

    cout << "\n";
    cout << "\tМеню редактирования данных о заказе" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "1. Клиент" << endl;
    cout << "2. Тур" << endl;
    cout << "3. Дата отправления" << endl;
    cout << "4. Кол-во человек" << endl;
    cout << "5. Тип транспорта" << endl;
    cout << "6. Выход к меню менеджера\n" << endl;
    do {
        cout << "   Ваш выбор: ";
        cin >> choice;
        flag = check(choice);
    } while (!flag);

    return choice;
}


void sort_menu() {

    cout << "\n\n";
    cout << "\t     Меню сортировки" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "1. По ID клиентов" << endl;
    cout << "2. По ID туров" << endl;
    cout << "3. По количеству человек" << endl;
    cout << "4. По общей стоимости" << endl;
    cout << "5. Выход к предыдущему меню\n";
    cout << "   Ваш выбор: ";
}

void filt_menu() {
    cout << "\n\n";
    cout << "\t     Меню фильтрации" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "1. По ID клиентов" << endl;
    cout << "2. По ID туров" << endl;
    cout << "3. По количеству человек" << endl;
    cout << "4. Выход к предыдущему меню\n";
    cout << "   Ваш выбор: ";
}

void search_menu() {
    cout << "\n\n";
    cout << "\t     Меню поиска" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "1. По ID клиентов" << endl;
    cout << "2. По ID туров" << endl;
    cout << "3. По количеству человек" << endl;
    cout << "4. По типу транспорта" << endl;
    cout << "5. Выход к предыдущему меню\n";
    cout << "   Ваш выбор: ";
}


