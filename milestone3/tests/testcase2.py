#testing loops and if else
def main()->None:
    x:int = 1
    y:int = 2
    z:int = 2
    while z>1:
        if x>y:
            x+=y
        else:
            x = x+7
        z = z-1

    i:int = 0
    for i in range(1,x):
        z = z+1

    print(z)

if __name__ == "__main__":
    main() 