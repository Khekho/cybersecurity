import random

# Function to find GCD
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Function to find modular inverse
def mod_inverse(e, phi):
    for d in range(1, phi):
        if (e * d) % phi == 1:
            return d
    return None

# Function to check for prime
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# RSA Key generation
def generate_keys():
    p = q = 0
    while not is_prime(p):
        p = random.randint(10, 50)
    while not is_prime(q) or q == p:
        q = random.randint(10, 50)

    n = p * q
    phi = (p - 1) * (q - 1)

    e = random.choice([x for x in range(2, phi) if gcd(x, phi) == 1])
    d = mod_inverse(e, phi)

    return (e, n), (d, n)

# Encryption
def encrypt(message, public_key):
    e, n = public_key
    return [pow(ord(char), e, n) for char in message]

# Decryption
def decrypt(ciphertext, private_key):
    d, n = private_key
    return ''.join([chr(pow(char, d, n)) for char in ciphertext])

# Example usage
public, private = generate_keys()
msg = "gopal"
cipher = encrypt(msg, public)
plain = decrypt(cipher, private)

print("Original:", msg)
print("Encrypted:", cipher)
print("Decrypted:", plain)
