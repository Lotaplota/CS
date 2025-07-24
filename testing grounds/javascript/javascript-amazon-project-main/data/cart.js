export let cart = [{
  productId: 'e43638ce-6aa0-4b85-b27f-e1d07eb678c6',
  quantity: 2
}, {
  productId: '15b6fc6f-327a-4ec4-896f-486349e85a3d',
  quantity: 1
}];

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
      quantity: 1
    })
  }
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
  // Isn't this method more intensive?
}