#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <stdlib.h>
#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileOperations.h"

using namespace std;

class UserManager {
    int loggedInUserId;

    bool isLoginExist(string login);
    bool isLoginNotExist(string login);
    void enterNewUserData();
    int getNewUserId();
    void saveNewUser(User newUser);

public:
    UserManager() {
        loggedInUserId=0;
    };

    bool isUserLoggedIn();
    void userRegistration();
    void userLogIn();
    void userLogOut();
    void passwordChange(int loggedInUserId);
    int getUserId();
};

#endif // USERMANAGER_H
