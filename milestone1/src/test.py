def func(x: int, y:float) -> int:
    z : int = x + y
    return z 

class Circle:
    def __init__(self, radius: float) -> None:
        self.radius: float = radius

    def area(self) -> float:
        return 3.14159 * self.radius ** 2

    def circumference(self) -> float:
        return 2 * 3.14159 * self.radius

    def diameter(self) -> float:
        return 2 * self.radius