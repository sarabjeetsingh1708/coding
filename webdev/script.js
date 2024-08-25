let cartCount = 0;

function addToCart(productName, productPrice) {
    cartCount++;
    document.getElementById('cart-count').innerText = cartCount;

    const cartItems = JSON.parse(localStorage.getItem('cartItems')) || [];
    cartItems.push({ name: productName, price: productPrice });
    localStorage.setItem('cartItems', JSON.stringify(cartItems));

    alert(`${productName} has been added to your cart.`);
}

// To show cart items in the future, you could use this function
function showCartItems() {
    const cartItems = JSON.parse(localStorage.getItem('cartItems')) || [];
    console.log(cartItems);
}
