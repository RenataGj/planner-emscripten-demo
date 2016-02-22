//
//  List.hpp
//  ToDoList
//
//  Created by Renata Gjoreska on 2/16/16.
//  Copyright © 2016 Renata Gjoreska. All rights reserved.
//

#ifndef List_h
#define List_h

#include "headers.h"
#include "Item.h"
#include <emscripten/bind.h>

using namespace emscripten;

class List
{
public:
    List(std::string name);

     ~List();
    static List* Create(std::string name);
    
    void setName(std::string name);
    std::string getName() const;
    
    void addItem(Item* item);
    void deleteItem(Item* item);
	int getItemsCount();
	Item* getItem(int index);
	std::vector<Item*> getItems();

    
private:
    std::string name;
    std::vector<Item*> itemList;

};

#endif /* List_h */
