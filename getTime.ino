String timeHM(){

int timeZone = 2;

// get the time of the client
timeClient.update();

// get what hour the time is
unsigned long hours = timeClient.getHours();
// add timezone defrind
hours += timeZone;

// add a "0" infront of eny nommer les then 10 
String hoursStr = hours < 10 ? "0" + String(hours) : String(hours);

// add a "0" infront of eny nommer les then 10 
unsigned long mins = timeClient.getMinutes();
String minsStr = mins < 10 ? "0" + String(mins) : String(mins);


// combines the 2 string together 
String hoursMinutesReturn = hoursStr + ":" + minsStr;

return String( hoursMinutesReturn );
}
