#include<iostream>
using namespace std;

struct rooms{
    int power;
    int cursed;
    int flag;
};

struct floor{
    int no_room;
    rooms rr;
};

struct dungeon{
    int floor_count;
    floor ff;
};

struct hero{
    char name[8];
    int HP;
    dungeon dd;
};

int main()
{
    hero h1;
    dungeon d1;
    floor f1;
    rooms r1;
    int i, j;
    h1.dd.floor_count=0 ;
   h1.dd.ff.no_room=1 ;
cout<<"===================================="<<endl ;    
cout<<"===================================="<<endl ;
    cout << "Enter Hero Name: "<<endl;
    i = 0;
    while (i < 8) {              // stop at 8, name[8] for null char '\0'
        cin >> h1.name[i];
        cin.ignore();
        i++;
    }
    h1.name[i] = '\0';

    cout << "Enter Value of N: ";
    cin >> h1.dd.floor_count;
cout<<"===================================="<<endl ;
cout<<"===================================="<<endl ;
    cout << " Hero : ";
    i = 0;
    while (h1.name[i] != '\0') {
        cout << h1.name[i];
        i++;
    }
    cout << endl;

    cout << " N : " << h1.dd.floor_count << endl;

    int **matrix = new int*[h1.dd.floor_count];
    for (i = 0; i < h1.dd.floor_count; i++) {
        matrix[i] = new int[h1.dd.floor_count - i];
    }

    for (i = 0; i < h1.dd.floor_count; i++) {
    for (j = 0; j < h1.dd.floor_count - i; j++) {

        int floorNo = i + 1;
        int roomNo = j + 1;

        // Base power
        h1.dd.ff.rr.power = roomNo * 10;

        // If floor number AND room number are odd
        if (floorNo % 2 != 0 && roomNo % 2 != 0) {
            h1.dd.ff.rr.power = h1.dd.ff.rr.power * 2;
        }

        // Every 3rd room is locked
        if (h1.dd.ff.no_room % 3 == 0) {
            h1.dd.ff.rr.power = 0;
        }

        // Store final power
        // matrix[i][j] = h1.dd.ff.rr.power;

        // Move to next room
        h1.dd.ff.no_room++;
    }
}

    // *(*(matrix + h1.dd.floor_count - 1) + 0) = 99;      // BOSS CHAMBER last floor's only room
 // here 0 means j=0
 cout<<"===================================="<<endl ;
 cout<<"===================================="<<endl ;
    cout << "Print pattern" << endl;
    for (i = 0; i < h1.dd.floor_count; i++) {
        cout<<"Floor "<<i+1;
        for (j = 0; j < h1.dd.floor_count - i; j++) {
            cout <<" [" <<*(*(matrix + i) + j) << "] ";
        }
        cout << endl;
    }

    return 0;
}