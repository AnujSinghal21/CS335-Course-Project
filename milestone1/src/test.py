
def funct(x: int = 5, y: int = 10) -> int:
    a: int
    b: float
    global xa, xy

    z: int = x + y
    z: int = z + a
    w: int = 2
    u: int = 3

class A():
    def __init__(self, x: int, y: int, z: int) -> None:
        self.x = x
        self.y = y
        i:int = 0
        a = [1 , 2, 3]
        for a[i] in range(3):
            print(i)
    def funct(self, z: int) -> int:
        return self.x + self.y + z
    
class B():
    def __init__(self, x: int, y: int, z: int) -> None:
        super()
        self.z = z

    def funct(self, w: int) -> int:
        return self.x + self.y + self.z + w