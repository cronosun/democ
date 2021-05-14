#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

// Opaque basket type.
typedef void *Basket;
// true: item successfully added to basket.
typedef bool BasketAddSuccess;

// The size of basket.
size_t basket_size();
// inititlaize the basket.
void basket_init(Basket self);
// add an item to the basket.
BasketAddSuccess basket_add(Basket self, uint64_t item_id, float price);
// compute the price of all items in the basket.
float basket_compute_price(Basket self);
// number of items in the basket.
int basket_number_of_items(Basket self);