
def remove_duplicates(strings: list[str]) -> list[str]:
    unique_strings: list[str] = []
    for string in strings:
        if string not in unique_strings:
            unique_strings.append(string)
    return unique_strings

def bubble_sort_reverse(strings: list[str]) -> list[str]:
    n: int = len(strings)

    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if strings[j] < strings[j + 1]:
                temp: str = strings[j]
                strings[j] = strings[j+1]
                strings[j+1] = temp
                #strings[j], strings[j + 1] = strings[j + 1], strings[j]

    return strings

def count_vowels(string: str) -> int:
    vowels: str = "aeiouAEIOU"
    count: int = 0
    for char in string:
        if char in vowels:
            count += 1
    return count

def main() -> None:
    # Example input strings with duplicates
    input_strings: list[str] = ["apple", "banana", "orange", "grape", "kiwi", "melon",
                     "cat", "dog", "elephant", "lion", "tiger", "zebra",
                     "python", "java", "csharp", "ruby", "javascript", "html",
                     "apple", "orange", "kiwi", "lion", "java", "ruby"]

    # Remove duplicates from the set of strings
    unique_strings: list[str] = remove_duplicates(input_strings)

    # Sort the unique strings in reverse lexicographical order using bubble sort
    sorted_unique_strings: list[str] = bubble_sort_reverse(unique_strings)

    # Find and print the minimum number of vowels in each string
    min_vowels: list[int] = []
    for string in sorted_unique_strings:
        min_vowels.append(count_vowels(string))

    # Print the original and unique strings, and the minimum number of vowels
    print("Original Strings:", input_strings)
    print("Unique Strings:", sorted_unique_strings)
    print("Minimum Number of Vowels in Each String:", min_vowels)

if __name__ == "__main__":
    main()
