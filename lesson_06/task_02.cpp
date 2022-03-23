/*
 * task_02.cpp
 *
 *  Created on: 23 мар. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

using namespace std;

/*

class Car
{
public:
// –азрешена ли посадка пассажиров
bool isBoardingAllowed() const;
// –азрешена ли погрузка грузов
bool isLoadingAllowed() const;
// —колько в машине мест дл€ пассажиров
unsigned int getNumberOfSeats() const;
// —колько в машине мест дл€ грузовых контейнеров
unsigned int getNumberOfContainers() const;
};
 */

class Car
{
protected:
	bool allowesBoarding;
	bool allowesLoading;
	unsigned int numberOfSeats;
	unsigned int numberOfContainers;
public:
	Car(bool allowesBoarding, bool allowesLoading, unsigned int numberOfSeats,
			unsigned int numberOfContainers) {
		this->allowesBoarding = allowesBoarding;
		this->allowesLoading = allowesLoading;
		this->numberOfSeats = numberOfSeats;
		this->numberOfContainers = numberOfContainers;
	}
	~Car() {}

	bool isBoardingAllowed() const {
		return allowesBoarding;
	}
	bool isLoadingAllowed() const {
		return allowesLoading;
	}
	unsigned int getNumberOfSeats() const {
		return numberOfSeats;
	}
	unsigned int getNumberOfContainers() const {
		return numberOfContainers;
	}
};


class ConvoyManager
{
public:
	ConvoyManager() : total_seats(0), total_containers(0) {}

	void registerCar(const Car& c)
	{
		if (c.isBoardingAllowed())
			total_seats += c.getNumberOfSeats();

		if (c.isLoadingAllowed())
			total_containers += c.getNumberOfContainers();
	}

	unsigned int getTotalSeats() const
	{
		return total_seats;
	}

	unsigned int getTotalContainers() const
	{
		return total_containers;
	}

private:
	unsigned int total_seats, total_containers;

};

/*

int main()
{
	ConvoyManager cm;
	Car c1(true, false, 12, 3);
	cm.registerCar(c1);
	Car c2(false, true, 12, 3);
	cm.registerCar(c2);
	Car c3(true, true, 12, 3);
	cm.registerCar(c3);
	Car c4(false, false, 12, 3);
	cm.registerCar(c4);
	cout << "Total available seats: " << cm.getTotalSeats() << endl;
	cout << "Total available containers: " << cm.getTotalContainers() << endl;

	return 0;
}
*/
