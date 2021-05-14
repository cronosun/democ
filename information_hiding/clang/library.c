#include <stdint.h>
#include "library.h"
#include <stddef.h>

int const basket_max_items = 30;

struct BasketItem
{
    uint64_t item_id;
    float price;
};

struct BasketImplementation
{
    struct BasketItem items[basket_max_items];
    int number_of_items;
};

struct BasketImplementation *basket_cast(Basket self)
{
    return (struct BasketImplementation *)self;
}

size_t basket_size()
{
    return sizeof(struct BasketImplementation);
}

void basket_init(Basket self)
{
    struct BasketImplementation *cast = basket_cast(self);
    cast->number_of_items = 0;
}

BasketAddSuccess basket_add(Basket self, uint64_t item_id, float price)
{
    struct BasketImplementation *cast = basket_cast(self);
    if (cast->number_of_items >= basket_max_items)
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
