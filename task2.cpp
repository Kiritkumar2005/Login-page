#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(string u, string p) {
        username = u;
        password = p;
    }

    void displayUser() {
        cout << "Username: " << username << "\n";
    }

    string login(string u, string p) {
        if (username == u && password == p) {
            return "Login successful!";
        }
        return "Invalid credentials. Try again.";
    }
};

class System {
private:
    User* registeredUser;

public:
    System() {
        registeredUser = nullptr;
    }

    void registerUser() {
        string username, password;
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;
        registeredUser = new User(username, password);
        cout << "Registration successful!\n";
    }

    void loginUser() {
        if (registeredUser == nullptr) {
            cout << "No user registered. Please register first.\n";
            return;
        }
        
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        cout << registeredUser->login(username, password) << "\n";
    }
};

int main() {
    System system;
    int choice;
    
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;
    
    if (choice == 1) {
        system.registerUser();
    } else if (choice == 2) {
        system.loginUser();
    } else {
        cout << "Invalid option.\n";
    }
    
    return 0;
}
