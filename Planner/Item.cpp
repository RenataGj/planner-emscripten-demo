//
//  Item.cpp
//  ToDoList
//
//  Created by Renata Gjoreska on 2/16/16.
//  Copyright © 2016 Renata Gjoreska. All rights reserved.
//

#include "Item.h"

Item::Item(std::string description)
: description(description)
, status(Open)
, alarmDate(0)
, hasAlarm(false)
{
}

Item* Item::Create(std::string description, eStatus status /*= eStatus_NotStarted*/, time_t alarmDate /*= 0*/)
{
	Item* pItem = new Item(description);
	pItem->setStatus(status);
	pItem->setAlarmDate(alarmDate);

    return pItem;
}

void Item::setDescription(std::string description)
{
    this->description = description;
}
std::string Item::getDescription() const 
{
    return description;
}
void Item::setStatus(eStatus status)
{
    this->status = status;
}
int Item::getStatus() const 
{
    return status;
}
void Item::setAlarmDate(time_t date)
{
    this->alarmDate = date;
}
time_t Item::getAlarmDate() const
{
    return alarmDate;
}
void Item::setHasAlarm(bool hasAlarm)
{
	this->hasAlarm = hasAlarm;
}
bool Item::getHasAlarm() const
{
	return hasAlarm;
}


// Binding code
EMSCRIPTEN_BINDINGS(Item) {
	class_<Item::Item>("Item")
		.constructor<string>()
		.function("Create", &Item::Create, allow_raw_pointers())
		.property("description", &Item::getDescription, &Item::setDescription)
		.property("status", &Item::getStatus, &Item::setStatus)
        .property("alarmDate", &Item::getAlarmDate, &Item::setAlarmDate)
		;

	enum_<eStatus>("Status")
		.value("Open", Open)
		.value("Complete", Complete)
		;
}