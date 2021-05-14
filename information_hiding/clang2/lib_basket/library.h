#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

// Opaque basket type.
typedef void *Basket;
// true: item successfully added to basket.
typedef bool BasketAddSuccess;

// add an item to the basket.
BasketAddSuccess basket_add(Basket self, uint64_t item_id, float price);
// compute the price of all items in the basket.
float basket_compute_price(Basket self);
// number of items in the basket.
int basket_number_of_items(Basket self);