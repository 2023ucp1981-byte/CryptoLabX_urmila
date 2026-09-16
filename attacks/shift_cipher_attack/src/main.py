from shift_cipher import encrypt
from brute_force_dictionary import load_dictionary, dictionary_attack
from chi_square_attack import chi_square_attack


plaintext = "this is a simple secret message for cryptography testing"
actual_key = 5

ciphertext = encrypt(plaintext, actual_key)

dictionary = load_dictionary("../dictionary/english_words.txt")

dict_key, dict_score, dict_plaintext = dictionary_attack(
    ciphertext, dictionary
)

chi_key, chi_score, chi_plaintext = chi_square_attack(ciphertext)

print("Original Plaintext:")
print(plaintext)

print("\nActual Key:", actual_key)

print("\nCiphertext:")
print(ciphertext)

print("\nDictionary Attack")
print("Predicted Key:", dict_key)
print("Score:", dict_score)
print("Plaintext:", dict_plaintext)

print("\nChi-Square Attack")
print("Predicted Key:", chi_key)
print("Score:", chi_score)
print("Plaintext:", chi_plaintext)
