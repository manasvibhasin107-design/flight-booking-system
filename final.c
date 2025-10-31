#include <stdio.h>
#include <string.h>
struct Flight {
    int flightNumber;
    char destination[50];
    int availableSeats;
    float ticketPrice;
    char seatType[10];
};
struct Flight flights[5];
int flightCount = 5;
void saveBookingToFile(struct Flight f) {
    FILE *fp = fopen("bookings.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%d,%s,%.2f,%s\n", f.flightNumber, f.destination, f.ticketPrice, f.seatType);
        fclose(fp);
    } else {
        printf("Error opening file for writing!\n");
    }
}

void welcomeMessage() {
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                     TO                    =");
    printf("\n\t\t\t        =               Airline Ticket              =");
    printf("\n\t\t\t        =               Booking  SYSTEM             =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}

void viewAvailableFlights() {
    printf("\nAvailable Flights:\n");
    printf("Flight Number | Destination    | Available Seats | Ticket Price\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < flightCount; i++) {
        printf("%-14d | %-15s | %-15d | %.2f\n",
               flights[i].flightNumber,
               flights[i].destination,
               flights[i].availableSeats,
               flights[i].ticketPrice);
    }
}

void bookaFlight() {
    int flightNumber, i, found = 0;
    printf("ENTER THE FLIGHT NUMBER TO BOOK: ");
    scanf("%d", &flightNumber);
    getchar(); 

    for (i = 0; i < flightCount; i++) {
        if (flights[i].flightNumber == flightNumber) {
            found = 1;
            if (flights[i].availableSeats > 0) {
                printf("\nTicket Price for Flight %d to %s: %.2f\n",
                       flights[i].flightNumber, flights[i].destination, flights[i].ticketPrice);

                printf("Choose Seat Type:\n");
                printf("1. Window\n2. Middle\n3. Aisle\n");
                printf("Enter your choice (1-3): ");
                int seatChoice;
                scanf("%d", &seatChoice);
                getchar();

                switch (seatChoice) {
                    case 1: strcpy(flights[i].seatType, "Window"); break;
                    case 2: strcpy(flights[i].seatType, "Middle"); break;
                    case 3: strcpy(flights[i].seatType, "Aisle"); break;
                    default:
                        printf("Invalid seat choice. Booking cancelled.\n");
                        return;
                }

                int paymentMethod;
                printf("Choose Payment Method:\n");
                printf("1. UPI\n2. Credit Card\n3. Debit Card\n4. Net Banking\n");
                printf("Enter choice (1-4): ");
                scanf("%d", &paymentMethod);
                getchar();

                if (paymentMethod >= 1 && paymentMethod <= 4) {
                    printf("Processing payment...\n");
                    printf("Payment of %.2f successful!\n", flights[i].ticketPrice);
                    flights[i].availableSeats--;
                    saveBookingToFile(flights[i]);
                    printf("Booking successful! Seat reserved on Flight %d to %s (%s seat).\n",
                           flights[i].flightNumber, flights[i].destination, flights[i].seatType);
                } else {
                    printf("Invalid payment option. Booking cancelled.\n");
                }
            } else {
                printf("SORRY, FLIGHT IS COMPLETELY BOOKED.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Flight number not found.\n");
    }
}

void viewBookings() {
    FILE *fp = fopen("bookings.txt", "r");
    char line[200];
    printf("\nCURRENT BOOKINGS:\n");
    printf("Flight Number | Destination    | Ticket Price | Seat Type\n");
    printf("--------------------------------------------------------------\n");
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            char flightNumber[10], destination[50], ticketPrice[10], seatType[15];
            sscanf(line, "%[^,],%[^,],%[^,],%s", flightNumber, destination, ticketPrice, seatType);
            printf("%-14s | %-15s | %-12s | %s\n", flightNumber, destination, ticketPrice, seatType);
        }
        fclose(fp);
    } else {
        printf("No bookings found.\n");
    }
}

int main() {
    welcomeMessage();
    char registeredUser[100], registeredPass[100];
    char inputUser[100], inputPass[100];
    int choice = 0;

    printf("Register a new account\n");
    printf("Enter new username: ");
    fgets(registeredUser, 100, stdin);
    registeredUser[strcspn(registeredUser, "\n")] = '\0';

    printf("Enter new password: ");
    fgets(registeredPass, 100, stdin);
    registeredPass[strcspn(registeredPass, "\n")] = '\0';  
    printf("\nLogin with your credentials\n");
    printf("Enter username: ");
    fgets(inputUser, 100, stdin);
    inputUser[strcspn(inputUser, "\n")] = '\0';

    printf("Enter password: ");
    fgets(inputPass, 100, stdin);
    inputPass[strcspn(inputPass, "\n")] = '\0';

    if (strcmp(inputUser, registeredUser) != 0 || strcmp(inputPass, registeredPass) != 0) {
        printf("Login failed. Please check your username or password.\n");
        return 0;
    }

    printf("You are logged in.\n");
   
    flights[0] = (struct Flight){101, "Mumbai", 50, 3000};
    flights[1] = (struct Flight){202, "Bangalore", 30, 4000};
    flights[2] = (struct Flight){303, "Jaipur", 20, 6000};
    flights[3] = (struct Flight){404, "Chandigarh", 22, 4500};
    flights[4] = (struct Flight){505, "Agra", 34, 5000};
   
    do {
        printf("\n\n  FLIGHT BOOKING SYSTEM \n");
        printf("------------------------------------\n");
        printf("1. View available flights\n");
        printf("2. Book a flight\n");
        printf("3. View bookings\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                viewAvailableFlights();
                break;
            case 2:
                bookaFlight();
                break;
            case 3:
                viewBookings();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("INVALID CHOICE!!! Try again...\n");
        }
    } while (choice != 4);

    return 0;
}  