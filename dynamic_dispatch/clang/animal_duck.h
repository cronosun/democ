#pragma once
#include <stddef.h>

typedef void *AnimalDuck;
size_t animal_duck_size();
struct Animal animal_duck_init(AnimalDuck duck, float weight);
