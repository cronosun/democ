#include "animal.h"
#include "animal_duck.h"
#include "animal_dog.h"
#include <stdio.h>
#include <alloca.h>

void use_animal_with_dynamic_dispatch(struct Animal *animal)
{
    float weight = animal_weight(animal);
    printf("----- BEGIN ANIMAL DESCRIPTION -----\n");
    printf("The animal has a weight of %f kg.\n", weight);
    bool is_mamal = animal_is_mamal(animal);
    if (is_mamal)
    {
        printf("It's a mamal\n");
    }
    else
    {
        printf("It's not a mamal (maybe a bird or a fish)\n");
    }
    animal_say_hello(animal);
    printf("----- END -----\n");
}

int main()
{
    // duck 1: stack allocation
    AnimalDuck duck_1 = alloca(animal_duck_size());
    struct Animal duck_1_a = animal_duck_init(duck_1, 0.75);
    // duck 2: stack allocation
    AnimalDuck duck_2 = alloca(animal_duck_size());
    struct Animal duck_2_a = animal_duck_init(duck_2, 1.25);
    // dog 1: stack allocation
    AnimalDuck dog_1 = alloca(animal_dog_size());
    struct Animal dog_1_a = animal_dog_init(dog_1, 14.3, BELLA);
    // dog 2: stack allocation
    AnimalDuck dog_2 = alloca(animal_dog_size());
    struct Animal dog_2_a = animal_dog_init(dog_2, 17.8, BALU);

    // print information about the animals: This uses dynamic dispatch.
    use_animal_with_dynamic_dispatch(&duck_1_a);
    use_animal_with_dynamic_dispatch(&duck_2_a);
    use_animal_with_dynamic_dispatch(&dog_1_a);
    use_animal_with_dynamic_dispatch(&dog_2_a);
}
