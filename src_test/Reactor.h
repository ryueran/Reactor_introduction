#ifndef REACTOR_H_
#define REACTOR_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include "Event_Handler.h"
#include "Select.h"

class Event_Handler;

class Reactor {
public:
    Reactor();
    ~Reactor();
    void handle_events();
    void register_handler(Event_Handler *h);
    void remove_handler(Event_Handler *h);
    bool get_pending_status();

private:
    std::vector<Event_Handler*> handlers_ = {};
    bool pending_;
};

Reactor::Reactor()
{
    std::cout << "Reactor constructed!" << std::endl;
    pending_ = false;
}

Reactor::~Reactor()
{
    std::cout << "Reactor destructed!" << std::endl;
}

void Reactor::register_handler(Event_Handler *h)
{
    handlers_.push_back(h);
}

void Reactor::remove_handler(Event_Handler *h)
{
    std::vector<Event_Handler*>::iterator delete_mark;
    delete_mark = std::remove(handlers_.begin(), handlers_.end(), h);
}

void Reactor::handle_events()
{
    // here we have to extract the handlers that has already been assigned
    // std::vector<Event_Handler*> act_handlers = select(handlers_, 0, handlers_.size());
    
    Select *selector = new Select();
    std::vector<Event_Handler*> act_handlers = selector->select_wait(handlers_, 0, 3);

    for(int i = 0; i < act_handlers.size(); i++)
    {
        while(!act_handlers[i]->if_handler_available()){}
        act_handlers[i]->handle_event();
    }

    pending_ = true;
}

bool Reactor::get_pending_status()
{
    return pending_;
}

#endif