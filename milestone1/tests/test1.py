def insertion_sort(arr: list[int], n: int) -> None:
    for i in range(1, n):
        key: int = arr[i]
        j: int = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge_sorted_arrays(arr1: list[int], arr2: list[int], n: int) -> list[int]:
    merged_array: list[int] = [0] * (2 * n)  # Initialize with zeros, assuming double the size for merging
    i: int = 0
    j: int = 0
    k: int = 0

    while i < n and j < n:
        if arr1[i] == arr2[j]:
            merged_array[k] = arr1[i]
            i += 1
            j += 1
        elif arr1[i] < arr2[j]:
            merged_array[k] = arr1[i]
            i += 1
        else:
            merged_array[k] = arr2[j]
            j += 1
        k += 1

    while i < n:
        merged_array[k] = arr1[i]
        i += 1
        k += 1

    while j < n:
        merged_array[k] = arr2[j]
        j += 1
        k += 1

    # Remove extra zeros from the merged array
    result: list[int] = []
    for m in merged_array:
        if m != 0:
            result.append(m)
        elif m == 0 and result and result[-1] is not None:
            result.append(None)

    return result

def main() -> None:
    # Example input arrays
    n: int = 5
    array1: list[int] = [4, 2, 8, 1, 6]
    array2: list[int] = [7, 3, 5, 9, 10]

    # Sort the arrays using insertion sort
    insertion_sort(array1, n)
    insertion_sort(array2, n)

    # Merge the sorted arrays without duplicates
    merged_result: list[int] = merge_sorted_arrays(array1, array2, n)

    # Find and print the union of the two arrays
    union_result: list[int] = []
    for item in merged_result:
        if item is not None:
            union_result.append(item)
    print("Union of Arrays:", union_result)

    # Print the minimum and maximum values in the merged array
    print("Merged and Sorted Array:", union_result)
    print("Minimum Value:", min(union_result))
    print("Maximum Value:", max(union_result))

if __name__ == "__main__":
    main()
