# 🚆 Railway Ticket Booking System (C++)

A menu-driven Railway Ticket Booking System implemented in C++.  
The system demonstrates core programming concepts such as classes, constructors, dynamic memory allocation, pointers, structs, vectors, and user-interactive console workflows.

---

## 📌 Features

### ✔ Train Management  
- Predefined trains with their respective routes.  
- Each train contains multiple coach/class types (2AC, 3AC, Sleeper, Chair Car, Second Sitting).  

### ✔ Ticket Booking  
- User selects train, boarding station, destination station, and class.  
- System validates seat availability and confirms booking.  

### ✔ Ticket Cancellation  
- Users can cancel previously booked tickets.  
- Seat count is updated accordingly.

### ✔ Availability Check  
- Displays remaining seats in each class for every train.

### ✔ Booking History  
- Stores name of passenger, train name, route, and class of travel.

---

## 🧩 C++ Concepts Used

### 🔹 Classes as User-Defined Types  
Used to model trains, train classes, and booking data structures.

### 🔹 Constructors & Initializer Lists  
Initialize seat counts, class names, and train routes.

### 🔹 Dynamic Memory Allocation  
`new` operator allocates train-class objects at runtime.

### 🔹 Pointers  
Vectors store pointers to dynamically allocated class objects.

### 🔹 `struct` for Data Records  
`Booking` struct used for storing passenger booking details.

### 🔹 STL Vectors  
Used for:
- Train list  
- Route list  
- Available classes  
- Booking history  

### 🔹 Menu-Driven Program Flow  
Interactive loop using `do-while` and conditional branching.

### 🔹 String Handling  
Uses `std::string` throughout for safe text processing.

---

## 🛠 How to Run

1. Compile the program using g++:
   ```bash
   g++ -std=c++17 railway.cpp -o railway


#Output- 
<img width="465" height="608" alt="image" src="https://github.com/user-attachments/assets/0df507e3-bcdb-4c5e-8395-3214bee181ae" />
<img width="421" height="428" alt="image" src="https://github.com/user-attachments/assets/c59e1876-982b-4d0d-9c15-29b776227ff6" />
<img width="423" height="385" alt="image" src="https://github.com/user-attachments/assets/1371f416-3bf4-4dbc-a1c9-2ce40aa42a4f" />


