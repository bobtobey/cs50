-- Keep a log of any SQL queries you execute as you solve the mystery.

-- ACTION: Read crime report for that date and on that street
SELECT description FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
-- RESULT: the crime happended at 10:15am in Emma's bakery, there are 3 witness interviews that mention the bakery

-- ACTION: Next read interviews for that date of the crime where witness mentions bakery
SELECT name, transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';
-- RESULT: witness Ruth sees thief leave in a car at 10:25am from bakery parking lot
-- RESULT: witness Eugene recognizes the thief from that morning before 10:15am, withdrawing money at the Leggett St. ATM
-- RESULT: witness Raymond saw the thief leaving the bakery and call someone for less than a minute right after the crime
-- RESULT: witness Raymond overheard the thief say they wanted the first flight out of town tommorrow and for the accomplice to buy the ticket

-- ACTION: Review bakery security logs for 10:15am to 10:30am
SELECT hour, activity, bsl.license_plate, people.name FROM bakery_security_logs AS bsl
    JOIN people ON bsl.license_plate = people.license_plate
    WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND activity LIKE 'exit' ORDER BY bsl.license_plate;
-- RESULT: 9 vehicles exit the bakery parking lot at 10am yielding 9 license_plate

-- ACTION: Review atm transactions from 10:14am or earlier at Leggett st.
SELECT * FROM atm_transactions
    WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' ORDER BY account_number;
-- RESULT: 8 atm withdrawls were made on Leggett St. yielding 8 account_numbers

-- ACTION: Cross check Bank records against atm records for crime location and date similarities
CREATE TEMPORARY TABLE temp_bank_table AS
SELECT ba.account_number, ba.person_id, people.id, people.name FROM bank_accounts AS ba
    JOIN atm_transactions AS atm ON ba.account_number = atm.account_number
    JOIN people ON ba.person_id = people.id
        WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' ORDER BY ba.account_number;
SELECT * FROM temp_bank_table;
-- RESULTS: mapped names to bank accounts used for 8 atm transactions yields 8 names

-- ACTION: find persons name from bank account and store them in a temp table
CREATE TEMPORARY TABLE temp_suspect_table AS
SELECT name, id FROM people WHERE id IN (
    SELECT person_id FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number FROM atm_transactions
            WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')
);
SELECT * FROM temp_people_table;
-- RESULTS: yield 8 possible names

-- ACTION: Review phone calls from 10:15am to 10:30am
SELECT * FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;
-- RESULT: 9 calls were made on this date that lasted less than 1 min. yields 9 callers/receivers

-- ACTION: Review earliest flights leaving on 7/29 and Airport id's
SELECT * FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute;
SELECT * FROM airports;
-- RESULTS: earliest flight leaves at 8:20am going to 4 = LGA LaGuardia Airport NYC

-- ACTIONS: review passenger info for flight 36
SELECT * FROM passengers WHERE flight_id = 36;
-- RESULTS: 8 persons found

-- ACTION: cross check phone numbers and license plates with temp people table
SELECT temp_people_table.name, temp_people_table.id, pc.caller, p.passport_number, bsl.license_plate FROM temp_people_table
    JOIN phone_calls AS pc ON temp_people_table.phone_number = pc.caller
    JOIN bakery_security_logs AS bsl ON temp_people_table.license_plate = bsl.license_plate
    JOIN passengers AS p ON temp_people_table.passport_number = p.passport_number
-- RESULTS: there are 5 matching names with atm transactions and phone calls
        WHERE pc.year = 2023 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60
-- RESULTS: there are 3 matching names with license plate
        AND bsl.year = 2023 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.activity LIKE 'exit'
-- RESULTS: there are 2 matching names with passports
        AND p.flight_id = 36;
