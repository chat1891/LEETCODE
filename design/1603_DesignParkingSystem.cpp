class ParkingSystem
{
public:
    int big;
    int medium;
    int small;

    enum type
    {
        bigCar = 1,
        mediumCar,
        smallCar
    };

    ParkingSystem(int big, int medium, int small)
    {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool checkSpot(int& spotLeft)
    {
        if (spotLeft > 0)
        {
            spotLeft--;
            return true;
        }
        return false;
    }

    bool addCar(int carType)
    {
        if (carType == type::bigCar)
        {
            return checkSpot(big);

        }
        else if (carType == type::mediumCar)
        {
            return checkSpot(medium);

        }
        else if (carType == type::smallCar)
        {
            return checkSpot(small);
        }

        return false;
    }
};