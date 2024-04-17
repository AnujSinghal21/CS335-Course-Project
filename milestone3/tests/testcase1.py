# Testing arithmetic operations
def main()->None:
    a1:int = 4
    a2:int = 2
    a3:int = 5
    a4:int = 10
    a5:int = 9
    a6:int = 2
    a7:int = 8
    a8:int = 5
    a9:int = a3 + a4
    print(a9-a1)
    print(a9+a7+a8)
    print(a1/a2)
    a10:int = a4/a3+a5*a6  # testing operation evaluation order
    print(a10)
    print(a1<a2) #boolean testing
    print(a1>a2) 
    a8 =  a1**a2 
    print(a8)

if __name__ == "__main__":
    main()