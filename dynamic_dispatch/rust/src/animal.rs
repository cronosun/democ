pub trait Animal {
    fn weight(&self) -> f32;
    fn is_mammal(&self) -> bool;
    fn say_hello(&self);
}
