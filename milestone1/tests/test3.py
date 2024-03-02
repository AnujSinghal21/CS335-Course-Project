class Rectangle:
    def __init__(self, length: float, width: float) -> None:
        self.length: float = length
        self.width: float = width

    def area(self) -> float:
        return self.length * self.width

    def perimeter(self) -> float:
        return 2 * (self.length + self.width)

    def diagonal_length(self) -> float:
        return (self.length ** 2 + self.width ** 2) ** 0.5

class Square(Rectangle):
    def __init__(self, side: float) -> None:
        super().__init__(side, side)

class Circle:
    def __init__(self, radius: float) -> None:
        self.radius: float = radius

    def area(self) -> float:
        return 3.14159 * self.radius ** 2

    def circumference(self) -> float:
        return 2 * 3.14159 * self.radius

    def diameter(self) -> float:
        return 2 * self.radius

def main() -> None:
    # Example polygons
    rectangles: list[Rectangle] = [Rectangle(4, 5), Rectangle(3, 8), Rectangle(2, 6), Rectangle(5, 7), Rectangle(1, 4)]
    squares: list[Square] = [Square(3), Square(2), Square(5), Square(1), Square(4)]
    circles: list[Circle] = [Circle(2), Circle(3), Circle(1), Circle(4), Circle(5)]

    # Calculate and print information for rectangles
    print("Rectangles:")
    for rectangle in rectangles:
        print(f"Area: {rectangle.area()}, Perimeter: {rectangle.perimeter()}, Diagonal Length: {rectangle.diagonal_length()}")

    print("\nSquares:")
    max_square_area: float = 0
    max_square: Square = None
    for square in squares:
        area: float = square.area()
        print(f"Area: {area}, Perimeter: {square.perimeter()}, Diagonal Length: {square.diagonal_length()}")

        if area > max_square_area:
            max_square_area = area
            max_square = square

    # Calculate and print information for circles
    print("\nCircles:")
    max_circle_area: float = 0
    max_circle: Circle = None
    for circle in circles:
        area: float = circle.area()
        print(f"Area: {area}, Circumference: {circle.circumference()}, Diameter: {circle.diameter()}")

        if area > max_circle_area:
            max_circle_area = area
            max_circle = circle

    # Check if the square with the largest area can fit inside the circle with the largest area
    if max_square.length <= max_circle.radius * 2:
        print("\nThe square with the largest area can fit inside the circle with the largest area.")
    else:
        print("\nThe square with the largest area cannot fit inside the circle with the largest area.")
if __name__ == "__main__":
    main()
