#include <stdint.h>
#include "library.h"
#include <stddef.h>

struct BasketImplementation *basket_cast(Basket self)
{
    return (struct BasketImplementation *)self;
}

BasketAddSuccess basket_add(Basket self, uint64_t item_id, float price)
{
    struct BasketImplementation *cast = basket_cast(self);
    if (cast->number_of_items >= BASKET_MAX_ITEMS)
    {
        return false;
    }
    else
    {
        cast->items[cast->number_of_items].item_id = item_id;
        cast->items[cast->number_of_items].price = price;
        cast->number_of_items += 1;
        return true;
    }
}

float basket_compute_price(Basket self)
{
    struct BasketImplementation *cast = basket_cast(self);
    float price_sum = 0;
    for (int i = 0; i < cast->number_of_items; i++)
    {
        price_sum += cast->items[i].price;
    }
    return price_sum;
}

int basket_number_of_items(Basket self)
{
    struct BasketImplementation *cast = basket_cast(self);
    return cast->number_of_items;
}

Basket basket_impl_init(struct BasketImplementation *basket)
{
    basket->number_of_items = 0;
    return (Basket)basket;
}