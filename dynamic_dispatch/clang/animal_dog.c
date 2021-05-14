#include <stdint.h>
#include <stddef.h>
#include "animal.h"
#include "animal_dog.h"
#include <stdbool.h>
#include <stdio.h>

struct AnimalDogImplementation
{
    float weight;
    enum AnimalDogName name;
};

size_t animal_dog_size()
{
    return sizeof(struct AnimalDogImplementation);
}

struct AnimalDogImplementation *animal_dog_cast_data(AnimalData data)
{
    return (struct AnimalDogImplementation *)data;
}

float v_table_weight_dog(AnimalData self)
{
    struct AnimalDogImplementation *data = animal_dog_cast_data(self);
    return data->weight;
}

bool v_table_is_mammal_dog(AnimalData self)
{
    // note: self is unused.
    return true;
}

void v_table_say_hello_dog(AnimalData self)
{
    float weight = v_table_weight_dog(self);
    struct AnimalDogImplementation *data = animal_dog_cast_data(self);
    char *name;
    switch (data->name)
    {
    case BELLA:
        name = "Bella";
        break;
    case BALU:
        name = "Balu";
        break;
    default:
        name = "Unknown";
    }
    printf("Hello, I'm a dog. I'm called %s, my weight is %f kg.\n", name, weight);
}

const struct AnimalVTable animal_dog_vtable = {
    .weight = v_table_weight_dog,
    .is_mammal = v_table_is_mammal_dog,
    .say_hello = v_table_say_hello_dog};

struct Animal animal_dog_init(AnimalDog dog, float weight, enum AnimalDogName name)
{
    struct AnimalDogImplementation *self = (struct AnimalDogImplementation *)dog;
    self->weight = weight;
    self->name = name;
    struct Animal animal = {
        .data = self,
        .v_table = &animal_dog_vtable,
    };
    return animal;
}
