-- Test log of any SQL queries you execute as you solve the mystery.

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
SELECT bsl.day, bsl.hour, bsl.minute, bsl.activity, bsl.license_plate, people.name FROM bakery_security_logs AS bsl
    JOIN people ON bsl.license_plate = people.license_plate
    WHERE bsl.year = 2023 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 30 AND bsl.activity LIKE 'exit' ORDER BY bsl.minute;
-- RESULT: 8 vehicles exit the bakery parking lot at 10am yielding 8 license_plate

-- ACTION: Review atm transactions from 10:14am or earlier at Leggett st.
SELECT * FROM atm_transactions
    WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' ORDER BY account_number;
-- RESULT: 8 atm withdrawls were made on Leggett St. yielding 8 account_numbers

-- ACTION: Cross check Bank records against atm records for crime location and date similarities
CREATE TEMPORARY TABLE temp_bank_table AS
SELECT ba.account_number, ba.person_id, people.id, people.name FROM bank_accounts AS ba
    JOIN atm_transactions AS atm ON ba.account_number = atm.account_number
    JOIN people ON ba.person_id = people.id
        WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' ORDER BY people.name;
SELECT * FROM temp_bank_table;
-- RESULTS: mapped names to bank accounts used for 8 atm transactions yields 8 names

-- ACTION: find persons name from bank account and store them in a temp table
CREATE TEMPORARY TABLE temp_people_table AS
SELECT name, id, phone_number, passport_number, license_plate FROM people WHERE id IN (
    SELECT person_id FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number FROM atm_transactions
            WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')
) ORDER BY name;
SELECT * FROM temp_people_table;
-- RESULTS: yield 8 possible names

-- ACTION: Review phone calls from 10:15am to 10:30am
SELECT * FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60 ORDER BY duration;
-- RESULT: 9 calls were made on this date that lasted less than 1 min. yields 9 callers/receivers

-- ACTION: Match peoples names to their #'s callers or receivers
SELECT p1.name, caller, p2.name, receiver, duration FROM phone_calls
    JOIN people AS p1 ON phone_calls.caller = p1.phone_number
    JOIN people AS p2 ON phone_calls.receiver = p2.phone_number
        WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60 ORDER BY duration;
-- RESULTS: Mapped names to their phone # for date of the crime

-- ACTION: Review earliest flights leaving on 7/29 and Airport id's
SELECT * FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute;
SELECT * FROM airports;
-- RESULTS: earliest flight leaves at 8:20am going to 4 = LGA LaGuardia Airport NYC
-- ANSWER: LaGuardia Airport NYC is the thief's destination

-- ACTIONS: review passenger info for flight 36
SELECT flight_id, pssgr.passport_number, seat, name FROM passengers AS pssgr
    JOIN people ON pssgr.passport_number = people.passport_number
    WHERE flight_id = 36 ORDER BY name;
-- RESULTS: Mapped names to passports for flight 36 - 8 persons found

-- ACTION: Temp Aggregate table for cross checking details across tables to eliminate suspects
SELECT DISTINCT 'Aggregate' AS table_name
    ,tpt.name, tpt.id, pc.caller AS caller_num
    ,p.passport_number, bsl.license_plate
    ,ppl.name AS rec_name, pc.receiver AS rec_num
    ,tbt.id AS bank_id, tbt.account_number
FROM temp_people_table AS tpt
    JOIN phone_calls AS pc ON tpt.phone_number = pc.caller
    JOIN people AS ppl ON pc.receiver = ppl.phone_number
    JOIN bakery_security_logs AS bsl ON tpt.license_plate = bsl.license_plate
    JOIN passengers AS p ON tpt.passport_number = p.passport_number
    JOIN temp_bank_table AS tbt ON tpt.id = tbt.person_id
-- RESULTS: This narrows it down to 5 matching names with atm transactions and phone calls
        WHERE pc.year = 2023 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60
-- RESULTS: This narrows it down to 2 matching names after reviewing security logs for license plates and robbery time
        AND bsl.year = 2023 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 30 AND bsl.activity LIKE 'exit'
-- RESULTS: This narrows it down to 1 matching name after passport reviews and checking flight #
        AND p.flight_id = 36
        ;
-- RESULTS - ANSWER: Thief is Bruce / Accomplice is Robin / Escaped to NYC

-- DROP TEMPORARY TABLE IF EXISTS temp_people_table;
-- DROP TEMPORARY TABLE IF EXISTS temp_bank_table;
