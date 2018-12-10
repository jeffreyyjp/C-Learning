#define QUIT 5
#define HOTEL1 180.0
#define HOTEL2 225.0
#define HOTEL3 255.0
#define HOTEL4 355.0
#define DISCOUNT 0.95
#define STARS "********************"

// shows list of choices
int menu(void);

// returns number of nights desired
int getnights(void);

// calculates price from rate, nights
// add displays result
void showprice(double rate, int nights);