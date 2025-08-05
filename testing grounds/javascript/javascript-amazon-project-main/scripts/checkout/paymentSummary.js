import { cart } from "../../data/cart.js";
import { getProduct } from "../../data/products.js";

export function renderPaymentSummary() {
  cart.forEach(cartItem => {
    const product = getProduct(cartItem.productId);
    product.priceCents // CONTINUE
  });
}