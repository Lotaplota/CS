import { getProduct } from "./products.js";

export let cart = JSON.parse(localStorage.getItem('cart')) ||
[{ // Why didn't the teacher use the default operator like this?
  productId: 'e43638ce-6aa0-4b85-b27f-e1d07eb678c6',
  quantity: 666,
  deliveryOptionId: '1'
}, {
  productId: '15b6fc6f-327a-4ec4-896f-486349e85a3d',
  quantity: 1,
  deliveryOptionId: '2'
}];

// if (!cart) {
//   cart = [{
//     productId: 'e43638ce-6aa0-4b85-b27f-e1d07eb678c6',
//     quantity: 666
//     }, {
//       productId: '15b6fc6f-327a-4ec4-896f-486349e85a3d',
//       quantity: 1
//     }];
// }

function saveToStorage() {
  localStorage.setItem('cart', JSON.stringify(cart));
}

export function addToCart(productId) {
  let matchingItem;

  cart.forEach(cartItem => {
    if (cartItem.productId === productId) {
      matchingItem = cartItem
    }
  })

  if (matchingItem) {
    matchingItem.quantity++;
  } else {
    cart.push({
      productId: productId,
      quantity: 1,
      deliveryOptionId: '1' // Changing it to a string fixed a bug
    })
  }
  
  saveToStorage();
}

export function removeFromCart(productId) {
  // cart.forEach((item, index) => {
  //   if (item.productId === productId) {
  //     cart.splice(index, 1);
  //     return;
  //   }
  // })

  // For some reason the teacher prefers the method below:
  let newCart = [];

  cart.forEach(item => {
    if (item.productId !== productId) {
      newCart.push(item);
    }
  });

  cart = newCart;
  // Isn't this method more memory intensive?

  saveToStorage();
}

export function updateDeliveryOption (productId, deliveryOptionId) {
  let matchingItem = getProduct(productId);

  console.log(matchingItem); // DONKEY
  matchingItem.deliveryOptionId = deliveryOptionId; // CONTINUE fix this bug where the delivery option checkmark is not changing
  console.log(matchingItem); // DONKEY

  saveToStorage();
}