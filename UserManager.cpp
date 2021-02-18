#include "UserManager.h"

bool UserManager::isUserLoggedIn() {
    return (loggedInUserId > 0);
}

void UserManager::userRegistration() {
    enterNewUserData();
    cout << endl << "Uzytkownik zostal zarejestrowany" << endl << endl;
    system("pause");
}

int UserManager::getUserId() {
    return loggedInUserId;
}

void UserManager::enterNewUserData() {
    User user;
    FileOperations file;
    string login="", password="", name="", surname="";

    user.setId(file.getNewUserId());

    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (file.isLoginExist(user.getLogin()));
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    file.saveNewUser(user);
}

void UserManager::userLogIn() {
    FileOperations file;
    loggedInUserId = file.userLogIn();
}

void UserManager::userLogOut() {
    loggedInUserId = 0;
}

void UserManager::passwordChange(int loggedInUserId) {
    FileOperations file;
    file.passwordChange(loggedInUserId);
}
