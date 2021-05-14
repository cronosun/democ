#pragma once

#include <stdint.h>
#include "../lib_basket/library.h"
#include <stddef.h>

#define BASKET_MAX_ITEMS 30

struct BasketItem
{
    uint64_t item_id;
    float price;
};

struct BasketImplementation
{
    struct BasketItem items[BASKET_MAX_ITEMS];
    int number_of_items;
};

Basket basket_impl_init(struct BasketImplementation *basket);