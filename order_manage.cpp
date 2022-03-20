#include "myLib.h"

//HATS

void hat_client() {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "| ID |   �������   |     ���     |    ��������   | ����� �������� |    ����� ��������    |" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
}

void hat_tour() {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "| ID |    �����    | ������������(���) | ��� ���������� | ��������� �� ������ |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
}

void hat_order() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "|   ID   |   ID    |  ID  |    ����     |  ���-��  |  ��� ����������  |    ���������        | ��������  |" << endl;
    cout << "| ������ | ������� | ���� | ����������� | �������  | (�� ������ ����) | ��������������� ($) | ��������� |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}


//CHECKS
bool client_check(Client& client, int ID) {
    bool num = false;

    ifstream file(file_clients);
    if (!file) {
        cerr << "������ ��� �������� �����!" << endl;
        return false;
    }

    while (file >> client.id >> client.surname >> client.name >> client.patronymin >> client.passport_number >> client.phone) {
        if (ID == client.id) {
            num = true;
            break;
        }
    }
    file.close();
    return num;
}


bool tour_check(Tour& tour, int ID) {
    bool num = false;
    string veh_type;
    Plane plane;
    Car car;
    Bus bus;

    ifstream file(file_tours);
    if (!file) {
        cerr << "������ ��� �������� �����!" << endl;
        return false;
    }

    while (file >> tour.id >> tour.city >> tour.duration >> veh_type >> tour.tour_cost_per_person) {
        if (veh_type == "�������") {
            tour.vehicle = &plane;
        }
        else if (veh_type == "����������") {
            tour.vehicle = &car;
        }
        else {
            tour.vehicle = &bus;
        }
        if (ID == tour.id) {
            num = true;
            break;
        }
    }
    file.close();
    return num;
}

//SHOW

void show_clients() {
    Client client;
    ifstream show(file_clients);
    if (!show) {
        cerr << "������ ��� �������� �����!" << endl;
        return;
    }
    cout << "\n";
    hat_client();
    while (show >> client.id >> client.surname >> client.name >> client.patronymin >> client.passport_number >> client.phone) {
        cout << "| " << setup << setw(2) << client.id << " | "
            << setw(11) << client.surname << " | "
            << setw(11) << client.name << " | "
            << setw(13) << client.patronymin << " | "
            << setw(14) << client.passport_number << " | "
            << setw(20) << client.phone << " | \n";
        cout << "------------------------------------------------------------------------------------------\n";
    }
    show.close();
}

void show_tours() {
    Tour tour;
    string veh_type;
    Plane plane;
    Car car;
    Bus bus;

    ifstream show(file_tours);
    if (!show) {
        cerr << "������ ��� �������� �����!" << endl;
        return;
    }
    cout << "\n";
    hat_tour();

    while (show >> tour.id >> tour.city >> tour.duration >> veh_type >> tour.tour_cost_per_person) {
        if (veh_type == "�������") {
            tour.vehicle = &plane;

        }
        else if (veh_type == "����������") {
            tour.vehicle = &car;
        }
        else {
            tour.vehicle = &bus;
        }
        cout << "| " << setup << setw(2) << tour.id << " | "
            << setw(11) << tour.city << " | "
            << setw(17) << tour.duration << " | "
            << setw(14) << tour.vehicle->get_type() << " | "
            << setw(19) << tour.tour_cost_per_person << " |\n";
        cout << "-------------------------------------------------------------------------------\n";
    }
    show.close();
}

//SETS

void set_date(Date& date) {
    bool flag;
    do {
        cout << "����: ";
        cin >> date.day;
        flag = check(date.day);
        if (flag && (date.day > 31)) {
            cerr << "�������� ����! ���������� ��� ���:)\n";
            flag = false;
        }
    } while (!flag);
    do {
        cout << "�����: ";
        cin >> date.month;
        flag = check(date.month);
        if (flag && (date.month > 12)) {
            cerr << "�������� �����! ���������� ��� ���:)\n";
            flag = false;
        }
    } while (!flag);
    do {
        cout << "���: ";
        cin >> date.year;
        flag = check(date.year);
        if (flag && (date.year < 2021 || date.year > 2023)) {
            cerr << "�������� ���, ���� ������� � 2021 �� 2023 ���! ���������� ��� ���:)\n";
            flag = false;
        }
    } while (!flag);
}


int id(fstream& file, const string name, int k) {
    string lines, veh_type;
    Order order;
    int n = 0, num = 0, i = 0;
    int* arr;

    file.open(name, ios::in);
    if (!file.is_open()) {
        cerr << "������ ��� �������� �����!" << endl;
        return 1;
    }
    while (getline(file, lines)) {
        n++;
    }
    file.close();
    arr = new int[n];

    file.open(name, ios::in);
    if (!file.is_open()) {
        cerr << "������ ��� �������� �����!" << endl;
        return 1;
    }
    for (i = 0; i < n; i++) {
        file >> order.id >> order.client.id >> order.tour.id >> order.departure_date.day >>
            order.departure_date.month >> order.departure_date.year >> order.number_of_people >>
            veh_type >> order.transportation_cost >> order.total_cost;
        arr[i] = order.id;
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


//MAIN FUNCTIONS

void show_orders() {
    Order order;
    string veh_type;
    Plane plane;
    Car car;
    Bus bus;

    ifstream show(file_orders);
    if (!show) {
        cerr << "\t������ ��� �������� �����!" << endl;
        return;
    }
    cout << "\n";
    cout << "������ � �������:\n";
    hat_order();

    while (show >> order.id >> order.client.id >> order.tour.id >>
        order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
        order.number_of_people >> veh_type >> order.transportation_cost >> order.total_cost) {
        if (veh_type == "�������") {
            order.vehicle = &plane;
        }
        else if (veh_type == "����������") {
            order.vehicle = &car;
        }
        else {
            order.vehicle = &bus;
        }
        cout << "| " << setup << setw(6) << order.id << " | "
            << setw(7) << order.client.id << " | " << setw(4) << order.tour.id << " | ";
        if (order.departure_date.day < 10)
            cout << "0" << order.departure_date.day;
        else
            cout << setw(2) << order.departure_date.day;
        cout << ".";
        if (order.departure_date.month < 10)
            cout << "0" << order.departure_date.month;
        else
            cout << setw(2) << order.departure_date.month;
        cout << "." << setw(4) << order.departure_date.year << "  | "
            << setw(8) << order.number_of_people << " | "
            << setw(16) << order.vehicle->get_type() << " | "
            << setw(19) << order.transportation_cost << " | "
            << setw(9) << order.total_cost << " |\n";
        cout << "---------------------------------------------------------------------------------------------------------\n";
    }
    show.close();
}

void add_order() {
    fstream file;
    bool flag, num;
    int ID;
    Plane plane;
    Bus bus;
    Car car;

    int size, choice;
    Order* arr = nullptr;

    do {
        cout << "\n���������� ����������� �������: ";
        cin >> size;
        flag = check(size);
    } while (!flag);

    arr = new Order[size];//������������ ��������� ������

    for (int i = 0; i < size; i++) {
        cout << "\n\t----------------------------------------\n";
        cout << "\t ���� ���������� � " << i + 1 << "-� ������\n";
        cout << "\t----------------------------------------\n";

        arr[i].id = id(file, file_orders, 1) + i;
        cout << "������ � ��������:";
        show_clients();
        Client client;

        while (true) {
            do {
                cout << "ID ������: ";
                cin >> ID;
                flag = check(ID);
            } while (!flag);
            num = client_check(client, ID);
            if (!num)
                cerr << "������� � ����� ID �� ����������!\n";
            else
                break;
        }
        arr[i].client = client;

        cout << "\n������ � �����:";
        show_tours();
        Tour tour;

        while (true) {
            do {
                cout << "ID ����: ";
                cin >> ID;
                flag = check(ID);
            } while (!flag);
            num = tour_check(tour, ID);
            if (!num)
                cerr << "���� � ����� ID �� ����������!\n";
            else
                break;
        }

        arr[i].tour = tour;

        Date date;
        cout << "\t------------------\n";
        cout << "\t ���� �����������\n";
        cout << "\t------------------\n";

        set_date(date);
        arr[i].departure_date = date;

        do {
            cout << "\n���������� �������: ";
            cin >> arr[i].number_of_people;
            flag = check(arr[i].number_of_people);
            if (flag && (arr[i].number_of_people > 5)) {
                cerr << "�� ������ ������� ����� �������� �� ����� 5 �������!\n";
                flag = false;
            }
        } while (!flag);

        bool fl = true;
        do {
            do {
                cout << "\n   ��� ���������� �� ����� �����������\n";
                cout << "1) �������\n";
                cout << "2) ����������\n";
                cout << "3) �������\n";
                cout << "   ��� �����: ";
                cin >> choice;
                flag = check(choice);
            } while (!flag);

            switch (choice) {
            case 1: {
                arr[i].vehicle = &plane;
                break;
            }
            case 2: {
                arr[i].vehicle = &car;
                break;
            }
            case 3: {
                arr[i].vehicle = &bus;
                break;
            }
            default: {
                if (flag) {
                    cout << "��������� �����!\n";
                    fl = false;
                }
                break;
            }
            }
        } while (!fl);

        arr[i].vehicle->find_the_transp_cost(arr[i]);//������������ �����������!
        cout << "\n��������� ���������������: " << arr[i].transportation_cost << " $ " << endl;
        arr[i].set_total_cost();
        cout << "�������� ��������� �������: " << arr[i].total_cost << " $ " << endl;
    }
    file.open(file_orders, ios::app);
    if (!file) {
        cerr << "������ ��� �������� �����!" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        file << setup << arr[i].id << "   " << arr[i].client.get_id() << "   " << arr[i].tour.get_id() << "   " <<
            arr[i].departure_date.day << "   " << arr[i].departure_date.month << "   " << arr[i].departure_date.year << "   "
            << arr[i].number_of_people << "   " << arr[i].vehicle->get_type() << "   " << arr[i].transportation_cost << "   " << arr[i].total_cost << endl;
    }
    file.close();

    delete[] arr;//�������� ���������� ��� ������ ������� ������

    cout << "  - ������ ������� ��������� -\n";
}


void edit_order() {
    Order order;
    Plane plane;
    Car car;
    Bus bus;
    Date date;
    Client cl;
    Tour tour;
    string veh_type, buf;

    int ID, a = 0, i, choice;
    bool flag, num, cost_changes = false;
    fstream file;

    show_orders();

    file.open(file_orders, ios::in);
    if (!file) {
        cerr << "������ ��� �������� �����!" << endl;
        return;
    }

    while (true) {
        for (i = 0; i < 3; i++) {
            cout << "������� ID �������������� ������: ";
            cin >> ID;
            flag = check(ID);
            if (flag)
                break;
        }
        if (i == 3) {
            cout << "  - ��� ���� ��������� ������� -" << endl;
            return;
        }
        while (file >> order.id >> order.client.id >> order.tour.id >>
            order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
            order.number_of_people >> veh_type >> order.transportation_cost >> order.total_cost) {
            tour_check(tour, order.tour.id);
            order.tour = tour;
            client_check(cl, order.client.id);
            order.client = cl;
            if (veh_type == "�������") {
                order.vehicle = &plane;
            }
            else if (veh_type == "����������") {
                order.vehicle = &car;
            }
            else {
                order.vehicle = &bus;
            }

            if (ID == order.id) {
                a = 1;
                switch (order_editing_menu()) {
                case 1: {
                    while (true) {
                        do {
                            cout << "\nID ������: ";
                            cin >> ID;
                            flag = check(ID);
                        } while (!flag);
                        num = client_check(cl, ID);
                        if (!num)
                            cerr << "������� � ����� ID �� ����������!\n";
                        else
                            break;
                    }
                    order.client = cl;
                    break;
                }
                case 2: {
                    while (true) {
                        do {
                            cout << "\nID ����: ";
                            cin >> ID;
                            flag = check(ID);
                        } while (!flag);
                        num = tour_check(tour, ID);
                        if (!num)
                            cerr << "���� � ����� ID �� ����������!\n";
                        else
                            break;
                    }
                    order.tour = tour;
                    cost_changes = true;
                    break;
                }
                case 3: {
                    set_date(date);
                    order.departure_date = date;
                    break;
                }
                case 4: {
                    do {
                        cout << "\n���-�� �������: ";
                        cin >> order.number_of_people;
                        flag = check(order.number_of_people);
                    } while (!flag);
                    cost_changes = true;
                    break;
                }
                case 5: {
                    bool fl = true;
                    do {
                        do {
                            cout << "\n   ��� ����������\n";
                            cout << "1) �������\n";
                            cout << "2) ����������\n";
                            cout << "3) �������\n";
                            cout << " ��� �����: ";
                            cin >> choice;
                            flag = check(choice);
                        } while (!flag);

                        switch (choice) {
                        case 1: {
                            order.vehicle = &plane;
                            break;
                        }
                        case 2: {
                            order.vehicle = &car;
                            break;
                        }
                        case 3: {
                            order.vehicle = &bus;
                            break;
                        }
                        default: {
                            if (flag) {
                                cout << "��������� �����!\n";
                                fl = false;
                            }
                            break;
                        }
                        }
                    } while (!fl);

                    cost_changes = true;
                    break;
                }
                case 6: {
                    return;
                }
                default: {
                    cout << "\n��������� �����!\n";
                    return;
                }
                }
                if (cost_changes) {
                    order.vehicle->find_the_transp_cost(order);
                    cout << "���������� ��������� ���������������: " << setup << order.transportation_cost << " $ " << endl;
                    order.set_total_cost();
                    cout << "���������� �������� ���������: " << setup << order.total_cost << " $ " << endl;
                }
            }

            buf += to_string(order.id) + "   " + to_string(order.client.id) + "   " + to_string(order.tour.id) + "   " + to_string(order.departure_date.day) + "   "
                + to_string(order.departure_date.month) + "   " + to_string(order.departure_date.year) + "   " + to_string(order.number_of_people) + "   "
                + order.vehicle->get_type() + "   " + point(order.transportation_cost) + "   " + point(order.total_cost) + "\n";
        }
        file.close();

        if (a == 0) {
            cout << "������ � ����� ID �� ����������!\n";
            buf = "";
            file.close();
            file.open(file_orders, ios::in);
            if (!file) {
                cerr << "������ ��� �������� �����!" << endl;
                return;
            }
        }
        else {
            file.open(file_orders, ios::out);
            file << buf;
            file.close();
            break;
        }
    }
}

void delete_order() {
    show_orders();
    Order order;
    Plane plane;
    Car car;
    Bus bus;
    string buf, veh_type;
    int ID, a = 0, i, flag;
    fstream file(file_orders, ios::in | ios::out);
    while (true) {
        for (i = 0; i < 3; i++) {
            cout << "������� ID ������: ";
            cin >> ID;
            flag = check(ID);
            if (flag)
                break;
        }
        if (i == 3) {
            cout << "  - ��� ���� ��������� ������� -" << endl;
            return;
        }
        while (file >> order.id >> order.client.id >> order.tour.id >>
            order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
            order.number_of_people >> veh_type >> order.transportation_cost >> order.total_cost) {
            if (veh_type == "�������") {
                order.vehicle = &plane;
            }
            else if (veh_type == "����������") {
                order.vehicle = &car;
            }
            else {
                order.vehicle = &bus;
            }
            if (ID == order.id) {
                a = 1;
            }
            else
                buf += to_string(order.id) + "   " + to_string(order.client.id) + "   " + to_string(order.tour.id) + "   " + to_string(order.departure_date.day) + "   "
                + to_string(order.departure_date.month) + "   " + to_string(order.departure_date.year) + "   " + to_string(order.number_of_people) + "   "
                + order.vehicle->get_type() + "   " + point(order.transportation_cost) + "   " + point(order.total_cost) + "\n";
        }
        if (a == 0) {
            cout << "������ � ����� ID �� ����������!\n";
            buf = "";
            file.close();
            file.open(file_orders, ios::in);
        }
        else
            break;
    }
    file.close();

    file.open(file_orders, ios::out);
    file << buf;
    file.close();
    cout << "----------------------\n";
    cout << "����� � ID " << ID << " ��� ������� ������" << endl;
}

