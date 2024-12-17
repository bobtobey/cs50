-- ACTION: Read crime report for that date and on that street
SELECT description FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
-- RESULT: the crime happended at 10:15am in the bakery, there are 3 witness interviews that mention the bakery

-- ACTION: Next read interviews for that date of the crime where witness mentions bakery
SELECT name, transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- ACTION: Review bakery security logs for 10:15am to 10:30am
SELECT hour, activity, license_plate FROM bakery_security_logs
    WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND activity LIKE 'exit' ORDER BY license_plate;
-- RESULT: 9 vehicles exit the bakery parking lot at 10am yielding 9 license_plate

-- ACTION: Review atm transactions from 10:14am or earlier at Leggett st.
SELECT * FROM atm_transactions
    WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' ORDER BY account_number;
-- RESULT: 8 atm withdrawls were made on Leggett St. yielding 8 account_numbers

-- ACTIONS: Cross check atm records for crime location and date with Bank records
CREATE TEMPORARY TABLE temp_bank_table AS
SELECT account_number, person_id FROM bank_accounts
    WHERE account_number IN (SELECT account_number FROM atm_transactions
        WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ORDER BY account_number;
SELECT * FROM temp_bank_table;
-- RESULTS: found the matching person id's for the 8 atm transactions yields 8 names

-- ACTION: find persons name from bank account and store them in a temp table
CREATE TEMPORARY TABLE temp_people_table AS
SELECT name, id, phone_number, passport_number, license_plate FROM people WHERE id IN (
    SELECT person_id FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number FROM atm_transactions
            WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')
);
SELECT * FROM temp_people_table;
-- RESULTS: yield 8 possible names

-- Review phone calls from 10:15am to 10:30am
SELECT * FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;
-- RESULT: 9 calls were made on this date that lasted less than 1 min. yields 9 callers/receivers

-- ACTION: Match peoples names to their #'s callers or receivers
SELECT p1.name, caller, p2.name, receiver FROM phone_calls
    JOIN people AS p1 ON phone_calls.caller = p1.phone_number
    JOIN people AS p2 ON phone_calls.receiver = p2.phone_number
        WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;

-- Review earliest flights leaving on 7/29 and Airport id's
SELECT * FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute;
SELECT * FROM airports;
-- RESULTS: earliest flight leaves at 8:20am going to 4 = LGA LaGuardia Airport NYC

-- ACTIONS: review passenger info for flight 36
SELECT * FROM passengers WHERE flight_id = 36;
-- RESULTS: 8 persons found

-- ACTION: cross check phone numbers and license plates with temp people table
SELECT 'temp_people_table' AS table_name
    ,tpt.name, tpt.id, pc.caller
    ,ppl.name, pc.receiver
    ,p.passport_number, bsl.license_plate
    -- ,tbt.person_id AS bank_id, tbt.account_number
FROM temp_people_table AS tpt
    JOIN phone_calls AS pc ON tpt.phone_number = pc.caller
    JOIN people AS ppl ON pc.receiver = ppl.phone_number
    JOIN bakery_security_logs AS bsl ON tpt.license_plate = bsl.license_plate
    JOIN passengers AS p ON tpt.passport_number = p.passport_number
    -- JOIN temp_bank_table AS tbt ON ppl.id = tbt.person_id
-- RESULTS: there are 5 matching names with atm transactions and phone calls
        WHERE pc.year = 2023 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60
-- RESULTS: there are 3 matching names with license plate
        AND bsl.year = 2023 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.activity LIKE 'exit'
-- RESULTS: there are 2 matching names with passports
        AND p.flight_id = 36;

-- ACTIONS: review remaining tables

SELECT tpt.name, tpt.id, tbt.account_number, pc.caller, ppl.name AS receiver_name, bsl.license_plate, p.passport_number
FROM temp_people_table AS tpt
JOIN temp_bank_table AS tbt ON tpt.id = tbt.person_id
JOIN phone_calls AS pc ON tpt.phone_number = pc.caller
JOIN people AS ppl ON pc.receiver = ppl.phone_number
JOIN bakery_security_logs AS bsl ON tpt.license_plate = bsl.license_plate
JOIN passengers AS p ON tpt.passport_number = p.passport_number
WHERE pc.year = 2023 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60
AND bsl.year = 2023 AND bsl.month = 7 AND bsl.day = 28 AND bsl.hour = 10 AND bsl.activity LIKE 'exit'
AND p.flight_id = 36;


SELECT * FROM people;

-- DROP TEMPORARY TABLE IF EXISTS temp_people;
