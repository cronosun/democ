/// The "inteface" (or trait) for basket. Implementation specific information is hidden.
pub trait Basket {
    fn add(&mut self, item_id: impl Into<ItemId>, price: f32) -> Result<(), ()>;
    fn compute_price(&self) -> f32;
    fn number_of_items(&self) -> usize;
}

pub struct ItemId(u64);

impl From<u64> for ItemId {
    fn from(value: u64) -> Self {
        Self(value)
    }
}
