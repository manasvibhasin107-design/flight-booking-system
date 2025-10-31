Overview -
The Flight Booking System is a simple C-based console application that allows users to view available flights, book tickets, and check existing bookings.
It simulates a real-world airline ticket booking process — including seat selection, payment methods, and saving booking records to a file.

Features -
1.User Registration & Login – Each user must register and log in before using the system.
2.View Available Flights – Displays flight number, destination, available seats, and ticket price.
3.Book a Flight – Users can:
Select a flight by its flight number.
Choose a seat type (Window, Middle, or Aisle).
Select a payment method (UPI, Credit Card, Debit Card, Net Banking).
Automatically save the booking details to a file.
4.Data Persistence – All bookings are stored in a text file for future reference.

Tech Stack-
Language: C
File Handling: For saving and retrieving bookings
Compiler: Any C compiler (GCC, Vs code, Code::Blocks, etc.)

Working of program-
1.Start the program – You’ll see a welcome screen.
2.Register & Login – Enter a username and password to create your account.
3.Choose an option from the menu:
  1: View available flights
  2: Book a flight
  3: View all your bookings
  4: Exit
4.Booking details will be saved in a file named bookings.txt.
