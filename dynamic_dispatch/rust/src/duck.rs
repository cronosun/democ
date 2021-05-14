use crate::Animal;

pub struct Duck {
    weight: f32,
}

impl Duck {
    pub fn new(weight: f32) -> Self {
        Self { weight }
    }
}

impl Animal for Duck {
    fn weight(&self) -> f32 {
        self.weight
    }

    fn is_mammal(&self) -> bool {
        false
    }

    fn say_hello(&self) {
        println!("Hello, I'm a duck. My weight is {} kg.", self.weight);
    }
}
