from shift_cipher import encrypt, decrypt

text = "HELLO WORLD"
key = 3

cipher = encrypt(text, key)
plain = decrypt(cipher, key)

print("Plaintext :", text)
print("Ciphertext:", cipher)
print("Decrypted :", plain)
