-- ACTION: Read crime report for that date and on that street
SELECT description FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
-- RESULT: the crime happended at 10:15am in the bakery, there are 3 witness interviews that mention the bakery

-- Next read interviews for that date of the crime where witness mentions bakery
SELECT name, transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- Review bakery security logs for 10:15am to 10:30am
SELECT hour, activity, license_plate FROM bakery_security_logs
    WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND activity LIKE 'exit' ORDER BY license_plate;

-- Review atm transactions from 10:14am or earlier at Leggett st.
SELECT * FROM atm_transactions
    WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' ORDER BY account_number;
-- ACTIONS: Cross check atm records for crime location and date with Bank records
SELECT account_number, person_id FROM bank_accounts
    WHERE account_number IN (SELECT account_number FROM atm_transactions
        WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ORDER BY account_number;
-- ACTION: find persons name from bank account
SELECT name, id FROM people WHERE id IN (
    SELECT person_id FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number FROM atm_transactions
            WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')
);
-- RESULTS: yield 8 possible names

-- Review phone calls from 10:15am to 10:30am
SELECT * FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;

-- Review earliest flights leaving on 7/29 and Airport id's
SELECT * FROM flights WHERE year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute;
SELECT * FROM airports;
-- RESULTS: earliest flight leaves at 8:20am going to 4 = LGA LaGuardia Airport NYC

-- ACTIONS: review passenger info for flight 36
SELECT * FROM passengers WHERE flight_id = 36;
-- RESULTS: 8 persons found

-- ACTIONS: review remaining tables
SELECT * FROM people;
