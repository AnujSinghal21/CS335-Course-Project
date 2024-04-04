d: int = 5
def add(x: int,y: int) -> int:
    p:int = x+y
    z: int = 10; z = z + 1
    p = p * z
    q:int = z + p
    print(q)
    # global d
    # d: int = 6
    if p < q:
        p = p + 1
    else:
        p = p - 1

    if p < q:
        p = p + 1
    elif q == p:
        p = p - 1
    else:
        p = p * 2
    return p

def main():
    p:int = 2
    s:int = 3
    add(p,s)
class A():
    x:int = 5
    y:int =10
    
    def hello()->int:
        z:int = 100

l:list[int] = [1,2,3,4]
i:int = 5
a:int = l[i]

# if __name__ == "__main__":
#   main()
