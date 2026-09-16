import os
from datetime import datetime
from collections import Counter


DATASET_FOLDER = "datasets"
OUTPUT_FOLDER = "outputs"
LOG_FILE = os.path.join(OUTPUT_FOLDER, "cryptolabx.log")


def create_required_folders():
    """Create required folders if they do not exist."""
    os.makedirs(DATASET_FOLDER, exist_ok=True)
    os.makedirs(OUTPUT_FOLDER, exist_ok=True)


def log_activity(option):
    """Record date, time and selected menu option."""
    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    with open(LOG_FILE, "a") as file:
        file.write(f"{current_time} - Selected Option: {option}\n")


def display_menu():
    """Display the main menu."""
    print("\n" + "=" * 45)
    print("              CryptoLabX")
    print("=" * 45)
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Attack")
    print("4. Analyze")
    print("5. Exit")
    print("=" * 45)


def analyze_file():
    """Analyze a text file from the datasets folder."""

    print("\nAvailable datasets:")

    files = [
        file for file in os.listdir(DATASET_FOLDER)
        if file.endswith(".txt")
    ]

    if not files:
        print("No dataset files found.")
        return

    for index, file in enumerate(files, start=1):
        print(f"{index}. {file}")

    try:
        choice = int(input("\nSelect dataset number: "))

        if choice < 1 or choice > len(files):
            print("Invalid dataset selection.")
            return

        selected_file = files[choice - 1]
        file_path = os.path.join(DATASET_FOLDER, selected_file)

        with open(file_path, "r", encoding="utf-8") as file:
            text = file.read()

        characters = len(text)
        words = len(text.split())
        lines = len(text.splitlines())
        unique_characters = len(set(text))

        letters_only = [
            char.lower()
            for char in text
            if char.isalpha()
        ]

        frequency = Counter(letters_only)

        print("\n" + "=" * 45)
        print("             File Analysis")
        print("=" * 45)

        print(f"File Name          : {selected_file}")
        print(f"Number of Characters: {characters}")
        print(f"Number of Words     : {words}")
        print(f"Number of Lines     : {lines}")
        print(f"Unique Characters   : {unique_characters}")

        print("\nLetter Frequency:")
        print("-" * 25)

        for letter in sorted(frequency):
            print(f"{letter.upper()} : {frequency[letter]}")

        save_analysis(selected_file, characters, words, lines,
                      unique_characters, frequency)

    except ValueError:
        print("Please enter a valid number.")


def save_analysis(filename, characters, words, lines,
                  unique_characters, frequency):
    """Save file analysis results to outputs."""

    output_file = os.path.join(OUTPUT_FOLDER, "analysis_output.txt")

    with open(output_file, "w", encoding="utf-8") as file:
        file.write("CryptoLabX - File Analysis Report\n")
        file.write("=" * 40 + "\n")
        file.write(f"File Name           : {filename}\n")
        file.write(f"Number of Characters: {characters}\n")
        file.write(f"Number of Words     : {words}\n")
        file.write(f"Number of Lines     : {lines}\n")
        file.write(f"Unique Characters   : {unique_characters}\n\n")

        file.write("Letter Frequency:\n")
        file.write("-" * 25 + "\n")

        for letter in sorted(frequency):
            file.write(f"{letter.upper()} : {frequency[letter]}\n")

    print(f"\nAnalysis saved to: {output_file}")


def coming_soon(feature):
    """Display a placeholder for future functionality."""
    print(f"\n{feature} module: Coming Soon")


def main():
    """Main program."""

    create_required_folders()

    while True:
        display_menu()

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            log_activity("Encrypt")
            coming_soon("Encrypt")

        elif choice == "2":
            log_activity("Decrypt")
            coming_soon("Decrypt")

        elif choice == "3":
            log_activity("Attack")
            coming_soon("Attack")

        elif choice == "4":
            log_activity("Analyze")
            analyze_file()

        elif choice == "5":
            log_activity("Exit")
            print("\nThank you for using CryptoLabX.")
            break

        else:
            log_activity("Invalid Option")
            print("\nInvalid option. Please try again.")


if __name__ == "__main__":
    main()
