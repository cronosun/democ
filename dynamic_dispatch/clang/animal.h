#pragma once
#include <stdbool.h>

// Opaque animal data.
typedef void *AnimalData;

// Virtual method table for animal: https://en.wikipedia.org/wiki/Virtual_method_table
struct AnimalVTable
{
    // returns the weight (in kg) of the animal.
    float (*weight)(AnimalData self);
    // true if it's a mammal
    bool (*is_mammal)(AnimalData self);
    // prints something.. says hello.
    void (*say_hello)(AnimalData self);
};

// The animal, this is called "trait object in rust".
struct Animal
{
    AnimalData data;
    const struct AnimalVTable *v_table;
};

float animal_weight(struct Animal *self);
float animal_is_mamal(struct Animal *self);
void animal_say_hello(struct Animal *self);