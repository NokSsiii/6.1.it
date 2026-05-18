#include "FlightTicket.h"
#include <fstream>

// Додавання елемента в кінець списку
void addRequest(TicketRequest*& head, const TicketRequest& newReq) {
    TicketRequest* node = new TicketRequest{ newReq.destination, newReq.flightNumber, newReq.passengerName, newReq.departureDate, nullptr };
    if (!head) {
        head = node;
        return;
    }
    TicketRequest* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = node;
}

// Видалення конкретної заявки за назвою та номером рейсу
bool deleteRequest(TicketRequest*& head, const std::string& passengerName, const std::string& flightNum) {
    if (!head) return false;

    TicketRequest* temp = head;
    TicketRequest* prev = nullptr;

    while (temp) {
        if (temp->passengerName == passengerName && temp->flightNumber == flightNum) {
            if (prev == nullptr) {
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}

// Очищення пам'яті списку
void clearList(TicketRequest*& head) {
    while (head) {
        TicketRequest* temp = head;
        head = head->next;
        delete temp;
    }
}

// Сортування списку (за номером рейсу методом Bubble Sort)
void sortListByFlight(TicketRequest*& head) {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        TicketRequest* current = head;
        while (current && current->next) {
            if (current->flightNumber > current->next->flightNumber) {
                // Обмін даними між вузлами
                std::swap(current->destination, current->next->destination);
                std::swap(current->flightNumber, current->next->flightNumber);
                std::swap(current->passengerName, current->next->passengerName);
                std::swap(current->departureDate, current->next->departureDate);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Вибірка заявок за рейсом і датою з їх АВТОМАТИЧНИМ ВИДЕННЯМ з основного списку.
// Повертає вказівник на новий ізольований список знайдених заявок.
TicketRequest* extractAndRemoveByFlightAndDate(TicketRequest*& head, const std::string& flightNum, const std::string& date) {
    TicketRequest* extractedHead = nullptr;
    TicketRequest* current = head;
    TicketRequest* prev = nullptr;

    while (current) {
        if (current->flightNumber == flightNum && current->departureDate == date) {
            // Копіюємо дані до результату
            TicketRequest tempReq = { current->destination, current->flightNumber, current->passengerName, current->departureDate, nullptr };
            addRequest(extractedHead, tempReq);

            // Видаляємо вузол з оригінального списку
            TicketRequest* toDelete = current;
            if (!prev) {
                head = current->next;
                current = head;
            }
            else {
                prev->next = current->next;
                current = current->next;
            }
            delete toDelete;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return extractedHead;
}

// Збереження у файл
bool saveToFile(const TicketRequest* head, const std::string& filename) {
    std::ofstream out(filename);
    if (!out.is_open()) return false;

    const TicketRequest* temp = head;
    while (temp) {
        out << temp->destination << "\n"
            << temp->flightNumber << "\n"
            << temp->passengerName << "\n"
            << temp->departureDate << "\n";
        temp = temp->next;
    }
    out.close();
    return true;
}

// Завантаження з файлу
bool loadFromFile(TicketRequest*& head, const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) return false;

    clearList(head); // Очищуємо старий список перед завантаженням новий

    std::string dest, flight, name, date;
    while (std::getline(in, dest) && std::getline(in, flight) &&
        std::getline(in, name) && std::getline(in, date)) {
        TicketRequest req{ dest, flight, name, date, nullptr };
        addRequest(head, req);
    }
    in.close();
    return true;
}