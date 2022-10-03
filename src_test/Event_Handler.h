#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <iostream>
#include <functional>
#include <thread>

enum Event_Type {
    ACCEPT_EVENT = 0,
    READ_EVENT = 1,
    WRITE_EVENT = 2
};

class Event_Handler {
public:
    Event_Handler();
    ~Event_Handler();
    void set_event(Event_Type type);
    void handle_event();
    void set_accept_actor(std::function<void()> task);
    void set_read_actor(std::function<void()> task);
    void set_write_actor(std::function<void()> task);
    bool if_handler_available();
private:
    std::function<void()> accept_actor_;
    std::function<void()> read_actor_;
    std::function<void()> write_actor_;
    Event_Type type_;
};

Event_Handler::Event_Handler()
{
    std::cout << "Event_Handler constructed!" << std::endl;
}

Event_Handler::~Event_Handler()
{
    std::cout << "Event_Handler destructed!" << std::endl;
}

void Event_Handler::set_event(Event_Type type)
{
    type_ = type;
}

void Event_Handler::set_accept_actor(std::function<void()> task)
{
    accept_actor_ = task;
}

void Event_Handler::set_read_actor(std::function<void()> task)
{
    read_actor_ = task;
}

void Event_Handler::set_write_actor(std::function<void()> task)
{
    write_actor_ = task;
}

void Event_Handler::handle_event()
{
    if(type_ == ACCEPT_EVENT)
    {
        accept_actor_();
    }

    if(type_ == READ_EVENT)
    {
        read_actor_();
    }

    if(type_ == WRITE_EVENT)
    {
        write_actor_();
    }
}

bool Event_Handler::if_handler_available()
{
    if(accept_actor_ == NULL && write_actor_ == NULL && read_actor_ == NULL)
    {
        return false;
    }

    return true;
}

#endif