function Cart(localStorageKey) {
    const cart = {
        cartItems: undefined,

        loadFromStorage() {
            this.cartItems = JSON.parse(localStorage.getItem(localStorageKey));

            if (!this.cartItems) {
                this.cartItems = [{
                    productId: 'e43638ce-6aa0-4b85-b27f-e1d07eb678c6',
                    quantity: 2,
                    deliveryOptionId: '1'
                }, {
                    productId: '15b6fc6f-327a-4ec4-896f-486349e85a3d',
                    quantity: 1,
                    deliveryOptionId: '2'
                }];
            }
        },

        saveToStorage() {
            localStorage.setItem(localStorageKey, JSON.stringify(this.cartItems));
        },

        addToCart(productId) {
            let matchingItem;

            this.cartItems.forEach(cartItem => {
                if (cartItem.productId === productId) {
                    matchingItem = cartItem
                }
            })

            if (matchingItem) {
                matchingItem.quantity++;
            } else {
                this.cartItems.push({
                    productId: productId,
                    quantity: 1,
                    deliveryOptionId: '1' // Changing it to a string fixed a bug
                })
            }
            
            this.saveToStorage();
        },

        removeFromCart(productId) {
            let newCart = [];

            this.cartItems.forEach(item => {
                if (item.productId !== productId) {
                    newCart.push(item);
                }
            });

            this.cartItems = newCart;

            saveToStorage();
        },

        updateDeliveryOption (productId, deliveryOptionId) {
            let matchingItem = getItem(productId);

            matchingItem.deliveryOptionId = deliveryOptionId;

            saveToStorage();
        },

        getItem(id) {
            let matchingItem;

            this.cartItems.forEach(item => {
            if (id === item.productId) {
                matchingItem = item;
            }
            });

            return matchingItem;
        }
    };

    return cart;
}

const cart = Cart('cart-oop');
const businessCart = Cart('cart-business');

cart.loadFromStorage();
businessCart.loadFromStorage();

console.log(cart);
console.log(businessCart);