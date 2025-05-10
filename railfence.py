def encrypt_rail_fence(text, key):
    rail = ['' for _ in range(key)]
    row, step = 0, 1
    for char in text:
        rail[row] += char
        if row == 0 or row == key - 1: step *= -1
        row += step
    return ''.join(rail)

def decrypt_rail_fence(cipher, key):
    rail = [['' for _ in cipher] for _ in range(key)]
    idx, row, step = 0, 0, 1

    # Mark positions with '*'
    for col in range(len(cipher)):
        rail[row][col] = '*'
        if row == 0 or row == key - 1: step *= -1
        row += step

    # Fill rail with ciphertext
    for i in range(key):
        for j in range(len(cipher)):
            if rail[i][j] == '*' and idx < len(cipher):
                rail[i][j] = cipher[idx]
                idx += 1

    # Read the zigzag pattern
    result, row, step = '', 0, 1
    for col in range(len(cipher)):
        result += rail[row][col]
        if row == 0 or row == key - 1: step *= -1
        row += step
    return result

# Example
msg, k = "HELLOHILL", 3
enc = encrypt_rail_fence(msg, k)
dec = decrypt_rail_fence(enc, k)
print("Encrypted:", enc)
print("Decrypted:", dec)
