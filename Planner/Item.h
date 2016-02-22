//
//  Item.hpp
//  ToDoList
//
//  Created by Renata Gjoreska on 2/16/16.
//  Copyright © 2016 Renata Gjoreska. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include "headers.h"
#include <emscripten/bind.h>
#include <time.h>

using namespace emscripten;
using namespace std;

enum eStatus
{
	Open,
	Complete
};

class Item
{
public:
    Item(std::string description);

    static Item* Create(std::string description, eStatus status = Open, time_t alarmDate = 0);
    
    void setDescription(const std::string description);
    std::string getDescription() const;
    void setStatus(eStatus status);
    int getStatus() const;
    void setAlarmDate(time_t date);
    time_t getAlarmDate() const;
	void setHasAlarm(bool hasAlarm);
	bool getHasAlarm() const;

private:
    std::string description;
    eStatus status;
    time_t alarmDate;
	bool hasAlarm;
};

#endif /* Item_h */
