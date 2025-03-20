#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <limits>
using namespace std;

struct emp {
    string name, id, address;
    string contact;
    int salary;
};

emp e[100];
int total = 0;

void empdata() {
    int choice;
    cout << "\nHow many employees' data do you want to add? ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = total; i < total + choice; i++) {
        cout << "\nEnter employee Data " << i + 1 << ":\n";
        cout << "\tEnter Name: ";
        getline(cin, e[i].name);
        cout << "\tEnter ID: ";
        getline(cin, e[i].id);
        cout << "\tEnter Address: ";
        getline(cin, e[i].address);
        cout << "\tEnter Contact Number: ";
        getline(cin, e[i].contact);
        cout << "\tEnter Salary: ";
        cin >> e[i].salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
    }
    total += choice;
}

void view() {
    if (total != 0) {
        cout << "\nEmployee Records:\n";
        for (int i = 0; i < total; i++) {
            cout << "\tEmployee Data " << i + 1 << ":\n";
            cout << "\t\tName: " << e[i].name << "\n";
            cout << "\t\tID: " << e[i].id << "\n";
            cout << "\t\tAddress: " << e[i].address << "\n";
            cout << "\t\tContact Number: " << e[i].contact << "\n";
            cout << "\t\tSalary: " << e[i].salary << "\n";
            cout << "\t------------------------\n";
        }
        Sleep(3000);
    } else {
        cout << "\nYour Record is Empty\n";
        Sleep(2000);
    }
}

void search() {
    if (total != 0) {
        string id;
        cout << "\nEnter ID to search: ";
        cin.sync();
        getline(cin, id);
        cout << "Entered ID: '" << id << "'\n";
        bool found = false;
        for (int i = 0; i < total; i++) {
            if (e[i].id == id) {
                cout << "\n\tEmployee Data " << i + 1 << ":\n";
                cout << "\t\tName: " << e[i].name << "\n";
                cout << "\t\tID: " << e[i].id << "\n";
                cout << "\t\tAddress: " << e[i].address << "\n";
                cout << "\t\tContact Number: " << e[i].contact << "\n";
                cout << "\t\tSalary: " << e[i].salary << "\n";
                cout << "\t------------------------\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nID not found\n";
        }
        Sleep(3000);
    } else {
        cout << "\nYour Record is Empty\n";
        Sleep(2000);
    }
}

void update() {
    if (total != 0) {
        string id;
        cout << "\nEnter ID to update: ";
        cin.sync();
        getline(cin, id);
        cout << "Entered ID: '" << id << "'\n";
        bool found = false;
        for (int i = 0; i < total; i++) {
            if (e[i].id == id) {
                cout << "\n\tCurrent Employee Data " << i + 1 << ":\n";
                cout << "\t\tName: " << e[i].name << "\n";
                cout << "\t\tID: " << e[i].id << "\n";
                cout << "\t\tAddress: " << e[i].address << "\n";
                cout << "\t\tContact Number: " << e[i].contact << "\n";
                cout << "\t\tSalary: " << e[i].salary << "\n";
                cout << "\t------------------------\n";
                cout << "\tEnter new Name: ";
                getline(cin, e[i].name);
                cout << "\tEnter new Address: ";
                getline(cin, e[i].address);
                cout << "\tEnter new Contact Number: ";
                getline(cin, e[i].contact);
                cout << "\tEnter new Salary: ";
                cin >> e[i].salary;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t------------------------\n";
                cout << "\tEmployee Data Updated Successfully\n";
                found = true;
                Sleep(2000);
                break;
            }
        }
        if (!found) {
            cout << "\nID not found\n";
            Sleep(2000);
        }
    } else {
        cout << "\nYour Record is Empty\n";
        Sleep(2000);
    }
}

void del() {
    if (total != 0) {
        cout << "\nPress 1 to Delete Full Record\n";
        cout << "Press 2 to Delete Specific Record\n";
        char user = _getch();
        cout << user << "\n\n";
        system("CLS");
        if (user == '1') {
            total = 0;
            cout << "\nFull Record Deleted....!\n";
            Sleep(2000);
        } else if (user == '2') {
            string id;
            cout << "\nEnter ID to delete: ";
            cin.sync();
            getline(cin, id);
            cout << " Entered ID: '" << id << "'\n";
            bool found = false;
            for (int i = 0; i < total; i++) {
                if (e[i].id == id) {
                    for (int j = i; j < total - 1; j++) {
                        e[j] = e[j + 1];
                    }
                    total--;
                    cout << "\nRecord with ID " << id << " Deleted Successfully!\n";
                    found = true;
                    Sleep(2000);
                    break;
                }
            }
            if (!found) {
                cout << "\nID not found\n";
                Sleep(2000);
            }
        } else {
            cout << "\nInvalid choice\n";
            Sleep(2000);
        }
    } else {
        cout << "\nYour Record is Empty\n";
        Sleep(2000);
    }
}

int main() {
    string username, passwd;
    bool isSignedUp = false;
    char choice;

    while (1) {
        system("CLS");
        cout << "\n\n\t\tEmployee Management System\n";
        cout << "\t\t---------------------------\n";
        cout << "\t\t   1. Sign Up           \n";
        cout << "\t\t   2. Login             \n";
        cout << "\t\t---------------------------\n";
        cout << "\t\tEnter your choice (1-2): ";
        choice = _getch();
        cout << choice << "\n\n";

        switch (choice) {
            case '1':
                cout << "\t\tSign Up\n";
                cout << "\t\tEnter Username: ";
                cin >> username;
                cout << "\t\tEnter Password: ";
                cin >> passwd;
                cout << "\n\t\tYour ID is being created, please wait";
                for (int i = 0; i < 5; i++) {
                    cout << ".";
                    Sleep(1000);
                }
                cout << "\n\n\t\tYour ID Created Successfully...!\n";
                isSignedUp = true;
                Sleep(1000);
                break;

            case '2':
            {
            start:
                system("CLS");
                cout << "\n\n\t\tEmployee Management System\n";
                cout << "\t\t---------------------------\n";
                cout << "\t\tLogin\n";
                if (!isSignedUp) {
                    cout << "\n\t\tNo account exists! Please sign up first.\n";
                    Sleep(3000);
                    break;
                }
                string username1, passwrd1;
                cout << "\t\tUsername: ";
                cin >> username1;
                cout << "\t\tPassword: ";
                cin >> passwrd1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (username1 == username && passwrd1 == passwd) {
                    system("CLS");
                    char user;
                    while (1) {
                        cout << "\n\n\t\tEmployee Management System Menu\n";
                        cout << "\t\t---------------------------\n";
                        cout << "\t\t1. Enter Data\n";
                        cout << "\t\t2. View Data\n";
                        cout << "\t\t3. Search Data\n";
                        cout << "\t\t4. Update Data\n";
                        cout << "\t\t5. Delete Data\n";
                        cout << "\t\t6. Logout\n";
                        cout << "\t\t7. Exit\n";
                        cout << "\t\tEnter your choice (1-7): ";
                        user = _getch();
                        cout << user << "\n\n";
                        switch (user) {
                            case '1':
                                empdata();
                                break;
                            case '2':
                                view();
                                break;
                            case '3':
                                search();
                                break;
                            case '4':
                                update();
                                break;
                            case '5':
                                del();
                                break;
                            case '6':
                                system("CLS");
                                goto start;
                                break;
                            case '7':
                                cout << "\n\t\tExiting Program...\n";
                                Sleep(1000);
                                return 0;
                            default:
                                cout << "\t\tInvalid choice\n";
                                Sleep(1000);
                                break;
                        }
                    }
                } else {
                    cout << "\n\t\tInvalid Username or Password...!\n";
                    Sleep(3000);
                    goto start;
                }
                break;
            }

            default:
                cout << "\t\tInvalid choice! Please press 1 or 2.\n";
                Sleep(2000);
                break;
        }
    }

    return 0;
}