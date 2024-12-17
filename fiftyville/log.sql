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
SELECT hour, activity, license_plate FROM bakery_security_logs
    WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND activity LIKE 'exit' ORDER BY license_plate;
-- RESULT: 9 vehicles exited the bakery parking lot at 10 with plate info

-- ACTION: Review atm transactions from 10:14am or earlier at Leggett st.
SELECT * FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28;
-- RESULT: 8 atm withdrawls were made on Leggett St.

-- ACTION: Cross check atm records for crime location and date with Bank records
SELECT account_number, person_id FROM bank_accounts
    WHERE account_number IN (SELECT account_number FROM atm_transactions
        WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ORDER BY account_number;
-- RESULTS: found the matching person id's for the 8 atm transactions

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
-- RESULT: 9 calls were made on this date that lasted less than 1 min.
-- ACTION: cross check phone numbers with temp people table
SELECT temp_people_table.name, temp_people_table.id, phone_number FROM temp_people_table
    JOIN phone_calls ON temp_people_table.phone_number = phone_calls.caller WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;
-- RESULTS: there are 5 matching names with atm transactions and phone calls

-- ACTION: Review earliest flights leaving on 7/29 and Airport id's
SELECT * FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute;
SELECT * FROM airports;
-- RESULTS: earliest flight leaves at 8:20am going to 4 = LGA LaGuardia Airport NYC

-- ACTIONS: review passenger info for flight 36
SELECT * FROM passengers WHERE flight_id = 36;
-- RESULTS: 8 persons found
