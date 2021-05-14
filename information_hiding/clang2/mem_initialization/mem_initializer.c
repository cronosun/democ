// note: This is the only part of the application that has access to the 
// internal details of "lib basket".

#include "../lib_basket_impl/library.h"

// data segment basket a
struct BasketImplementation basket_a;
// data segment basket b
struct BasketImplementation basket_b;

Basket basket_a_init_and_get()
{
    return basket_impl_init(&basket_a);
}

Basket basket_b_init_and_get()
{
    return basket_impl_init(&basket_b);
}
