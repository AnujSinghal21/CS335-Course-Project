def bubbleSort(array: list[int], x:int) -> None: # KOI PROBLEM??
  i: int = 0
  j: int
  n: int = len(array)
  for i in range(n):
    swapped: bool = False
    for j in range(0, n - i - 1): 
      if x < i:
        break
      if array[j] > array[j + 1]:
        temp: int = array[j]
        array[j] = array[j + 1]
        array[j + 1] = temp
        swapped = True
    if not swapped:
      break

def main():
  data: list[int] = [-2, 45, 0, 11, -9]
  bubbleSort(data, 5) 
  print('Sorted Array in Ascending Order:')
  i: int = 0
  n: int = len(data)
  for i in range(n):
    print(data[i]) 

if __name__ == "__main__":
  main()
