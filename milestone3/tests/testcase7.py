class Rectangle:
    def __init__(self, length: int, width: int):
        self.length:int = length
        self.width:int = width
    
    def calculate_area(self) -> int:
        return self.length * self.width
    
    def calculate_perimeter(self) -> int:
        return 2*(self.length+self.width)


def main():
    # Create an instance of Rectangle
    rectangle1:Rectangle = Rectangle(5, 10)
    rectangle2:Rectangle = Rectangle(4, 12)
    print("rectangle1 area")
    area1:int = rectangle1.calculate_area()
    print(area1)
    print("rectangle2 area")
    area2:int = rectangle2.calculate_area()
    print(area2)
    
    if area1 > area2:
        print("rectangle1 has larger area")
    elif area1 == area2:
        print("Both has same area")
    else:
        print("rectangle1 has smaller area")
    

    print("rectangle1 perimeter")
    per1:int = rectangle1.calculate_perimeter()
    print(per1)
    print("rectangle2 perimeter")
    per2:int = rectangle2.calculate_perimeter()
    print(per2)
    
    if per1 > per2:
        print("rectangle1 has larger perimeter")
    elif per1 == per2:
        print("Both has same perimeter")
    else:
        print("rectangle1 has smaller perimeter")
    

if __name__ == "__main__":
    main()
