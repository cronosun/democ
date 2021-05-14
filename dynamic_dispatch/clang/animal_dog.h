#pragma once
#include <stddef.h>

enum AnimalDogName
{
    BELLA,
    BALU
};
typedef void *AnimalDog;
size_t animal_dog_size();
struct Animal animal_dog_init(AnimalDog duck, float weight, enum AnimalDogName name);