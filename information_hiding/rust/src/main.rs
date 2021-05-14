use std::ops::{Deref, DerefMut};

mod basket;
mod basket_impl;

pub use {basket::*, basket_impl::*};

fn information_about_basket(basket: &impl Basket) {
    let computed_price = basket.compute_price();
    let number_of_items_in_basket = basket.number_of_items();
    let average_price = computed_price / (number_of_items_in_basket as f32);
    println!(
        "Price of all items in the shopping basket is {} CHF; there are {} \
    items in the basket; average price is {} CHF.",
        computed_price, number_of_items_in_basket, average_price
    );
}

fn fill_the_basket_with_items(basket: &mut impl Basket) {
    basket.add(21412, 15.30).unwrap();
    basket.add(3122, 4.20).unwrap();
    basket.add(212, 9.00).unwrap();
    basket.add(2412341, 48.30).unwrap();
}

fn stack_allocated() {
    // stack allocate basket and init (just one call here)
    let mut basket = BasketImpl::new();
    fill_the_basket_with_items(&mut basket);
    information_about_basket(&basket);
}

fn heap_allocated() {
    // heap allocate and init the basket
    let mut basket = Box::new(BasketImpl::new());
    fill_the_basket_with_items(basket.deref_mut());
    information_about_basket(basket.deref());
    // note: free (or drop) is not required in rust (compiler will do that automatically)
}

fn main() {
    stack_allocated();
    // the same also works with heap allocation
    heap_allocated();
}
