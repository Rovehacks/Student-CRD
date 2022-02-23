#include <iostream>
using namespace std;

struct Date
{
    int day, month, year;
};

struct Name
{
    char name[30], lastName[20], mothersLastName[20];
};

struct Student
{
    char code[10];
    Name name;
    char career[25];
    Date dateOfBirth;
    float gpa;
    Date dateOfAdmission;
};

static bool checkIndex(int index, int max);

static bool checkStudent(int index, Student* list);

static Student registerStudent();

static void printStudent(Student s);

static Student deleteStudent(Student s);

int main()
{
    char m = 0;
    Student list[50];
    for (int i = 0; i < 50;i++)
    {
        list[i].code[0] = '*';
    }
    while (m != '5')
    {
        cout << "1)Registrar alumno\n2)Consultar alumno\n3)Eliminar alumno\n4)Mostrar lista de alumnos\n5)Salir\n";
        cin >> m;
        switch (m)
        {
        case '1':
        {
            int index;
            cout << "Ingresa el indice en el que quieres agregar el alumno (0-49)" << endl;
            cin >> index;
            if (!checkIndex(index, 50))
                cout << "Ingresa un indice dentro del rango permitido" << endl;
            else
                list[index] = registerStudent();
        }break;
        case '2':
        {
            int index;
            cout << "Ingresa el indice del alumno que deseas consultar (0-49)" << endl;
            cin >> index;
            if (!checkIndex(index, 50))
                cout << "Ingresa un indice dentro del rango permitido" << endl;
            else
            {
                if (!checkStudent(index, list))
                    cout << "No hay alumno registrado en ese indice" << endl;
                else
                    printStudent(list[index]);
            }
        }break;
        case '3':
        {
            int index;
            cout << "Ingresa el indice del alumno que deseas eliminar (0-49)" << endl;
            cin >> index;
            if (!checkIndex(index, 50))
                cout << "Ingresa un indice dentro del rango permitido" << endl;
            else
            {
                if (!checkStudent(index, list))
                    cout << "No hay alumno registrado en ese indice" << endl;
                else
                    list[index] = deleteStudent(list[index]);
            }
        }break;
        case '4':
        {
            bool res = 1;
            for (Student s : list)
            {
                if (s.code[0] != '*')
                {
                    res = 0;
                    printStudent(s);
                    cout << endl << endl;
                }                
            }    
            if (res == 1)
                cout << "No hay alumnos registrados en la Lista" << endl;
        }break;
        default:
        {

        }break;
        }
        system("pause");
        system("cls");
    }
}

static bool checkIndex(int index, int max)
{
    if (index >= max || index < 0)
        return 0;
    else
        return 1;
}

static bool checkStudent(int index, Student *list)
{
    if (list[index].code[0] == '*')
        return 0;
    else
        return 1;
}

static Student registerStudent()
{
    Student s;
    cout << "Ingrese el codigo del alumno" << endl;
    cin >> s.code;
    cout << "Ingrese el nombre del alumno" << endl;
    cin >> s.name.name;
    cout << "Ingrese el apellido paterno del alumno" << endl;
    cin >> s.name.lastName;
    cout << "Ingrese el apellido materno del alumno" << endl;
    cin >> s.name.mothersLastName;
    cout << "Ingrese la carrera del alumno" << endl;
    cin >> s.career;
    cout << "Ingrese el dia de nacimiento del alumno" << endl;
    cin >> s.dateOfBirth.day;
    cout << "Ingrese el mes de nacimiento del alumno" << endl;
    cin >> s.dateOfBirth.month;
    cout << "Ingrese el año de nacimiento del alumno" << endl;
    cin >> s.dateOfBirth.year;
    cout << "Ingrese el promedio del alumno" << endl;
    cin >> s.gpa;
    cout << "Ingrese el dia de ingreso del alumno" << endl;
    cin >> s.dateOfAdmission.day;
    cout << "Ingrese el mes de ingreso del alumno" << endl;
    cin >> s.dateOfAdmission.month;
    cout << "Ingrese el año de ingreso del alumno" << endl;
    cin >> s.dateOfAdmission.year;
    return s;
}

static void printStudent(Student s)
{
    cout << "Codigo: " << s.code << endl;
    cout << "Nombre: " << s.name.name << " " << s.name.lastName << " " << s.name.mothersLastName << endl;
    cout << "Carrera: " << s.career << endl;
    cout << "Fecha de nacimiento: " << s.dateOfBirth.day << "/" << s.dateOfBirth.month << "/" << s.dateOfBirth.year << endl;
    cout << "Promedio: " << s.gpa << endl;
    cout << "Fecha de ingreso: " << s.dateOfAdmission.day << "/" << s.dateOfAdmission.month << "/" << s.dateOfAdmission.year << endl;
}

static Student deleteStudent(Student s)
{
    s = Student();
    s.code[0] = '*';
    return s;
}