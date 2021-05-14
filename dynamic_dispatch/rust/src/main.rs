mod animal;
mod dog;
mod duck;

pub use {animal::*, dog::*, duck::*};

fn use_animal_with_dynamic_dispatch(animal: &dyn Animal) {
    let weight = animal.weight();
    println!("----- BEGIN ANIMAL DESCRIPTION -----");
    println!("The animal has a weight of {} kg.", weight);
    let is_mamal = animal.is_mammal();
    if is_mamal {
        println!("It's a mamal");
    } else {
        println!("It's not a mamal (maybe a bird or a fish)");
    }
    animal.say_hello();
    println!("----- END -----");
}

fn main() {
    // stack allocation
    let duck_1 = Duck::new(0.75f32);
    let duck_2 = Duck::new(1.25f32);
    let dog_1 = Dog::new(14.3f32, DogName::Bella);
    let dog_2 = Dog::new(17.8f32, DogName::Balu);

    // dynamic dispatch
    use_animal_with_dynamic_dispatch(&duck_1);
    use_animal_with_dynamic_dispatch(&duck_2);
    use_animal_with_dynamic_dispatch(&dog_1);
    use_animal_with_dynamic_dispatch(&dog_2);

    // rust addition (only works with rust): the same animals can also be static dispatched.
    rust_addition_static_dispatch(&duck_1);
    rust_addition_static_dispatch(&duck_2);
    rust_addition_static_dispatch(&dog_1);
    rust_addition_static_dispatch(&dog_2);
}

fn rust_addition_static_dispatch(animal: &impl Animal) {
    let weight = animal.weight();
    println!("----- BEGIN ANIMAL DESCRIPTION -----");
    println!("The animal has a weight of {} kg.", weight);
    let is_mamal = animal.is_mammal();
    if is_mamal {
        println!("It's a mamal");
    } else {
        println!("It's not a mamal (maybe a bird or a fish)");
    }
    animal.say_hello();
    println!("----- END -----");
}
