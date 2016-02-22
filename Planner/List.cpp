//
//  List.cpp
//  ToDoList
//
//  Created by Renata Gjoreska on 2/16/16.
//  Copyright © 2016 Renata Gjoreska. All rights reserved.
//

#include "List.h"

List::List(std::string name)
: name(name)
{
}

List::~List()
{
    for(auto it = itemList.begin(); it != itemList.end(); it++)
    {
        Item* item = *it;
        if (item)
         delete item;
    }
    
    itemList.clear();
}

List* List::Create(std::string name)
{
    return new List(name);
}

void List::setName(std::string name)
{
    this->name = name;
}
std::string List::getName() const 
{
    return name;
}

void List::addItem(Item* item)
{
    itemList.push_back(item);
}
void List::deleteItem(Item* item)
{
    
}
int List::getItemsCount()
{
	return itemList.size();
}
Item* List::getItem(int index)
{
	return itemList.size() > index ? itemList.at(index) : 0;
}
std::vector<Item*> List::getItems()
{
	return itemList;
}

// Binding code
EMSCRIPTEN_BINDINGS(List) {
	class_<List::List>("List")
		.constructor<std::string>()
		.function("Create", &List::Create, allow_raw_pointers())
		.function("addItem", &List::addItem, allow_raw_pointers())
		.function("getItem", &List::getItem, allow_raw_pointers())
		.function("getItemsCount", &List::getItemsCount)
		.function("getItems", &List::getItems, allow_raw_pointers())
		.property("name", &List::getName, &List::setName)
		;
}