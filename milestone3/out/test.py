class A:
    def __init__(self) -> None:
        self.x:int = 0
        self.y:int = 0
        return
    def print_x(self) -> A:
        print(self.x)
        self.x = self.x * 2
        return self
    def print_y(self) -> A:
        print(self.y)
        return self
def main():
    a: A = A()
    a.x = 1
    a.y = 2
    a.print_x().print_x().print_y()
    s:str = "Hello, world"
    a.x = a.x + s
    return

if __name__ == "__main__":
    main()