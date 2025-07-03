#pragma once
#include <iostream>
#include "clsUser.h"
using namespace std;
// Global variable to hold the current user
clsUser CurrentUser= clsUser::Find("","");

short RetryCount = 2; // Number of login attempts allowed