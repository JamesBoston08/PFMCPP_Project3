/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




struct CookieShop  
{
    int numberOfStaff;                                       
    CookieShop() : numberOfStaff(10) { }
    float avgEarningsPerWeek = 1500.50f;
    float avgCookieDoughPerWeek = 20.5f;
    float avgCoffeePerWeek { 17.8f }; 
    float cashOnHand = 2447.89f;

    struct Oven  
    {
        int widthOfOven = 30;
        int maxTemp=450; 
        std::string manufacturer = "Maytag";
        int widthOfOvenWindow = 26;
        int numOfKnobs { 7 }; 

        void produceHeat(bool isOvenOn);
        void displayTimer(std::string setTime);
        void displayTemp(std::string setTemp);
        void lowerTemp(int currentTemp); // new member function 1
    };

    void bakeCookies(bool isPreheatTempReached);
    float calculateTotalCustomerCharge(float cookiePrice = 1.95f, float coffeePrice = 3.15f); 
    void buyNewOven(Oven manufacturer);
    int hireNewStaff(int newStaffMember); // new member function 2
};

void CookieShop::Oven::produceHeat(bool isOvenOn)
{
    if (isOvenOn == true)
    {
        std::cout << std::endl;
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
    std::cout << "Changing temperature to " << maxTemp <<  "." << std::endl;
    std::cout << std::endl;
}

void CookieShop::Oven::lowerTemp(int currentTemp) //New member function 1
{
    Oven oven;
    while(oven.maxTemp > currentTemp)
    {
        oven.maxTemp -= 10;
        std::cout << "Lowering temp to: " << oven.maxTemp << std::endl;
    }
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
    std::cout << "We will now go from " << numberOfStaff << " to " << numberOfStaff + 3 << " employees." << std::endl; 
    std::cout << std::endl;
}

int CookieShop::hireNewStaff(int totalStaffNeeded) //new member function 2
{
    for(int i = numberOfStaff; i <= totalStaffNeeded; ++i)
    {
        ++numberOfStaff;
        std::cout << "Increasing staff: " << numberOfStaff << std::endl;     
    }   
    return numberOfStaff;
}

struct LawnMower 
{ 
    float amountOfGas = 3.00f;
    int numOfWires;
    LawnMower() : numOfWires (20) { } 
    int numOfBlades = 3; 
    float bladeHeight { 2.5f }; 
    int rpmsOfBlades = 3000;

    void cutGrass(bool engineOn = false, bool engineHandleBarPressedDown = false);
    void consumeGas(bool engineOn = false);
    void selfPropel(bool engineOn = false, bool selfPropelHandleBarPressedDown = false);
    float fillGasTank(float newGasAmount); //new member function 3
};

void LawnMower::cutGrass(bool engineOn, bool engineHandleBarPressedDown)
{
    if ((engineOn == true) && (engineHandleBarPressedDown == true))
    {
        std::cout << std::endl;
        std::cout << "Ready to cut grass." << std::endl;
        std::cout << "Blade height is set to " << bladeHeight << " inches." << std::endl; 
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
        std::cout << std::endl;
    }
    else if ((engineOn == true) && (selfPropelHandleBarPressedDown == false))
    {
        std::cout << "Self Propel off." << std::endl;
        std::cout << std::endl;
    }
}

float LawnMower::fillGasTank(float newGasAmount) //new member function 3
{
    while (amountOfGas < newGasAmount)
    { 
        amountOfGas += 0.25f;
        std::cout << "Tank is filling: " << amountOfGas << " gallons of gas." << std::endl;
    }
    return amountOfGas;
        
}
    
struct Laptop
{
    int towerHeight = 13;
    int numOfFans; 
    Laptop() : numOfFans (3) { } 
    int amountOfRam = 16;
    int numOfUSBPorts = 6; 
    int numOfKeys { 120 }; 

    void typeLetter(bool isLetterKeyPressed);
    int productOfNumbers(int num1, int num2);
    void runSoftware(bool hasDoubleClickedIcon);
    int increaseRam(int newRam); //new member function 4
    
};

void Laptop::typeLetter(bool isLetterKeyPressed)
{
    if (isLetterKeyPressed == true)
    {
        char letterPressed = 'B';
        std::cout << std::endl;
        std::cout << "Out of " << numOfKeys << " keys, you pressed the letter " << letterPressed << "." << std::endl; 
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
        std::cout << std::endl;
    }   
}

int Laptop::increaseRam(int addNewRam) //new member function 4
{
    for(int i = amountOfRam; i < addNewRam; ++i)
    {
        amountOfRam += 4;
        std::cout << "Increasing RAM to: " << amountOfRam << std::endl;
        if( amountOfRam >= addNewRam)
            return amountOfRam;
    }
    return amountOfRam;
}

struct NuclearPowerPlant
{ 
    float amountOfWaterUsed = 375.5f;
    float tempOfWater;  
    NuclearPowerPlant() : tempOfWater (284.8f) { } 
    int numOfGenerators { 3 };
    float weightOfGenerators = 389.79f;
    int numOfEngineers = 100;

    void produceHeat(bool isFissionSuccessful);
    void generateSteam(bool tubesReachedNeededTemp);
    void produceElectricity(bool isGeneratorReceivingSteam);
    int addMoreGenerators( int generatorsAdded); //new member function 5
};

void NuclearPowerPlant::produceHeat(bool isFissionSuccessful)
{
    if (isFissionSuccessful)
    {
        std::cout << std::endl;
        std::cout << "It's getting hot!" << std::endl;
        std::cout << "The water temperature is " << tempOfWater << "F." << std::endl; 
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
        std::cout << std::endl;
    }
}

int NuclearPowerPlant::addMoreGenerators(int generatorsAdded) //new member function 5
{
    while(numOfGenerators < generatorsAdded)
    {
        ++numOfGenerators;
        std::cout << "Adding more genertors: " << numOfGenerators << std::endl;    
    }
    return numOfGenerators;
}

struct Airplane
{
    int numOfPassengerSeats;
    Airplane() : numOfPassengerSeats (180) { }
    float totalWeightOfPlane = 92354.67f;
    float lengthOfPlaneWings { 33.5f }; 
    int numOfLuggagePieces = 225;
    int amountOfFuel = 20000;

    struct Cockpit
    { 
        int numOfSwitches { 30 }; 
        int numOfDisplays = 8;
        int numOfFlightControllers = 2;
        int numOfRudderPedals = 4;
        int numOfPilots; 
        Cockpit() : numOfPilots (2) { } 

        int turnPlane(int degreesTurned);
        void landingGearRaised(bool isGearLeverInUpPostion);
        void talkToAirTrafficControl(bool isPushToTalkSwitchPressed);
        int addMoreDisplays(int displayTotal); //new member function 6
    };

    void takeOff(bool isRunwayClear, bool isTakeOffSpeedReached);
    void land(bool isLandingSpeedReached, bool areWheelsDeployed);
    void sendDataToControlTower(bool isGreenLightOn);
    int  increaseTotalLuggage(int totalLuggage); //new member function 7
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
        std::cout << std::endl;
    }
}

int Airplane::Cockpit::addMoreDisplays(int displayTotal) //new member function 6
{
    while(numOfDisplays < displayTotal)
    {
        ++numOfDisplays;
        std::cout <<"Increasing number of displays "<< numOfDisplays << std::endl;   
    }
    return numOfDisplays;
}

void Airplane::takeOff(bool isRunwayClear, bool isTakeOffSpeedReached)
{
    if ((isRunwayClear == true) && (isTakeOffSpeedReached == true))
    {
        std::cout << std::endl;
        std::cout << "Ready for takeoff!" << std::endl;
        std::cout << "We only have " << numOfPassengerSeats - 20 << " passenger seats filled." << std::endl; 
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
        std::cout << std::endl;
    }
}

int Airplane::increaseTotalLuggage(int totalLuggage) //new member function 7
{
    for(int i = numOfLuggagePieces; i < totalLuggage; ++i)
    {
        ++numOfLuggagePieces;
        std::cout << " Increasing luggage to " << numOfLuggagePieces << std::endl;  
    }
    return numOfLuggagePieces;
}

struct Hangar
{
    float hangarSize = 8000.0f;
    int numOfPlanes; 
    Hangar() : numOfPlanes (3) { } 
    int numOfMaintenanceEmployees = 100;
    int numOfAircraftJacks { 12 }; 
    int maxHeightOfMaintenancePlatform = 12;

    void washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane);
    void routinePlaneMaintenance(int hrsNeededtoPerformMaintenance, int numOfEmployeesPerformingMaintenace);
    void installEngine(int numOfEmployeesInstallEngine, int hrsNeededToInstallEngine);
    int decreaseMaxHeightOfPlatform(int newMaxHeightOfPlatform);  //new member function 8
};

void Hangar::washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane)
{
    if ((numOfEmployeesWashing >= 5) && (hrsNeededToWashPlane <= 7))
    {
        std::cout << std::endl;
        std::cout << "All " << numOfPlanes << " planes can be washed." << std::endl;
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
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Do not install engine." << std::endl;
    }      
}

int Hangar::decreaseMaxHeightOfPlatform(int newMaxHeightOfPlatform) //new member function 8
{
    while(maxHeightOfMaintenancePlatform > newMaxHeightOfPlatform)
    {
        --maxHeightOfMaintenancePlatform;
        std::cout << "Decreaseing height of platform to " <<  maxHeightOfMaintenancePlatform << " feet." << std::endl;
    }
    return  maxHeightOfMaintenancePlatform;
}
struct ParkingLot
{
    int numOfCars = 3000; 
    int numOfParkingPasses = 2687;
    float sizeOfParkingLot = 12.3f;
    int numOfParkingSpaces { 3500 }; 
    int numOfParkingLotExits; 
    ParkingLot() : numOfParkingLotExits (5) { } 

    void parkCars(bool isOpenParkingSpace);
    void purchaseParking (bool isParkingPaid);
    void liftBarrierArm(bool isTicketButtonPressed);
    int increaseParkingPasses(int totalParkingPasses); //new member function 9
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
        std::cout << "All " << numOfParkingSpaces << " parking spaces are filled." << std::endl; 
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
        std::cout << std::endl;
    }       
}

int ParkingLot::increaseParkingPasses(int totalParkingPasses) //new member function 9
{
    while(numOfParkingPasses < totalParkingPasses)
    {
        ++numOfParkingPasses;
        std::cout << "Total new parking passes: " << numOfParkingPasses << std::endl;

    }
    return numOfParkingPasses;
}

struct ControlTower
{
    int numOfWindows = 40;
    int numOfAirTarfficControllers; 
    ControlTower() : numOfAirTarfficControllers (8) { } 
    float controlTowerHeight = 369.5f;
    int numOfDisplays = 50;
    int numOfRadars { 2 }; 

    void provideAirplaneGateClearance(bool hasSentPushBackClearence, int timeToPushBackFromGate);
    std::string monitorPlaneFlight(float planeSpeed, std::string directionOfMovement);
    void clearPlaneForLanding(bool hasSentLandingClearance, bool hasReachedLandingSpeed);
    int hireNewAirTraffiControllers (int newAirTrafficController); //new member function 10
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
        std::cout << "Airplane can't clear gate because " << numOfRadars - 1 << " radar is down." << std::endl;
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
        std::cout << std::endl;
    }
}

int ControlTower::hireNewAirTraffiControllers (int newAirTrafficControllers) //new member function 10
{
    for(int i = numOfAirTarfficControllers; i < newAirTrafficControllers; ++i)
    {
        ++numOfAirTarfficControllers;
        std::cout << "Total air traffic controllers: " << numOfAirTarfficControllers << std::endl;
        
    }
    return numOfAirTarfficControllers;
}
struct TerminalBuilding
{
    int numOfTerminals { 2 }; 
    int numOfTicketCounters;
    TerminalBuilding() : numOfTicketCounters (15) { }
    int numOfTSAEmployees = 100;
    int numOfSecurityCheckpoints = 10;
    int numOfGates = 120;

    float chargeBaggageFee(float numOfBags, float costPerBag);
    void purchaseTicket(bool isTicketPaid = false);
    void screenPassengersForSecurity(bool didPassengerWalkThorughImageDetector, bool wasAnythingDetected);
    int increaseTotalTerminals(int newTerminals); //new member function 11
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
        std::cout << "Ticket purchased at one of " << numOfTicketCounters << " ticket counters." << std::endl;
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
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Error." << std::endl;
        std::cout << std::endl;
    }      
}

int TerminalBuilding::increaseTotalTerminals(int newTerminals) //new member function 11
{
    for( int i = numOfTerminals; numOfTerminals < newTerminals; ++i)
    {
        ++numOfTerminals;
        std::cout << "Increasing number of terminals: " << numOfTerminals << std::endl; 
    }
    return numOfTerminals;
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
    int addTSAEmployees (int totalTSAEmployees); //new member function 12
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
    std::cout << "We lost " << controlTower.numOfRadars - 1 << " radar and need to buy another one." << std::endl;   
    float totalRadarCost = priceOfRadar * numOfRadars;
    std::string radarTotalCost = std::to_string(totalRadarCost);
    std::cout << "Total cost for radars:$ " + radarTotalCost << "." << std::endl;
    std::cout << std::endl;
    return totalRadarCost;
}

int Airport::addTSAEmployees (int totalTSAEmployees) //new member function 12
{
    while(terminalBuilding.numOfTSAEmployees < totalTSAEmployees)
    {
        ++terminalBuilding.numOfTSAEmployees;
        std::cout << "Adding new TSA employees: " <<  terminalBuilding.numOfTSAEmployees << std::endl;
    }
    return  terminalBuilding.numOfTSAEmployees;
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
    cookieShop.hireNewStaff(12);

    newOven1.produceHeat(true);
    newOven1.displayTimer("10:00");
    newOven1.displayTemp("400F");
    newOven1.lowerTemp(430);

    lawnMower.cutGrass(true, true);
    lawnMower.consumeGas(true);
    lawnMower.selfPropel(true, false);
    lawnMower.fillGasTank(4.00f);

    laptop.typeLetter(true );
    laptop.productOfNumbers(5, 6);
    laptop.runSoftware(true);
    laptop.increaseRam(32);

    nucPlant.produceHeat(true);
    nucPlant.generateSteam(true);
    nucPlant.produceElectricity(true);
    nucPlant.addMoreGenerators(7);

    airplane.takeOff(true, true);
    airplane.land(true, true);
    airplane.sendDataToControlTower(false);
    airplane.increaseTotalLuggage(228);

    cockpit.turnPlane(25);
    cockpit.landingGearRaised(true);
    cockpit.talkToAirTrafficControl(true);
    cockpit.addMoreDisplays(11);

    hangar.washPlane(6, 6);
    hangar.routinePlaneMaintenance(3, 2);
    hangar.installEngine(7, 8);
    hangar.decreaseMaxHeightOfPlatform(10);

    parkingLot.parkCars(false);
    parkingLot.purchaseParking(true);
    parkingLot.liftBarrierArm(true);
    parkingLot.increaseParkingPasses(2690);

    controlTower.provideAirplaneGateClearance(false, 1700);
    controlTower.monitorPlaneFlight(900, "North");
    controlTower.clearPlaneForLanding(true, true);
    controlTower.hireNewAirTraffiControllers(11);

    termBuilding.chargeBaggageFee(2.0f, 50);
    termBuilding.purchaseTicket(true);
    termBuilding.screenPassengersForSecurity(true, true);
    termBuilding.increaseTotalTerminals(5);

    airport.openRestaurant(400000, 2500);
    airport.passengerReachDestination("Boston", "New York");
    airport.buyRadars(500000, 3);
    airport.addTSAEmployees (103);

    std::cout <<"\nYou have " << lawnMower.amountOfGas << " gallons of gas." << std::endl;
    std::cout <<"There are " << termBuilding.numOfSecurityCheckpoints << " security checkpoints." << std::endl;
    std::cout << "The airplane has " << cockpit.numOfPilots << " pilots." << std::endl;
    std::cout << "good to go!" << std::endl;
}
