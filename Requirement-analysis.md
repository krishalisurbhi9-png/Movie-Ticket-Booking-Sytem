# Functional Requirements

## FR1 - Movies :

The system should display all the currently playing movies with their movie name and language.

##

## FR2 - Shows :

The system should display all the available shows for the selected movie along with screen number and start time.

##

## FR3 - Seat Layout :

For the selected show, the system should display the seat layout along with the seat number, seat type, price and status of every seat (AVAILABLE / BOOKED).

##

## FR4 - Booking :

A customer can select one or more available seat numbers for a show. If any selected seat is already BOOKED, the booking should be rejected and the seat status should not be changed. Booking should be confirmed only after successful payment.

##

## FR5 - Calculate Price :

The total price should be calculated based on the type of the selected seats. SILVER: Rs.150, GOLD: Rs.250 and PLATINUM: Rs.400.

##

## FR6 - Payment :

Exactly one payment method (UPI/CASH/CARD) should be selected for each booking. If payment fails, the booking should not be confirmed and the selected seats should remain AVAILABLE.

##

## FR7 - Ticket :

Only after successful payment, the system should display a ticket containing Booking ID, Movie name, Screen number, Show's start time, booked seat numbers and total amount paid.

##

## FR8 - Cancel Booking :

A customer should be able to cancel a booked seat. After cancellation, the seat status should be changed from BOOKED to AVAILABLE again.

# Non-Functional Requirements

## NFR1 - Modularity :

Each class should have its own source file. The system should be organized into classes and modules so that changes in one class do not unnecessarily affect other classes.

##

## NFR2 - Extensibility :

The design should allow new features or payment methods to be added without making major changes to the existing classes.

##

## NFR3 - Input Validation :

If the user enters an invalid movie ID, show ID, seat number or payment option, the system should reject the invalid input and display a clear message.

##

## NFR4 - Clean Code :

Variable names and function names should clearly describe their purpose. The code should avoid unnecessary duplication, very long functions and magic numbers.

##

## NFR5 - Usability :

The menu-driven system should be simple to understand and should provide clear messages for successful and unsuccessful operations.
