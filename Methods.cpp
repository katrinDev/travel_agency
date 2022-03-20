#include "myLib.h"

map <string, float> distances{
    {"Тбилиси", 2575.5f},
    {"Ереван", 2851.4f},
    {"Анталия", 2406.1f},
    {"Аланья", 2824.8f},
    {"Москва", 830.3f},
    {"Петербург", 801.6f},
    {"Берлин", 1201.6f},
    {"Прага", 1189.5f}
};

//Методы класса User

User::User(int id, string l, string p) {
    ID = id;
    login = l;
    password = p;
}

User::User() : ID(0), login("unspecified"), password("unspecified") {};

int User:: get_id() {
    return ID;
}
string User:: get_login() {
	return login;
}
string User:: get_password() {
	return password;
}

void User::set_login(string l) {
    login = l;
}
void User::set_password(string p) {
    password = p;
}

//Методы класса Client

Client::Client(int Id, string s, string n, string patron, string p_num, string ph){
    id = Id;
    surname = s;
    name = n;
    patronymin = patron;
    passport_number = p_num;
    phone = ph;
}

int Client::get_id() {
    return id;
}


//Методы класса Vehicle и дочерних

int Vehicle::get_speed() {
    return speed;
}

float Vehicle::get_cost_per_km() {
    return cost_per_km;
}

string Vehicle::get_type() {
    return type;
}

void Plane::find_the_transp_cost(Order& order) {//переопределение чисто виртуальной функции в дочернем классе
    order.transportation_cost = (cost_per_km * order.tour.get_distance() + nutrition_cost) * order.number_of_people * 2;
}

void Bus::find_the_transp_cost(Order& order) {//переопределение чисто виртуальной функции в дочернем классе
    order.transportation_cost = cost_per_km * order.tour.get_distance() * order.number_of_people * 2;
}

void Car::find_the_transp_cost(Order& order) {
    order.transportation_cost = cost_per_km * order.tour.get_distance() * 2;
}

//Методы класса Tour

Tour::Tour(int Id, string c, int dur, Vehicle* veh, float cost){
    id = Id;
    city = c;
    duration = dur;
    vehicle = veh;
    tour_cost_per_person = cost;
}

float Tour::get_cost_per_person() {
    return tour_cost_per_person;
}

float Tour::get_distance() {
    return distances[city];
}

int Tour::get_id() {
    return id;
}

bool Tour::operator==(Tour ob) {//перегрузка операторов
    bool f = false;
    if (tour_cost_per_person == ob.tour_cost_per_person)
        f = true;
    return f;
}

bool Tour::operator<(Tour ob) {
    bool f;
    if (tour_cost_per_person < ob.tour_cost_per_person)
        f = true;
    else
        f = false;
    return f;
}

bool Tour::operator>(Tour ob) {
    bool f;
    if (tour_cost_per_person > ob.tour_cost_per_person)
        f = true;
    else
        f = false;
    return f;
}

//Методы класса Order

int Order::count = 0;

Order::Order(int Id, Client c, Tour t, Date date, int num, float transp_cost, float t_cost){
    tour = t;
    number_of_people = num;
    total_cost = t_cost;
    transportation_cost = transp_cost;
    client = c;
    count++;
}

void Order::set_total_cost() {
    total_cost = tour.get_cost_per_person() * number_of_people + transportation_cost;
}

int Order::get_count() {
    return count;
}

int Order::get_number_of_people() {
    return number_of_people;
}


//Методы класса Date

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}


//Методы класса Duration

template <class T>
 Duration <T> :: Duration(T dur) {
    duration = dur;
}

template <class T>
T Duration <T> ::get_duration() {
    return duration;
 }

template <class T>
Duration <T> ::Duration() {
    duration = 0;
}




