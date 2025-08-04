import { cart, removeFromCart } from '../data/cart.js';
import { products } from '../data/products.js';    // Double dots means return one folder
import { formatCurrency } from './utils/money.js'; // Single dot means same folder
import { hello } from 'https://unpkg.com/supersimpledev@1.0.1/hello.esm.js';
import dayjs from 'https://unpkg.com/supersimpledev@8.5.0/dayjs/esm/index.js'; // The ESM version of the code is needed to use it as a module (see ECMAScript)
                                                                               // This is also called a "default export". The other ones are called "named exports" 
import { deliveryOptions } from '../data/deliveryOptions.js';

let today = dayjs().format('dddd, MMM. D');

let cartSummaryHTML = ''

cart.forEach(cartItem => {
  const productId = cartItem.productId;

  // Getting the cart item's product data
  let matchingProduct;
  
  products.forEach(product => {
    if (product.id === productId) {
      matchingProduct = product;
    }
  })
  
  // Getting the delivery option
  let matchingDeliveryOption;

  deliveryOptions.forEach(option => {
    if (option.id === cartItem.deliveryOptionId) {
      matchingDeliveryOption = option;
    }
  });

  const today = dayjs();
  const deliveryDate = today.add(matchingDeliveryOption.deliveryDays, 'days');
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
            $${formatCurrency(matchingProduct.priceCents)}
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

    const priceString = deliveryOption.priceCents
      ? `${formatCurrency(deliveryOption.priceCents)} -`
      : 'FREE'
    ;

    const isChecked = deliveryOption.id === cartItem.deliveryOptionId;

    html += `
      <div class="delivery-option">
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
    })
  })