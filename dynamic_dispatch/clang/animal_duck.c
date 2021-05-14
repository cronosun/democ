#include <stdint.h>
#include <stddef.h>
#include "animal.h"
#include "animal_duck.h"
#include <stdbool.h>
#include <stdio.h>

struct AnimalDuckImplementation
{
    float weight;
};

size_t animal_duck_size()
{
    return sizeof(struct AnimalDuckImplementation);
}

struct AnimalDuckImplementation *animal_duck_cast_data(AnimalData data)
{
    return (struct AnimalDuckImplementation *)data;
}

float v_table_weight(AnimalData self)
{
    struct AnimalDuckImplementation *data = animal_duck_cast_data(self);
    return data->weight;
}

bool v_table_is_mammal(AnimalData self)
{
    // note: self is unused.
    return false;
}

void v_table_say_hello(AnimalData self)
{
    float weight = v_table_weight(self);
    printf("Hello, I'm a duck. My weight is %f kg.\n", weight);
}

const struct AnimalVTable animal_duck_vtable = {
    .weight = v_table_weight,
    .is_mammal = v_table_is_mammal,
    .say_hello = v_table_say_hello};

struct Animal animal_duck_init(AnimalDuck duck, float weight)
{
    struct AnimalDuckImplementation *self = (struct AnimalDuckImplementation *)duck;
    self->weight = weight;
    struct Animal animal = {
        .data = self,
        .v_table = &animal_duck_vtable,
    };
    return animal;
}
