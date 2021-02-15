#include "UserManager.h"

bool UserManager::isUserLoggedIn() {
    if(loggedInUserId > 0)
        return true;
    else
        return false;
}

void UserManager::userRegistration() {
    enterNewUserData();
    cout << endl << "Uzytkownik zostal zarejestrowany" << endl << endl;
    system("pause");
}

bool UserManager::isLoginExist(string login) {
    CMarkup xml;
    xml.Load("Users.xml");

    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("login");
        if (xml.GetData()==login) {
            cout<<"Login: "<<login<<" juz istnieje w programie!"<<endl;
            return true;
        }
        xml.OutOfElem();
    }
    return false;
}

int UserManager::getUserId() {
    return loggedInUserId;
}

void UserManager::enterNewUserData() {
    User user;
    string login="", password="", name="", surname="";

    user.setId(getNewUserId());

    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    saveNewUser(user);
}

void UserManager::saveNewUser(User newUser) {
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem("userId", newUser.getId());
    xml.AddElem("login", newUser.getLogin());
    xml.AddElem("password", newUser.getPassword());
    xml.AddElem("name", newUser.getName());
    xml.AddElem("surname", newUser.getSurname());
    xml.OutOfElem();
    xml.Save("Users.xml");
}

int UserManager::getNewUserId() {
    int counter=0;
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("USER")) {
        counter += 1;
    }
    return counter+1;
}

bool UserManager::isLoginNotExist(string login) {
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("login");
        if (xml.GetData()==login) {
            return true;
        }
        xml.OutOfElem();
    }
    cout<<"Login: "<<login<<" NIE istnieje w programie!"<<endl;
    system("pause");
    return false;
}

void UserManager::userLogIn() {
    string login = "", password = "", userPassword="";
    CMarkup xml;

    do {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::getLine();
    } while (isLoginNotExist(login) != true);

    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("login");
        if (xml.GetData()==login) {
            xml.FindElem("password");
            userPassword = xml.GetData();
            xml.ResetMainPos();
            xml.FindElem("userId");
            loggedInUserId = atoi(MCD_2PCSZ(xml.GetData()));
        }
        xml.OutOfElem();
    }

    for(int iloscProb = 3; iloscProb > 0; iloscProb--) {
        cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
        password = AuxiliaryMethods::getLine();
        if(password==userPassword) {
            cout<<endl<<"Zalogowales sie!"<<endl<<endl;
            return;
        }
    }
    cout << "Wprowadzono 3 razy bledne haslo." << endl;
    system("pause");
    return;
}

void UserManager::userLogOut() {
    loggedInUserId = 0;
}

void UserManager::passwordChange() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::getLine();

    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("userId");
        if (xml.GetData()==AuxiliaryMethods::intToStrConversion(loggedInUserId)) {
            xml.FindElem("password");
            xml.SetData(newPassword);
        }
        xml.OutOfElem();
    }
    xml.Save("Users.xml");
    cout << "Haslo zostalo zmienione." << endl << endl;
    system("pause");
}





