#include "mem_initialization/mem_initializer.h"
#include "lib_basket/library.h"
#include <stdio.h>

void information_about_basket(Basket basket)
{
    float computed_price = basket_compute_price(basket);
    int number_of_items_in_basket = basket_number_of_items(basket);
    float average_price = computed_price / (float)number_of_items_in_basket;
    printf("Price of all items in the shopping basket is %f CHF; there are %i "
           "items in the basket; average price is %f CHF.\n",
           computed_price, number_of_items_in_basket, average_price);
}

// this is the application. Note: No information about the used basket 
// implementation / no implementation details are accessible.
void application_run(Basket basket_a, Basket basket_b)
{
    // use basket a
    basket_add(basket_a, 21412, 15.30);
    basket_add(basket_a, 3122, 4.20);
    basket_add(basket_a, 212, 9.00);
    basket_add(basket_a, 2412341, 48.30);

    // use basket b
    basket_add(basket_b, 3423323, 1.20);
    basket_add(basket_b, 234234, 3.30);
    basket_add(basket_b, 234555, 2.00);
    basket_add(basket_b, 23402340, 1.2);
    basket_add(basket_b, 233423423, 1.24);

    information_about_basket(basket_a);
    information_about_basket(basket_b);
}

int main()
{
    // initialize the data segment
    // all global data from the data segment (could be much more).
    Basket basket_a = basket_a_init_and_get();
    Basket basket_b = basket_b_init_and_get();
    // run the application
    application_run(basket_a, basket_b);
}