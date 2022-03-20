#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

const string file_users = "Files\\Users.txt";
const string file_clients = "Files\\Clients.txt";
const string file_tours = "Files\\Tours.txt";
const string file_orders = "Files\\Orders.txt";


class User {
	int ID;
	string login;
	string password;
public:
	User();
	User(int id, string l, string p);
	int get_id();
	string get_login();
	string get_password();
	void set_login(string);
	void set_password(string);
};

class Order;

class Date {
	int day;
	int month;
	int year;
public:
	Date() : day(0), month(0), year(0) {};
	Date(int d, int m, int y);
	friend void set_date(Date& date);
	friend void add_order();
	friend void show_orders();
	friend void edit_order();
	friend int id(fstream& file, const string name, int k);
	friend void delete_order();
	friend void task();
	friend void sort();
	friend void show_order(Order& order);
	friend void search();
	friend void filtration();
};

class Order;

namespace Cool_Vehicle {
	class Vehicle {//абстрактный класс
	protected:
		int speed;//средняя скорость
		float cost_per_km;
		string type;
	public:
		Vehicle() : speed(0), cost_per_km(0), type("Unknown") {};
		int get_speed();
		float get_cost_per_km();
		string get_type();
		virtual void find_the_transp_cost(Order& order) = 0;//чисто виртуальная функция
	};

	class Plane :public Vehicle {
		const int nutrition_cost = 15;
	public:
		Plane() {
			speed = 500;
			cost_per_km = 0.06f;
			type = "Самолет";
		}
		void find_the_transp_cost(Order& order);
	};

	class Bus :public Vehicle {
	public:
		Bus() {
			speed = 60;
			cost_per_km = 0.04f;
			type = "Автобус";
		}
		void find_the_transp_cost(Order& order);//переопределение чисто виртуальной функции в дочернем классе
	};

	class Car :public Vehicle {
	public:
		Car() {
			speed = 80;
			cost_per_km = 0.05f;
			type = "Автомобиль";
		}
		void find_the_transp_cost(Order& order);
	};
}


template <class T = string>
class Duration {
	T duration;
public:
	Duration();
	Duration(T dur);
	T get_duration();
};

using namespace Cool_Vehicle;//использую пользовательское пространство имен

class Tour {
	int id;
	string city;
	int duration;
	Vehicle* vehicle;
	float tour_cost_per_person;
public:
	Tour(int Id = 0, string c = "Unknown", int dur = 0, Vehicle* veh = NULL, float cost = 0.0f);
	float get_distance();
	float get_cost_per_person();
	int get_id();
	friend class Order;//дружественный класс
	friend void show_tours();//дружественная функция
	friend bool tour_check(Tour& tour, int ID);
	friend void show_orders();
	friend void edit_order();

	friend int id(fstream& file, const string name, int k);
	friend void delete_order();
	friend void task();
	friend void sort();
	friend void show_order(Order& order);
	friend void search();
	friend void filtration();


	bool operator==(Tour);
	bool operator<(Tour);
	bool operator>(Tour);
};

class Client {
	int id;
	string surname;
	string name;
	string patronymin;
	string passport_number;
	string phone;
public:
	Client(int Id = 0, string s = "Unknown", string n = "Unknown", string patron = "Unknown",
		string p_num = "Unknown", string ph = "Unknown");
	friend void show_clients();
	friend void client_check(Client& client);
	friend void show_orders();
	friend void edit_order();
	friend int id(fstream& file, const string name, int k);
	friend void delete_order();
	friend bool client_check(Client& client, int ID);
	int get_id();
	friend void task();
	friend void sort();
	friend void show_order(Order& order);
	friend void search();
	friend void filtration();
};


class Order {
	static int count;//статическое поле 
	int id;
	Client client;
	Tour tour;
	Date departure_date;
	Vehicle* vehicle;
	int number_of_people;
	float transportation_cost;
	float total_cost;
public:
	Order(int Id = 0, Client c = Client(), Tour t = Tour(), Date date = Date(), int num = 0, float transp_cost = 0.0f, float t_cost = 0.0f);
	void set_total_cost();
	static int get_count();//статический метод
	int get_number_of_people();
	friend void Plane :: find_the_transp_cost(Order& order);//дружественная функция - метод другого класса
	friend void Bus::find_the_transp_cost(Order& order);//дружественная функция
	friend void Car::find_the_transp_cost(Order& order);//дружественная функция
	friend void add_order();
	friend void show_orders();
	friend void edit_order();
	friend int id(fstream& file, const string name, int k);
	friend void delete_order();
	friend void task();
	friend void sort();
	friend void show_order(Order& order);
	friend void search();
	friend void filtration();
};

template <class T>//шаблонная функции
int check(T num);

void Authentication(int num);
void add_user();
void edit_user();
void delete_user();
void show_user();
int id(fstream& file, const string name);
int id(fstream& file, const string name, int k);//перегрузка функции, высчитывающей ID

void Main_menu();
void admin_menu();
void manager_menu();
void user_manage_menu();
int user_editing_menu();
int order_editing_menu();

void add_order();
void show_orders();
void edit_order();
void delete_order();
void set_date(Date& date);


void encryption(string& password, int num);
bool password_check(string name);

void shell(int* A, int N);//перегрузка функции
void shell(float* A, int N);
ostream& setup(ostream& stream);//манипуляторная функция
string point(float num);

void hat_order();
void hat_user();
void hat_tour();
void hat_order();

void show_tours();
void show_clients();
bool tour_check(Tour& tour, int ID);
bool client_check(Client& client, int ID);

void task();
void sort_menu();
void search_menu();
void show_order(Order& order);

void sort();
void search();

void compare_tours();
void filtration();
void filt_menu();
template <class T>
T set_duration(Order order);