-- Keep a log of any SQL queries you execute as you solve the mystery.
--Get the reports
SELECT * 
FROM crime_scene_reports
WHERE year = 2021 AND day = 28 AND month = 7;

--Get the interviews
SELECT * 
FROM interviews
WHERE year = 2021 AND day = 28 AND month = 7;

--Get people from the bakery's security log 
-- Get people that exit the bakery within ten minutes of the theft 
SELECT *  FROM people 
WHERE  license_plate IN (
	SELECT license_plate 
	FROM bakery_security_logs
	WHERE year = 2021 AND day = 28 AND month = 7
	AND hour = 10 AND minute <= 15 + 10
	AND activity = 'exit');


--Get peple that withdraw money that day at the Legget Street
SELECT * FROM people 
WHERE  id IN ( SELECT person_id FROM bank_accounts 
	WHERE account_number IN (
		SELECT account_number
		FROM atm_transactions
		WHERE day = 28 AND month = 7 AND year = 2021 
		AND atm_location = 'Leggett Street'
		AND transaction_type = 'withdraw'));	
			
--Get people that called that day for less than a minute
SELECT * FROM people 
WHERE phone_number IN ( 
	SELECT caller FROM phone_calls
	WHERE day = 28 AND month = 7 AND year = 2021 
	AND duration < 60);  

--Get peple that flew the following date
SELECT * FROM people
WHERE passport_number IN (
	SELECT passport_number 
	FROM flights 
 	WHERE day = 29 AND month = 7 AND year = 2021);

--Get the suspects that flew the following day 
SELECT suspects.id 
FROM suspects_atm, suspects_calls,suspects_bakery_log as suspects 
WHERE suspects.passport_number IN (
	SELECT suspects.passport_number 
	FROM flights 
 	WHERE day = 29 AND month = 7 AND year = 2021);
--
--Get suspects that are in more than one source 
SELECT id
FROM suspects
WHERE id IN (
	SELECT id 
	FROM suspects_atm )

AND id  IN ( 
	SELECT id 
	FROM suspects_calls)

AND id  IN ( 
	SELECT id 
	FROM suspects_bakery_log)
;

--Get the data from the flights 
SELECT * FROM  suspects
JOIN passengers ON suspects.passport_number = passengers.passport_number 
JOIN flights ON  passengers.flight_id = flights.id
JOIN airports ON flights.destination_airport_id = airports.id

--Get the accomplice 
SELECT name FROM people 
WHERE phone_number IN ( 
	SELECT receiver FROM phone_calls 
	WHERE caller IN ( 
		SELECT phone_number FROM people 
		WHERE  id  IN ( 
			SELECT id FROM suspects 
			WHERE name = 'Bruce')
	AND day = 28 AND month = 7 AND year =  2021)); 
