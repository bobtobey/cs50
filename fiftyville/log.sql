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
