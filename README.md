# Retry-Until-Valid Input Menu

A small C++ console utility simulating a warehouse kiosk: a menu-driven
session where a worker logs item codes, checks running stats, and quits
whenever they choose — with invalid input reprompted in place rather than
ending the program, and a hard cap on session length as a safety net.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter 8: `while`, `do-while`, `switch`, `break`, and `continue` — and on
choosing the loop shape that actually matches the job (bounded vs.
unbounded, at-least-once vs. maybe-zero-times). Earlier fundamentals
(multi-file structure, validation, encapsulated global state) are used as
supporting scaffolding, not the focus.

## What it does

- Presents a menu (log item, view stats, quit) in an outer session loop,
  dispatching on the user's choice with a `switch`
- Retries the item-code prompt in place until a valid code is entered,
  without ending the program on invalid input
- Tracks running counts of successfully logged items and failed attempts
  across the whole session
- Shows those counts on demand via "view stats," and again in the closing
  message when the session ends
- Enforces a `constexpr` maximum number of items per session, ending the
  session automatically — with a distinct message — if the cap is reached
  before the user chooses to quit

## Project structure

```
main.cpp                    // program entry point, orchestrates the menu/session loop                   
io/
  io.h                      // reading menu choices and item codes, printing all output
  io.cpp             
validation/
  validation.h              // isMenuOptionValid() / isItemCodeValid() — pure predicates
globals/
  globals.h                 // session counters (items logged, failed attempts) and the session cap
  globals.cpp          
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp io/io.cpp globals/globals.cpp
```

Or open `Retry-Until-Valid Input Menu.slnx` in Visual Studio.

## Running

```bash
./app
```

Example session:

```
=== Warehouse Kiosk ===
1) Log item
2) View stats
3) Quit
Choose an option: 1

Enter item code (1000-9999): 42
Invalid item code. Try again.
Enter item code (1000-9999): 7734
Item 7734 logged.

=== Warehouse Kiosk ===
1) Log item
2) View stats
3) Quit
Choose an option: 3

Session ended. 1 item(s) logged this session (1 failed attempts).
```

## Notes

Session state (`itemsSuccess`, `itemsError`) is hidden behind `static`
variables inside `globals.cpp` and exposed only through functions in
`globals.h` — no other file can read or modify it directly. The session
cap (`maxSessionItems`) is an `inline constexpr` in the header, shared
safely across files. The inner item-code retry uses `while (true)` with an
explicit `break` rather than `do-while`, a deliberate choice to avoid
writing the same validity check twice. Non-numeric console input isn't
handled defensively yet — recovering a failed input stream is Ch 9
material and is a known, intentional gap at this stage of the course.