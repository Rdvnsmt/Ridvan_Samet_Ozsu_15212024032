   
#include <iostream>
#include <string>
using namespace std;

struct song {
    string title;
    string artist;
    int rating[3];
    song* next;
    song* prev;
};

song* head = nullptr;
song* current = nullptr;

void AddSong(string Title, string Artist,int rating1,int rating2,int rating3) {
    song* newSong = new song();
    newSong->title = Title;
    newSong->artist = Artist;
    newSong->rating[0] = rating1;
    newSong->rating[1] = rating2;
    newSong->rating[2] = rating3;

    if (head == nullptr) {
        newSong->prev = nullptr;
        head = newSong;
        current = newSong;
    }
    else {
        song* lastSong = head;
        while (lastSong->next != nullptr) lastSong = lastSong->next;

        lastSong->next = newSong;
        newSong->prev = lastSong;
    }
    cout << endl;
}

void removeCurrent() {
    if (current == nullptr)return;

    if (current->prev != nullptr) current->prev = current->next;
    else head = current->next;

    if (current->next != nullptr) current->next->prev = current->prev;

    song* silinecek = new song();

    current = (silinecek->next != nullptr) ? silinecek : head;

    delete silinecek;
    silinecek = nullptr;
}

void displaySongs() {
    song* ToDisplay = head;
    while (ToDisplay != nullptr) {

        if (ToDisplay == current) cout << "->";
        else cout << "  ";

        cout << ToDisplay->title << " [";
        for (int i = 0; i < 3; i++) {
            cout << ToDisplay->rating[i] << " ";
        }
        cout << "]" << endl;

        ToDisplay = ToDisplay->next;
    }
}

void nextSong() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
        cout << "Sonraki sarkiya gecildi" << endl;
    }
    else {
        cout << "Zaten listenin sonundasiniz!" << endl;
    }
}

void prevSong() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        cout << "Onceki sarkiya gecildi" << endl;
    }
    else {
        cout << "Zaten listenin basindasiniz!" << endl;
    }
}

int main()
{
    int Choise = -1;
    string myTitle = "";
    string myArtist = "";
    int myRating1 = 0;
    int myRating2 = 0;
    int myRating3 = 0;

    while (true) {
        cout << "1.Ekle" << endl;
        cout << "2.Sil" << endl;
        cout << "3.Ekranda Goster" << endl;
        cout << "4.Sonraki" << endl;
        cout << "5.Onceki" << endl;
        cout << "0.Cikis" << endl;
        cout << "Secim: ";
        cin >> Choise;
        cout << endl;
        if (Choise == 1) {
            cout << "Isim: ";
            cin >> myTitle;
            cout << "Artist: ";
            cin >> myArtist;
            cout << "Rating 1: ";
            cin >> myRating1;
            cout << "Rating 2: ";
            cin >> myRating2;
            cout << "Rating 3: ";
            cin >> myRating3;

            AddSong(myTitle, myArtist, myRating1, myRating2, myRating3);
        }
        else if (Choise == 2) {
            removeCurrent();
            cout << "Suanki sarki silindi!" << endl;
        }
        else if (Choise == 3) {
            displaySongs();
        }
        else if (Choise == 4) {
            nextSong();
        }
        else if (Choise == 5) {
            prevSong();
        }
        else if (Choise == 0) return 0;
        else {
            cout << "Gecersiz Secim!!" << endl;
        }
        
    }
    return 0;
}
