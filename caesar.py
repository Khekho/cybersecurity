def caesar_cipher(text, shift, mode='encrypt'):
    result = ''
    
    # Adjust shift for decryption
    if mode == 'decrypt':
        shift = -shift

    for char in text:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            # Shift character and wrap around alphabet
            shifted = (ord(char) - base + shift) % 26 + base
            result += chr(shifted)
        else:
            result += char  # Non-alphabetic characters unchanged

    return result

# Example usage
message = input("Enter message: ")
shift = int(input("Enter shift (number): "))
mode = input("Encrypt or Decrypt? ").strip().lower()

output = caesar_cipher(message, shift, mode)
print(f"Result: {output}")
