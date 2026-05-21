
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


// Task 1
class human {
protected:
	string name;
	string surname;
	string patronymic;
	unsigned int age;
	float weight;
public:
	human() {
		name = "Unknown";
		surname = "Unknown";
		patronymic = "Unknown";
		age = 0;
		weight = 0;
	}
	// human(string n, string s, string p, unsigned int age, float weight) : name(n), surname(s), patronymic(p), age(age), weight(weight) {}

	human(string n, string s, string p, unsigned int age, float weight) {
		name = n;
		surname = s;
		patronymic = p;
		this->age = age;
		this->weight = weight;
	}

	~human() {
		cout << "Викликано деструктор для: " << name << " " << surname << " " << patronymic << endl;
	}

	void print_data() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Patronymic: " << patronymic << endl;
		cout << "Age: " << age << endl;
		cout << "Weight: " << weight << endl;
	}
	void input_data() {
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter patronymic: ";
		cin >> patronymic;
		cout << "Enter age: ";
		cin >> age;
		cout << "Enter weight: ";
		cin >> weight;
	}

	// For task 3
	void print_stream(ostream& os) const {
		os << "Name: " << name << endl;
		os << "Surname: " << surname << endl;
		os << "Patronymic: " << patronymic << endl;
		os << "Age: " << age << endl;
		os << "Weight: " << weight << endl;
	}

	void input_stream(istream& is) {
		cout << "Enter name: ";
		is >> name;
		cout << "Enter surname: ";
		is >> surname;
		cout << "Enter patronymic: ";
		is >> patronymic;
		cout << "Enter age: ";
		is >> age;
		cout << "Enter weight: ";
		is >> weight;
	}
};

ostream& operator<<(ostream& out, const human& h) {
	h.print_stream(out);
	return out;
}

istream& operator>>(istream& is, human& h) {
	h.input_stream(is);
	return is;
}

class student : public human {
private:
	unsigned int course;
public:
	student() : human() {
		course = 0;
	}

	student(string n, string s, string p, unsigned int age, float weight, unsigned int c) : human(n, s, p, age, weight) {
		course = c;
	}

	~student() {
		cout << "Викликано деструктор для студента курсу: " << course << endl;
	}

	void print_data() {
		human::print_data();
		cout << "Course: " << course << endl;
	}

	void input_data() {
		human::input_data();
		cout << "Course: ";
		cin >> course;
	}

	// Перевизначення віку 

	void set_age() {
		cout << "Enter new age: ";
		cin >> age;
	}

	// Перевизнгачення курсу 
	void set_course() {
		cout << "Enter new course: ";
		cin >> course;
	}

	// For task 3
	void print_stream (ostream& out) const {
		human::print_stream(out); 
		out << "Course: " << course << endl; 

	}
	
	void input_stream(istream& is) {
		human::input_stream(is);
		cout << "Course: ";
		is >> course;
	}
	
	student(const student& other) : human(other) {
		this->course = other.course; 
	}

	student& operator=(const student& other) {
		if (this != &other) { // Перевірка на самоприсвоювання (наприклад, s1 = s1)
			human::operator=(other); // Копіюємо поля базового класу human
			this->course = other.course; // Копіюємо курс
		}
		return *this;
	}
};

ostream& operator<<(ostream& out, const student& s) {
	s.print_stream(out);
	return out;

}

istream& operator>>(istream& is, student& s) {
	s.input_stream(is);
	return is;
}

// Task 2

class window {
protected:
	string color;
	float width;
	float height;
public:
	window() {
		color = "White";
		width = 1.0;
		height = 1.0;
	}
	window(string c, float w, float h) {
		color = c;
		width = w;
		height = h;
	}

	float area() {
		return width * height;
	}
	~window() {
		cout << "Викликано деструктор для вікна площею: " << area() << endl;
	}

	void input_data() {
		cout << "Enter color: ";
		cin >> color;
		cout << "Enter width: ";
		cin >> width;
		cout << "Enter height: ";
		cin >> height;
	}
	void print_data() {
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
		cout << "Color: " << color << endl;
		cout << "Area: " << area() << endl;
	}

};

class TitleWindow : public window {
private:
	string title;
public:
	TitleWindow() : window() {
		title = "Untitled";
	}
	TitleWindow(string c, float w, float h, string t) : window(c, w, h) {
		title = t;
	}

	~TitleWindow() {
		cout << "Викликано деструктор для вікна з назвою: " << title << endl;
	}

	void input_data() {
		window::input_data();
		cout << "Enter title: ";
		cin >> title;
	}
	
	void print_data() {
		window::print_data();
		cout << "Title: " << title << endl;
	}


};

class WindowWithButton : public window {
private:
	string buttonText;
public:
	WindowWithButton() : window() {
		buttonText = "Button without text";
	}
	WindowWithButton(string c, float w, float h, string bt) : window(c, w, h) {
		buttonText = bt;
	}

	~WindowWithButton() {
		cout << "Викликано деструктор для вікна з кнопкою: " << buttonText << endl;
	}

	void input_data() {
		window::input_data();
		cout << "Enter button text: ";
		cin >> buttonText;
	}

	void print_data() {
		window::print_data();
		cout << "Button Text: " << buttonText << endl;
	}

};

// Task 3

class DiplomaStudent : public student {
private:
	string diplomaTopic;
public:
	DiplomaStudent() : student() {
		diplomaTopic = "No Topic";
	}
	DiplomaStudent(string n, string s, string p, unsigned int age, float weight, unsigned int c, string dt) : student(n, s, p, age, weight, c) {
		diplomaTopic = dt;
	}
	~DiplomaStudent() {
		cout << "Викликано деструктор для дипломного студента з темою: " << diplomaTopic << endl;
	}
	void input_data() {
		student::input_data();
		cout << "Enter diploma topic: ";
		cin >> diplomaTopic;
	}
	void print_data() {
		student::print_data();
		cout << "Diploma Topic: " << diplomaTopic << endl;
	}

	void print_stream(ostream& out) const {
		student::print_stream(out);
		out << "Diploma Topic: " << diplomaTopic << endl;
	}

	void input_stream(istream& is) {
		student::input_stream(is);
		cout << "Enter diploma topic: ";
		is >> diplomaTopic;
	}

	DiplomaStudent(const DiplomaStudent& other) : student(other) {
		this->diplomaTopic = other.diplomaTopic;
	}

	DiplomaStudent& operator=(const DiplomaStudent& other) {
		if (this != &other) { 
			student::operator=(other); 
			this->diplomaTopic = other.diplomaTopic; 
		}
		return *this;
	}

};

ostream& operator<<(ostream& out, const DiplomaStudent& ds) {
	ds.print_stream(out);
	return out;
}

istream& operator>>(istream& is, DiplomaStudent& ds) {
	ds.input_stream(is);
	return is;
}



int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	human h1;
	student s1;
	window w1;
	TitleWindow tw1;
	WindowWithButton wb1;
	DiplomaStudent ds1;

	int main_choice;
	do {
		cout << "Main menu\n";
		cout << "1.Task: working with class human and student\n";
		cout << "2.Task: working with class window\n";
		cout << "3.Task: working with class diploma student\n";
		cout << "0.Exit \n";
		cout << "Choise: ";
		cin >> main_choice;

		switch (main_choice) {

		case 1: {
			int sub_choice;
			do {
				cout << "\n--- Task 1 ---\n";
				cout << "1. Input human data\n";
				cout << "2. Input student data\n";
				cout << "3. Change age\n";
				cout << "4. Change course\n";
				cout << "5. Print data\n";
				cout << "0. Return to main menu\n";
				cout << "Your choice: ";
				cin >> sub_choice;

				switch (sub_choice) {
				case 1:
					h1.input_data();
					break;
				case 2:
					s1.input_data();
					break;
				case 3:
					s1.set_age();
					break;
				case 4:
					s1.set_course();
					break;
				case 5:
					cout << "\nHuman data:\n";
					h1.print_data();
					cout << endl;
					cout << "\nStudent data:\n";
					s1.print_data();
					break;
				}
			} while (sub_choice != 0); // Крутимо підменю, поки не введемо 0
			break;
		}
		case 2: {
			int sub_choice2;
			do {
				cout << "\n--- Task 2 ---\n";
				cout << "1. Input window data\n";
				cout << "2. Input title window data\n";
				cout << "3. Input window with button data\n";
				cout << "4. Print all windows data\n";
				cout << "0. Return to main menu\n";
				cout << "Your choice: ";
				cin >> sub_choice2;
				switch (sub_choice2) {
				case 1:
					w1.input_data();
					break;
				case 2:
					tw1.input_data();
					break;
				case 3:
					wb1.input_data();
					break;
				case 4:
					cout << "\nWindow data:\n";
					w1.print_data();
					cout << endl;
					cout << "\nTitle Window data:\n";
					tw1.print_data();
					cout << endl;
					cout << "\nWindow with Button data:\n";
					wb1.print_data();
					break;
				}
			} while (sub_choice2 != 0); // Крутимо підменю, поки не введемо 0
			break;
		}
		case 3: {
			int sub_choice3;
			do {
				cout << "\n--- Task 3---\n";
				cout << "1. Input DiplomaStudent data\n";
				cout << "2. Test copy constructor and assigment\n"; // конструктор копіювання та оператора присвоєння 
				cout << "3. Print main DiplomaStudents\n";
				cin >> sub_choice3;
				switch (sub_choice3) {
				case 1:
					cin >> ds1;
					break;
				case 2: {
					DiplomaStudent ds2 = ds1;
					DiplomaStudent ds3;
					ds3 = ds1;
					cout << "\n--- Copy (ds2) ---\n" << ds2;
					cout << "\n--- Assignment (ds3) ---\n" << ds3;
					break;
				}
				case 3:
					cout << "\nMain Diploma Student:\n" << ds1;
					break;
				case 0:
					cout << "\nReturn to main menu\n";
					break;
				}
			} while (sub_choice3 != 0);
			break;
		}
		case 0:
			cout << "\nThanks for working\n";
			break;
		}
	} while (main_choice != 0);

	return 0;
}

