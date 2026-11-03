#include <iostream>
using namespace std;

struct rooms
{
    int power;
    int cursed;
    int flag;
};

struct floor
{
    int no_room;
    rooms rr;
};

struct dungeon
{
    int floor_count;
    floor ff;
};

struct hero
{
    char *name = new char[9];   // 8 characters + '\0'
    int HP;
    dungeon dd;
};


int* funct(int **matrix, hero S, int &bestFloor, int &bestRoom)
{
    int *p = &matrix[0][0];

    bestFloor = 0;
    bestRoom = 0;

    for (int i = 0; i < S.dd.floor_count; i++)
    {
        for (int j = 0; j < S.dd.floor_count - i; j++)
        {
            // Skip sealed vault
            if (*(*(matrix + i) + j) == 0)
                continue;

            if (*(*(matrix + i) + j) > *p)
            {
                p = &matrix[i][j];

                bestFloor = i;
                bestRoom = j;
            }
        }
    }

    return p;
}

// Part C
hero* EHTASHAM_THE_BRAVE()
{
    hero *h ;
    dungeon d1 ;
    floor f1 ;
    rooms r1 ;

    return h;       // dangling pointer 
}


int main()
{
    hero h1;
    int i, j;
    int sealed=0 ;
    int cursed=0;
    int wasted=0 ;
    int total_room=0 ;
    int HP ;
    h1.dd.floor_count = 0;
    h1.dd.ff.no_room = 1;

    cout << "====================================" << endl;
    cout << "====================================" << endl;

    cout << "Please enter Hero Name is a Char: " << endl;
    i = 0;
    // 8 characters
    while (i < 8)
    {
        cin >> h1.name[i];
        i++;
    }
    h1.name[i] = '\0';
    cout << "Enter Value of N: ";
    cin >> h1.dd.floor_count;

    cout << "====================================" << endl;
    cout << "====================================" << endl;

    cout << "Hero : ";
    i = 0;
    while (h1.name[i] != '\0')
    {
        cout << h1.name[i];
        i++;
    }
    cout << endl;

    cout << "N : " << h1.dd.floor_count << endl;

    // Create jagged array
    int **matrix = new int*[h1.dd.floor_count];

    for (i = 0; i < h1.dd.floor_count; i++)
    {
        matrix[i] = new int[h1.dd.floor_count - i];
    }

    // Fill matrix
    for (i = 0; i < h1.dd.floor_count; i++)
    {
        for (j = 0; j < h1.dd.floor_count - i; j++)
        {
            h1.dd.ff.rr.power = (j + 1) * 10;

            // Base power
            *(*(matrix + i) + j) = h1.dd.ff.rr.power;

            // Curse
            if ((i + 1) % 2 != 0 && (j + 1) % 2 != 0)
            {
                *(*(matrix + i) + j) = 2 * h1.dd.ff.rr.power;
                    cursed++ ;
            }

            // Every third room is locked
            if (h1.dd.ff.no_room % 3 == 0)
            {
                *(*(matrix + i) + j) = 0;
                sealed++ ;
            }

            h1.dd.ff.no_room++;
            total_room++;
        }
    }
    
    // Print pattern
    cout << "DUNGON OF THE LOST POINTER" << endl;

    for (i = 0; i < h1.dd.floor_count; i++)
    {
        cout << "Floor " << i + 1;

        for (j = 0; j < h1.dd.floor_count - i; j++)
        {
            cout << "[ " << *(*(matrix + i) + j) << " ]";
        }
        cout << endl;
    }
    if(*(*(matrix+h1.dd.floor_count -1)+0)==0){
        cout<<"<==Oh Boss Chamber Sealed "<<endl;
    }
    if(*(*(matrix+h1.dd.floor_count -1)+0)!=0)
    cout<<"Congr Boos Room is not Sealed"<<endl;
    // Part B
    int bestFloor;
    int bestRoom;

    int *const ptr =
        funct(matrix, h1, bestFloor, bestRoom);

    cout << "====================================" << endl;
    cout << "Strongest Monster HP: " << *ptr << " ( Floor: " << bestFloor + 1 << " , Room: " << bestRoom + 1 << " )" << endl;
    cout << "====================================" << endl;
    // Part C
    hero *p=new hero;

    p = EHTASHAM_THE_BRAVE();

    // Store the returned dangling address
    hero *pptr=new hero;
    pptr = p;
    
    cout<<"Rooms carved :"<< total_room<<"     Rooms wasted :"<<wasted<<endl;
    cout<<"Cursed Rooms :"<<cursed<<"      Sealed Rooms :"<<sealed<<endl;
    // Delete jagged matrix
    for (i = 0; i < h1.dd.floor_count; i++)
    {
        delete[] matrix[i];
        cout<<" Floor "<<i+1<< " Freed "<<"...Ok"<<endl;
        matrix[i]=nullptr;
    }

    delete[] matrix;
    matrix=nullptr;
    cout<<" Floor table Freed "<<"...Ok"<<endl;
    delete[] h1.name;
    h1.name=nullptr;
    cout<<"Hero Name Freed"<<"...Ok"<<endl;
    cout << "====================================" << endl;
    cout<<"DUNGEON COLLAPSED 0 BYTES LEAKED"<<endl;
    cout << "====================================" << endl;
    return 0;
}