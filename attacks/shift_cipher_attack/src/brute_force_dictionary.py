from shift_cipher import decrypt


def load_dictionary(filename):
    with open(filename, "r") as file:
        return set(word.strip().lower() for word in file)


def dictionary_attack(ciphertext, dictionary):
    best_key = 0
    best_score = -1
    best_plaintext = ""

    for key in range(26):
        plaintext = decrypt(ciphertext, key)

        words = plaintext.lower().split()
        score = sum(word in dictionary for word in words)

        if score > best_score:
            best_score = score
            best_key = key
            best_plaintext = plaintext

    return best_key, best_score, best_plaintext

