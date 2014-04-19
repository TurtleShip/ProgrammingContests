#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

typedef long long ll;

class RotatedClock
{
public:
    string getEarliest(int hourHand, int minuteHand);
};


string RotatedClock::getEarliest(int hourHand, int minuteHand)
{
    string ans = "";
    
    for(int mark = 0; mark < 360; mark += 30)
    {
        int hour = (hourHand + mark) % 360;
        int minute = (hour * 12) % 360;
        if(minute == (minuteHand + mark) % 360 )
        {  
            hour = hour / 30;
            minute = minute / 6;
            ostringstream oss;
            oss << setfill('0') << setw(2) << hour << ":" << setw(2) << minute;
            return oss.str();
        }
        
    }
    return ans;
}
