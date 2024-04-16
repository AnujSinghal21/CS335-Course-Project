class A():

    def __init__(self,new:int)-> None   :
        self.x:int = new
        
    def fibo(self,x:int) -> int:
        if(x == 0):
            return 0
        if(x==1):
            return 1


def main() -> None :
    x:int = 4
    y:int = 5
    z: int = x + y
    a:A = A(5)
    a.x = 10  
    print(a.fibo(10))
    return


if __name__ == "__main__":
    main()
