def second_max(arr: list[int]) -> int:
    n:int = len(arr)
    if n < 2:
        print("list must have at least two elements")
    
    first_max:int= -1000000
    second_max:int = -1000000
    i:int

    for i in range(n):
        if arr[i] > first_max:
            second_max = first_max
            first_max = arr[i]
        elif arr[i] > second_max and arr[i] != first_max:
            second_max = arr[i]
    
    return second_max

def sum_list(arr: list[int]) -> int:
    n:int = len(arr)
    total:int = 0
    i:int

    for i in range(n):
        total += arr[i]
    
    return total

def max_sum_of_two(arr: list[int]) -> int:
    n:int = len(arr)
    if n < 2:
        print("list must have at least two elements.")
    
    max_sum:int = -1000000
    i:int
    j:int

    for i in range(n):
        for j in range(i + 1, n):
            temp_sum:int = arr[i] + arr[j]
            if temp_sum > max_sum:
                max_sum = temp_sum
    
    return max_sum

def main()->None:
    numbers:list[int] = [3, 6, 8, 10, 1, 2, 1,-4,-10]
    print("second max")
    print(second_max(numbers))
    print("sum of list")
    print(sum_list(numbers))
    print("largest pair sum")
    print(max_sum_of_two(numbers))

if __name__ == "__main__":
  main()
