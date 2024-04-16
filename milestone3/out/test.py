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
    return

if __name__ == "__main__":
    main()
