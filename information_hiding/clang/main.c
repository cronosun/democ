#include "library.h"
#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

void information_about_basket(Basket basket)
{
    float computed_price = basket_compute_price(basket);
    int number_of_items_in_basket = basket_number_of_items(basket);
    float average_price = computed_price / (float)number_of_items_in_basket;
    printf("Price of all items in the shopping basket is %f CHF; there are %i "
           "items in the basket; average price is %f CHF.\n",
           computed_price, number_of_items_in_basket, average_price);
}

void fill_the_basket_with_items(Basket basket)
{
    basket_add(basket, 21412, 15.30);
    basket_add(basket, 3122, 4.20);
    basket_add(basket, 212, 9.00);
    basket_add(basket, 2412341, 48.30);
}

void stack_allocated()
{
    // stack allocate basket
    Basket basket = alloca(basket_size());
    // .. and init
    basket_init(basket);
    fill_the_basket_with_items(basket);
    information_about_basket(basket);
}

void heap_allocated()
{
    // heap allocate the basket
    Basket basket = malloc(basket_size());
    // .. and init
    basket_init(basket);
    fill_the_basket_with_items(basket);
    information_about_basket(basket);
    free(basket);
}

int main()
{
    stack_allocated();
    // the same also works with heap allocation
    heap_allocated();
}