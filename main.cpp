/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


/*
Thing 1) Cookie Shop
5 properties:
    1) number of staff (int)    
    2) avg. earnings per week (dollars) (float)
    3) avg. amount of cookie dough used per week (lbs) (float)
    4) avg. amount of coffee used per week (lbs) (float)
    5) amount of cash on hand (float)
3 things it can do:
    1) bake cookies
    2) calculate total charge for customer
    3) brew coffee
*/

struct CookieShop
{
//number of staff (int)
int numberOfStaff = 10;
//avg.earnings per week (dollars) (float)
float avgEarningsPerWeek = 1500.50f;
//avg. amount of cookie dough per week (lbs.) (float)
float avgCookieDoughPerWeek = 20.5f;
//avg. amount of coffee per week (lbs.) (float)
float avgCoffeePerWeek = 17.8f;
//amount of cash on hand (dollars) (float)
float cashOnHand = 2447.89f;

//bake cookies
void bakeCookies(int amountOfChocolateChips, int numOfEggs = 10);
//calculate total charge for customer
float calculateTotalCustomerCharge(float cookiePrice = 1.95f, float coffeePrice = 3.15f);
//brew coffee
void brewCoffee(bool coffeeMakerOn = false, int coffeeUsedPerCup = 2);
};

/*
Thing 2) LawnMower
5 properties:
    1) amount of gasoline (gallon) (float)
    2) number of wires (int)
    3) number of blades (int)
    4) blade height setting (inches) (float)
    5) rpms of blades (int)
3 things it can do:
    1) cut grass
    2) consume gas
    3) self propel
 */
struct LawnMower
{
//amount of gasoline (gallon) (float)
float amountOfGas = 3.00f;
//number of wires (int)
int numOfWires = 20;
//number of blades (int)
int numOfBlades = 3; 
//blade height setting (inches) (float)
float bladeHeight = 2.5f;
//rpms of blades (int)
int rpmsOfBlades = 3000;

//cut grass
void cutGrass(bool engineOn = false, bool engineHandleBarPressedDown = false);
//consume gas
void consumeGas(bool engineOn = false);
//self propel
void selfPropel(bool engineOn = false, bool selfPropelHandleBarPressedDown = false);
};
/*
Thing 3) Laptop
5 properties:
    1) height of tower (inches) (int)
    2) number of fans (int)
    3) amount of ram (GB)(int)
    4) number of usb ports (int)
    5) number of keys (int)
3 things it can do:
    1) display letters typed
    2) multiply numbers
    3) run software
 */
struct Laptop
{
//height of tower (inches) (int)
int towerHeight = 13;
//number of fans (int)
int numOfFans = 3;
//amount of ram (GB)(int)
int amountOfRam = 16;
//number of usb ports (int)
int numOfUSBPorts = 6;
//number of keys (int)
int numOfKeys = 120;

//display letters typed
void typeLetter(bool isLetterKeyPressed);
//multiply numbers
int productOfNumbers(int num1, int num2);
//run software
void runSoftware(bool hasDoubleClickedIcon);
};
/*
Thing 4) Nuclear Power Plant
5 properties:
    1) amount of water used (gallons per mega-watt hr.) (float)
    2) temp. of water (float)
    3) number of generators (int)
    4) weight of generator (tons) (float)
    5) number of engineers (int)
3 things it can do:
    1) produce heat
    2) generate steam
    3) produce electricity
 */
struct NuclearPowerPlant
{
//amount of water used (gallons per mega-watt hr.) (float)
float amountOfWaterUsed = 375.5f;
//temp. of water (celcius) (float)
float tempOfWater = 284.8f;
//number of generators (int)
int numOfGenerators = 3;
//weight of generator (tons) (float)
float weightOfGenerators = 389.79f;
//number of engineers (int)
int numOfEngineers = 100;

//produce heat
//void produceHeat(bool isnuclearChainReactionSuccessful);
//generate steam
//void generateSteam( )
//produce electricity
};
/*
Thing 5) Airplane
5 properties:
    1) Number of passenger seats (int)
    2) Total weight of plane (lbs.) (float)
    3) Length of plane wings (meters) (float)
    4) Number of luggage pieces (int)
    5) Amount of fuel (gallons) (int)
3 things it can do:
    1) Take off and fly
    2) Land 
    3) Send data to control tower
 */
struct Airplane
{
//Number of passenger seats (int)
int numOfPassengerSeats = 180;
//Total weight of plane (lbs.) (float)
float totalWeightOfPlane = 92354.67f;
//Length of plane wings (meters) (float)
float lengthOfPlaneWings = 33.5f;
//Number of luggage pieces (int)
int numOfLuggagePieces = 225;
//Amount of fuel (gallons) (int)
int amountOfFuel = 20000;

//Take off
void takeOff(bool isRunwayClear, bool isTakeOffSpeedReached);
//Land
void land(bool isLandingSpeedReached, bool areWheelsDeployed);
//Send data to control tower
//void sendDataToContolTower() 
};
/*
Thing 6) Hangar
5 properties:
    1) Size of hangar (feet) (float)
    2) Number of planes (int)
    3) Number of maintenance employees (int)
    4) Number of aircraft jacks (int)
    5) Max height of maintenance platforms (feet) (int)
3 things it can do:
    1) Wash airplanes
    2) Perform routine maintenance on airplanes
    3) Install engine
 */
struct Hangar
{
//Size of hangar (feet) (float)
float hangarSize = 8000.0f;
//Number of planes (int)
int numOfPlanes = 3;
//Number of maintenance employees (int)
int numOfMaintenanceEmployees = 100;
//Number of aircraft jacks (int)
int numOfAircraftJacks = 12;
//Max height of maintenance platforms (feet) (int)
int maxHeightOfMaintenancePlatform = 12;

//Wash airplanes
void washPlane(int numOfEmployeesWashing, int hrsNeededToWashPlane);
//Perform routine maintenance on airplanes
void routinePlaneMaintenance(int hrsNeededtoPerformMaintenance, int numOfEmployeesPerformingMaintenace);
//Install engine
void installEngine(int numOfEmployeesInstalEngine, int hrsNeededToInstallEngine);
};
/*
Thing 7) Parking Lot
5 properties:
    1) Number of cars (int)
    2) Number of parking passes (int)
    3) Size of parking lot (float)
    4) Number of parking spaces (int)
    5) Number of parking lot exits (int)
3 things it can do:
    1) Park cars
    2) purchase parking
    3) Lift barrier arm for entering cars
 */
struct ParkingLot
{
//Number of cars (int)
int numOfCars = 3000;
//Number of parking passes (int)
int numOfParkingPasses = 2687;
//Size of parking lot (acres)(float)
float sizeOfParkingLot = 12.3f;
//Number of parking spaces (int)
int numOfParkingSpaces = 3500;
//Number of parking lot exits (int)
int numOfParkingLotExits = 5;

//Park cars
void parkCars(bool isOpenParkingSpace);
//Purchase parking
void purchaseParking(int totalCostOfTicket, bool isParkingPaid);
//Lift barrier arm for entering cars
void (bool isTicketButtonPressed);
}
/*
Thing 8) Control Tower
5 properties:
    1) Number of windows (int)
    2) Number of aircaft trafic controllers (int)
    3) Height of control tower (feet) (float)
    4) Number of monitors/displays (int)
    5) Number of radars (int)
3 things it can do:
    1) Provide airplance clearance to move from gate
    2) Monitor airplane during flight
    3) Clear airplane for landing
 */
struct ControlTower
{
//Number of windows (int)
int numOfWindows = 40;
//Number of aircaft trafic controllers (int)
int numOfAirTarfficControllers = 8;
//Height of control tower (feet) (float)
float controlTowerHeight = 369.5f;
//Number of monitors/displays (int)
int numOfDisplays = 50;
//Number of radars (int)
int numOfRadars = 2;

//Provide airplance clearance to move from gate
void directPlaneOnGround(bool hasSentPushBackClearence, int timeToPushBackFromGate);
//Monitor airplane during flight 
void monitorPlaneFlight(float planeSpeed, float planeAttitude, std::string directionOfMovement);
//Clear airplane for landing
void clearPlaneForLanding(bool hasSentLandingClearance, bool hasReachedLandingSpeed);
};
/*
Thing 9) Terminal Building
5 properties:
    1) Number of terminals (int)
    2) Number of airline ticket counters (int)
    3) Number of TSA emplyees (int)
    4) Number of security checkpoints (int)
    5) Number of gates (int)
3 things it can do:
    1) Check in baggage
    2) Purchase tickets
    3) Screen passengers for security purposes
 */
struct TerminalBuilding
{
//Number of terminals (int)
int numOfTerminals = 2;
//Number of airline ticket counters (int)
int numOfTicketCounters = 15;
//Number of TSA emplyees (int)
int numofTSAEmplyees = 100;
//Number of security checkpoints (int)
int numOfSecurityCheckpoints = 10;
//Number of gates (int)
int numOfGates = 120;

//Check in baggage
void checkBaggage(int numOfBags, float costPerBag);
//Purchase tickets
void purchaseTicket(float totalCostOfTicket, bool isTicketPaid = false);
//Screen passengers for security purposes
void screenPassengersForSecurity(bool didPassengerWalkThorughImageDetector, bool didImageDisplay, bool wasAnythingDetected);
}
/*
Thing 10) Airport
5 properties:
    1) Airplane
    2) Hangar
    3) Parking Lot
    4) Control Tower
    5) Terminal Building
3 things it can do:
    1) Maintain airplanes
    2) Transport passenger to destination
    3) Transport cargo to destination
 */
//Airplane
//Hangar
//Parking Lot
//Control Tower
//Terminal Building
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
