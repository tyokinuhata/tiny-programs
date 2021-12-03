# assert文
# アサーション(内部セルフチェック)を行うための言語機能

def apply_discount(product, discount):
    price = int(product["price"] * (1.0 - discount))
    assert 0 <= price <= product["price"], ("foo", "bar", "baz")
    return price

shoes = {
    "name": "Fancy Shoes",
    "price": 14900
}

price = apply_discount(shoes, 0.25)
print(price)

# AssertionError
price = apply_discount(shoes, 2.0)
print(price)
