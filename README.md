# Movie Ticket Booking System

## Problem Statement

Build a small Movie Ticket Booking System for a single cinema.
A customer can view movies, select a show, check seats, book seats,
make payment, print a ticket and cancel a booking.

## Functional Requirements

1. The system shall display all currently playing movies.
2. The system shall display shows for a selected movie.
3. The system shall display the seat layout for a selected show.
4. The system shall allow customers to book one or more available seats.
5. The system shall reject seats that are already booked.
6. The system shall calculate price according to seat type.
7. Silver seat price is Rs.150.
8. Gold seat price is Rs.250.
9. Platinum seat price is Rs.400.
10. The system shall support UPI, CASH and CARD payment.
11. A failed payment shall not confirm the booking.
12. The system shall generate a ticket after successful payment.
13. The ticket shall contain booking ID, movie, screen, show time,
    seat numbers and total amount.
14. The system shall allow cancellation of a booking.
15. Cancelled seats shall become available again.

## Non-Functional Requirements

- The system should be easy to use.
- The system should respond quickly.
- The system should prevent duplicate seat booking.
- The code should be modular and easy to maintain.
- The system should provide clear messages to the customer.

## Seat Pricing

| Seat Type | Price |
|-----------|-------|
| SILVER | Rs.150 |
| GOLD | Rs.250 |
| PLATINUM | Rs.400 |

## Main Classes

- Movie
- Show
- Seat
- Customer
- Payment
- Booking

## Technologies

- C++
- Object-Oriented Programming
- GitHub

## Project Modules

Movie Module:
Stores movie information.

Show Module:
Stores screen and show timing.

Seat Module:
Manages seat type, price and availability.

Customer Module:
Stores customer details.

Payment Module:
Handles UPI, CASH and CARD payments.

Booking Module:
Creates and manages movie ticket bookings.

## Author

Surbhi Krishali
 1
