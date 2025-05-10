import math

def encrypt(msg, key):
    k_order = sorted(range(len(key)), key=lambda x: key[x])
    rows = math.ceil(len(msg) / len(key))
    grid = [msg[i:i+len(key)].ljust(len(key), 'X') for i in range(0, len(msg), len(key))]
    return ''.join(''.join(row[i] for row in grid) for i in k_order)

def decrypt(cipher, key):
    k_order = sorted(range(len(key)), key=lambda x: key[x])
    cols, rows = len(key), math.ceil(len(cipher) / len(key))
    grid = [[''] * cols for _ in range(rows)]
    idx = 0
    for i in k_order:
        for r in range(rows):
            grid[r][i] = cipher[idx]
            idx += 1
    return ''.join(''.join(row) for row in grid).rstrip('X')

# Example
msg, key = "WEAREDISCOVEREDFLEEATONCE", "ZEBRAS"
enc = encrypt(msg, key)
dec = decrypt(enc, key)
print("Encrypted:", enc)
print("Decrypted:", dec)



🔐 Encryption Steps:
Write the message in rows, filling a grid with key length columns.

Pad with X if the message doesn't fit the grid evenly.

Number columns by the alphabetical order of the key.

Read columns in the key's alphabetical order to get the ciphertext.

🔓 Decryption Steps:
Create an empty grid with the same number of rows and columns as encryption.

Fill the columns of the grid using the ciphertext in the key's alphabetical order.

Read the grid row-wise to retrieve the original message.

Remove padding (X) if used.