-- Keep a log of any SQL queries you execute as you solve the mystery.

-- ACTION: Read crime report for that date and on that street
SELECT description FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
-- RESULT: the crime happended at 10:15am in Emma's bakery, there are 3 witness interviews that mention the bakery

-- ACTION: Next read interviews for that date of the crime where witness mentions bakery
SELECT name, transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';
-- RESULT: witness Ruth sees thief leave in a car at 10:25am from bakery parking lot
-- RESULT: witness Eugene recognizes the thief from that morning before 10:15am, withdrawing money at the Leggett St. ATM
-- RESULT: witness Raymond saw the thief leaving the bakery and call someone for less than a minute right after the crime
