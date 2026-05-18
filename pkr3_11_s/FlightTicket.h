#pragma once
#include <string>

struct TicketRequest {
    std::string destination; 
    std::string flightNumber;     
    std::string passengerName;   
    std::string departureDate;    

    TicketRequest* next = nullptr; 
};

void addRequest(TicketRequest*& head, const TicketRequest& newReq);
bool deleteRequest(TicketRequest*& head, const std::string& passengerName, const std::string& flightNum);
void clearList(TicketRequest*& head);
void sortListByFlight(TicketRequest*& head);

TicketRequest* extractAndRemoveByFlightAndDate(TicketRequest*& head, const std::string& flightNum, const std::string& date);

bool saveToFile(const TicketRequest* head, const std::string& filename);
bool loadFromFile(TicketRequest*& head, const std::string& filename);