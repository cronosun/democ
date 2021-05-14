use crate::Animal;

pub enum DogName {
    Bella,
    Balu,
}

pub struct Dog {
    weight: f32,
    name: DogName,
}

impl Dog {
    pub fn new(weight: f32, name: DogName) -> Self {
        Self { weight, name }
    }
}

impl Animal for Dog {
    fn weight(&self) -> f32 {
        self.weight
    }

    fn is_mammal(&self) -> bool {
        true
    }

    fn say_hello(&self) {
        let name = match self.name {
            DogName::Bella => "Bella",
            DogName::Balu => "Balu",
        };
        println!(
            "Hello, I'm a dog. I'm called {}, my weight is {} kg.",
            name, self.weight
        );
    }
}
