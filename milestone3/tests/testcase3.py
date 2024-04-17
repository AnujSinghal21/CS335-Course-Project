def numstep(n:int)->int:
    if n==1 or n==3:
        return 1
    else:
        if n>3:
            return numstep(n-1)+numstep(n-3)
        elif n<3:
            return numstep(n-1)

def numstep2(n:int)->int:
    if n==1 or n==2:
        return 1
    else:
        return numstep2(n-1)+numstep2(n-2)

def main()->None:
    num_dist:int = 40
    dist:int

    for dist in range(1,num_dist):
        steps1:int = numstep(dist)
        steps2:int = numstep2(dist)

        if steps1 > steps2:
            print("1 and 3 has more ways")
        elif steps1 ^ steps2 == 0:
            print("TAKE AS YOUR WISH")
        else:
            print("1 and 2 has more ways")

   
if __name__ == "__main__":
    main() 