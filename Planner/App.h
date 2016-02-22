//
//  App.hpp
//  ToDoList
//
//  Created by Renata Gjoreska on 2/16/16.
//  Copyright © 2016 Renata Gjoreska. All rights reserved.
//

#ifndef App_h
#define App_h

#include "headers.h"
#include "List.h"
#include <emscripten/bind.h>

using namespace emscripten;

class App
{
public:
    App();
    ~App();

    void addList(List* list);
	int getListsCount();
	List* getList(int index);
	std::vector<List*> getLists();

private:
    std::vector<List*> toDoLists;

};

#endif /* App_h */
