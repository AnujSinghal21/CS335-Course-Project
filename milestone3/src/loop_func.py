arr1: list[int] = [1,2,3,4,5,6,7,8]
arr2: list[int] = [1,4,7,9,10,12,15,18]

def func(y:list[int], z:int) -> bool:
    n: int = len(y)
    i: int = 0
    for i in range(0,n-1):
        if y[i] == z:
            return 1
    
    k: int = 0
    while k < n:
        if y[i]+1 == z:
            return 1
        k+=1
    return 0

def newarray(a:list[int], b:list[int]) -> list[int]:
    arr:list[int] = [0,0,0,0,0,0,0,0]
    n:int = len(arr)
    m:int = len(a)
    k:int = len(b)

    if n-m != 0 or m-k !=0:
        print("invalid")
    
    i:int = 0
    j:int = n-1

    while i<n:
        arr[i]=a[i]+b[j]
        i += 1
        j -= 1
    
    return arr

def main():
    # found:int = 0
    n1:int = len(arr1)
    n2:int = len(arr2)
    if n1!=n2:
        print("invalid input")
    
    i:int = 0
    for i in range(n1):
        j:int 
        for j in range(0,n2-1):
            find:bool = func(arr1,arr2[j])
            comp:bool = ((arr1[i]==arr2[j]) or (arr1[i]+1 == arr2[j]))
            if find == comp:
                print("success")

    arr3:list[int] = newarray(arr1,arr2)

if __name__ == "__main__":
  main()