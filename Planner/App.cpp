//
//  App.cpp
//  ToDoList
//
//  Created by Renata Gjoreska on 2/16/16.
//  Copyright © 2016 Renata Gjoreska. All rights reserved.
//

#include "App.h"

App::App()
{
	List* toDoList = List::Create("To Do List");

	Item* item1 = Item::Create("Make presentation", Open);
	Item* item2 = Item::Create("Code example", Complete);
	Item* item3 = Item::Create("Breakfast", Complete);
	Item* item4 = Item::Create("Running", Open);
	Item* item5 = Item::Create("Shopping", Open);

	toDoList->addItem(item1);
	toDoList->addItem(item2);
	toDoList->addItem(item3);
	toDoList->addItem(item4);
	toDoList->addItem(item5);
}

App::~App()
{
    for(auto it = toDoLists.begin(); it != toDoLists.end(); it++)
    {
        List* list = *it;
        if (list)
            delete list;
    }
    
    toDoLists.clear();
}

void App::addList(List* list)
{
    toDoLists.push_back(list);
}
int App::getListsCount()
{
	return toDoLists.size();
}
List* App::getList(int index)
{
	return index < toDoLists.size() ? toDoLists[index] : 0;
}
std::vector<List*> App::getLists()
{
	return toDoLists;
}

// Binding code
EMSCRIPTEN_BINDINGS(App) {
	class_<App::App>("App")
		.constructor<>()
		.function("addList", &App::addList, allow_raw_pointers())
		.function("getList", &App::getList, allow_raw_pointers())
		;
}