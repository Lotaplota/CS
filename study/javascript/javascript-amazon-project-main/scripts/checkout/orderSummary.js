import { cart, removeFromCart, updateDeliveryOption } from '../../data/cart.js';
import { getProduct, products } from '../../data/products.js';    // Double dots means return one folder
import { formatCurrency } from '../utils/money.js'; // Single dot means same folder
import { hello } from 'https://unpkg.com/supersimpledev@1.0.1/hello.esm.js';
import dayjs from 'https://unpkg.com/supersimpledev@8.5.0/dayjs/esm/index.js'; // The ESM version of the code is needed to use it as a module (see ECMAScript)
                                                                               // This is also called a "default export". The other ones are called "named exports" 
import { deliveryOptions, getDeliveryOption } from '../../data/deliveryOptions.js';
import { renderPaymentSummary } from './paymentSummary.js';
import { renderCheckout } from '../checkout.js';

export function renderOrderSummary() {

  let cartSummaryHTML = ''
  
  cart.forEach(cartItem => {
    const productId = cartItem.productId;
  
    // Getting the cart item's product data
    let matchingProduct = getProduct(productId);
    
    // Getting the delivery option
    const deliveryOption = getDeliveryOption(cartItem.deliveryOptionId);
  
    const today = dayjs();
    const deliveryDate = today.add(deliveryOption.deliveryDays, 'days');
    const dateString = deliveryDate.format('dddd, MMMM D');
  
    // Buildind the cart summary's html
    cartSummaryHTML += `
      <div class="cart-item-container js-cart-item-container-${matchingProduct.id}">
        <div class="delivery-date">
          Delivery date: ${dateString}
        </div>
  
        <div class="cart-item-details-grid">
          <img class="product-image"
            src="${matchingProduct.image}">
  
          <div class="cart-item-details">
            <div class="product-name">
              ${matchingProduct.name}
            </div>
            <div class="product-price">
              ${matchingProduct.getPrice()}
            </div>
            <div class="product-quantity">
              <span>
                Quantity: <span class="quantity-label">${cartItem.quantity}</span>
              </span>
              <span class="update-quantity-link link-primary">
                Update
              </span>
              <span class="delete-quantity-link link-primary js-delete-link" data-product-id="${matchingProduct.id}">
                Delete
              </span>
            </div>
          </div>
  
          <div class="delivery-options">
            <div class="delivery-options-title">
              Choose a delivery option:
            </div>
            ${deliveryOptionsHTML(matchingProduct, cartItem)}
          </div>
        </div>
      </div>
    `
  })
  
  function deliveryOptionsHTML(product, cartItem) {
    let html = '';
  
    deliveryOptions.forEach(deliveryOption => {
      const today = dayjs();
      const deliveryDate = today.add(deliveryOption.deliveryDays, 'days');
      const dateString = deliveryDate.format('dddd, MMMM D');
  
      const priceString = deliveryOption.priceCents // I realized that checking === 0 would communicate intent more evidently. When rereading this code, I wasn't sure what was this bit doing because it wasn't clear enough. Though I will leave this in here so this bit of learning from my mistakes gets recorded.
        ? `${formatCurrency(deliveryOption.priceCents)} -`
        : 'FREE'
      ;
  
      const isChecked = deliveryOption.id === cartItem.deliveryOptionId;
  
      html += `
        <div class="delivery-option js-delivery-option"
        data-product-id="${product.id}"
        data-delivery-option-id="${deliveryOption.id}">
          <input type="radio" ${isChecked ? 'checked' : ''}
            class="delivery-option-input"
            name="delivery-option-${product.id}">
          <div>
            <div class="delivery-option-date">
              ${dateString}
            </div>
            <div class="delivery-option-price">
              ${priceString} Shipping
            </div>
          </div>
        </div>
      `
    });
  
    return html;
  }
  
  document.querySelector('.js-order-summary')
    .innerHTML = cartSummaryHTML;
  
  document.querySelectorAll('.js-delete-link')
    .forEach(link => {
      link.addEventListener('click',() => {
        const productId = link.dataset.productId;
        removeFromCart(productId);
  
        const container = document.querySelector(`.js-cart-item-container-${productId}`);
        container.remove();

        renderCheckout();
        renderPaymentSummary();
      })
    })
  
  document.querySelectorAll('.js-delivery-option')
    .forEach((element) =>{
      element.addEventListener('click', () => {
        const {productId, deliveryOptionId} = element.dataset; // This is a shorthand property. A bit tricky to master so... keep in mind.
        updateDeliveryOption(productId, deliveryOptionId);
        renderOrderSummary();
        renderPaymentSummary();
      })
    })
}

renderOrderSummary(); // The professor talked about MVC, a design pattern that stands for 'Model, View, and Controller', which happens in a cicle