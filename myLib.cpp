#include "myLib.h"

void show_order(Order &order) {
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

void sort() {
    Order order;
    Plane plane;
    Car car;
    Bus bus;
    ifstream file;
    string lines, veh_type;
    int n = 0;
    bool flag = false;

    file.open(file_orders);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }
    while (getline(file, lines)) {
        n++;
    }
    file.close();

    int* arr = new int[n];
    float* arr_f = new float[n];
    int i, choice, * element = nullptr, int_repeat_check;
    float* element_f = nullptr, float_repeat_check;

    while (true) {
        i = 0, int_repeat_check = -1, float_repeat_check = -1;
        sort_menu();
        cin >> choice;
        flag = check(choice);

        switch (choice) {
        case 1: {
            element = &order.client.id;
            break;
        }
        case 2: {
            element = &order.tour.id;
            break;
        }
        case 3: {
            element = &order.number_of_people;
            break;
        }
        case 4: {
            element_f = &order.total_cost;
            break;
        }
        case 5: {
            return;
        }
        default: {
            if (flag) {
                cout << "Ошибочный выбор!\n";
            }
            break;
        }
        }

        file.open(file_orders);
        if (!file.is_open()) {
            cerr << "Ошибка при открытии файла!" << endl;
            return;
        }
        while (file >> order.id >> order.client.id >> order.tour.id >>
            order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
            order.number_of_people >> veh_type >> order.transportation_cost >> order.total_cost) {
            if (choice == 4)
                arr_f[i] = *element_f;
            else
                arr[i] = *element;
            i++;
        }
        file.close();

        if (choice == 4)
            shell(arr_f, n);
        else
            shell(arr, n);

        hat_order();

        file.open(file_orders);
        if (!file.is_open()) {
            cerr << "Ошибка при открытии файла!" << endl;
            return;
        }
        for (i = 0; i < n; i++) {
            if (choice == 4) {
                if (arr_f[i] == float_repeat_check) {
                    while (arr_f[i] == float_repeat_check)
                        i++;
                }
            }
            else {
                if (arr[i] == int_repeat_check) {
                    while (arr[i] == int_repeat_check)
                        i++;
                }
            }
            while (file >> order.id >> order.client.id >> order.tour.id >>
                order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
                order.number_of_people >> veh_type >> order.transportation_cost >> order.total_cost) {
                if (veh_type == "Самолет") {
                    order.vehicle = &plane;
                }
                else if (veh_type == "Автомобиль") {
                    order.vehicle = &car;
                }
                else {
                    order.vehicle = &bus;
                }
                if ((choice == 4 && *element_f == arr_f[i]) || (choice != 4 && *element == arr[i])) {
                    show_order(order);
                }
            }
            int_repeat_check = arr[i];
            float_repeat_check = arr_f[i];
            file.close();
            file.open(file_orders);
            if (!file.is_open()) {
                cerr << "Ошибка при открытии файла!" << endl;
                return;
            }
        }
        file.close();
    }
    delete[] arr;
    delete[] arr_f;
}

void search() {
    Order order;
    Plane plane;
    Car car;
    Bus bus;
    ifstream file;
    int  I, a, choice, * element = nullptr, vehicle_number;
    bool flag, fl;
    string* element_s = nullptr, veh, veh_type;
    a = 1;
    while (true) {
        if (a == 1) {
            search_menu();
            cin >> choice;
        }
        fl = false;
        a = 0;
        flag = check(choice);

        switch (choice) {
        case 1: {
            cout << "\n";
            do{
                cout << "Введите ID клиента: ";
                cin >> I;
                flag =check(I);
            } while (!flag);

            element = &order.client.id;
            break;
        }
        case 2: {
            cout << "\n";
            do{
                cout << "Введите ID тура: ";
                cin >> I;
                flag = check(I);
            } while (!flag);
            element = &order.tour.id;
            break;
        }
        case 3: {
            cout << "\n";
            do{
                cout << "Введите количество человек: ";
                cin >> I;
                flag = check(I);
            } while (!flag);
            element = &order.number_of_people;
            break;
        }
        case 4: {
            cout << "\n";
            do{
                cout << "Введите тип транспортного средства(1.Самолет 2.Автомобиль 3.Автобус): ";
                cin >> vehicle_number;
                flag = check(vehicle_number);
            } while (!flag);
            switch (vehicle_number) {
            case 1: {
                veh_type = "Самолет";
                break;
            }
            case 2: {
                veh_type = "Автомобиль";
                break;
            }
            case 3: {
                veh_type = "Автобус";
                break;
            }
            default: {
                cout << "Ошибочный ввод!\n";
                break;
            }
            }
            break;
        }
        case 5: {
            return;
        }
        default: {
            fl = 1;
            if (flag)
                cout << "Ошибочный выбоор!\n";
            break;
        }
        }

        if (!fl) {
            file.open(file_orders);
            if (!file.is_open()) {
                cerr << "Ошибка при открытии файла!" << endl;
                return;
            }
            while (file >> order.id >> order.client.id >> order.tour.id >>
                order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
                order.number_of_people >> veh >> order.transportation_cost >> order.total_cost) {
                if (veh == "Самолет") {
                    order.vehicle = &plane;
                }
                else if (veh == "Автомобиль") {
                    order.vehicle = &car;
                }
                else {
                    order.vehicle = &bus;
                }
                if ((choice == 4 && order.vehicle->get_type() == veh_type) || (choice != 4 && *element == I)) {
                    a = 1;
                }
            }
            file.close();

            if (a == 0) {
                switch (choice) {
                case 1: {
                    cout << "В заказах нет клиента с таким ID!" << endl;
                    break;
                }
                case 2: {
                    cout << "В заказах нет тура с таким ID!" << endl;
                    break;
                }
                case 3: {
                    cout << "Нет заказа с таким количеством человек!" << endl;
                    break;
                }
                case 4: {
                    cout << "Заказа с таким типом транспорта нет!" << endl;
                    break;
                }
                default: {
                    cout << "Ошибочный выбор!\n";
                    break;
                }
                }
            }
            else {
                hat_order();
                file.open(file_orders);
                if (!file.is_open()) {
                    cerr << "Ошибка при открытии файла!" << endl;
                    return;
                }
                while (file >> order.id >> order.client.id >> order.tour.id >>
                    order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
                    order.number_of_people >> veh >> order.transportation_cost >> order.total_cost) {
                    if (veh == "Самолет") {
                        order.vehicle = &plane;
                    }
                    else if (veh == "Автомобиль") {
                        order.vehicle = &car;
                    }
                    else {
                        order.vehicle = &bus;
                    }
                    if ((choice == 4 && order.vehicle->get_type() == veh_type) || (choice != 4 && *element == I)){
                        show_order(order);
                    }
                }
                file.close();
            }
        }
    }
}

void Authentication(int num) {
    cout << "\n\n\t\t   Авторизация" << endl;
    cout << "\t* * * * * * * * * * * * * * * * * *" << endl;
   
    ifstream auth(file_users);
    int i = 0, j = 0, h, fl, Id;
    string l, p, log, pass;

    if (!auth) {
        cout << "\tОшибка при открытии файла!" << endl;
        return;
    }

    if (num == 1) {
        auth >> Id >> l >> p;
        auth.close();
   
        encryption(l, 2);
        encryption(p, 2);
        User user(Id, l, p);

        for (; i < 3; i++) {
            for (h = 0; h < 3; h++) {
                cout << "\tВведите логин: ";
                cin >> log;
                fl = password_check(log);
                if (fl)
                    break;
            }
            if (h == 3) {
                cerr << "\t  - Это была последняя попытка -" << endl;
                return;
            }
            if (user.get_login() == log) {
                for (; j < 3; j++) {
                    for (h = 0; h < 3; ++h) {
                        cout << "\tВведите пароль: ";
                        cin >> pass;
                        fl = password_check(pass);
                        if (fl)
                            break;
                    }
                    if (h == 3) {
                        cerr << "\t  - Это была последняя попытка -" << endl;
                        return;
                    }
                    if (user.get_password() == pass) {
                        cout << "          - Авторизация прошла успешно -" << endl;
                        system("cls");
                        break;
                    }
                    else
                        cout << "\t\t        Неверный пароль!" << endl;

                }
                if (j == 3) {
                    cerr << "\t  - Это была последняя попытка -" << endl;
                    return;
                }
                break;
            }
            else
                cerr << "\t\t        Неверный логин!" << endl;
        }
        if (i == 3) {
            cerr << "\t  - Это была последняя попытка -" << endl;
            return;
        }
        else
            admin_menu();
    }
    if (num == 2) {
        for (; i < 3; i++) {
            int a = 0;
            for (h = 0; h < 3; h++) {
                cout << "\tВведите логин: ";
                cin >> log;
                fl = password_check(log);
                if (fl)
                    break;
            }
            if (h == 3) {
                cerr << "\t  - Это была последняя попытка -" << endl;
                auth.close();
                return;
            }
            while (auth >> Id >> l >> p) {
                encryption(l, 2);
                encryption(p, 2);
                User user(Id, l, p);
                if (user.get_login() == log) {
                    a = 1;
                    for (; j < 3; j++) {
                        for (h = 0; h < 3; h++) {

                            cout << "\tВведите пароль: ";
                            cin >> pass;
                            fl = password_check(pass);
                            if (fl)
                                break;
                        }
                        if (h == 3) {
                            cerr << "\t  - Это была последняя попытка -" << endl;
                            auth.close();
                            return;
                        }
                        if (user.get_password() == pass) {
                            cout << "          - Авторизация прошла успешно -" << endl;
                            auth.close();
                            system("cls");
                            break;
                        }
                        else cout << "\t\t        Неверный пароль!" << endl;
                    }
                    if (j == 3) {
                        cerr << "\t  - Это была последняя попытка -" << endl;
                        auth.close();
                        return;
                    }
                    break;
                }
            }
            if (a == 0) {
                cout << "\t\t        Неверный логин!" << endl;
                auth.close();
                auth.open(file_users);
                if (!auth.is_open()) {
                    cout << "\tОшибка при открытии файла!" << endl;
                    return;
                }
            }
            else
                break;
        }
        if (i == 3) {
            cerr << "\t  - Это была последняя попытка -" << endl;
            auth.close();
            return;
        }
        else
            manager_menu();
    }
}

void shell(int* A, int N) {
    int i, j, step, buf;
    for (step = N / 2; step > 0; step /= 2) {
        for (i = step; i < N; i++) {
            buf = *(A + i);
            for (j = i; j >= step; j -= step) {
                if (buf < *(A + j - step))
                    *(A + j) = *(A + j - step);
                else
                    break;
            }
            *(A + j) = buf;
        }
    }
}


void shell(float* A, int N) {
    int i, j, step;
    float buf;
    for (step = N / 2; step > 0; step /= 2) {
        for (i = step; i < N; i++) {
            buf = *(A + i);
            for (j = i; j >= step; j -= step) {
                if (buf < *(A + j - step))
                    *(A + j) = *(A + j - step);
                else
                    break;
            }
            *(A + j) = buf;
        }
    }
}

ostream& setup(ostream& stream) {
    stream.setf(ios::left | ios::fixed);
    stream << setprecision(2);
    return stream;
}


string point(float num) {
    string str = to_string(num);
    string m;
    int i = 0;
    for (; i < str.size(); i++) {
        if (str[i] == ',') {
            str[i] = '.';
            break;
        }
    }
    return str;
}

void task() {
    Order order;
    Tour tour;
    string lines, veh_type;
    int n = 0, num = 0, num1 = 0;
    int* arr;
    int best = 0, best1 = 0;
    show_orders();
    fstream file;

    file.open(file_orders, ios::in);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }

    while (getline(file, lines)) {
        n++;
    }
    file.close();

    arr = new int[n];

    file.open(file_orders, ios::in);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        file >> order.id >> order.client.id >> order.tour.id >> order.departure_date.day >>
            order.departure_date.month >> order.departure_date.year >> order.number_of_people >>
            veh_type >> order.transportation_cost >> order.total_cost;
        arr[i] = order.tour.id;
    }
    file.close();

    shell(arr, n);

    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i + 1]) {
            num++;
            best = arr[i];
        }
        else {
            if (num1 < num) {
                num1 = num;
                best1 = best;
            }
            num = 0;
        }
    }

    cout << "\t\t\t - Наиболее популярный тур - " << endl;
    hat_tour();
    file.open(file_tours, ios::in);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }
    while (file >> tour.id >> tour.city >> tour.duration >> veh_type >> tour.tour_cost_per_person) {
        if (tour.id == best1) {
            cout << "| " << setup << setw(2) << tour.id << " | "
                << setw(11) << tour.city << " | "
                << setw(17) << tour.duration << " | "
                << setw(14) << veh_type << " | "
                << setw(19) << tour.tour_cost_per_person << " |\n";
            cout << "-------------------------------------------------------------------------------\n";
        }
    }
    delete[] arr;

    file.close();
}

void compare_tours() {
    Tour tour1;
    Tour tour2;
    int ID1, ID2;
    bool flag, num;
    show_tours();
    while (true) {
        do {
            cout << "Введите ID 1-го тура: ";
            cin >> ID1;
            flag = check(ID1);
        } while (!flag);
        num = tour_check(tour1, ID1);
        if (!num)
            cerr << "Тура с таким ID не существует!\n";
        else
            break;
    }
    while (true) {
        do {
            cout << "Введите ID 2-го тура: ";
            cin >> ID2;
            flag = check(ID2);
        } while (!flag);
        num = tour_check(tour2, ID2);
        if (!num)
            cerr << "Тура с таким ID не существует!\n";
        else
            break;
    }
    cout << "---------------------------" << endl;
    if (tour1 > tour2)
        cout << "Стоимость тура c ID " << tour1.get_id() << " выше\n";
    else if (tour1 < tour2)
        cout << "Стоимость тура c ID " << tour2.get_id() << " выше\n";
    else
        cout << "Стоимости выбранных Вами туров одинаковы\n";
}

void filtration() {
    Order order, order1;
    Plane plane;
    Car car;
    Bus bus;
    ifstream file;
    string lines, veh_type;
    int a = 0, * element = nullptr;
    bool flag = false, fl = false, num;
    int ID;


    int i, choice;

    while (true) {
        while (true) {
            i = 0, a = 0;
            do {
                filt_menu();
                cin >> choice;
                flag = check(choice);
            } while (!flag);

            switch (choice) {
            case 1: {
                do {
                    cout << "\nВведите ID клиента(отображаются заказы, где ID меньше данного): ";
                    cin >> ID;
                    flag = check(ID);
                    num = client_check(order1.client, ID);
                    if (flag && !num) {
                        cerr << "Клиента с таким ID нет ни в одном заказе!\n";
                    }
                } while (!flag || !num);
                element = &order.client.id;
                break;
            }
            case 2: {
                do {
                    cout << "\nВведите ID тура(отображаются заказы, где ID меньше данного): ";
                    cin >> ID;
                    flag = check(ID);
                    num = tour_check(order.tour, ID);
                    if (flag && !num)
                        cerr << "Тура с таким ID нет ни в одном заказе!\n";
                } while (!flag || !num);
                element = &order.tour.id;
                break;
            }
            case 3: {
                do {
                    cout << "\nВведите количество человек(отображаются заказы, где значение меньше данного): ";
                    cin >> ID;
                    flag = check(ID);
                } while (!flag);
                element = &order.number_of_people;
                break;
            }
            case 4: {
                return;
            }
            default: {
                fl = true;
                if (flag) {
                    cout << "Ошибочный выбор!\n";
                }
                break;
            }
            }

            if (!fl) {
                file.open(file_orders);
                if (!file.is_open()) {
                    cerr << "Ошибка при открытии файла!" << endl;
                    return;
                }
                while (file >> order.id >> order.client.id >> order.tour.id >>
                    order.departure_date.day >> order.departure_date.month >> order.departure_date.year >>
                    order.number_of_people >> veh_type >> order.transportation_cost >> order.total_cost) {
                    if (*element < ID) {
                        a = 1;
                        break;
                    }
                }

                file.close();
                if (a == 0) {
                    cout << "Таких заказов нет!\n";
                }
                else
                    break;
            }
        }
        

        hat_order();

        file.open(file_orders);
        if (!file.is_open()) {
            cerr << "Ошибка при открытии файла!" << endl;
            return;
        }

        while (file >> order.id >> order.client.id >> order.tour.id >> order.departure_date.day >> 
            order.departure_date.month >> order.departure_date.year >> 
            order.number_of_people >> veh_type >> order.transportation_cost >> order.total_cost) {
            if (veh_type == "Самолет") {
                order.vehicle = &plane;
            }
            else if (veh_type == "Автомобиль") {
                order.vehicle = &car;
            }
            else {
                order.vehicle = &bus;
            }
            if (*element < ID) {                      
                show_order(order);
            }
        }
        file.close();
    }
}


template <class T>
int check(T num) {//шаблонная функции
    int k = 1;
    if (cin.fail()) {
        k = 0;
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Вы можете использовать только числа!\n";
    }
    if (k == 1 && num <= 0) {
        cout << "Вы можете использовать только положительные числа!\n";
        k = 0;
    }
    return k;
}

template <class T>
Duration <T> set_duration(Order order) {
    if (order.get_number_of_people() == 1) {
        Duration <string> duration("неделя");
        return duration;
    }
    else if (order.get_number_of_people() == 2) {
        Duration <int> duration(10);
        return duration;
    }
    else if (order.get_number_of_people() == 3) {
        Duration <int> duration(14);
        return duration;
    }
    else if (order.get_number_of_people() == 4) {
        Duration <string> duration("2 недели");
        return duration;
    }
    else if (order.get_number_of_people() == 5) {
        Duration <string> duration("месяц");
        return duration;
    }
}
