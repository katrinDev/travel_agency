#include "myLib.h"

void Main_menu() {
    int choice;
    bool flag;
    while (true) {
        system("cls");

        cout << "\n\n";
        cout << "\t\t   ������� ����" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * \n\n";
        cout << "\t1. ��������\n";//���� � �������� ��������� ��������
        cout << "\t2. ��������\n";//���� � �������� ��������� 
        cout << "\t3. �����\n" << endl;
        do{
            cout << "\t   ��� �����: ";
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
                    cout << "\t   ��������� �����!\n";
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
        cout << "\t    ���� ���������\n";
        cout << "* * * * * * * * * * * * * * * * * *\n";
        cout << "1. ����������� ������ � ��������� �����\n";
        cout << "2. ���������� ������ � �������\n";
        cout << "3. ���������� ������ � �������\n";
        cout << "4. ����� ������ �� ���������� ������\n";
        cout << "5. ������� �������� �������������� ���\n";//������
        cout << "6. ���������� ��������������\n";
        cout << "7. ��������� ����� �� ���������\n";
        cout << "8. ��������� ������\n\n";
        do {
            cout << "   ��� �����: ";
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
                cout << "   ��������� �����!\n";
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
        cout << "\t     ���� ���������\n";
        cout << "* * * * * * * * * * * * * * * * * * *\n";
        cout << "1. ����������� ������ � ��������� �����\n";
        cout << "2. ���������� ������ � �������\n";
        cout << "3. ���������� ������ � �������\n";
        cout << "4. ����� ������ �� ���������� ������\n";
        cout << "5. �������� �����\n";
        cout << "6. ������� �����\n";
        cout << "7. ������������� �����\n";
        cout << "8. ��������� ������\n";

        do {
            cout << "   ��� �����: ";
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
                cout << "   ��������� �����!\n";
            break;
        }
        }
    }
}


void user_manage_menu() {
    int choice, flag;

    while (true) {
        cout << "\n\n";
        cout << "\t���� ���������� ��������������" << endl;
        cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "1. �������� ������������" << endl;
        cout << "2. ������������� ���������������� ������" << endl;
        cout << "3. ������� ������������" << endl;
        cout << "4. ����������� ������ � ��������� �����" << endl;
        cout << "5. ����� � ���� ��������������\n" << endl;
        do {
            cout << "   ��� �����: ";
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
                cout << "   ��������� �����!\n";
            break;
        }
        }
    }
}

int user_editing_menu() {
    int choice, flag;

    cout << "\n";
    cout << "\t���� �������������� ������ ������������" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "1. �����" << endl;
    cout << "2. ������" << endl;
    cout << "3. ����� � ���� ���������� ��������������\n" << endl;
    do {
        cout << "   ��� �����: ";
        cin >> choice;
        flag = check(choice);
    } while (!flag);

    return choice;
}

int order_editing_menu() {
    int choice, flag;

    cout << "\n";
    cout << "\t���� �������������� ������ � ������" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "1. ������" << endl;
    cout << "2. ���" << endl;
    cout << "3. ���� �����������" << endl;
    cout << "4. ���-�� �������" << endl;
    cout << "5. ��� ����������" << endl;
    cout << "6. ����� � ���� ���������\n" << endl;
    do {
        cout << "   ��� �����: ";
        cin >> choice;
        flag = check(choice);
    } while (!flag);

    return choice;
}


void sort_menu() {

    cout << "\n\n";
    cout << "\t     ���� ����������" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "1. �� ID ��������" << endl;
    cout << "2. �� ID �����" << endl;
    cout << "3. �� ���������� �������" << endl;
    cout << "4. �� ����� ���������" << endl;
    cout << "5. ����� � ����������� ����\n";
    cout << "   ��� �����: ";
}

void filt_menu() {
    cout << "\n\n";
    cout << "\t     ���� ����������" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "1. �� ID ��������" << endl;
    cout << "2. �� ID �����" << endl;
    cout << "3. �� ���������� �������" << endl;
    cout << "4. ����� � ����������� ����\n";
    cout << "   ��� �����: ";
}

void search_menu() {
    cout << "\n\n";
    cout << "\t     ���� ������" << endl;
    cout << "   - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "1. �� ID ��������" << endl;
    cout << "2. �� ID �����" << endl;
    cout << "3. �� ���������� �������" << endl;
    cout << "4. �� ���� ����������" << endl;
    cout << "5. ����� � ����������� ����\n";
    cout << "   ��� �����: ";
}


