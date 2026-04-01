
#include <iostream>
using namespace std;

struct Package
{
    string packageId;
    string destinationCity;
    int dimensons[3];
    Package* next = nullptr;
};

struct Courier {
    string courierName[5];
    string vehicleType[5];
    int front;
    int rear;
    int noItem;
};
void Push(Package* &Top ,string Id,string DesCity,int dim[3]) {
    Package* newPck = new Package;
    newPck->destinationCity = DesCity;
    newPck->packageId = Id;
    newPck->dimensons[0] = dim[0];
    newPck->dimensons[1] = dim[1];
    newPck->dimensons[2] = dim[2];
    
    newPck->next = Top;
    Top = newPck;
 }

void Enqueue(Courier* Front,string cName, string vType) {
    if (Front->noItem == 5) {
        cout << "It is full" << endl;
        return;
    }

    Front->rear = (Front->rear + 1) % 5;
    Front->courierName[Front->rear] = cName;
    Front->vehicleType[Front->rear] = vType;

    Front->noItem++;

}

void Dispatch(Package* &Top, Courier* Front) {
    if (Top == nullptr || Front->noItem == 0) {
        cout << "Hata" << endl;
        return;
    }

    string cName = Front->courierName[Front->front];
    Front->front = (Front->front + 1) % 5;
    Front->noItem--;

    Package* Temp = Top;
    string pID = Top->packageId;
    Top = Top->next;

    cout << "--> Gonderildi: " << cName << "->" << pID << endl << endl;
    delete Temp;
    Temp = nullptr;
}

void Display(Package* &Top, Courier* Front) {
    cout << "Packages" << endl;
    cout << "-------------------------" << endl;
    Package* temp = Top;
    for (int i = 0; i < 5; i++) {
        if ( temp == nullptr) {
            cout << i + 1 << ". Paket yok" << endl;
            
        }
        else {        
            cout << i + 1 << ". " << temp->packageId << endl;
            temp = temp->next;
        }
        
    }
    cout << endl;

    cout << "Couriers" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ".Name: " << Front->courierName[i] << "  Vehicle Type: " << Front->vehicleType[i] << endl;
    }
    cout << endl;
}
int main()
{
    Package* stackTop = nullptr;

    Courier myQueue; 
    myQueue.front = 0;
    myQueue.rear = -1;
    myQueue.noItem = 0;
    int d[3] = { 10, 10, 10 };

    Push(stackTop, "P1", "Dest1", d);
    Push(stackTop, "P2", "Dest2", d);

    Enqueue(&myQueue, "Courier1", "vehicle1");
    Enqueue(&myQueue, "Courier2", "Vehicle2");

    Display(stackTop, &myQueue);

    Dispatch(stackTop, &myQueue);
    Display(stackTop, &myQueue);
}