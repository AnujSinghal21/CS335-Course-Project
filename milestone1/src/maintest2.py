def compute_min() -> float:
  min_value: float = -100000.0
  data: list[float] = [-2.3, 3.14, 0.9, 1.1, -9.1]
  i: int = 0
  n: int = len(data)
  for i in range(n):
    if not min_value:
      min_value = data[i]
    elif data[i] < min_value:
      min_value = data[i]
  return min_value


def compute_avg() -> float:
  avg_value: float = 1.0
  data: list[float] = [-2.3, 3.14, 0.9, 1.1, -9.1]
  sum: int = 0
  i: int = 0
  n: int = len(data)
  for i in range(n):
    sum += data[i]
  return sum / n


def main():
  min_value: float = compute_min()
  print("Minimum value: ")
  print(min_value)
  avg_value: float = compute_avg()
  print("Average value: ")
  print(avg_value)


if __name__ == "__main__":
  main()
