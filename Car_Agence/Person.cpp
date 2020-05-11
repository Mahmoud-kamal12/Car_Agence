#include "Person.h"

char to_upper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch - 32;
    return ch;
}

void Person::setuser(string user)
{
    this->user_name = user;
}

void Person::setpass(string pass)
{
    this->password = pass;
}

string Person::getuser()
{
    return this->user_name;
}

string Person::getpass()
{
    return this->password;
}

void Person::show(string arr[])
{
    cout << "+ Make                 : ";    cout << arr[0] << endl;
    cout << "+ Model                : ";    cout << arr[1] << endl;
    cout << "+ Engine_Capacity      : ";    cout << arr[2] << endl;
    cout << "+ Cylinders            : ";    cout << arr[3] << endl;
    cout << "+ Drive_Type           : ";    cout << arr[4] << endl;
    cout << "+ Fuel_Tank_Capacity   : ";    cout << arr[5] << endl;
    cout << "+ Fuel_Economy         : ";    cout << arr[6] << endl;
    cout << "+ Fuel_Type            : ";    cout << arr[7] << endl;
    cout << "+ Horsepower           : ";    cout << arr[8] << endl;
    cout << "+ Top_Speed            : ";    cout << arr[9] << endl;
    cout << "+ Length               : ";    cout << arr[10] << endl;
    cout << "+ Width                : ";    cout << arr[11] << endl;
    cout << "+ Height               : ";    cout << arr[12] << endl;
}

void Person::Search(string searchWord, int& x)

{
    for (char& ch : searchWord) {
        ch = to_upper(ch);
    }
    fstream myfile("Cars.txt");
    string arr[13];
    char c;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            for (int i = 0; i < 13; i++)
            {
                if (i == 12)
                    getline(myfile, arr[i]);
                else
                    getline(myfile, arr[i], '|');

            }

            if (arr[0]._Equal(searchWord))
            {
                x++;
                cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
                show(arr);
            }

        }
        if (x == 0) { cout << "\n********** Not Found **************" << endl; }
    }
    else
        cout << "\n********** File Not Found  **************" << endl;

}

void Person::showall()
{
    fstream myfile("Cars.txt");
    string arr[13] , var;
    int c = 0;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile,var );
            c++;
        }
        myfile.close();
    }
    else
        cout << "\n********** File Not Found  **************" << endl;
    myfile.open("Cars.txt");
    for (int x = 1; x < c; x++)
    {
        for (int i = 0; i < 13; i++)
        {
            if (i == 12)
                getline(myfile, arr[i]);
            else
                getline(myfile, arr[i], '|');

        }
        show(arr);
        cout << "\n ======================================================\n" << endl;
    }

}

void Admins::addaccount(Person per)
{
    int x = 0;
    char searchKey;
    string out;
    fstream myfile("Admin.txt");
    string inp = "$" + per.getuser() + ":" + per.getpass();
    if (myfile.is_open())
    {
        if (myfile.is_open())
        {
            while (!myfile.eof())
            {
                getline(myfile, out);
                if (out._Equal(inp) && x == 0)
                {
                    x++;
                }
            }
        }
    }
    else { cout << "\n********** File Not Found **************" << endl; }
    myfile.close();
    myfile.open("Admin.txt", ios::app);
    if (x == 0)
    {
        myfile << inp << endl;
        cout << "\n********** ADD DOON **************" << endl;
    }
    else { cout << "\n********** The account already exists **************" << endl; }
    myfile.close();
}

void Admins::addCar(Car& car)

{
    string s; int n; float f;
    system("cls");
    cin.ignore();
    cout << "+ Enter Maker ( HONDA ) : ";        getline(cin, s);
    for (char& ch : s) {
        ch = to_upper(ch);
    }
    car.setMake(s);
    cout << "+ Model                : ";        getline(cin, s);
    for (char& ch : s) {
        ch = to_upper(ch);
    }
    car.setModel(s);
    cout << "+ Engine_Capacity      : ";        cin >> n;
    car.setEngine_Capacity(n);
    cout << "+ Cylinders            : ";        cin >> n;
    car.setCylinders(n);
    cout << "+ Drive_Type           : ";        cin.ignore(); getline(cin, s);
    car.setDrive_Type(s);
    cout << "+ Fuel_Tank_Capacity   : ";        getline(cin, s);
    car.setFuel_Tank_Capacity(n);
    cout << "+ Fuel_Economy         : ";        cin >> f;
    car.setFuel_Economy(f);
    cout << "+ Fuel_Type            : ";        cin.ignore(); getline(cin, s);
    car.setFuel_Type(s);
    cout << "+ Horsepower           : ";        cin >> n;
    car.setHorsepower(n);
    cout << "+ Top_Speed            : ";        cin >> n;
    car.setTop_Speed(n);
    cout << "+ Length               : ";        cin >> f;
    car.setLength(f);
    cout << "+ Width                : ";        cin >> f;
    car.setWidth(f);
    cout << "+ Height               : ";        cin >> f;
    car.setHeight(f);

    addCarInfoToFile(car);
}

void Admins::addCarInfoToFile(Car car)

{
    if (checkCarFound(car.getModel()))
    {
        ofstream myfile("Cars.txt", ios::app);
        myfile << car.getMake() << "|";
        myfile << car.getModel() << "|";
        myfile << car.getEngine_Capacity() << "|";
        myfile << car.getCylinders() << "|";
        myfile << car.getDrive_Type() << "|";
        myfile << car.getFuel_Tank_Capacity() << "|";
        myfile << car.getFuel_Economy() << "|";
        myfile << car.getFuel_Type() << "|";
        myfile << car.getHorsepower() << "|";
        myfile << car.getTop_Speed() << "|";
        myfile << car.getLength() << "|";
        myfile << car.getWidth() << "|";
        myfile << car.getHeight() << " " << endl;
        myfile.close();
        cout << "\n********** ADD DOON **************" << endl;
    }
    else
    {
        cout << "\n\t\t=============>  The car is already there <===================" << endl;
    }
}

void Admins::fromCarToTemp(string model, int& x, int& z)

{
    fstream temp;
    fstream myfile;
    string arr[13];
    temp.open("temp.txt", ios::out);
    myfile.open("Cars.txt", ios::in);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            if (!myfile.eof())
            {
                for (int i = 0; i < 13; i++)
                {
                    if (i == 12)
                        getline(myfile, arr[i]);
                    else
                        getline(myfile, arr[i], '|');
                }
                if (model != arr[1])
                {
                    for (int i = 0; i < 13; i++)
                    {
                        if (i == 12)
                        {
                            temp << arr[i] << " " << endl;
                        }
                        else
                        {
                            temp << arr[i] << "|";
                        }
                    }
                    x++;
                }
                else { z++; continue; }
            }
        }
        temp.close();
        myfile.close();

    }
    else
        cout << "file not found " << endl;
}

void Admins::fromTempToCar(int& x)

{
    fstream temp;
    fstream myfile;
    string arr[13];
    temp.open("temp.txt", ios::in);
    myfile.open("Cars.txt", ios::out);

    if (temp.is_open())
    {
        while (!temp.eof() && x > 1)
        {
            if (!temp.eof())
            {
                for (int i = 0; i < 13; i++)
                {
                    if (i == 12)
                        getline(temp, arr[i]);
                    else
                        getline(temp, arr[i], '|');
                }
                if (myfile.is_open()) {
                    for (int i = 0; i < 13; i++)
                    {
                        if (i == 12)
                        {
                            myfile << arr[i] << " " << endl;
                        }
                        else
                        {
                            myfile << arr[i] << "|";
                        }
                    }
                }
            }
            x--;
        }
    }
    temp.close();
    myfile.close();
    remove("temp.txt");
}

void Admins::DeletCar(string model)
{
    int x = 0, z = 0;
    for (char& ch : model) {
        ch = to_upper(ch);
    }
    fromCarToTemp(model, x, z);
    if (z != 0)
    {
        fromTempToCar(x);
        cout << "\n********** DELET DOON **************" << endl;
    }
    else { cout << "\n********** Not Found **************" << endl; remove("temp.txt"); }
}

bool Admins::check(Person p)

{
    string ch = p.getuser() + ":" + p.getpass();
    string out;
    ifstream myfile("Admin.txt");
    char searchKey;
    int x = 0;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile >> searchKey;
            if (searchKey == '$')
            {
                getline(myfile, out);
                if (out._Equal(ch))
                {
                    x++;
                }
            }
        }
    }
    if (x == 0) { return false; }
    else { return true; }
}

void Admins::updataCar(string model, Car car)
{
    int x = 0, z = 0;
    for (char& ch : model) {
        ch = to_upper(ch);
    }
    fromCarToTemp(model, x, z, car);
    if (z != 0)
    {
        cout << "\n********** UpDate DOON **************" << endl;
        fromTempToCar(x);
    }
    else { cout << "\n********** Not Found **************" << endl; remove("temp.txt"); }
}

void Admins::fromCarToTemp(string model, int& x, int& z, Car car)
{
    fstream temp;
    fstream myfile;
    string arr[13];
    temp.open("temp.txt", ios::out);
    myfile.open("Cars.txt", ios::in);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            if (!myfile.eof())
            {
                for (int i = 0; i < 13; i++)
                {
                    if (i == 12)
                        getline(myfile, arr[i]);
                    else
                        getline(myfile, arr[i], '|');
                }
                if (model != arr[1])
                {
                    for (int i = 0; i < 13; i++)
                    {
                        if (i == 12)
                        {
                            temp << arr[i] << " " << endl;
                        }
                        else
                        {
                            temp << arr[i] << "|";
                        }
                    }
                    x++;
                }
                else
                {
                    z++;
                    addCar(car);
                }
            }
        }
        temp.close();
        myfile.close();

    }
    else
        cout << "\n********** File Not Found **************" << endl;
}

bool Admins::checkCarFound(string searchWord)
{
    for (char& ch : searchWord) {
        ch = to_upper(ch);
    }
    fstream myfile("Cars.txt");
    string arr[13];
    int x = 0;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            for (int i = 0; i < 13; i++)
            {
                if (i == 12)
                    getline(myfile, arr[i]);
                else
                    getline(myfile, arr[i], '|');

            }

            if (arr[1]._Equal(searchWord))
            {
                x++;
            }

        }
    }
    else
        cout << "\n********** File Not Found  **************" << endl;
    if (x == 0)
    {
        return true;
    }
    else
    {
        return false;
    }


}

void users::addaccount(Person per)

{
    int x = 0;
    char searchKey;
    string out;
    fstream myfile("User.txt");
    string inp = "$" + per.getuser() + ":" + per.getpass();
    if (myfile.is_open())
    {
        if (myfile.is_open())
        {
            while (!myfile.eof())
            {
                getline(myfile, out);
                if (out._Equal(inp))
                {
                    x++;
                }
            }
        }
    }
    else { cout << "\n********** File Not Found **************" << endl; }
    myfile.close();
    myfile.open("User.txt", ios::app);
    if (x == 0)
    {
        myfile << inp << endl;
        cout << "\n********** ADD DOON **************" << endl;
    }
    else { cout << "\n********** The account already exists **************" << endl; }
    myfile.close();
}

bool users::check(Person p)

{
    string ch = p.getuser() + ":" + p.getpass();
    string out;
    ifstream myfile("User.txt");;
    char searchKey;
    int x = 0;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile >> searchKey;
            if (searchKey == '$')
            {
                getline(myfile, out);
                if (out._Equal(ch))
                {
                    x++;
                }
            }
        }
    }
    if (x == 0) { return false; }
    else { return true; }
}

void users::Buy(string model , Person person)
{
    for (char& ch : model) {
        ch = to_upper(ch);
    }
    fstream temp;
    fstream myfile;
    string arr[13];
    int x = 0;
    temp.open("orders.txt", ios::app);
    myfile.open("Cars.txt", ios::in);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            if (!myfile.eof())
            {
                for (int i = 0; i < 13; i++)
                {
                    if (i == 12)
                        getline(myfile, arr[i]);
                    else
                        getline(myfile, arr[i], '|');
                }
                if (model == arr[1] && x == 0)
                {
                    temp << person.getuser() << endl;
                    for (int i = 0; i < 13; i++)
                    {
                        if (i == 12)
                        {
                            temp << arr[i] << " " << endl;
                        }
                        else
                        {
                            temp << arr[i] << "|";
                        }
                    }
                    x++;
                }
                else { continue; }
            }
        }
        temp.close();
        myfile.close();
        if (x == 0)
        {
            cout << "\n********** ORDER Failed **************" << endl;
        }
        else
        {
            cout << "\n********** ORDER DOON **************" << endl;
        }
    }
    else
        cout << "file not found " << endl;
}

void users::orderList(Person person)
{
    fstream myfile;
    string arr[13] , word ;
    int z = 0;
    myfile.open("orders.txt", ios::in);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            if (!myfile.eof())
            {
                z = 0;
                getline(myfile, word);
                if (person.getuser() == word)
                {
                    
                    for (int i = 0; i < 13; i++)
                    {
                        if (i == 12)
                            getline(myfile, arr[i]);
                        else
                            getline(myfile, arr[i], '|');
                        z++;
                    }
                    
                }
                else
                {
                    getline(myfile, word);
                }

                if (z > 0 )
                {
                    show(arr);
                    cout << "\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-\n";
                }
            }
        }
        myfile.close();


    }
    else
        cout << "\n********** File Not Found **************" << endl;
}
