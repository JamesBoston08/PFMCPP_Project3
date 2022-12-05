/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()




struct CookieShop  
{
    CookieShop();
    int numberOfStaff = 10;
    float avgEarningsPerWeek = 1500.50f;
    float avgCookieDoughPerWeek = 20.5f;
    float avgCoffeePerWeek = 17.8f;
    float cashOnHand = 2447.89f;

    struct Oven  
    {
        Oven();
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
    float calculateTotalCustomerCharge(float cookiePrice = 1.95f, float coffeePrice = 3.15f); 
    void buyNewOven(Oven manufacturer);
};

CookieShop::Oven::Oven() 
{
    std::cout << "Oven being constructed!" << std::endl;
}

void CookieShop::Oven::produceHeat(bool isOvenOn)
{
    if (isOvenOn == true)
    {
        std::cout << "Oven heating." << std::endl;
    }
}

void CookieShop::Oven::displayTimer(std::string setTime)
{
    std::cout << "Timer is " << setTime << std::endl;
}

void CookieShop::Oven::displayTemp(std::string setTemp)
{
    std::cout << "Temperature is " << setTemp << std::endl;
}

CookieShop::CookieShop() 
{
    std::cout << "\nCookieShop being constructed!" << std::endl;
}

void CookieShop::bakeCookies(bool isPreheatTempReached)
{
    if (isPreheatTempReached)
    {
        std::cout << "\nReady to bake." << std::endl;
    }
}

float CookieShop::calculateTotalCustomerCharge(float cookiePrice, float coffeePrice)
{
    float total = cookiePrice + coffeePrice;
    std::cout << "Your total is:$ " << total << std::endl;
    return total;
}

void CookieShop::buyNewOven(Oven newOvenA)
{
    std::cout << "I bought a new oven from " << newOvenA.manufacturer << std::endl;
}

struct LawnMower 
{
    LawnMower();
    float amountOfGas = 3.00f;
    int numOfWires = 20;
    int numOfBlades = 3; 
    float bladeHeight = 2.5f;
    int rpmsOfBlades = 3000;

    void cutGrass(bool engineOn = false, bool engineHandleBarPressedDown = false);
    void consumeGas(bool engineOn = false);
    void selfPropel(bool engineOn = false, bool selfPropelHandleBarPressedDown = false);
};

LawnMower::LawnMower()
{
    std::cout << "LawnMower being constructed!" << std::endl;
}

void LawnMower::cutGrass(bool engineOn, bool engineHandleBarPressedDown)
{
    if ((engineOn == true) && (engineHandleBarPressedDown == true))
    {
        std::cout << "\nReady to cut grass." << std::endl;
    }    
}

void LawnMower::consumeGas(bool engineOn)
{
    if (engineOn == true)
    {
        std::cout << "Consuming gas." << std::endl;
    }
}

void LawnMower::selfPropel(bool engineOn, bool selfPropelHandleBarPressedDown)
{
    if ((engineOn == true) && (selfPropelHandleBarPressedDown == true))
    {
        std::cout << "Self Propel On." << std::endl;
    }
    else if ((engineOn == true) && (selfPropelHandleBarPressedDown == false))
    {
        std::cout << "Self Propel off." << std::endl;
    }
}

struct Laptop
{
    Laptop();
    int towerHeight = 13;
    int numOfFans = 3;
    int amountOfRam = 16;
    int numOfUSBPorts = 6;
    int numOfKeys = 120;

    void typeLetter(bool isLetterKeyPressed);
    int productOfNumbers(int num1, int num2);
    void runSoftware(bool hasDoubleClickedIcon);
};

Laptop::Laptop()
{
    std::cout << "Laptop being constructed!" << std::endl;
}

void Laptop::typeLetter(bool isLetterKeyPressed)
{
    if (isLetterKeyPressed == true)
    {
        char letterPressed = 'B';
        std::cout << "\nYou pressed the letter " << letterPressed << std::endl;
    }
}

int Laptop::productOfNumbers(int num1, int num2)
{
    int product = num1 * num2;
    std::cout << "Product is " << product << std::endl;
    return product;
}

void Laptop::runSoftware(bool hasDoubleClickedIcon)
{
    if (hasDoubleClickedIcon == true)
    {
        std::cout << "Software Running." << std::endl; 
    }   
}

struct NuclearPowerPlant
{
    NuclearPowerPlant();
    float amountOfWaterUsed = 375.5f;
    float tempOfWater = 284.8f;
    int numOfGenerators = 3;
    float weightOfGenerators = 389.79f;
    int numOfEngineers = 100;

    void produceHeat(bool isFissionSuccessful);
    void generateSteam(bool tubesReachedNeededTemp);
    void produceElectricity(bool isGeneratorReceivingSteam);
};

NuclearPowerPlant::NuclearPowerPlant()
{
    std::cout << "NuclearPowerPlant being constructed!" << std::endl;
}

void NuclearPowerPlant::produceHeat(bool isFissionSuccessful)
{
    if (isFissionSuccessful)
    {
        std::cout << "\nIt's getting hot!" << std::endl;
    }
}

void NuclearPowerPlant::generateSteam(bool tubesReachedNeededTemp)
{
    if (tubesReachedNeededTemp)
    {
        std::cout << "Generating steam." << std::endl;
    }
}

void NuclearPowerPlant::produceElectricity(bool isGeneratorReceivingSteam)
{
    if (isGeneratorReceivingSteam)
    {
        std::cout << "Producing elctricity." << std::endl;
    }
}

struct Airplane
{
    Airplane();
    int numOfPassengerSeats = 180;
    float totalWeightOfPlane = 92354.67f;
    float lengthOfPlaneWings = 33.5f;
    int numOfLuggagePieces = 225;
    int amountOfFuel = 20000;

    struct Cockpit
    {
        Cockpit();
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
    void sendDataToControlTower(bool isGreenLightOn); 
};

Airplane::Airplane()
{
    std::cout << "Airplane being constructed!" << std::endl;
}

Airplane::Cockpit::Cockpit()
{
    std::cout << "Cockpit being constructed!" << std::endl;
}

int Airplane::Cockpit::turnPlane(int degreesTurned)
{
    std::cout<< "Plane turned " << degreesTurned << " degrees" << std::endl;
    return degreesTurned;
}

void Airplane::Cockpit::landingGearRaised(bool isGearLeverInUpPostion)
{
    if(isGearLeverInUpPostion)
    {
        std::cout << "Landing Gear is raised." << std::endl;
    }
}

void Airplane::Cockpit::talkToAirTrafficControl(bool isPushToTalkSwitchPressed)
{
    if(isPushToTalkSwitchPressed)
    {
        std::cout << "Ready to talk." << std::endl;
    }
}

void Airplane::takeOff(bool isRunwayClear, bool isTakeOffSpeedReached)
{
    if ((isRunwayClear == true) && (isTakeOffSpeedReached == true))
    {
        std::cout << "\nReady for takeoff!" << std::endl;   
    }  
}

void Airplane::land(bool isLandingSpeedReached, bool areWheelsDeployed)
{
    if (isLandingSpeedReached && areWheelsDeployed)
    {
        std::cout << "Ready for landing." << std::endl;
    }       
}

void Airplane::sendDataToControlTower(bool isGreenLightOn)
{
    if (isGreenLightOn == false)
    {
        std::cout << "Data is not being sent to control." << std::endl;
    }
}

struct Hangar
{
    Hangar();
    float hangarSize = 8000.0f;
    int numOfPlanes = 3;
    int numOfMaintenanceEmployees = 100;
    int numOfAircraftJacks = 12;
    int maxHeightOfMaintenancePlatform = 12;

    void washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane);
    void routinePlaneMaintenance(int hrsNeededtoPerformMaintenance, int numOfEmployeesPerformingMaintenace);
    void installEngine(int numOfEmployeesInstallEngine, int hrsNeededToInstallEngine);
};

Hangar::Hangar()
{
    std::cout << "Hangar being constructed!" << std::endl;
}

void Hangar::washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane)
{
    if ((numOfEmployeesWashing >= 5) && (hrsNeededToWashPlane <= 7))
    {
        std::cout << "\nPlane can be washed." << std::endl;
    }
    else
    {
        std::cout << "\nPlane can't be washed." << std::endl;
    }
}

void Hangar::routinePlaneMaintenance(int hrsNeededtoPerformMaintenance, int numOfEmployeesPerformingMaintenace)
{
    if ((hrsNeededtoPerformMaintenance <= 2) && (numOfEmployeesPerformingMaintenace >= 2))
    {
        std::cout << "Please perform maintenace."<< std::endl;
    }
    else
    {
        std::cout << "Do not perform maintenace." << std::endl;
    }      
}

void Hangar::installEngine(int numOfEmployeesInstallEngine, int hrsNeededToInstallEngine)
{
    if ((numOfEmployeesInstallEngine >= 5) && (hrsNeededToInstallEngine <= 10))
    {
        std::cout << "Please install engine." << std::endl;
    }
    else
    {
        std::cout << "Do not install engine." << std::endl;
    }      
}

struct ParkingLot
{
    ParkingLot();
    int numOfCars = 3000;
    int numOfParkingPasses = 2687;
    float sizeOfParkingLot = 12.3f;
    int numOfParkingSpaces = 3500;
    int numOfParkingLotExits = 5;

    void parkCars(bool isOpenParkingSpace);
    void purchaseParking (bool isParkingPaid);
    void liftBarrierArm(bool isTicketButtonPressed);
};

ParkingLot::ParkingLot()
{
    std::cout << "ParkingLot being constructed!" << std::endl;
}

void ParkingLot::parkCars(bool isOpenParkingSpace)
{
    if (isOpenParkingSpace)
    {
        std::cout << "\nPark cars here" << std::endl;
    }
    else
    {
        std::cout << "\nCan't park cars here." << std::endl;
    }    
}

void ParkingLot::purchaseParking (bool isParkingPaid)
{
    if (isParkingPaid)
    {
        std::cout << "Parking purchased." << std::endl;
    }     
}

void ParkingLot::liftBarrierArm(bool isTicketButtonPressed)
{
    if (isTicketButtonPressed)
    {
        std::cout << "Barrier lifted." << std::endl;
    }       
}

struct ControlTower
{
    ControlTower();
    int numOfWindows = 40;
    int numOfAirTarfficControllers = 8;
    float controlTowerHeight = 369.5f;
    int numOfDisplays = 50;
    int numOfRadars = 2;

    void provideAirplaneGateClearance(bool hasSentPushBackClearence, int timeToPushBackFromGate);
    std::string monitorPlaneFlight(float planeSpeed, std::string directionOfMovement);
    void clearPlaneForLanding(bool hasSentLandingClearance, bool hasReachedLandingSpeed);
};

ControlTower::ControlTower()
{
    std::cout << "ControlTower being constructed!" << std::endl;
}

void ControlTower::provideAirplaneGateClearance(bool hasSentPushBackClearence, int timeToPushBackFromGate)
{
    if ((hasSentPushBackClearence == true) && (timeToPushBackFromGate >= 1600))
    {
        std::cout << "\nAirplane ready to clear gate." << std::endl;
    }
}

std::string ControlTower::monitorPlaneFlight(float planeSpeed, std::string directionOfMovement)
{
    std::string planeSpeedString = std::to_string(planeSpeed);
    std::cout << "Plane Speed is: " << planeSpeed << " mph and " << "direction is: " << directionOfMovement << std::endl;
    return "Plane Speed " + planeSpeedString + "Direction " + directionOfMovement;
}

void ControlTower::clearPlaneForLanding(bool hasSentLandingClearance, bool hasReachedLandingSpeed)
{
    if ((hasSentLandingClearance == true) && (hasReachedLandingSpeed == true))
    {
        std::cout << "Airplane is ready for landing." << std::endl;
    }
}

struct TerminalBuilding
{
    TerminalBuilding();
    int numOfTerminals = 2;
    int numOfTicketCounters = 15;
    int numofTSAEmplyees = 100;
    int numOfSecurityCheckpoints = 10;
    int numOfGates = 120;

    float chargeBaggageFee(float numOfBags, float costPerBag);
    void purchaseTicket(bool isTicketPaid = false);
    void screenPassengersForSecurity(bool didPassengerWalkThorughImageDetector, bool wasAnythingDetected);
};

TerminalBuilding::TerminalBuilding()
{
    std::cout << "TerminalBuilding being constructed!" << std::endl;
}

float TerminalBuilding::chargeBaggageFee(float numOfBags, float costPerBag)
{
     float baggageFee = numOfBags * costPerBag;
     std::cout << "\nBaggage Fee amount: $ " << baggageFee << std::endl;
     return baggageFee;  
}

void TerminalBuilding::purchaseTicket(bool isTicketPaid)
{
    if (isTicketPaid)
    {
        std::cout << "Ticket purchased." << std::endl;
    }
}

void TerminalBuilding::screenPassengersForSecurity(bool didPassengerWalkThorughImageDetector, bool wasAnythingDetected)
{
    if ((didPassengerWalkThorughImageDetector == true) && (wasAnythingDetected == false))
    {
        std::cout << "Please continue walking." << std::endl;
    }
    else if ((didPassengerWalkThorughImageDetector == true) && (wasAnythingDetected == true))
    {
        std::cout << "Wait here." << std::endl;
    }
    else
    {
        std::cout << "Error." << std::endl;
    }      
}
    
struct Airport
{
    Airport();
    Airplane airplane;
    Hangar hangar;
    ParkingLot parkingLot;
    ControlTower controlTower;
    TerminalBuilding terminalBuilding;

    void openRestaurant(int PriceOfRestaurant, int spaceNeededForRestaurant);
    void passengerReachDestination(std::string passengerTicketDestination, std::string planeLandedAtDestination);
    float buyRadars(float priceOfRadar, float numOfRadars);
};

void Airport::openRestaurant(int PriceOfRestaurant, int spaceNeededForRestaurant)
{
    if ((PriceOfRestaurant <= 300000) && (spaceNeededForRestaurant <= 3000))
    {
        std::cout << "\nBuy the space for restaurant." << std::endl;
    }
    else
    {
        std::cout << "\nDo not buy space for restaurant." << std::endl;
    }
}

Airport::Airport()
{
    std::cout << "Airport being constructed!" << std::endl;
}

void Airport::passengerReachDestination(std::string passengerTicketDestination, std::string planeLandedAtDestination)
{
    if (passengerTicketDestination == planeLandedAtDestination) 
    {
        std::cout << "Passenger Reached Destination." << std::endl;
    } 
    else
    {
        std::cout << "Passenger did not reach destination." << std::endl;
    }
}

float Airport::buyRadars(float priceOfRadar, float numOfRadars)
{
    float totalRadarCost = priceOfRadar * numOfRadars;
    std::string radarTotalCost = std::to_string(totalRadarCost);
    std::cout << "Total cost for radars:$ " + radarTotalCost << std::endl;
    return totalRadarCost;
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
    Example::main();
    
    CookieShop cookieShop;
    CookieShop::Oven newOven1;
    LawnMower lawnMower;
    Laptop laptop;
    NuclearPowerPlant nucPlant;
    Airplane airplane;
    Airplane::Cockpit cockpit;
    Hangar hangar;
    ParkingLot parkingLot;
    ControlTower controlTower;
    TerminalBuilding termBuilding;
    Airport airport;
    
    cookieShop.bakeCookies(true);
    cookieShop.calculateTotalCustomerCharge(2.00f, 4.00f);
    cookieShop.buyNewOven(newOven1);

    newOven1.produceHeat(true);
    newOven1.displayTimer("10:00");
    newOven1.displayTemp("400F");

    lawnMower.cutGrass(true, true);
    lawnMower.consumeGas(true);
    lawnMower.selfPropel(true, false);

    laptop.typeLetter(true );
    laptop.productOfNumbers(5, 6);
    laptop.runSoftware(true);

    nucPlant.produceHeat(true);
    nucPlant.generateSteam(true);
    nucPlant.produceElectricity(true);

    airplane.takeOff(true, true);
    airplane.land(true, true);
    airplane.sendDataToControlTower(false);

    cockpit.turnPlane(25);
    cockpit.landingGearRaised(true);
    cockpit.talkToAirTrafficControl(true);

    hangar.washPlane(3, 7);
    hangar.routinePlaneMaintenance(3, 2);
    hangar.installEngine(7, 8);

    parkingLot.parkCars(false);
    parkingLot.purchaseParking(true);
    parkingLot.liftBarrierArm(true);

    controlTower.provideAirplaneGateClearance(true, 1700);
    controlTower.monitorPlaneFlight(900, "North");
    controlTower.clearPlaneForLanding(true, true);

    termBuilding.chargeBaggageFee(2.0f, 50);
    termBuilding.purchaseTicket(true);
    termBuilding.screenPassengersForSecurity(true, true);

    airport.openRestaurant(400000, 2500);
    airport.passengerReachDestination("Boston", "New York");
    airport.buyRadars(500000, 3);

    std::cout <<"\nYou have " << lawnMower.amountOfGas << " gallons of gas." << std::endl;
    std::cout <<"There are " << termBuilding.numOfSecurityCheckpoints << " security checkpoints." << std::endl;
    std::cout << "The airplane has " << cockpit.numOfPilots << " pilots." << std::endl;
    std::cout << "good to go!" << std::endl;
}
