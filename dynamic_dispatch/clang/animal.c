#include "animal.h"

float animal_weight(struct Animal *self)
{
    return self->v_table->weight(self->data);
}

float animal_is_mamal(struct Animal *self)
{
    return self->v_table->is_mammal(self->data);
}

void animal_say_hello(struct Animal *self)
{
    self->v_table->say_hello(self->data);
}