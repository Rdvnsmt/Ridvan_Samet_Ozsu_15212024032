#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Sensor
{
    int sensor_id;
    float sicaklik;
};
int main()
{
    Sensor Temp;
    string Student_Id;
    long long int IdInt;
    int firstTemp = 0;
    cout << "Enter your Student id: ";
    cin >> Student_Id;
    IdInt = stoll(Student_Id);
    int N = IdInt % 50;
    int E = IdInt % 100;

    fstream Sensors("sensors.bin", ios::in | ios::out | ios::binary);

    Sensors.seekg(N * sizeof(Sensor), ios::beg);
    Sensors.read((char*)&Temp, sizeof(Sensor));
    firstTemp = Temp.sicaklik;
    Temp.sicaklik += E;

    Sensors.seekp(-N * sizeof(Sensor), ios::cur);
    Sensors.write((char*)&Temp, sizeof(Sensor));
    Sensors.close();

    ofstream Student(Student_Id + "_Quiz5.txt");

    Student << "Number: " + Student_Id << endl;
    Student << "Sensor Index used in the Process: " << N << endl;
    Student << "First Temperature: " << firstTemp <<  " -> New Temperature: " << Temp.sicaklik << endl;

    Student.close();
}
