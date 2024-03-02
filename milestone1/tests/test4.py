def find_max_operations(nums: list[int]) -> None:
    max_xor: int = 0
    max_or: int = 0
    max_and: int = 10e9
    max_sum: int = -10e9
    max_product = -10e9

    max_xor_triplet: list[int] = []
    max_or_triplet: list[int] = []
    max_and_triplet: list[int] = []
    max_sum_triplet: list[int] = []
    max_product_triplet: list[int]= []

    n: int = len(nums)

    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                xor_result: int= nums[i] ^ nums[j] ^ nums[k]
                or_result: int = nums[i] | nums[j] | nums[k]
                and_result: int = nums[i] & nums[j] & nums[k]
                sum_result: int = nums[i] + nums[j] + nums[k]
                product_result: int = nums[i] * nums[j] * nums[k]

                if xor_result > max_xor:
                    max_xor = xor_result
                    max_xor_triplet = [nums[i], nums[j], nums[k]]

                if or_result > max_or:
                    max_or = or_result
                    max_or_triplet = [nums[i], nums[j], nums[k]]

                if and_result < max_and:
                    max_and = and_result
                    max_and_triplet = [nums[i], nums[j], nums[k]]

                if sum_result > max_sum:
                    max_sum = sum_result
                    max_sum_triplet = [nums[i], nums[j], nums[k]]

                if product_result > max_product:
                    max_product = product_result
                    max_product_triplet = [nums[i], nums[j], nums[k]]

    # Print results
    print(f"Maximum XOR: {max_xor} with Triplet: {max_xor_triplet}")
    print(f"Maximum OR: {max_or} with Triplet: {max_or_triplet}")
    print(f"Maximum AND: {max_and} with Triplet: {max_and_triplet}")
    print(f"Maximum Sum: {max_sum} with Triplet: {max_sum_triplet}")
    print(f"Maximum Product: {max_product} with Triplet: {max_product_triplet}")

def main() -> None:
    # Example array of numbers
    numbers: list[int] = [4, 7, 2, 9, 1, 5, 3, 8, 11]

    # Find triplets with maximum operations
    find_max_operations(numbers)

if __name__ == "__main__":
    main()
