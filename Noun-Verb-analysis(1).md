# Noun–Verb Analysis

| Noun Found | Keep as a Class? | Reason |
|---|---|---|
| Movie | Yes | A movie has its own information, such as its name and language. |
| Customer | Yes | A customer has their own details, such as name and phone number. |
| Show | Yes | A show represents a movie playing on a specific screen at a specific time. |
| Seat | Yes | Each seat has its own number, type, price and availability. |
| Booking | Yes | A booking stores the information related to a customer's reservation. |
| Payment | Yes | Payment handles the selected payment method and payment status. |
| Cinema | No | The current system is designed for a single cinema, so a separate Cinema class is not necessary. |
| Screen | No | Screen information can be stored as part of a Show in this simple implementation. |
| Ticket | No | Ticket details are printed directly after successful booking, so a separate Ticket class is not necessary. |
| Seat Layout | No | It is only a way of displaying the seats. |
| Seat Type | No | It is stored as a property of a Seat. |
| Start Time | No | It is stored as information inside Show. |
| Booking ID | No | It is stored as part of Booking information. |
| Total Amount | No | It is calculated and stored as part of the booking process. |

# Core Entity Classes

| Class | Data members | Methods | Access modifiers | Knows | Does | Must NOT do |
|---|---|---|---|---|---|---|
| `Movie` | `int id`<br>`string name`<br>`string language` | `display()` | Data: `private`<br>Methods: `public` | Movie ID, name, language | Stores and displays movie information | Manage seats, bookings or payments |
| `Seat` | `string seatNumber`<br>`string seatType`<br>`int price`<br>`bool booked` | `getSeatNumber()`<br>`getPrice()`<br>`isAvailable()`<br>`bookSeat()`<br>`cancelSeat()`<br>`displaySeat()` | Data: `private`<br>Methods: `public` | Seat number, type, price and status | Manages seat information and availability | Process payments or manage movies |
| `Show` | `int showId`<br>`string movieName`<br>`string screen`<br>`string startTime` | `displayShow()` | Data: `private`<br>Methods: `public` | Movie name, screen and start time | Represents a movie show | Process payments or book seats |
| `Customer` | `int customerId`<br>`string name`<br>`string phone` | `displayCustomer()`<br>`getName()` | Data: `private`<br>Methods: `public` | Customer name and phone | Stores customer information | Manage seats or payments |
| `Booking` | `int bookingId`<br>`string customerName`<br>`string movieName`<br>`string screen`<br>`string showTime`<br>`vector<string> seats`<br>`int totalAmount`<br>`bool confirmed` | `confirmBooking()`<br>`isConfirmed()`<br>`printTicket()`<br>`getBookingId()` | Data: `private`<br>Methods: `public` | Booking details and selected seats | Stores booking information and prints ticket | Process payment or manage seat availability |

# Behaviour / Service Classes

| Class | Data Members | Methods | Access Specifiers | Knows | Does | Must NOT Do |
|---|---|---|---|---|---|---|
| `Payment` | `string method`<br>`bool successful` | `makePayment(double amount)`<br>`isSuccessful()` | Data: `private`<br>Methods: `public` | Payment method and status | Handles payment confirmation | Manage movies or seats |
| `Booking Process` | None | `findSeat()`<br>`findShow()` | Functions: `public` | Available seats and shows | Finds seats and shows during booking | Process payment details itself |
| `Menu / Main` | `bookingId`<br>System data | `showMovies()`<br>`showShows()`<br>`showSeats()`<br>`main()` | Data: `private` where applicable<br>Functions: `public` | Available system options | Displays menu and coordinates user actions | Store detailed movie or payment logic |
