def bubbleSort(array: list[int]) -> None: # KOI PROBLEM??
  i: int = 0
  j: int 
  n: int = len(array)
  for i in range(n):
    swapped: bool = False
    for j in range(0, n - i - 1): 
      if array[j] > array[j + 1]:
        temp: int = array[j]
        array[j] = array[j + 1]
        array[j + 1] = temp
        swapped = True
    if not swapped:
      break

def main():
  data: list[int] = [-2, 45, 0, 11, -9]
  bubbleSort(data) 
  print('Sorted Array in Ascending Order:')
  i: int = 0
  n: int = len(data)
  # x:int = 0
  # while x:
  #   y:int = 0
  for i in range(n):
    print(data[i]) #YE KYA ERROR HE, LAST ME PURA AA RHA HE NA ERROR, LIKE NO DECARATION OF FUNCTION WITH THESE PARAMETERS, YE TYPE ERROR KYON AAA RHA
  # jb tk koi func call na kro tb tk theek h, wrna end_func nhi aa rha
  # nhi samjha doubt, aake bata dena THEEK HE

if __name__ == "__main__":
  main()
