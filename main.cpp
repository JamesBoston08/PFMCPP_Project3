 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};

}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        void stepForward();
        int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward()
{
   
}
int Person::Foot::stepSize()
{
   return 10;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }    
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

struct CookieShop
{
    int numberOfStaff = 10;
    float avgEarningsPerWeek = 1500.50f;
    float avgCookieDoughPerWeek = 20.5f;
    float avgCoffeePerWeek = 17.8f;
    float cashOnHand = 2447.89f;

    struct Oven
    {
        int widthOfOven = 30;
        int maxTemp = 450;
        std::string manufacturer = "Maytag";
        int widthOfOvenWindow = 26;
        int numOfKnobs = 7;

        void produceHeat(bool isOvenOn);
        void displayTimer(std::string setTime);
        void displayTemp(std::string setTemp);
    };
    void bakeCookies(bool isPreheatTempReached);
    float calculateTotalCustomerCharge(float cookiePrice = 1.95f, float coffeePrice = 
    3.15f); 
    void buyNewOven(Oven manufacturer);
};

void CookieShop::Oven::produceHeat(bool isOvenOn)
{
    if (isOvenOn == true)
    {
        std::cout << "Oven heating" << std::endl;
    }
}

void CookieShop::Oven::displayTimer(std::string setTime)
{
    std::cout << "Timer is " << setTime << std::endl;
}

void CookieShop::Oven::displayTemp(std::string setTemp)
{
    std::cout << "Tempertue is " << setTemp << std::endl;
}

void CookieShop::bakeCookies(bool isPreheatTempReached)
{
    if (isPreheatTempReached)
    {
        std::cout << "Ready to bake" << std::endl;
    }
}

float CookieShop::calculateTotalCustomerCharge(float cookiePrice, float coffeePrice)
{
    return cookiePrice + coffeePrice;
}

void CookieShop::buyNewOven(Oven newOvenA)
{
    std::cout << "I bought a new oven from " << newOvenA.manufacturer;
}

struct LawnMower
{
    float amountOfGas = 3.00f;
    int numOfWires = 20;
    int numOfBlades = 3; 
    float bladeHeight = 2.5f;
    int rpmsOfBlades = 3000;

    void cutGrass(bool engineOn = false, bool engineHandleBarPressedDown = false);
    void consumeGas(bool engineOn = false);
    void selfPropel(bool engineOn = false, bool selfPropelHandleBarPressedDown = false);
};

void LawnMower::cutGrass(bool engineOn, bool engineHandleBarPressedDown)
{
    if ((engineOn == true) && (engineHandleBarPressedDown == true))
    {
        std::cout << "Ready to cut grass" << std::endl;
    }    
}

void LawnMower::consumeGas(bool engineOn)
{
    if (engineOn == true)
    {
        std::cout << "Consuming gas" << std::endl;
    }
}

void LawnMower::selfPropel(bool engineOn, bool selfPropelHandleBarPressedDown)
{
    if ((engineOn == true) && (selfPropelHandleBarPressedDown == true))
    {
        std::cout << "Self Propel On" << std::endl;
    }
    else if ((engineOn == true) && (selfPropelHandleBarPressedDown == false))
    {
        std::cout << "Self Propel off" << std::endl;
    }
}

struct Laptop
{
    int towerHeight = 13;
    int numOfFans = 3;
    int amountOfRam = 16;
    int numOfUSBPorts = 6;
    int numOfKeys = 120;

    void typeLetter(bool isLetterKeyPressed);
    int productOfNumbers(int num1, int num2);
    void runSoftware(bool hasDoubleClickedIcon);
};

void Laptop::typeLetter(bool isLetterKeyPressed)
{
    if (isLetterKeyPressed == true)
    {
        char letterPressed;
        std::cin >> letterPressed;
        std::cout << letterPressed << std::endl;
    }
}

int Laptop::productOfNumbers(int num1, int num2)
{
    int product = num1 * num2;
    return product;
}

void Laptop::runSoftware(bool hasDoubleClickedIcon)
{
    if (hasDoubleClickedIcon == true)
    {
        std::cout << "Software Running" << std::endl; 
    }   
}

struct NuclearPowerPlant
{
    float amountOfWaterUsed = 375.5f;
    float tempOfWater = 284.8f;
    int numOfGenerators = 3;
    float weightOfGenerators = 389.79f;
    int numOfEngineers = 100;

    void produceHeat(bool isFissionSuccessful);
    void generateSteam(bool tubesReachedNeededTemp);
    void produceElectricity(bool isGeneratorReceivingSteam);
};

void NuclearPowerPlant::produceHeat(bool isFissionSuccessful)
{
    if (isFissionSuccessful)
    {
        std::cout << "It's getting hot!" << std::endl;
    }
}

void NuclearPowerPlant::generateSteam(bool tubesReachedNeededTemp)
{
    if (tubesReachedNeededTemp)
    {
        std::cout << "Generating steam" << std::endl;
    }
}

void NuclearPowerPlant::produceElectricity(bool isGeneratorReceivingSteam)
{
    if (isGeneratorReceivingSteam)
    {
        std::cout << "Producing elctricity" << std::endl;
    }
}

struct Airplane
{
    int numOfPassengerSeats = 180;
    float totalWeightOfPlane = 92354.67f;
    float lengthOfPlaneWings = 33.5f;
    int numOfLuggagePieces = 225;
    int amountOfFuel = 20000;

    struct Cockpit
    {
        int numOfSwitches = 30;
        int numOfDisplays = 8;
        int numOfFlightControllers = 2;
        int numOfRudderPedals = 4;
        int numOfPilots = 2;

        int turnPlane(int degreesTurned);
        void landingGearRaised(bool isGearLeverInUpPostion);
        void talkToAirTrafficControl(bool isPushToTalkSwitchPressed);
    };
    void takeOff(bool isRunwayClear, bool isTakeOffSpeedReached);
    void land(bool isLandingSpeedReached, bool areWheelsDeployed);
    void sendDataToContolTower(bool isGreenLightOn); 
};

int Airplane::Cockpit::turnPlane(int degreesTurned)
{
    return degreesTurned;
}

void Airplane::Cockpit::landingGearRaised(bool isGearLeverInUpPostion)
{
    if(isGearLeverInUpPostion)
    {
        std::cout << "Landing Gear is raised" << std::endl;
    }
}

void Airplane::Cockpit::talkToAirTrafficControl(bool isPushToTalkSwitchPressed)
{
    if(isPushToTalkSwitchPressed)
    {
        std::cout << "Ready to talk" << std::endl;
    }
}

void Airplane::takeOff(bool isRunwayClear, bool isTakeOffSpeedReached)
{
    if ((isRunwayClear == true) && (isTakeOffSpeedReached == true))
    {
        std::cout << " Ready for takeoff" << std::endl;   
    }  
}

void Airplane::land(bool isLandingSpeedReached, bool areWheelsDeployed)
{
    if (isLandingSpeedReached && areWheelsDeployed)
    {
        std::cout << "Ready for landing" << std::endl;
    }       
}

void Airplane::sendDataToContolTower(bool isGreenLightOn)
{
    if (isGreenLightOn == false)
    {
        std::cout << "Data is not being sent to control" << std::endl;
    }
}

struct Hangar
{
    float hangarSize = 8000.0f;
    int numOfPlanes = 3;
    int numOfMaintenanceEmployees = 100;
    int numOfAircraftJacks = 12;
    int maxHeightOfMaintenancePlatform = 12;

    void washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane);
    void routinePlaneMaintenance(int hrsNeededtoPerformMaintenance, int 
    numOfEmployeesPerformingMaintenace);
    void installEngine(int numOfEmployeesInstallEngine, int hrsNeededToInstallEngine);
};

void Hangar::washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane)
{
    if ((numOfEmployeesWashing >= 5) && (hrsNeededToWashPlane <= 7))
    {
        std::cout << "Plane can be washed" << std::endl;
    }
    else
    {
        std::cout << "Plane can't be washed" << std::endl;
    }
}

void Hangar::routinePlaneMaintenance(int hrsNeededtoPerformMaintenance, int 
    numOfEmployeesPerformingMaintenace)
{
    if ((hrsNeededtoPerformMaintenance <= 2) && (numOfEmployeesPerformingMaintenace >= 2))
    {
        std::cout << "Please perform maintenace"<< std::endl;
    }
    else
    {
        std::cout << "Do not perform maintenace" << std::endl;
    }      
}

void Hangar::installEngine(int numOfEmployeesInstallEngine, int hrsNeededToInstallEngine)
{
    if ((numOfEmployeesInstallEngine >= 5) && (hrsNeededToInstallEngine <= 10))
    {
        std::cout << "Please install engine" << std::endl;
    }
    else
    {
        std::cout << "Do not install engine" << std::endl;
    }      
}

struct ParkingLot
{
    int numOfCars = 3000;
    int numOfParkingPasses = 2687;
    float sizeOfParkingLot = 12.3f;
    int numOfParkingSpaces = 3500;
    int numOfParkingLotExits = 5;

    void parkCars(bool isOpenParkingSpace);
    void purchaseParking (bool isParkingPaid);
    void liftBarrierArm(bool isTicketButtonPressed);
};

void ParkingLot::parkCars(bool isOpenParkingSpace)
{
    if (isOpenParkingSpace)
    {
        std::cout << "Park cars here" << std::endl;
    }
    else
    {
        std::cout << "Can't park cars here" << std::endl;
    }    
}

void ParkingLot::purchaseParking (bool isParkingPaid)
{
    if (isParkingPaid)
    {
        std::cout << "Parking purchased" << std::endl;
    }     
}

void ParkingLot::liftBarrierArm(bool isTicketButtonPressed)
{
    if (isTicketButtonPressed)
    {
        std::cout << "Barrier lifted" << std::endl;
    }       
}
struct ControlTower
{
    int numOfWindows = 40;
    int numOfAirTarfficControllers = 8;
    float controlTowerHeight = 369.5f;
    int numOfDisplays = 50;
    int numOfRadars = 2;

    void provideAirplaneGateClearance(bool hasSentPushBackClearence, int 
    timeToPushBackFromGate);
    std::string monitorPlaneFlight(float planeSpeed, float planeAttitude, 
    std::string directionOfMovement);
    void clearPlaneForLanding(bool hasSentLandingClearance, bool hasReachedLandingSpeed);
};

void ControlTower::provideAirplaneGateClearance(bool hasSentPushBackClearence, int 
    timeToPushBackFromGate)
{
    if ((hasSentPushBackClearence == true) && (timeToPushBackFromGate >= 1600))
    {
        std::cout << "Airplane ready to clear gate" << std::endl;
    }
}

std::string ControlTower::monitorPlaneFlight(float planeSpeed, float planeAltitude, std::string directionOfMovement)
{
    std::string planeSpeedString = std::to_string(planeSpeed);
    std::string planeAltitudeString = std::to_string(planeAltitude);
    return "Plane Speed " + planeSpeedString + " Plane Altitude " + planeAltitudeString +     
    "Direction " + directionOfMovement;
}

void ControlTower::clearPlaneForLanding(bool hasSentLandingClearance, bool hasReachedLandingSpeed)
{
    if ((hasSentLandingClearance == true) && (hasReachedLandingSpeed == true))
    {
        std::cout << "Airplane is ready for landing" << std::endl;
    }
}

struct TerminalBuilding
{
    int numOfTerminals = 2;
    int numOfTicketCounters = 15;
    int numofTSAEmplyees = 100;
    int numOfSecurityCheckpoints = 10;
    int numOfGates = 120;

    float chargeBaggageFee(float numOfBags, float costPerBag);
    void purchaseTicket(bool isTicketPaid = false);
    void screenPassengersForSecurity(bool didPassengerWalkThorughImageDetector, bool 
     wasAnythingDetected);
};

float TerminalBuilding::chargeBaggageFee(float numOfBags, float costPerBag)
{
     float baggageFee = numOfBags * costPerBag;
     return baggageFee;  
}

void TerminalBuilding::purchaseTicket(bool isTicketPaid)
{
    if (isTicketPaid)
    {
        std::cout << "Ticket purchased" << std::endl;
    }
}

void TerminalBuilding::screenPassengersForSecurity(bool didPassengerWalkThorughImageDetector, bool wasAnythingDetected)
{
    if ((didPassengerWalkThorughImageDetector == true) && (wasAnythingDetected == false))
    {
        std::cout << "Please continue walking" << std::endl;
    }
    else if ((didPassengerWalkThorughImageDetector == true) && (wasAnythingDetected == 
    true))
    {
        std::cout << "Wait here" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }      
}
    
struct Airport
{
    Airplane airplane;
    Hangar hangar;
    ParkingLot parkingLot;
    ControlTower controlTower;
    TerminalBuilding terminalBuilding;

    void openRestaurant(int PriceOfRestaurant, int spaceNeededForRestaurant);
    void passengerReachDestination(std::string passengerTicketDestination, std::string 
    planeLandedAtDestination);
    float buyRadars(float priceOfRadar, float numOfRadars);
};

void Airport::openRestaurant(int PriceOfRestaurant, int spaceNeededForRestaurant)
{
    if ((PriceOfRestaurant <= 300000) && (spaceNeededForRestaurant <= 3000))
    {
        std::cout << "Buy restaurant" << std::endl;
    }
}

void Airport::passengerReachDestination(std::string passengerTicketDestination, std::string 
    planeLandedAtDestination)
{
    if (passengerTicketDestination == planeLandedAtDestination) 
    {
        std::cout << "Passenger Reached Destination" << std::endl;
    }      
}

float Airport::buyRadars(float priceOfRadar, float numOfRadars)
{
    return priceOfRadar * numOfRadars;
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
