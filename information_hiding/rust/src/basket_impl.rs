use crate::{Basket, ItemId};

const MAX_ITEMS: usize = 30;

/// Implementation of a basket.
pub struct BasketImpl {
    items: [BasketItem; MAX_ITEMS],
    number_of_items: usize,
}

impl Basket for BasketImpl {
    fn add(&mut self, item_id: impl Into<ItemId>, price: f32) -> Result<(), ()> {
        if self.number_of_items >= MAX_ITEMS {
            Err(())
        } else {
            self.items[self.number_of_items] = BasketItem {
                _item_id: item_id.into(),
                price,
            };
            self.number_of_items += 1;
            Ok(())
        }
    }

    fn compute_price(&self) -> f32 {
        let mut price = 0f32;
        for item in &self.items[0..self.number_of_items] {
            price += item.price;
        }
        price
    }

    fn number_of_items(&self) -> usize {
        self.number_of_items
    }
}

impl BasketImpl {
    pub fn new() -> Self {
        Self {
            items: Default::default(),
            number_of_items: 0,
        }
    }
}

struct BasketItem {
    _item_id: ItemId,
    price: f32,
}

impl Default for BasketItem {
    fn default() -> Self {
        Self {
            _item_id: 0.into(),
            price: 0f32,
        }
    }
}
