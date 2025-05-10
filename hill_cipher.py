import numpy as np

# Size of the matrix
N = 3

# Function to find modulo inverse of a number under mod 26
def mod_inverse(a, m):
	for x in range(1, m):
		if ((a % m) * (x % m)) % m == 1:
			return x
	return -1

# Function to get key matrix from key string
def getKeyMatrix(key):
	keyMatrix = [[0] * N for _ in range(N)]
	k = 0
	for i in range(N):
		for j in range(N):
			keyMatrix[i][j] = ord(key[k]) % 65
			k += 1
	return keyMatrix

# Function to perform matrix multiplication and modulo 26
def matrix_mod_mul(A, B):
	result = [[0] for _ in range(N)]
	for i in range(N):
		for j in range(1):
			for x in range(N):
				result[i][j] += A[i][x] * B[x][j]
			result[i][j] %= 26
	return result

# Function to compute inverse of a matrix modulo 26
def matrix_mod_inverse(matrix):
	det = int(np.round(np.linalg.det(matrix)))  # determinant
	det_inv = mod_inverse(det % 26, 26)

	if det_inv == -1:
		raise ValueError("Key matrix is not invertible under mod 26.")

	# Matrix of cofactors
	adjugate = np.round(det * np.linalg.inv(matrix)).astype(int) % 26

	# Multiply by modular inverse of the determinant
	inverse = (det_inv * adjugate) % 26
	return inverse.astype(int).tolist()

# Encrypt function
def HillCipherEncrypt(message, key):
	messageVector = [[ord(c) % 65] for c in message]
	keyMatrix = getKeyMatrix(key)
	cipherMatrix = matrix_mod_mul(keyMatrix, messageVector)
	CipherText = ''.join([chr(c[0] + 65) for c in cipherMatrix])
	return CipherText

# Decrypt function
def HillCipherDecrypt(cipher, key):
	cipherVector = [[ord(c) % 65] for c in cipher]
	keyMatrix = getKeyMatrix(key)
	invKeyMatrix = matrix_mod_inverse(keyMatrix)
	messageMatrix = matrix_mod_mul(invKeyMatrix, cipherVector)
	PlainText = ''.join([chr(m[0] + 65) for m in messageMatrix])
	return PlainText

# Driver
def main():
	message = "ACT"
	key = "GYBNQKURP"  # Must be 9 characters for 3x3

	print("Original Message:", message)
	cipher = HillCipherEncrypt(message, key)
	print("Encrypted Message:", cipher)

	decrypted = HillCipherDecrypt(cipher, key)
	print("Decrypted Message:", decrypted)

if __name__ == "__main__":
	main()
