/* The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes one flight daily. Write a seating reservation program with the following features:
    a. The program uses an array of 12 structures. Each structure should hold a seat identification number, a marker that indicates whether the seat is assigned, the last name of the seat holder, and the first name of the seat holder.

    b. The program displays the following menu:
        To choose a function, enter its letter label:
        a) Show number of empty seats
        b) Show list of empty seats
        c) Show alphabetical list of seats
        d) Assign a customer to a seat assignment
        e) Delete a seat assignment
        f) Quit
    
    c. The program successfully executes the promises of its menu. Choices d) and e) require additional input, and each should enable the user to abort an entry.

    d. After executing a particular function, the program shows the menu again, except for choice f).

    e. Data is saved in a file between runs. When the program is restarted, it first loads in the data, if any, from the file.