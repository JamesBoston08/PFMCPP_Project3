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
    int numberOfStaff; // member variable that is not initialized in-class                                             
    CookieShop() : numberOfStaff(10) { } // initializing member varibale that was not initailized in-class
    float avgEarningsPerWeek = 1500.50f;
    float avgCookieDoughPerWeek = 20.5f;
    float avgCoffeePerWeek { 17.8f }; // member variable initialized in-class
    float cashOnHand = 2447.89f;

    struct Oven  
    {
        int widthOfOven = 30;
        int maxTemp; //member variable that is not initialized in-class
        Oven() : maxTemp(450) { } // initializing member varibale that was not initailized in-class
        std::string manufacturer = "Maytag";
        int widthOfOvenWindow = 26;
        int numOfKnobs { 7 }; // member variable initialized in-class

        void produceHeat(bool isOvenOn);
        void displayTimer(std::string setTime);
        void displayTemp(std::string setTemp);
    };

    void bakeCookies(bool isPreheatTempReached);
    float calculateTotalCustomerCharge(float cookiePrice = 1.95f, float coffeePrice = 3.15f); 
    void buyNewOven(Oven manufacturer);
};

void CookieShop::Oven::produceHeat(bool isOvenOn)
{
    if (isOvenOn == true)
    {
        std::cout << "Oven heating." << std::endl;
    }
}

void CookieShop::Oven::displayTimer(std::string setTime)
{
    std::cout << "Timer is " << setTime << "." << std::endl;
}

void CookieShop::Oven::displayTemp(std::string setTemp)
{
    std::cout << "Temperature is " << setTemp << "." << std::endl;
    std::cout << "Changing temperature to " << maxTemp <<  "." << std::endl; // //2) printing out something interesting
}

void CookieShop::bakeCookies(bool isPreheatTempReached)
{
    if (isPreheatTempReached)
    {
        std::cout << std::endl;
        std::cout << "Ready to bake." << std::endl;
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
    std::cout << "I bought a new oven from " << newOvenA.manufacturer << "." << std::endl;
    std::cout << "We will now go from " << numberOfStaff << " to " << numberOfStaff + 3 << " employees." << std::endl; //2) printing out something interesting
}

struct LawnMower 
{ 
    float amountOfGas = 3.00f;
    int numOfWires; //member variable that is not initialized in-class
    LawnMower() : numOfWires (20) { } // initializing member varibale that was not initailized in-class
    int numOfBlades = 3; 
    float bladeHeight { 2.5f }; // member variable initialized in-class
    int rpmsOfBlades = 3000;

    void cutGrass(bool engineOn = false, bool engineHandleBarPressedDown = false);
    void consumeGas(bool engineOn = false);
    void selfPropel(bool engineOn = false, bool selfPropelHandleBarPressedDown = false);
};

void LawnMower::cutGrass(bool engineOn, bool engineHandleBarPressedDown)
{
    if ((engineOn == true) && (engineHandleBarPressedDown == true))
    {
        std::cout << std::endl;
        std::cout << "Ready to cut grass." << std::endl;
        std::cout << "Blade height is set to " << bladeHeight << " inches." << std::endl; //2) printing out something interesting
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
    int towerHeight = 13;
    int numOfFans; //member variable that is not initialized in-class   
    Laptop() : numOfFans (3) { } // initializing member varibale that was not initailized in-class
    int amountOfRam = 16;
    int numOfUSBPorts = 6; 
    int numOfKeys { 120 }; // member variable initialized in-class

    void typeLetter(bool isLetterKeyPressed);
    int productOfNumbers(int num1, int num2);
    void runSoftware(bool hasDoubleClickedIcon);
};

void Laptop::typeLetter(bool isLetterKeyPressed)
{
    if (isLetterKeyPressed == true)
    {
        char letterPressed = 'B';
        std::cout << std::endl;
        std::cout << "Out of " << numOfKeys << " keys, you pressed the letter " << letterPressed << "." << std::endl; //2) printing out something interesting
    }
}

int Laptop::productOfNumbers(int num1, int num2)
{
    int product = num1 * num2;
    std::cout << "Product is " << product << "." << std::endl;
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
    float amountOfWaterUsed = 375.5f;
    float tempOfWater; //member variable that is not initialized in-class   
    NuclearPowerPlant() : tempOfWater (284.8f) { } // initializing member varibale that was not initailized in-class
    int numOfGenerators { 3 }; // member variable initialized in-class
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
        std::cout << std::endl;
        std::cout << "It's getting hot!" << std::endl;
        std::cout << "The water temperature is " << tempOfWater << "F." << std::endl; //2) printing out something interesting
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
    int numOfPassengerSeats;//member variable that is not initialized in-class
    Airplane() : numOfPassengerSeats (180) { } // initializing member varibale that was not initailized in-class
    float totalWeightOfPlane = 92354.67f;
    float lengthOfPlaneWings { 33.5f }; // member variable initialized in-class
    int numOfLuggagePieces = 225;
    int amountOfFuel = 20000;

    struct Cockpit
    { 
        int numOfSwitches { 30 }; // member variable initialized in-class
        int numOfDisplays = 8;
        int numOfFlightControllers = 2;
        int numOfRudderPedals = 4;
        int numOfPilots; //member variable that is not initialized in-class
        Cockpit() : numOfPilots (2) { } // initializing member varibale that was not initailized in-class

        int turnPlane(int degreesTurned);
        void landingGearRaised(bool isGearLeverInUpPostion);
        void talkToAirTrafficControl(bool isPushToTalkSwitchPressed);
    };

    void takeOff(bool isRunwayClear, bool isTakeOffSpeedReached);
    void land(bool isLandingSpeedReached, bool areWheelsDeployed);
    void sendDataToControlTower(bool isGreenLightOn); 
};

int Airplane::Cockpit::turnPlane(int degreesTurned)
{
    std::cout << std::endl;
    std::cout << "Plane turned " << degreesTurned << " degrees." << std::endl;
    return degreesTurned;
}

void Airplane::Cockpit::landingGearRaised(bool isGearLeverInUpPostion)
{
    if(isGearLeverInUpPostion)
    {
        std::cout << "One of the " << numOfSwitches << " switches will raise the landing gear." << std::endl;
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
        std::cout << std::endl;
        std::cout << "Ready for takeoff!" << std::endl;
        std::cout << "We only have " << numOfPassengerSeats - 20 << " passenger seats filled." << std::endl; //2) printing out something interesting
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
    float hangarSize = 8000.0f;
    int numOfPlanes; //member variable that is not initialized in-class
    Hangar() : numOfPlanes (3) { } // initializing member varibale that was not initailized in-class
    int numOfMaintenanceEmployees = 100;
    int numOfAircraftJacks { 12 }; //member variable initialized in-class
    int maxHeightOfMaintenancePlatform = 12;

    void washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane);
    void routinePlaneMaintenance(int hrsNeededtoPerformMaintenance, int numOfEmployeesPerformingMaintenace);
    void installEngine(int numOfEmployeesInstallEngine, int hrsNeededToInstallEngine);
};

void Hangar::washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane)
{
    if ((numOfEmployeesWashing >= 5) && (hrsNeededToWashPlane <= 7))
    {
        std::cout << std::endl;
        std::cout << "All " << numOfPlanes << " planes can be washed." << std::endl; //2) printing out something interesting
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Planes can't be washed." << std::endl;
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
    int numOfCars = 3000; 
    int numOfParkingPasses = 2687;
    float sizeOfParkingLot = 12.3f;
    int numOfParkingSpaces { 3500 }; // member variable initialized in-class
    int numOfParkingLotExits; //member variable that is not initialized in-class
    ParkingLot() : numOfParkingLotExits (5) { } // initializing member varibale that was not initailized in-class

    void parkCars(bool isOpenParkingSpace);
    void purchaseParking (bool isParkingPaid);
    void liftBarrierArm(bool isTicketButtonPressed);
};

void ParkingLot::parkCars(bool isOpenParkingSpace)
{
    if (isOpenParkingSpace)
    {
        std::cout << std::endl;
        std::cout << "Park cars here" << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Can't park cars here." << std::endl;
        std::cout << "All " << numOfParkingSpaces << " parking spaces are filled." << std::endl; //2) printing out something interesting
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
    int numOfWindows = 40;
    int numOfAirTarfficControllers; //member variable that is not initialized in-class
    ControlTower() : numOfAirTarfficControllers (8) { } // initializing member varibale that was not initailized in-class
    float controlTowerHeight = 369.5f;
    int numOfDisplays = 50;
    int numOfRadars { 2 }; // member variable initialized in-class

    void provideAirplaneGateClearance(bool hasSentPushBackClearence, int timeToPushBackFromGate);
    std::string monitorPlaneFlight(float planeSpeed, std::string directionOfMovement);
    void clearPlaneForLanding(bool hasSentLandingClearance, bool hasReachedLandingSpeed);
};

void ControlTower::provideAirplaneGateClearance(bool hasSentPushBackClearence, int timeToPushBackFromGate)
{
    if ((hasSentPushBackClearence == true) && (timeToPushBackFromGate >= 1600))
    {
        std::cout << std::endl;
        std::cout << "Airplane ready to clear gate." << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Airplane can't clear gate because " << numOfRadars - 1 << " radar is down." << std::endl; //2) printing out something interesting
    }
}

std::string ControlTower::monitorPlaneFlight(float planeSpeed, std::string directionOfMovement)
{
    std::string planeSpeedString = std::to_string(planeSpeed);
    std::cout << "Plane Speed is: " << planeSpeed << " mph and " << "direction is: " << directionOfMovement << "." << std::endl;
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
    int numOfTerminals { 2 }; // member variable initialized in-class
    int numOfTicketCounters; //member variable that is not initialized in-class
    TerminalBuilding() : numOfTicketCounters (15) { } // initializing member varibale that was not initailized in-class
    int numofTSAEmplyees = 100;
    int numOfSecurityCheckpoints = 10;
    int numOfGates = 120;

    float chargeBaggageFee(float numOfBags, float costPerBag);
    void purchaseTicket(bool isTicketPaid = false);
    void screenPassengersForSecurity(bool didPassengerWalkThorughImageDetector, bool wasAnythingDetected);
};

float TerminalBuilding::chargeBaggageFee(float numOfBags, float costPerBag)
{
    float baggageFee = numOfBags * costPerBag;
    std::cout << std::endl;
    std::cout << "Baggage Fee amount: $ " << baggageFee << "." << std::endl;
    return baggageFee;  
}

void TerminalBuilding::purchaseTicket(bool isTicketPaid)
{
    if (isTicketPaid)
    {
        std::cout << "Ticket purchased at one of " << numOfTicketCounters << " ticket counters." << std::endl; //2) printing out something interesting
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
        std::cout << std::endl;
        std::cout << "Buy the space for restaurant." << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Do not buy space for restaurant." << std::endl;
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
    std::cout << "We lost " << controlTower.numOfRadars - 1 << " radar and need to buy another one." << std::endl; //2) printing out something interesting  
    float totalRadarCost = priceOfRadar * numOfRadars;
    std::string radarTotalCost = std::to_string(totalRadarCost);
    std::cout << "Total cost for radars:$ " + radarTotalCost << "." << std::endl;
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

    hangar.washPlane(6, 6);
    hangar.routinePlaneMaintenance(3, 2);
    hangar.installEngine(7, 8);

    parkingLot.parkCars(false);
    parkingLot.purchaseParking(true);
    parkingLot.liftBarrierArm(true);

    controlTower.provideAirplaneGateClearance(false, 1700);
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
