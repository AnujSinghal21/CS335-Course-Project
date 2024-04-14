class Planet:
    def __init__(self, name: str, x_coordinate: float, y_coordinate: float):
        self.name = name
        self.x_coordinate = x_coordinate
        self.y_coordinate = y_coordinate

class SpaceTravel:
    def __init__(self):
        self.planet_stations: list[Planet] = []
        self.passengers: list[str] = []
        self.commanders: list[str] = []

    def distance_between_planets(self, planet1: Planet, planet2: Planet) -> float:
        x1: float = planet1.x_coordinate
        y1: float = planet1.y_coordinate
        x2: float = planet2.x_coordinate
        y2: float = planet2.y_coordinate
        # x2, y2 = planet2.x_coordinate, planet2.y_coordinate
        return ((x2 - x1)**2 + (y2 - y1)**2)**0.5

    def calculate_price(self, planet1: Planet, planet2: Planet) -> float:
        distance: float = self.distance_between_planets(planet1, planet2)
        return distance**2

    def add_passenger(self, passenger_name: str):
        self.passengers.append(passenger_name)

    def remove_planet_station(self, planet_name: str):
        for planet in self.planet_stations:
            if planet.name == planet_name:
                self.planet_stations.remove(planet)
                break

    def display_planet_stations(self):
        print("Planet Stations:")
        for planet in self.planet_stations:
            print(f"{planet.name} - Coordinates: ({planet.x_coordinate}, {planet.y_coordinate})")

# Example usage
def main():
    space_travel: SpaceTravel = SpaceTravel()

    # Add planet stations
    earth: Planet = Planet("Earth", 0, 0)
    mars: Planet = Planet("Mars", 10, 5)
    moon: Planet = Planet("Moon", 2, 2)

    space_travel.planet_stations.extend([earth, mars, moon])

    # Display planet stations
    space_travel.display_planet_stations()

    # Calculate distance between planets
    distance_mars_moon: float = space_travel.distance_between_planets(mars, moon)
    print(f"\nDistance between Mars and Moon: {distance_mars_moon} units")

    # Calculate price for travel between planets
    price_mars_moon: float = space_travel.calculate_price(mars, moon)
    print(f"Price for traveling from Mars to Moon: {price_mars_moon} units")

    # Add passengers
    space_travel.add_passenger("Alice")
    space_travel.add_passenger("Bob")

    # Remove planet station
    space_travel.remove_planet_station("Mars")

    # Display updated planet stations
    space_travel.display_planet_stations()

if __name__ == "__main__":
    main()
