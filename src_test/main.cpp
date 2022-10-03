#include <iostream>
#include <memory>
#include "Event_Handler.h"
#include "Reactor.h"
#include "ThreadPool.h"

// int main()
// {
//     std::unique_ptr<Reactor> reactor = std::make_unique<Reactor>();

//     Event_Handler* handler1 = new Event_Handler();
//     Event_Handler* handler2 = new Event_Handler();
//     Event_Handler* handler3 = new Event_Handler();

//     handler1->set_event(ACCEPT_EVENT);
//     std::function<void()> act1 = []() {std::cout << "read event 1!" << std::endl;};
//     handler1->set_accept_actor(act1);
//     reactor->register_handler(handler1);

//     handler2->set_event(WRITE_EVENT);
//     std::function<void()> act2 = []() {std::cout << "write event 1!" << std::endl;};
//     handler2->set_write_actor(act2);
//     reactor->register_handler(handler2);

//     handler3->set_event(READ_EVENT);
//     std::function<void()> act3 = []() {std::cout << "read event 2!" << std::endl;};
//     handler3->set_read_actor(act3);
//     reactor->register_handler(handler3);

//     reactor->handle_events();
//     return 0;
// }

void add_handlers(
    Reactor* r1, Reactor* r2, Reactor* r3, Reactor* r4, Reactor* r5, 
    Event_Handler *h1, Event_Handler* h2, Event_Handler* h3)
{
    r1->register_handler(h1);
    r1->register_handler(h2);
    r1->register_handler(h3);

    r2->register_handler(h1);
    r2->register_handler(h2);
    r2->register_handler(h3);

    r3->register_handler(h1);
    r3->register_handler(h2);
    r3->register_handler(h3);

    r4->register_handler(h1);
    r4->register_handler(h2);
    r4->register_handler(h3);

    r5->register_handler(h1);
    r5->register_handler(h2);
    r5->register_handler(h3);
}

int main()
{
    ThreadPool pool(5);


    Event_Handler* handler1 = new Event_Handler();
    Event_Handler* handler2 = new Event_Handler();
    Event_Handler* handler3 = new Event_Handler();

    handler1->set_event(ACCEPT_EVENT);
    std::function<void()> act1 = []() {std::cout << "read event 1! is executed by: " << std::this_thread::get_id() << std::endl;};
    handler1->set_accept_actor(act1);

    handler2->set_event(WRITE_EVENT);
    std::function<void()> act2 = []() {std::cout << "write event 1! is executed by:" << std::this_thread::get_id() << std::endl;};
    handler2->set_write_actor(act2);

    handler3->set_event(READ_EVENT);
    std::function<void()> act3 = []() {std::cout << "read event 2! is executed by:" << std::this_thread::get_id() << std::endl;};
    handler3->set_read_actor(act3);

    Reactor* reactor1 = pool.getNextReactor();
    Reactor* reactor2 = pool.getNextReactor();
    Reactor* reactor3 = pool.getNextReactor();
    Reactor* reactor4 = pool.getNextReactor();
    Reactor* reactor5 = pool.getNextReactor();

    std::thread thread_main(add_handlers, reactor1, reactor2, reactor3, reactor4, reactor5, handler1, handler2, handler3);
    thread_main.join();

    return 0;
}