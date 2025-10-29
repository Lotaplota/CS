import { cart } from '../data/cart.js';
import { renderOrderSummary } from './checkout/orderSummary.js';
import { renderPaymentSummary } from './checkout/paymentSummary.js';

renderOrderSummary();
renderPaymentSummary();
renderCheckout();

export function renderCheckout(){
    document.querySelector('.return-to-home-link').innerHTML = cart.length;
}