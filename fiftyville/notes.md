 the theft took place on July 28, 2021 and that it took place on Humphrey Street.

## Crime scene report 
295|2021|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

## INTERVIEWS

161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and 
drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
 
## Getting the suspects 

so I have three sources of where to get suspects.

1. People that left the bakery's parking lot within 10 minutes of the theft
2. People that withdraw money at the ATM of Legget Street
3. People that called that day for less than a minute.

**They were planning on taking a flight out of fiftyvill for tomorrow**


### Suspects Database 

**Tables** 
 Theere will be three tables, referring to the the 3 sources of suspects

**I can get the accomplice by looking at caller or reciever from the call of the thief** 

Now that I have 3 suspects lists, I need to make the pool of suspects smalller. 

As one of the witnesses said that the thief was planning to take a flight out of fiftyville,
I can make my list smaller by filtering by the people that flew the following day. 

Now I have a list of 3 suspects, how can I make this list smaller?

One of my source of suspects was wrong, the phone_calls table doesn't have a table phone_number and 
one of my querys was using that field. 

Now with the correct suspects list from suspects_calls

The list of suspects has been reduced to : 

514354|Diana|(770) 555-1861|3592750733|322W7JE
686048|Bruce|(367) 555-5533|5773159633|94KL13X

864400|Robin|(375) 555-8161||4V16VO0|233|(367) 555-5533|(375) 555-8161|2021|7|28|45
847116|Philip|(725) 555-3243|3391710505|GW362R6|255|(770) 555-1861|(725) 555-3243|2021|7|28|49


How can make this list even smaller?

